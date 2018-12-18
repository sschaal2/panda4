/*!=============================================================================
  ==============================================================================

  \file    panda_servo_unix.c

  \author  Stefan Schaal
  \date    2007

  ==============================================================================
  \remarks

  Runs a servo loop for input/output with the actual panda robot
  by using the panda APIs

  ============================================================================*/

// system includes
#include "SL_system_headers.h"

// private includes
#include "utility.h"
#include "SL.h"
#include "SL_common.h"
#include "SL_objects.h"
#include "SL_unix_common.h"
#include "SL_user.h"
#include "SL_sensor_proc.h"
#include "SL_motor_servo.h"
#include "SL_man.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"

// panda includes
#include <assert.h>
#include "conio.h"
#include <ctype.h>
#include <HD/hd.h>
#include <HDU/hduVector.h>
#include <HDU/hduError.h>


#define TRANSLATION_FILE "Translation.cf"
#define TIME_OUT_NS  NO_WAIT

// global variables
int servo_enabled;
double servo_time;

double        **joint_lin_rot;
double         *pos_polar;
double         *load_polar;

// panda device & scheduler
HHD               hHD;
HDSchedulerHandle hHandle;


//! local variables
typedef struct Translation {
  double slope;
  double offset;
} Translation;

static Translation     joint_trans_positions[N_DOFS+1];
static Translation     joint_trans_velocities[N_DOFS+1];
static Translation     joint_trans_torques[N_DOFS+1];
static Translation     joint_trans_desired_torques[N_DOFS+1];
static Translation     misc_trans_sensors[N_MISC_SENSORS+1];
static int             raw_positions[N_DOFS+1];
static int             raw_velocities[N_DOFS+1];
static int             last_raw_positions[N_DOFS+1];
static int             raw_torques[N_DOFS+1];
static int             raw_desired_torques[N_DOFS+1];
static int             raw_misc_sensors[N_MISC_SENSORS+1];
static SL_Jstate       last_joint_sim_state[N_DOFS+1];

static int             panda_servo_errors = 0;
static double          panda_servo_time   = 0;
static long            panda_servo_calls  = 0;
static int             panda_servo_rate;
static double          panda_time_overrun = 0;

static double          real_time = 0;
static double          last_real_time = 0;
static double          real_time_dt = 0;
static double          tick_time_used;
static struct timeval  tp,start_tp;

// global functions
HDCallbackCode HDCALLBACK run_panda_servo(void *dptr);
HDCallbackCode HDCALLBACK calibrate_panda(void *dptr);


// local functions
static int  receive_des_commands(void);
static int  send_sim_state(void);
static int  send_misc_sensors(void);

static int  init_translation(void);
static void translate_sensor_readings(SL_Jstate *joint_raw_state);
static void translate_misc_sensor_readings(double *misc_raw_sensors);
static void translate_commands(SL_Jstate *commands);

static int  calibratePanda(void);

static void addVarsToDataCollection(void);

static int  init_panda_servo(void);

static void read_sensor_offs(void);


/*!*****************************************************************************
 *******************************************************************************
\note  main
\date  Feb 1999
\remarks 

initializes everything and starts the servo loop

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     argc : number of elements in argv
 \param[in]     argv : array of argc character strings

 ******************************************************************************/
int 
main(int argc, char**argv)
{
  int i, j;

  sprintf(servo_name,"phan");

  // parse command line options
  parseOptions(argc, argv);

  // adjust settings if SL runs for a real robot
  setRealRobotOptions();

  // initalize the servo
  if (!init_panda_servo())
    return FALSE;

  // signal handlers
  installSignalHandlers();

  // spawn command line interface thread
  spawnCommandLineThread(NULL);

  // spawn the panda thread
  hHandle = hdScheduleAsynchronous(run_panda_servo, 0, HD_MAX_SCHEDULER_PRIORITY);
  servo_enabled = TRUE;

  // wait for completion of the thread
  hdWaitForCompletion(hHandle, HD_WAIT_INFINITE);

  return TRUE;
}
 
