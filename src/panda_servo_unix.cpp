/*!=============================================================================
  ==============================================================================

  \file    panda_servo_unix.cpp

  \author  Stefan Schaal
  \date    2018

  ==============================================================================
  \remarks

  Runs a servo loop for input/output with the actual panda robot
  by using the libfranka APIs

  ============================================================================*/

// system includes
#include <array>
#include <atomic>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>

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
#include <franka/duration.h>
#include <franka/exception.h>
#include <franka/model.h>
#include <franka/rate_limiting.h>
#include <franka/robot.h>

#define TRANSLATION_FILE "Translation.cf"
#define TIME_OUT_NS  NO_WAIT

// global variables
int servo_enabled;
double servo_time;

double        **joint_lin_rot;
double         *pos_polar;
double         *load_polar;

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
static double          raw_positions[N_DOFS+1];
static double          raw_velocities[N_DOFS+1];
static double          raw_torques[N_DOFS+1];
static double          raw_desired_torques[N_DOFS+1];
static double          raw_misc_sensors[N_MISC_SENSORS+1];
static SL_Jstate       last_joint_sim_state[N_DOFS+1];

static int             panda_servo_errors = 0;
static double          panda_servo_time   = 0;
static long            panda_servo_calls  = 0;
static int             panda_servo_rate;
static double          panda_time_overrun = 0;

static double          real_time_dt = 0;

// global functions



// local functions
static int  receive_des_commands(void);
static int  send_sim_state(void);
static int  send_misc_sensors(void);

static int  init_translation(void);
static void translate_sensor_readings(SL_Jstate *joint_raw_state);
static void translate_misc_sensor_readings(double *misc_raw_sensors);
static void translate_commands(SL_Jstate *commands);

static void addVarsToDataCollection(void);

static int  init_panda_servo(franka::Robot &robot);
static int  run_panda_servo(void);

static void read_sensor_offs(void);

static void generate_data_dynamics_param(franka::Model &model);


/*!*****************************************************************************
 *******************************************************************************
\note  main
\date  Dec. 2018
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
  int  i,j;
  char ip_string[20];

  sprintf(servo_name,"panda");

  // parse command line options
  parseOptions(argc, argv);

  // check for Panda IP address
  for (i=1; i<argc; ++i) {
    if (strcmp(argv[i],"-ip")==0) {
      if (i+1 < argc) {
	strcpy(ip_string,argv[i+1]);
	printf("Connecting to Panda at %s ...\n",ip_string);
	break;
      }
    }
  }
  if (i>= argc) {
    // no IP found
    // try to find it in the parameter pool
    if (read_parameter_pool_string(config_files[PARAMETERPOOL],"panda_ip",ip_string)) {
      ;  // ip string found
    } else {
      // abort
      printf("No IP address for Panda\n");
      std::cout << "Press Enter to continue..." << std::endl;
      std::cin.ignore();
      return FALSE;
    }
  }

  // adjust settings if SL runs for a real robot
  setRealRobotOptions();

  // signal handlers
  installSignalHandlers();

  // spawn command line interface thread
  spawnCommandLineThread(NULL);

  // initialize Panda robot
  try {
    franka::Robot robot(ip_string);

    // Load the kinematics and dynamics model and keep it accessible in the scope of this file
    franka::Model model = robot.loadModel();

    // Define callback for the joint torque control loop.
    std::function<franka::Torques(const franka::RobotState&, franka::Duration)> panda_callback = 
      [&model,&robot](const franka::RobotState& state, franka::Duration period) -> franka::Torques {

      static int n_calls = 0;

      ++n_calls;

      // extract all relevant info from the robot state variable
      for (size_t i = 0; i < 7; i++) {
	raw_positions[i+1]  = state.q[i];
	raw_velocities[i+1] = state.dq[i];
	raw_torques[i+1]    = state.tau_J[i];
      }

      // check the timing: number of milliseconds the servo loop ran: should be 1 for perfect behavior
      real_time_dt = period.toMSec();

      // all processing is done in separate function
      std::array<double, 7> tau_d;

      if (! run_panda_servo() ) {

	robot.stop();

      } else {

	// copy the control commands back into franka::Torques
	if (n_calls < 10) {  // these are a few start-up ticks to assure the task servo has the robot state
	  for (size_t i = 0; i < 7; i++) 
	    tau_d[i] = 0.0;
	} else {
	  for (size_t i = 0; i < 7; i++) {
	    tau_d[i] = raw_desired_torques[i+1]; 
	  }
	}
      }
      
      // Send torque command.
      return tau_d;
    };

    // initalize the servo
    if (!init_panda_servo(robot))
      return FALSE;

    //    generate_data_dynamics_param(model);

    // Start real-time control with the callback without rate limitter and no cutoff
    servo_enabled = TRUE;
    // default first data collection
    scd();

    // note that the rate limitter is enabled, such that the robot does not shut down
    // e.g., when executing freeze. Normally, if smooth motion is generated, we should
    // not get weird dynamics from this
    robot.control(panda_callback,true,franka::kMaxCutoffFrequency);

  } catch (const franka::Exception& ex) {
    std::cerr << ex.what() << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
    
    return FALSE;
  } 


  return TRUE;
}
 
/*!*****************************************************************************
 *******************************************************************************
\note  init_panda_servo
\date  Dec. 2018
   
\remarks 

          Initializes all user specific sensory processing

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     \param[in,out]     robot  : robot object of Panda

 ******************************************************************************/
