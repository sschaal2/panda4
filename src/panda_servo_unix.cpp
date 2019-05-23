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
#include "utility_macros.h"
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
#include "SL_dynamics.h"

// panda includes
#include <franka/duration.h>
#include <franka/exception.h>
#include <franka/model.h>
#include <franka/rate_limiting.h>
#include <franka/robot.h>
#include <franka/gripper.h>

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
static double          u_grav[N_DOFS+1];

static int             panda_servo_errors = 0;
static double          panda_servo_time   = 0;
static long            panda_servo_calls  = 0;
static int             panda_servo_rate;
static double          panda_time_overrun = 0;

static double          real_time_dt = 0;

static pthread_t       cthread;   // thread for gripper read state
static pthread_t       ethread;   // thread for gripper execute

static char            ip_string[20]; // ip of franka robot

static int             change_endeff_flag = FALSE;


enum GripperTasks {
  MOVE,
  GRASP,
  READ_STATE,
};

static int             run_gripper_thread_flag = FALSE;
static int             gripper_task=READ_STATE;

static double          width,speed,force,eps_in,eps_out; //grasp parameters

enum CollectData {
  COLLECT_NONE=0,
  COLLECT_RANDOM,
  COLLECT_SYSTEMATIC,
};

// model parameters from Franka model library
static  std::array<double, 7> coriolis;
static  std::array<double, 7> u_gravity;
static  std::array<double, 49> mass;

static int collect_data = COLLECT_NONE;

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

static void compute_ft_offsets(void);
static void printDyn(void);

static void spawnGripperThread(void);
static void *gripperThread(void *);

static int  checkForMessages(void);