/*!*****************************************************************************
 *******************************************************************************
\note  init_panda_servo
\date  Nov. 2007
   
\remarks 

          Initializes all user specific sensory processing

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int
init_panda_servo(void)
{
  HDErrorInfo error;
  int i,j;
  double quat[N_QUAT+1];
  double pos[N_CART+1];
  double euler[N_CART+1];
  double aux;


  // get shared memory
  if (!init_shared_memory())
    return FALSE;

  // memory
  joint_lin_rot     = my_matrix(1,n_dofs,1,6);
  pos_polar         = my_vector(1,n_dofs);
  load_polar        = my_vector(1,n_dofs);

  // initalizes translation to and from units
  if (!init_translation())
    return FALSE;


  // initialize the base variables
  bzero((void *)&base_state,sizeof(base_state));
  bzero((void *)&base_orient,sizeof(base_orient));
  base_orient.q[_Q0_] = 1.0;

  if (read_parameter_pool_double_array(config_files[PARAMETERPOOL],"init_base_pos",N_CART,pos)) {
    for (i=1; i<=N_CART; ++i)
      base_state.x[i] = pos[i];
  }
  
  if (read_parameter_pool_double_array(config_files[PARAMETERPOOL],"init_base_quat",N_QUAT,quat)) {
    aux = 0.0;
    for (i=1; i<=N_QUAT; ++i)
      aux += sqr(quat[i]);
    aux = sqrt(aux);

    for (i=1; i<=N_QUAT; ++i) 
      base_orient.q[i] = quat[i]/(aux + 1.e-10);
  } else if (read_parameter_pool_double_array(config_files[PARAMETERPOOL],"init_base_euler",N_CART,euler)) {
    SL_quat qtmp;

    bzero((void *)&qtmp,sizeof(qtmp));
    eulerToQuat(euler, &qtmp);
    for (i=1; i<=N_QUAT; ++i) 
      base_orient.q[i] = qtmp.q[i];
  }


  // initialize servo variables
  servo_time           = 0;
  panda_servo_errors = 0;
  panda_servo_time   = 0;
  panda_servo_calls  = 0;
  panda_servo_rate   = servo_base_rate;
  
  // man pages
  addToMan("status","displays status information about servo",status);
  addToMan("readSensorOffsets","re-reads the sensor-offsets file",read_sensor_offs);
  
  // data collection
  initCollectData(servo_base_rate);
  addVarsToDataCollection();

  // the sensor calibration
  if (!read_sensor_calibration(config_files[SENSORCALIBRATION],joint_lin_rot,
      pos_polar,load_polar))
    return FALSE;

  if (!read_sensor_offsets(config_files[SENSOROFFSETS]))
    return FALSE;

  // initialize Panda
  hHD = hdInitDevice(HD_DEFAULT_DEVICE);
  
  if (HD_DEVICE_ERROR(error = hdGetError())) {
    hduPrintError(stderr, &error, "Failed to initialize Panda");
    fprintf(stderr, "\nPress any key to quit.\n");
    getchar();
    return FALSE;
  }

  hdSetSchedulerRate((HDulong)panda_servo_rate);
  hdStartScheduler();

  if (HD_DEVICE_ERROR(error = hdGetError()))  {
    hduPrintError(stderr, &error, "Failed to start scheduler");
    fprintf(stderr, "\nPress any key to quit.\n");
    getchar();
    return FALSE;
  }

  printf("\nPanda initialized\n");

  // calibrate -- we assume that the current position is the zero position
  if (!calibratePanda())
    return FALSE;

  // disable velocity limits
  if ( hdIsEnabled(HD_SOFTWARE_VELOCITY_LIMIT))
    hdDisable(HD_SOFTWARE_VELOCITY_LIMIT);   

  // enable motor control              
  if ( !hdIsEnabled(HD_FORCE_OUTPUT) )
    hdEnable(HD_FORCE_OUTPUT);   

  // what time is it?
  gettimeofday(&start_tp, NULL);
  last_real_time = 0;

  scd();

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  run_panda_servo
\date  Dec 1997
   
\remarks 

    this function is clocked by the panda thread at the moto_servo_rate

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     dptr  : not used

 ******************************************************************************/