static int
init_panda_servo(franka::Robot &robot)
{
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
  servo_time         = 0;
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

  // set Panda parameters

  // Set collision behavior: needs to be outside of real-time loop
  robot.setCollisionBehavior({{100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0}},
			     {{100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0}},
			     {{100.0, 100.0, 100.0, 100.0, 100.0, 100.0}},
			     {{100.0, 100.0, 100.0, 100.0, 100.0, 100.0}});
  
  robot.setJointImpedance({{3000, 3000, 3000, 2500, 2500, 2000, 2000}});
  robot.setCartesianImpedance({{3000, 3000, 3000, 300, 300, 300}});

  printf("\nPanda initialized\n");


  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  run_panda_servo
\date  Dec 2018
   
\remarks 

    this function is clocked by the panda callback at the moto_servo_rate

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

         none
     
         returns sucess or failure

 ******************************************************************************/
int
run_panda_servo(void) 
{
  int      i,j;
  double   aux;

  // increment time
  servo_time += 1./(double)panda_servo_rate;
  panda_servo_time = servo_time;
  ++panda_servo_calls;

  // translate the raw values to units
  for (i=1; i<=N_DOFS; ++i)
    last_joint_sim_state[i] = joint_sim_state[i];
  translate_sensor_readings(joint_sim_state);
  if (real_time_dt > 0) {
    for (i=1; i<=N_DOFS; ++i)
      joint_sim_state[i].thdd = (joint_sim_state[i].thd - last_joint_sim_state[i].thd)/
	(double)real_time_dt;
  }
  translate_misc_sensor_readings(misc_sim_sensor);

  // send to shared memory
  send_sim_state();
  send_misc_sensors();

  // trigger the motor servo with semFlush for nicer synchronization
  if (semFlush(sm_motor_servo_sem) == ERROR) {
    return FALSE;
  }

  // read the commands
  receive_des_commands();

  // translate commands to raw
  translate_commands(joint_sim_state);

  // data collection
  writeToBuffer();

  // check for servo overuns
  panda_servo_errors += real_time_dt - 1;

  return TRUE;
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

    raw_desired_torques[i] = (int) raw;

  }

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
  
  addVarToCollect((char *)&(real_time_dt),"real_time_dt","s", DOUBLE,FALSE);

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

/*!*****************************************************************************
 *******************************************************************************
\note  generate_data_dynamics_param
\date  Dec. 2018
   
\remarks 

generates a data file to estimate the Panda Rigid Body Parameters

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    model : the franka::Model

 ******************************************************************************/
static void
generate_data_dynamics_param(franka::Model &model)
{
  franka::RobotState state;
  std::array<double, 7> coriolis;
  std::array<double, 7> gravity;
  std::array<double, 49> mass;
  const int big=1000000;
  
  int count=0,temp;

  /*
  for (int i=0; i<7; ++i) {
    printf("%d. %f %f %f %f\n",i,joint_range[i+1][MIN_THETA], joint_range[i+1][MAX_THETA],franka::kMaxJointVelocity[i],franka::kMaxJointAcceleration[i]);
  }
  */
  printf("Generating parameter estimation data ...");
  
  // how much data to collect
  int max_data = pow(2.0,21.0);
    
  // prepare data collection
  changeSamplingTime( max_data/(double)panda_servo_rate );
  scd();

  while (count++ < max_data) {
    temp = count;
    
    for (int i=J1; i<=J7; ++i) { // position: some slack to stay away from extermes
      if (temp & 0x1)
	joint_sim_state[i].th = joint_range[i][MAX_THETA] - 0.03; 
      else
	joint_sim_state[i].th = joint_range[i][MIN_THETA] + 0.03;

      joint_sim_state[i].th = (double)(random_number((long int) ((joint_range[i][MAX_THETA] - 0.03)*big),
						     (long int) ((joint_range[i][MIN_THETA] + 0.03)*big)))/
	(double)big;   

      state.q[i-1] = joint_sim_state[i].th;
      temp = temp >> 1;
    }

    for (int i=J1; i<=J7; ++i) { // velocity
      if (temp & 0x1)
	joint_sim_state[i].thd = franka::kMaxJointVelocity[i-1];
      else
	joint_sim_state[i].thd = -franka::kMaxJointVelocity[i-1];

      joint_sim_state[i].thd = (double)(random_number((long int) (franka::kMaxJointVelocity[i-1]*big),
						     (long int) (-franka::kMaxJointVelocity[i-1]*big)))/
	(double)big;   


      state.dq[i-1] = joint_sim_state[i].thd;      
      temp = temp >> 1;
    }

    for (int i=J1; i<=J7; ++i) { // accelerations
      if (temp & 0x1)
	joint_sim_state[i].thdd = franka::kMaxJointAcceleration[i-1];
      else
	joint_sim_state[i].thdd = -franka::kMaxJointAcceleration[i-1];

      joint_sim_state[i].thdd = (double)(random_number((long int) (franka::kMaxJointAcceleration[i-1]*big),
						     (long int) (-franka::kMaxJointAcceleration[i-1]*big)))/
	(double)big;   

      state.ddq_d[i-1] = joint_sim_state[i].thdd;      
      temp = temp >> 1;
    }

    // compute the dynamics from these values in state
    gravity = model.gravity(state); // default gravity is -9.81 in Z
    coriolis = model.coriolis(state);
    mass = model.mass(state);

    for (int i=J1; i<=J7; ++i ) {
      joint_sim_state[i].u = gravity[i-1] + coriolis[i-1];
      for (int j=J1; j<=J7; ++j) {
	joint_sim_state[i].u += mass[i-1 + (j-1)*7]*state.ddq_d[j-1];
      }
      joint_sim_state[i].load = joint_sim_state[i].u;
    }

    writeToBuffer();

  }

  printf("done\n");

  saveData();
  changeSamplingTime( 5.0);

  
}