static int  set_stiffness_frame(franka::Robot &robot);



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

  // check for data collection flag
  for (i=1; i<argc; ++i) {
    if (strcmp(argv[i],"-cdr")==0) {
      collect_data = COLLECT_RANDOM;
      break;
    }
    if (strcmp(argv[i],"-cds")==0) {
      collect_data = COLLECT_SYSTEMATIC;
      break;
    }
  }


  // adjust settings if SL runs for a real robot
  setRealRobotOptions();

  // signal handlers
  installSignalHandlers();

  // spawn command line interface thread
  spawnCommandLineThread(NULL);

  // spawn gripper thread
  spawnGripperThread();

  // initialize Panda robot
  try {
    franka::Robot   robot(ip_string);

    // Load the kinematics and dynamics model and keep it accessible in the scope of this file
    franka::Model model = robot.loadModel();

    // turn on auto recovery
    robot.automaticErrorRecovery();

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

      // change sign of the readings as we seemingly get the force/torque the robot applies
      raw_misc_sensors[C_FX] = -state.K_F_ext_hat_K[0];
      raw_misc_sensors[C_FY] = -state.K_F_ext_hat_K[1];
      raw_misc_sensors[C_FZ] = -state.K_F_ext_hat_K[2];
      raw_misc_sensors[C_MX] = -state.K_F_ext_hat_K[3];
      raw_misc_sensors[C_MY] = -state.K_F_ext_hat_K[4];
      raw_misc_sensors[C_MZ] = -state.K_F_ext_hat_K[5];

      // check the timing: number of milliseconds the servo loop ran: should be 1 for perfect behavior
      real_time_dt = period.toMSec();

      // all processing is done in a separate function
      std::array<double, 7> tau_d;

      // computer gravity torques to inform the motor servo about the total command
      // and compute other dyn parameters for print out. Only gravity is really needed
      // while coriolis and mass matrix are just for debugging
      
      u_gravity = model.gravity(state); // default gravity is -9.81 in Z
      coriolis = model.coriolis(state);
      mass = model.mass(state);

      for (size_t i = 0; i < 7; ++i)
	u_grav[i+1] = u_gravity[i];


      if (! run_panda_servo() ) {

	robot.stop();

      } else {

	// copy the control commands back into franka::Torques
	if (n_calls <= 10) {  // these are a few start-up ticks to assure the task servo has the robot state
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

    // if data collection, exist right afterwards
    if (collect_data) {
      generate_data_dynamics_param(model);
      return TRUE;
    }

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
  int i,j, count;
  double quat[N_QUAT+1];
  double pos[N_CART+1];
  double euler[N_CART+1];
  double aux;
  MY_MATRIX(R,1,N_CART,1,N_CART);
  MY_VECTOR(v,1,N_CART);


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

  // read link parameters
  if (!read_link_parameters(config_files[LINKPARAMETERS]))
    return FALSE;

  // the the default endeffector parameters
  setDefaultEndeffector();

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
  addToMan("calibrate_cFT","calibrates the computed FT offsets",compute_ft_offsets);
  addToMan("printDyn","prints the dynamics parameters",printDyn);
  
  
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

  // set the stiffness frame of the robot to the endeffector frame
  set_stiffness_frame(robot);

#if 0
  std::array<double, 16> offset_homogeneous_matrix;
  offset_homogeneous_matrix.fill(0.0);

  // compute the rotation matrix of endeffector
  for (i=1; i<=N_CART; ++i)
    v[i] = endeff[HAND].a[i];

  eulerToRotMat(v,R);

  // sort all into a homogenous transformation matrix in column-major format (Franka!)
  count = 0;
  for (i=1; i<=N_CART; ++i) {
    for (j=1; j<=N_CART; ++j) {
      offset_homogeneous_matrix[count++] = R[j][i];
    }
    offset_homogeneous_matrix[count++] = 0.0;
  }

  for (i=1; i<=N_CART; ++i)
    offset_homogeneous_matrix[count++] = endeff[HAND].x[i];

  offset_homogeneous_matrix[count++] = 1.0;

  robot.setK(offset_homogeneous_matrix);

#endif
  
  printf("\nPanda initialized\n");


  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  set_stiffness_frame
\date  May 2019
   
\remarks 

 Sets the stiffness coordinate from the current endeffector info

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     robot  : robot object of Panda

 ******************************************************************************/
static int
set_stiffness_frame(franka::Robot &robot)
{
  int i,j, count;
  MY_MATRIX(R,1,N_CART,1,N_CART);
  MY_VECTOR(v,1,N_CART);

  // set the stiffness frame of the robot to the endeffector frame
  std::array<double, 16> offset_homogeneous_matrix;
  offset_homogeneous_matrix.fill(0.0);

  // compute the rotation matrix of endeffector
  for (i=1; i<=N_CART; ++i)
    v[i] = endeff[HAND].a[i];

  eulerToRotMat(v,R);

  // sort all into a homogenous transformation matrix in column-major format (Franka!)
  count = 0;
  for (i=1; i<=N_CART; ++i) {
    for (j=1; j<=N_CART; ++j) {
      offset_homogeneous_matrix[count++] = R[j][i];
    }
    offset_homogeneous_matrix[count++] = 0.0;
  }

  for (i=1; i<=N_CART; ++i)
    offset_homogeneous_matrix[count++] = endeff[HAND].x[i];

  offset_homogeneous_matrix[count++] = 1.0;

  robot.setK(offset_homogeneous_matrix);

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

  for (i=1; i<=N_DOFS; ++i)
    joint_sim_state[i].uff  += u_grav[i];

  if (real_time_dt > 0) {
    for (i=1; i<=N_DOFS; ++i)
      joint_sim_state[i].thdd = (joint_sim_state[i].thd - last_joint_sim_state[i].thd)/
	((double)real_time_dt/1000.0); // real_time_dt is in milliseconds
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

  // check for messages
  checkForMessages();

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

  for (i=1; i<=n_dofs; ++i) {
    joint_sim_state[i].u  = (double) sm_des_commands->des_command[i].u;
    joint_sim_state[i].uff = (double) sm_des_commands->des_command[i].uff;
  }
  
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

      if (collect_data == COLLECT_RANDOM)
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

      if (collect_data == COLLECT_RANDOM)
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

      if (collect_data == COLLECT_RANDOM)
	joint_sim_state[i].thdd = (double)(random_number((long int) (franka::kMaxJointAcceleration[i-1]*big),
							 (long int) (-franka::kMaxJointAcceleration[i-1]*big)))/
	  (double)big;   

      state.ddq_d[i-1] = joint_sim_state[i].thdd;      
      temp = temp >> 1;
    }

    // compute the dynamics from these values in state
    u_gravity = model.gravity(state); // default gravity is -9.81 in Z
    coriolis = model.coriolis(state);
    mass = model.mass(state);

    for (int i=J1; i<=J7; ++i ) {
      joint_sim_state[i].u = u_gravity[i-1] + coriolis[i-1];
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

/*!*****************************************************************************
 *******************************************************************************
\note  compute_ft_offsets
\date  Jan 2019
   
\remarks 

 computes an average offset of the computer F/T sensor of Panda

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static void
compute_ft_offsets(void)
{

  double data[2*N_CART+1]={0,0,0,0,0,0,0};
  int    count=100;
  int    i,j;
  long   last_panda_servo_calls = panda_servo_calls;

  
  for (i=1; i<= count; ++i) {
    
    while (last_panda_servo_calls == panda_servo_calls) {
      taskDelay(ns2ticks(10000000)); // wait 10ms
    }
    last_panda_servo_calls = panda_servo_calls;

    for (j=1; j<=2*N_CART; ++j)
      data[j] += raw_misc_sensors[C_FX-1+j];
    
  }

  for (j=1; j<=2*N_CART; ++j)
    misc_trans_sensors[C_FX-1+j].offset = -data[j]/(double)count;

  
}

/*!*****************************************************************************
*******************************************************************************
\note  spawnGripperThread
\date  Feb 2019
 
\remarks 
 
spawns off a thread to do non-real-time communication with gripper
 
*******************************************************************************
Function Parameters: [in]=input,[out]=output
 
none
 
******************************************************************************/
static void
spawnGripperThread(void) 
{
  int err = 0;
  int rc;
  pthread_attr_t pth_attr;
  size_t stack_size = 0;

  err = pthread_attr_init(&pth_attr);
  pthread_attr_getstacksize(&pth_attr, &stack_size);
  double reqd = 1024*1024*8;
  if (stack_size < reqd)
    pthread_attr_setstacksize(&pth_attr, reqd);

  // initialize a thread for blocking gripper commands
  run_gripper_thread_flag = TRUE;
  if ((rc=pthread_create( &cthread, &pth_attr, gripperThread, NULL)))
      printf("pthread_create returned with %d\n",rc);

}

/*!*****************************************************************************
*******************************************************************************
\note  gripperThread
\date  Feb 2019
 
\remarks 
 
non-realtime thread for gripper communication
 
*******************************************************************************
Function Parameters: [in]=input,[out]=output
 
none
 
******************************************************************************/
static void *
gripperThread(void *) 
{
  long   last_panda_servo_calls = panda_servo_calls;

  try {

    franka::Gripper gripper(ip_string);

    while (run_gripper_thread_flag) {

      
      while (last_panda_servo_calls == panda_servo_calls) {
	taskDelay(ns2ticks(10000000)); // wait 10ms
      }
      last_panda_servo_calls = panda_servo_calls;
      
      switch (gripper_task) {

      case MOVE:
	raw_misc_sensors[G_MOTION] = TRUE;
	gripper.move(width,speed);
	raw_misc_sensors[G_MOTION] = FALSE;	
	gripper_task = READ_STATE;
	break;
	
      case GRASP:
	raw_misc_sensors[G_MOTION] = TRUE;	
	gripper.grasp(width,speed,force,eps_in,eps_out);
	raw_misc_sensors[G_MOTION] = FALSE;		
	gripper_task = READ_STATE;
	break;
	
      case READ_STATE:
      default: // read the gripper state
	franka::GripperState gripper_state = gripper.readOnce();
	raw_misc_sensors[G_WIDTH] = gripper_state.width;

      }

    }

  } catch (const franka::Exception& ex) {

    std::cerr << "gripperThread:" << std::endl;
    std::cerr << ex.what() << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
    
  }

  return NULL;
  
}

/*!*****************************************************************************
 *******************************************************************************
\note  checkForMessages
\date  Feb 2019
   
\remarks 

      Messages can be given to the servo for hard-coded tasks.This allows
      some information passing between the different processes on variables
      of common interest, e.g., the endeffector specs, object information,
      etc.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

   none

 ******************************************************************************/
static int
checkForMessages(void)
{
  int i,j,k;
  char name[20];

  // check whether a message is available
  if (semTake(sm_simulation_message_ready_sem,NO_WAIT) == ERROR) {
    return FALSE;
  }

  // receive the message
  if (semTake(sm_simulation_message_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    printf("Couldn't take simulation message semaphore\n");
    return FALSE;
  }


  for (k=1; k<=sm_simulation_message->n_msgs; ++k) {

    // get the name of this message
    strcpy(name,sm_simulation_message->name[k]);

    // act according to the message name

    // -------------------------------------------------------------------------
    if (strcmp(name,"graspGripper") == 0) { // trigger a grasp movement
      float  buf[5+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(5));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];
      force   = buf[++j];
      eps_in  = buf[++j];
      eps_out = buf[++j];

      gripper_task = GRASP;

      
    // -------------------------------------------------------------------------
    } else if (strcmp(name,"moveGripper") == 0) { // trigger a gripper movement
      float  buf[2+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(2));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];

      gripper_task = MOVE;

      
      // ---------------------------------------------------------------------------
    } else if (strcmp(name,"changeEndeffector") == 0) {
      float buf[n_endeffs*10+1];
      int count = 0;
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(10*n_endeffs));
      
      for (i=1; i<=n_endeffs; ++i) {
	endeff[i].m = buf[++count];
	for (j=1; j<=N_CART; ++j)
	  endeff[i].mcm[j] = buf[++count];
	for (j=1; j<=N_CART; ++j)
	  endeff[i].x[j] = buf[++count];
	for (j=1; j<=N_CART; ++j)
	  endeff[i].a[j] = buf[++count];
      }

      // ---------------------------------------------------------------------------
    } else if (strcmp(name,"calibrateFT") == 0) { 

      sendCommandLineCmd("calibrate_cFT");
      
    // ---------------------------------------------------------------------------
    } else if (strcmp(name,"status") == 0) { 
      
      status();
      
    }
    // ---------------------------------------------------------------------------
    
    
  }

  // give back semaphore
  sm_simulation_message->n_msgs = 0;
  sm_simulation_message->n_bytes_used = 0;
  semGive(sm_simulation_message_sem);


  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  printDyn
\date  Jan 2019
   
\remarks 

 prints the current dynamics parameters, i.e., inertia matrix, coriolis vector,
 gravity vector

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static void
printDyn(void)
{
  int    i,j;

  printf("RBD Inertia Matrix:\n");
  for (i=1; i<=N_DOFS; ++i) {
    for (j=1; j<=N_DOFS; ++j) {
      printf("%7.4f ",mass[(j-1)*N_DOFS+i-1]);
    }
    printf("\n");
  }
  printf("\n");

  printf("RBD Coriolis Vector:\n");
  for (i=1; i<=N_DOFS; ++i) {
    printf("%7.4f ",coriolis[i-1]);
  }
  printf("\n");

  printf("RBD Gravity Vector:\n");
  for (i=1; i<=N_DOFS; ++i) {
    printf("%7.4f ",u_gravity[i-1]);
  }
  printf("\n");
  printf("\n");

}