HDCallbackCode HDCALLBACK 
run_panda_servo(void *dptr) 
{
  int      i,j;
  double   aux;
  HDlong   q_raw[6];
  HDlong   load_raw[3];
  HDlong   command_raw[3];
  HDdouble tick_duration;

  // increment time
  servo_time += 1./(double)panda_servo_rate;
  panda_servo_time = servo_time;
  ++panda_servo_calls;

  // get the real time
  gettimeofday(&tp, NULL);
  real_time      = (tp.tv_sec-start_tp.tv_sec)+(tp.tv_usec-start_tp.tv_usec)/1000000.;
  real_time_dt   = real_time-last_real_time;
  last_real_time = real_time;

  // too long processing -- shut down
  if (real_time_dt > 50./(double)panda_servo_rate) {
    hdDisable(HD_FORCE_OUTPUT);  
    printf("Force output disable due to dt = %f\n",real_time_dt);
  }

  // too short processing -- skip this cycle
  if (real_time_dt < 0.25/(double)panda_servo_rate) {
    return HD_CALLBACK_CONTINUE;
  }

  // read information from the robot
  hdBeginFrame(hHD); 
  hdGetLongv(HD_CURRENT_ENCODER_VALUES,q_raw); 
  hdGetLongv(HD_LAST_MOTOR_DAC_VALUES,load_raw); 

  // save last values
  for (i=1; i<=N_DOFS; ++i)
    last_raw_positions[i] = raw_positions[i];

  // assign to final values and convert to units
  raw_positions[SR]   = q_raw[0];
  raw_positions[SFE]  = q_raw[2];
  raw_positions[EB ]  = q_raw[2]-q_raw[1];

  for (i=1; i<=N_DOFS; ++i)
    raw_velocities[i]  = (raw_positions[i]-last_raw_positions[i])/
      (double)real_time_dt;

  raw_torques[SR]     = load_raw[0];
  raw_torques[SFE]    = load_raw[2];
  raw_torques[EB ]    = load_raw[1];

  // translate the raw values to units
  for (i=1; i<=N_DOFS; ++i)
    last_joint_sim_state[i] = joint_sim_state[i];
  translate_sensor_readings(joint_sim_state);
  for (i=1; i<=N_DOFS; ++i)
    joint_sim_state[i].thdd = (joint_sim_state[i].thd - last_joint_sim_state[i].thd)/
      (double)real_time_dt;      
  translate_misc_sensor_readings(misc_sim_sensor);

  // send to shared memory
  send_sim_state();
  send_misc_sensors();

  // trigger the motor servo with semFlush for nicer synchronization
  if (semFlush(sm_motor_servo_sem) == ERROR) {
    hdEndFrame(hHD); 
    return HD_CALLBACK_DONE;
  }

  // read the commands
  receive_des_commands();

  // translate commands to raw
  translate_commands(joint_sim_state);
  command_raw[0] = raw_desired_torques[SR];
  command_raw[1] = raw_desired_torques[EB];
  command_raw[2] = raw_desired_torques[SFE];

  // execute commands
  hdSetLongv(HD_CURRENT_MOTOR_DAC_VALUES, command_raw);
  hdEndFrame(hHD); 

  // data collection
  writeToBuffer();

  // check for servo overuns
  tick_duration = hdGetSchedulerTimeStamp();
  tick_time_used = tick_duration;
  aux = tick_duration - 1./(double)panda_servo_rate;
  if (aux > 0)
    panda_time_overrun += aux;
  //panda_servo_errors += ceil(tick_duration*panda_servo_rate) - 1;

  return HD_CALLBACK_CONTINUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  init_translation
\date  Dec 1997
   
\remarks 

          the translation of raw numbers to and from units

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int
init_translation(void)

{
  
  int       i,j;
  FILE      *in;
  int       error_flag = FALSE;
  char      string[100];
  int       rc;


  /* Get the translation info for each joint: we just parse those
     values from the file config/Translation.cf */

  sprintf(string,"%s%s",CONFIG,TRANSLATION_FILE);
  in = fopen(string,"r");
  if (in == NULL) {
    printf("ERROR: Cannot open file >%s<!\n",string);
    return FALSE;
  }

  /* parse all translation variables according to the joint variables */
  for (i=1; i<= n_dofs; ++i) {
    if (!find_keyword(in, &(joint_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",joint_names[i]);
      fclose(in);
      return FALSE;
    }
    rc = fscanf(in,"%lf %lf %lf %lf %lf %lf %lf %lf",
	   &joint_trans_positions[i].slope,
	   &joint_trans_positions[i].offset,
	   &joint_trans_velocities[i].slope,
	   &joint_trans_velocities[i].offset,
	   &joint_trans_torques[i].slope,
	   &joint_trans_torques[i].offset,
	   &joint_trans_desired_torques[i].slope,
	   &joint_trans_desired_torques[i].offset);
  }

  for (i=1; i<= n_misc_sensors; ++i) {
    if (!find_keyword(in, &(misc_sensor_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",misc_sensor_names[i]);
      fclose(in);
      return FALSE;
    }
    rc =fscanf(in,"%lf %lf",
	   &misc_trans_sensors[i].slope,
	   &misc_trans_sensors[i].offset);
  }

  fclose(in);

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  translate_sensor_readings
\date  Dec 1997
   
\remarks 

          translate sensors to unit values

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    raw : the raw state

 ******************************************************************************/
static void
translate_sensor_readings(SL_Jstate *joint_raw_state)

{

  int i,j;
  double temp=0;

  for (i=1; i<=N_DOFS; ++i) {

    // translate the position sensors
    joint_raw_state[i].th = (joint_trans_positions[i].offset + 
			     raw_positions[i]) * joint_trans_positions[i].slope;

    // translate the velocity sensors

    joint_raw_state[i].thd = (joint_trans_velocities[i].offset + 
			      raw_velocities[i]) * joint_trans_velocities[i].slope;

    // translate the force sensors
    joint_raw_state[i].load = (joint_trans_torques[i].offset + 
			       raw_torques[i]) * joint_trans_torques[i].slope;

    joint_raw_state[i].th   *= pos_polar[i];
    joint_raw_state[i].thd  *= pos_polar[i];
    joint_raw_state[i].load *= load_polar[i];

    // take out the user offset from the position
    joint_raw_state[i].th -= joint_range[i][THETA_OFFSET];

  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  translate_misc_sensor_readings
\date  Dec 1997
   
\remarks 

          translate miscellaneous sensors to unit values

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    raw : the raw state

 ******************************************************************************/
static void
translate_misc_sensor_readings(double *misc_raw_sensor)

{

  int i,j;
  double temp=0;

  for (i=1; i<=N_MISC_SENSORS; ++i) {

    /* translate the position sensors */

    misc_raw_sensor[i] = (misc_trans_sensors[i].offset + 
			     raw_misc_sensors[i]) * 
      misc_trans_sensors[i].slope;

  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  translate_commands
\date  Dec 1997
   
\remarks 

          translate unit commands into raw values

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     commands : the structure containing the commands

 ******************************************************************************/
#define MAX_SAFE_COMMAND (3404*2) //!< 3404 recommended by SensAble
static void
translate_commands(SL_Jstate *command)
{

  int i,j;
  double temp=0;
  double raw;

  for (i=1; i<=N_DOFS; ++i) {

    temp = command[i].u * load_polar[i];

    raw = temp/joint_trans_desired_torques[i].slope -
      joint_trans_desired_torques[i].offset; 

    if (raw < -MAX_SAFE_COMMAND) 
      raw = -MAX_SAFE_COMMAND;
    if (raw > MAX_SAFE_COMMAND)
      raw = MAX_SAFE_COMMAND;

    raw_desired_torques[i] = (int) raw;

  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  calibratePanda
\date  Dec. 2007
   
\remarks 

    zeros the encoders of the pandam, i.e., make the current position the
    zero position.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int
calibratePanda(void)
{
  HDErrorInfo error;
  void *dptr = NULL;

  hdScheduleAsynchronous(calibrate_panda,0,HD_MAX_SCHEDULER_PRIORITY);

  if (HD_DEVICE_ERROR(error = hdGetError())) {
    hduPrintError(stderr, &error, "Failed to calibrate Panda");
    fprintf(stderr, "\nPress any key to quit.\n");
    getchar();
    return FALSE;
  }

  return TRUE;
}

HDCallbackCode HDCALLBACK
calibrate_panda(void *dptr) 
{
  hdUpdateCalibration(HD_CALIBRATION_ENCODER_RESET);

  return HD_CALLBACK_DONE;
}


/*!*****************************************************************************
 *******************************************************************************
\note  addVarsToDataCollection
\date  Nov 2007
   
\remarks 

        adds important variables to data collection

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static void
addVarsToDataCollection(void)

{
  int i;
  
  addVarToCollect((char *)&(real_time),"real_time","s", DOUBLE,FALSE);
  addVarToCollect((char *)&(real_time_dt),"real_time_dt","s", DOUBLE,FALSE);
  addVarToCollect((char *)&(tick_time_used),"tick_time_used","s", DOUBLE,FALSE);

  for (i=1; i<=N_DOFS; ++i) {
    char string[100];

    sprintf(string,"%s_th",joint_names[i]);
    addVarToCollect((char *)&(joint_sim_state[i].th),string,"rad", DOUBLE,FALSE);
    sprintf(string,"%s_thd",joint_names[i]);
    addVarToCollect((char *)&(joint_sim_state[i].thd),string,"rad/s", DOUBLE,FALSE);
    sprintf(string,"%s_thdd",joint_names[i]);
    addVarToCollect((char *)&(joint_sim_state[i].thdd),string,"rad/s^2", DOUBLE,FALSE);
    sprintf(string,"%s_u",joint_names[i]);
    addVarToCollect((char *)&(joint_sim_state[i].u),string,"Nm", DOUBLE,FALSE);
    sprintf(string,"%s_load",joint_names[i]);
    addVarToCollect((char *)&(joint_sim_state[i].load),string,"Nm", DOUBLE,FALSE);
  }


  for (i=1; i<=N_MISC_SENSORS; ++i) {
    char string[100];

    sprintf(string,"%s",misc_sensor_names[i]);
    addVarToCollect((char *)&(misc_sim_sensor[i]),string,"-",DOUBLE,FALSE);
  }

  updateDataCollectScript();

}

/*!*****************************************************************************
 *******************************************************************************
\note  receive_des_commands
\date  Nov. 2007
   
\remarks 

        reads the commands from the joint_sim_state shared memory
        structure
	

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int 
receive_des_commands(void)
{
  
  int i;

  if (semTake(sm_des_commands_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++panda_servo_errors;
    return FALSE;

  } 

  for (i=1; i<=n_dofs; ++i)
    joint_sim_state[i].u = (double) sm_des_commands->des_command[i].u;
  
  semGive(sm_des_commands_sem);

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  send_sim_state
\date  Nov. 2007
   
\remarks 

        sends the entire joint_sim_state to shared memory
	

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int 
send_sim_state(void)
{
  
  int i;

  // joint state
  if (semTake(sm_joint_sim_state_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++panda_servo_errors;
    return FALSE;

  } 

  cSL_Jstate(joint_sim_state,sm_joint_sim_state_data,n_dofs,DOUBLE2FLOAT);
    
  for (i=1; i<=n_dofs; ++i)
      sm_joint_sim_state->joint_sim_state[i] = sm_joint_sim_state_data[i];

  sm_joint_sim_state->ts = servo_time;
  
  semGive(sm_joint_sim_state_sem);


  // base state
  if (semTake(sm_base_state_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++panda_servo_errors;
    return FALSE;

  } 

  cSL_Cstate(&base_state-1, sm_base_state_data, 1, DOUBLE2FLOAT);

  sm_base_state->state[1] = sm_base_state_data[1];
  
  sm_base_state->ts = servo_time;
  
  semGive(sm_base_state_sem);


  // base orient
  if (semTake(sm_base_orient_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++panda_servo_errors;
    return FALSE;

  } 

  cSL_quat(&base_orient-1, sm_base_orient_data, 1, DOUBLE2FLOAT);

  sm_base_orient->orient[1] = sm_base_orient_data[1];

  sm_base_orient->ts = servo_time;
  
  semGive(sm_base_orient_sem);


  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  send_misc_sensors
\date  Nov. 2007
   
\remarks 

        sends the entire misc_sim_sensor to shared memory
	

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int 
send_misc_sensors(void)
{
  
  int i;

  if (n_misc_sensors <= 0)
    return TRUE;

  if (semTake(sm_misc_sim_sensor_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++panda_servo_errors;
    return FALSE;

  } 

  for (i=1; i<=n_misc_sensors; ++i)
      sm_misc_sim_sensor->value[i] = misc_sim_sensor[i];

  sm_misc_sim_sensor->ts = servo_time;
  
  semGive(sm_misc_sim_sensor_sem);

  return TRUE;
}


/*!*****************************************************************************
 *******************************************************************************
\note  status
\date  Nov 2007
   
\remarks 

        prints out all important variables

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
void
status(void)
{

  printf("\n");
  printf("            Time                   = %f\n",panda_servo_time);
  printf("            Servo Calls            = %ld\n",panda_servo_calls);
  printf("            Servo Rate             = %d\n",servo_base_rate);
  printf("            Servo Errors           = %d (%6.2f%%)\n",panda_servo_errors,
	 (double)panda_servo_errors/(double)panda_servo_calls*100);
  printf("            Time Overrun           = %f (%6.2f%%)\n",panda_time_overrun,
	 panda_time_overrun/panda_servo_time*100.0);
  printf("\n");

}

/*!*****************************************************************************
 *******************************************************************************
\note  read_sensor_offs
\date  Oct 2011
   
\remarks 

interface to read sensor offsets configuration file

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
read_sensor_offs(void)
{
  read_sensor_offsets(config_files[SENSOROFFSETS]);
}

