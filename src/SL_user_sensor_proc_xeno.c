/*!=============================================================================
  ==============================================================================

  \file    SL_user_sensor_proc_xeno.c

  \author  Stefan Schaal
  \date    Oct 2010

  ==============================================================================
  \remarks

  performs reading of sensors, translation to units, and sending out
  motor commands. This verion of the functions is for the actual robot

  ============================================================================*/


#include "canControl.h"

#include <string.h>

// SL general includes of system headers
#include "SL_system_headers.h"

// private includes
#include "utility.h"
#include "utility_macros.h"
#include "SL.h"
#include "SL_common.h"
#include "SL_user.h"
#include "SL_sensor_proc.h"
#include "SL_shared_memory.h"
#include "SL_motor_servo.h"
#include "SL_collect_data.h"
#include "SL_unix_common.h"
#include "SL_kinematics.h"

#define TIME_OUT_NS  1000000000

// local variables

static int arm_enabled;
static int hand_enabled;

static double strain_gages_calibration[3+1][2+1]; //transforms raw values into physical values

static SL_Jstate raw_joint_state[N_DOFS+1];
static double raw_misc_sensors[N_MISC_SENSORS+1];

static RT_SEM sem_arm_device;
static const char sem_arm_device_name[] = "sem_arm_device";

// external variables
extern int           motor_servo_errors;

// global functions

// local functions
static int receive_sim_state(void);
static int receive_misc_sensors(void);
static int send_des_command(void);

void init_thread_loop(void *cookie);

int init_user_sensor_processing_wam();

int read_user_sensors_wam(SL_Jstate *raw,double *misc_raw);

int send_user_commands_wam(SL_Jstate *command);

/*!*****************************************************************************
 *******************************************************************************
\note  init_user_sensor_processing
\date  Nov. 2007

\remarks 

          Initializes all user specific sensory processing

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
int
init_user_sensor_processing(void)
{
	int res;
	char string[256];
	int i;


	// first check if head or arm are disabled:
	arm_enabled = TRUE;
	hand_enabled = TRUE;

	for (i=1; i<global_argc; ++i)
		if (strcmp(global_argv[i],"-no-arm")==0 || strcmp(global_argv[i],"-na")==0)
		{
			arm_enabled = FALSE;
			printf("Disabling arm control...\n");
		}
	for (i=1; i<global_argc; ++i)
		if (strcmp(global_argv[i],"-no-hand")==0)
		{
			hand_enabled = FALSE;
			printf("Disabling hand control...\n");
		}

	if (arm_enabled)
	{
		//check if someone is already accessing the device
		if( (res =rt_sem_bind(&sem_arm_device, sem_arm_device_name, TM_NONBLOCK)) == 0 )
		{
			if(rt_sem_p(&sem_arm_device, TM_NONBLOCK))
			{
				printf("cannot take semaphore %s, device is busy.\n", sem_arm_device_name);
				return FALSE;
			}
			printf("semaphore %s exist and was taken\n", sem_arm_device_name);
		}
		else if(res == -EWOULDBLOCK) //the semaphore is not in registry -> hardware is free
		{
			//create the semaphore and empty it
			if(rt_sem_create(&sem_arm_device, sem_arm_device_name, 1, S_FIFO))
			{
				printf("cannot create semaphore %s\n", sem_arm_device_name);
				return FALSE;
			}
			if(rt_sem_p(&sem_arm_device, TM_NONBLOCK))
			{
				printf("cannot take just created semaphore %s\n", sem_arm_device_name);
				return FALSE;
			}
		}
		else //something weird happened -> quit
		{
			printf("cannot bind to semaphore %s, error is %d.\n", sem_arm_device_name, res);
			return FALSE;
		}

	}


	if(arm_enabled)
	{
		if (init_user_sensor_processing_wam() == FALSE)
		{
			printf("Cannot init WAM\n");
			return FALSE;
		}
	}

	// just to be sure
	for (i=1; i<=N_DOFS; ++i) {
		raw_joint_state[i].th   = 0.0;//joint_sim_state[i].th;
		raw_joint_state[i].thd  = 0.0;//joint_sim_state[i].thd;
		raw_joint_state[i].thdd = 0.0;//joint_sim_state[i].thdd;
		raw_joint_state[i].load = 0.0;//joint_sim_state[i].u;
	}

	for (i=1; i<=N_MISC_SENSORS; ++i)
	{
		raw_misc_sensors[i] = 0.0;
	}

	//data collection
	for(i=1; i<=N_DOFS; ++i) {
		sprintf(string,"%s_raw_th",joint_names[i]);
		addVarToCollect((char *)&(raw_joint_state[i].th),string,"rad", DOUBLE,FALSE);
		sprintf(string,"%s_raw_thd",joint_names[i]);
		addVarToCollect((char *)&(raw_joint_state[i].thd),string,"rad/s", DOUBLE,FALSE);
		sprintf(string,"%s_raw_u",joint_names[i]);
		addVarToCollect((char *)&(raw_joint_state[i].u),string,"Nm", DOUBLE,FALSE);
		sprintf(string,"%s_raw_load",joint_names[i]);
		addVarToCollect((char *)&(raw_joint_state[i].load),string,"Nm", DOUBLE,FALSE);
	}

	for(i =1; i<=N_MISC_SENSORS; i++)
	{
		sprintf(string,"%s_raw",misc_sensor_names[i]);
		addVarToCollect((char *)&(raw_misc_sensors[i]),string,"rad", DOUBLE,FALSE);
	}

	updateDataCollectScript();

	return TRUE;
}



/*!*****************************************************************************
 *******************************************************************************
\note  read_user_sensors
\date  Dec 1997

\remarks 

    gets sensor readings from the robot and converts them into standard
    units

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    raw :     the raw sensor readings
 \param[out]    misc_raw: the raw miscelleneous sensor readings

 ******************************************************************************/
int
read_user_sensors(SL_Jstate *raw,double *misc_raw)
{
	int i,j;
	static int firstTime = TRUE;

	SL_Jstate prevState[N_DOFS+1];

	memcpy(prevState, raw_joint_state, sizeof(SL_Jstate) * (N_DOFS+1));

	//get feedback from the WAM
	if (arm_enabled)
		read_user_sensors_wam(raw_joint_state, raw_misc_sensors);
	else
	{
		// write zero values:
		for (i=R_SFE; i<=R_LF; ++i)
		{
			raw_joint_state[i].th   = joint_default_state[i].th + joint_range[i][THETA_OFFSET];
			raw_joint_state[i].thd  = 0.0;
			raw_joint_state[i].thdd = 0.0;
			raw_joint_state[i].load = 0.0;
		}
	}

	//offset correction
	for(i=1; i<=N_DOFS; i++)
	{
		raw_joint_state[i].th -= joint_range[i][THETA_OFFSET];
	}

	//compute velocities
	for(i = 1; i<=N_DOFS; i++)
	{
		if(firstTime)
		{
			raw_joint_state[i].thd = 0.0;
			raw_joint_state[i].thdd = 0.0;
			// firstTime = FALSE; <- this is set later
		}
		else
		{
			raw_joint_state[i].thd = (raw_joint_state[i].th - prevState[i].th) * (double)motor_servo_rate;
			raw_joint_state[i].thdd = (raw_joint_state[i].thd - prevState[i].thd) * (double)motor_servo_rate;
		}
	}

	//we copy to the output functions
	memcpy(raw, raw_joint_state, sizeof(SL_Jstate) * (N_DOFS+1));
	memcpy(misc_raw, raw_misc_sensors, sizeof(double) * (N_MISC_SENSORS+1));

	//update the openGL
	//joint state TODO do we send filtered data?
	if (semTake(sm_joint_sim_state_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
		++motor_servo_errors;
	}

	cSL_Jstate(raw, sm_joint_sim_state_data, N_DOFS, DOUBLE2FLOAT);

	for (i=1; i<=N_DOFS; ++i)
	{
		sm_joint_sim_state->joint_sim_state[i] = sm_joint_sim_state_data[i];
	}

	semGive(sm_joint_sim_state_sem);

	//misc_sensors
	if(semTake(sm_misc_sim_sensor_sem, ns2ticks(TIME_OUT_NS)) == ERROR)
	{
		++motor_servo_errors;
	}

	for(i=1; i<=N_MISC_SENSORS; i++)
	{
		sm_misc_sim_sensor_data[i] = (float)misc_raw[i];
		sm_misc_sim_sensor->value[i] = sm_misc_sim_sensor_data[i];
	}

	semGive(sm_misc_sim_sensor_sem);


	//we need to set the base state and orient
	if(firstTime) //(which are constant so far so we do it only once)
	{
		init_joint_state_filters(raw);
		init_misc_sensor_filters(misc_raw);

		// base state
		if (semTake(sm_base_state_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {

			++motor_servo_errors;
			return FALSE;

		}

		cSL_Cstate((&base_state)-1, sm_base_state_data, 1, DOUBLE2FLOAT);

		sm_base_state->state[1] = sm_base_state_data[1];

		semGive(sm_base_state_sem);


		base_orient.q[_Q0_] = 1;
		// base orient
		if (semTake(sm_base_orient_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {

			++motor_servo_errors;
			return FALSE;

		}

		cSL_quat(&(base_orient)-1, sm_base_orient_data, 1, DOUBLE2FLOAT);

		sm_base_orient->orient[1] = sm_base_orient_data[1];

		semGive(sm_base_orient_sem);
		firstTime = FALSE;
	}

	return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  send_user_commands
\date  April 1999

\remarks 

    translates the commands into raw and sends them to the robot

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     commands : the structure containing the commands

 ******************************************************************************/
int
send_user_commands(SL_Jstate *command)

{
	if (arm_enabled)
		send_user_commands_wam(command);

	return TRUE;
}


/*!*****************************************************************************
 *******************************************************************************
\note  user_controller
\date  Feb. 2009

\remarks 

          allows the user to modify the commands currently computed by 
          the active controller. Note that only u is actually used in
          the final send out of the commands to the robot, and ufb is only
          to kept as feedback to the user for data collection.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in,out] u     : the current total command
 \param[in,out] ufb   : the current feedback command

 ******************************************************************************/
void
user_controller(double *u, double *uf)
{
	int i,j;
}

/*!*****************************************************************************
 *******************************************************************************
\note  userCheckForMessage
\date  Feb. 2009

\remarks 

          this function allows the user to intercept a message send to the
          motor servo and use this information in sensor_user_proc

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     name : message identifying name
 \param[in]     k    : index of message in shared memory

 ******************************************************************************/
void
userCheckForMessage(char *name, int k)
{
	int i,j;

	//don't take any semaphore as the checkForMessages already did it

	//check if message wants to change the SG offset
	if(strcmp(name, "changeSGOffsets") == 0)
	{
	  memcpy(strain_gages_calibration, sm_motor_message->buf+sm_motor_message->moff[k], sizeof(double)*(3+1)*(2+1));
	}

}

////////////////////////////////////////////////////////
////////////// WAM STUFF ///////////////////////////////
////////////////////////////////////////////////////////
static int going = TRUE;
RT_MUTEX going_mutex;
RT_TASK initTask;


int init_user_sensor_processing_wam(void)
{
	int err;
	int i;
	char str[256];

	//first read the calibration file for the extra sensors (ONLY strain gages so far)
	for(i=1; i<=3; i++)
	{
		if(!read_parameter_pool_double_array("ExtraSensorCalibration.cf", joint_names[R_RF -1 + i], 2, strain_gages_calibration[i]))
		{
			printf("cannot read Extra SensorCalibration file - joint %s is missing\n", joint_names[R_RF -1 + i]);
			return FALSE;
		}
	}

	get_string("\nPlease switch the WAM in SHIFT-IDLE mode and then press", "Enter", str);


	//the WAM robot
	if( (err = initWam()))
	{
		printf("ERROR >> Wam init returned the code %d", err);
		return FALSE;
	}

	//hand
	if(hand_enabled)
	{
		if ((err = initHand()))
		{
			printf("ERROR >> hand init returned the code %d", err);
			bt_wambot_phys_destroy(wambot);
			return FALSE;
		}
	}


	//safety
	setSafetyLimits(0x7000, 0x7800, 7000, 8191);


	//start the realtime loop
	rt_mutex_create (&going_mutex, NULL);
	rt_task_create(&initTask, "Wait for Active Switch Task", 0, 99, T_JOINABLE | T_FPU);
	rt_task_start(&initTask, &init_thread_loop, NULL);

	get_string("Switch the WAM in Activate MODE and press ", "Enter", str);


	return TRUE;
}

//to be Barrett compliant we send 0 torques before setting the robot in Active mode
void init_thread_loop(void *cookie)
{
	int i;

	//init the 0 torques
	gsl_vector_set_zero(wambot->base.jtorque);

	//sleep we clean the periodic stuff
	rt_task_set_periodic(NULL, TM_NOW, (RTIME)(1e9/(double)motor_servo_rate));


	//hand position and strain gages
	requestFeedback(0, 0, 0, 0);

	int local_going;

	rt_mutex_acquire(&going_mutex,TM_INFINITE);
	local_going = going;
	rt_mutex_release(&going_mutex);

	while(local_going)
	{
		//sleep
		rt_task_wait_period(NULL);

		//get the wam positions
		wambot->base.update(&wambot->base);
		updateFeedback(NULL);


		for(i=0; i<7; i++)
		{
			wamState.wamPosition[i] = gsl_vector_get(wambot->base.jposition, i);
			joint_state[R_SFE+i].th = gsl_vector_get(wambot->base.jposition, i);
		}

		//wam command
		wambot->base.setjtor(&wambot->base);

		requestFeedback(0, 0, 0, 0);

		rt_mutex_acquire(&going_mutex,TM_INFINITE);
		local_going = going;
		rt_mutex_release(&going_mutex);

	}

}


int read_user_sensors_wam(SL_Jstate *raw,double *misc_raw)
{
	int i,j;
	static int firstTime = TRUE;


	if(firstTime)
	{
		rt_mutex_acquire(&going_mutex,TM_INFINITE);
		going = FALSE;
		rt_mutex_release(&going_mutex);
		rt_task_join(&initTask);
		rt_mutex_delete(&going_mutex);
		firstTime = FALSE;
	}

	//get the wam positions
	wambot->base.update(&wambot->base);
	for(i=0; i<7; i++)
	{
		wamState.wamPosition[i] = gsl_vector_get(wambot->base.jposition, i) * pos_polar[R_SFE+i];
		raw[R_SFE+i].th = wamState.wamPosition[i];

		//load is the previous torque command in the case of the WAM
		raw[R_SFE+i].load = raw_joint_state[R_SFE+i].u;
	}

	//get the answers from the other elements
	updateFeedback(NULL);

	raw[R_LF].th = (double)wamState.handPosition[0] * FINGER_TICKS_TO_RAD;
	raw[R_RF].th = (double)wamState.handPosition[1] * FINGER_TICKS_TO_RAD;
	raw[R_MF].th = (double)wamState.handPosition[2] * FINGER_TICKS_TO_RAD;
	raw[R_FR].th = (double)wamState.handPosition[3] * SPREAD_TICKS_TO_RAD;

	//load equals previous torque command
	raw[R_LF].load = raw_joint_state[R_LF].u;
	raw[R_RF].load = raw_joint_state[R_RF].u;
	raw[R_MF].load = raw_joint_state[R_MF].u;
	raw[R_FR].load = raw_joint_state[R_FR].u;

	//misc sensors
	misc_raw[R_LF_2ND] = (double)wamState.handPosition2[0] * FINGER2_TICKS_TO_RAD - FINGER2_POS_OFFSET;   //!< right hand angle of 2nd finger segment relative to 1st segment: RF
	misc_raw[R_RF_2ND] = (double)wamState.handPosition2[1] * FINGER2_TICKS_TO_RAD - FINGER2_POS_OFFSET;   //!< right hand angle of 2nd finger segment relative to 1st segment: MF
	misc_raw[R_MF_2ND] = (double)wamState.handPosition2[2] * FINGER2_TICKS_TO_RAD - FINGER2_POS_OFFSET;   //!< right hand angle of 2nd finger segment relative to 1st segment: LF

	misc_raw[R_LF_SG] = ((double)(wamState.handSG[0]) - strain_gages_calibration[R_LF - R_RF + 1][1]) * strain_gages_calibration[R_LF - R_RF + 1][2];
	misc_raw[R_RF_SG] = ((double)(wamState.handSG[1])  - strain_gages_calibration[R_RF - R_RF + 1][1]) * strain_gages_calibration[R_RF - R_RF + 1][2];
	misc_raw[R_MF_SG] = ((double)(wamState.handSG[2])  - strain_gages_calibration[R_MF - R_RF + 1][1]) * strain_gages_calibration[R_MF - R_RF + 1][2];

	return TRUE;
}

int send_user_commands_wam(SL_Jstate *command)

{
	int i,j;

        static int count_until_initialization_done = 0;

	//wam command (takes 200us)
	for(i = 0; i<7; i++)
	{
		gsl_vector_set(wambot->base.jtorque, i, command[R_SFE+i].u * pos_polar[R_SFE + i]);
	}


	wambot->base.setjtor(&wambot->base);


	//hand command
	int handRawTorques[4];
	double handTorques[4];

	handTorques[0] = command[R_LF].u;
	handTorques[1] = command[R_RF].u;
	handTorques[2] = command[R_MF].u;
	handTorques[3] = command[R_FR].u;

	if( (hand_enabled) && (count_until_initialization_done >= motor_servo_rate*4) )
	{
	  sendHandTorques(handTorques, handRawTorques, 1/(double)motor_servo_rate);
	}

	//update raw_joint_state
	for(i = 0; i<7; i++)
	{
		raw_joint_state[R_SFE + i].u = gsl_vector_get(wambot->base.jtorque, i);
	}

	raw_joint_state[R_LF].u = (double)handRawTorques[0];
	raw_joint_state[R_RF].u = (double)handRawTorques[1];
	raw_joint_state[R_MF].u = (double)handRawTorques[2];
	raw_joint_state[R_FR].u = (double)handRawTorques[3];

	//we have what we want
	if(hand_enabled)
	{
	  if(count_until_initialization_done == 0)//initialize the finger pucks
	  {
	    initializePuck(FINGER1_PUCK_NB);
	    initializePuck(FINGER2_PUCK_NB);
	    initializePuck(FINGER3_PUCK_NB);
	    requestFeedback(0,0,0,0);
	    count_until_initialization_done++;
	  }
	  else if(count_until_initialization_done == motor_servo_rate * 2)//initialize the spread
	  {
	    initializePuck(SPREAD_PUCK_NB);
	    requestFeedback(0,0,0,0);
	    count_until_initialization_done++;
	  }
	  else if(count_until_initialization_done == motor_servo_rate * 4)//done with init go into torque mode
	  {
	    bt_bus_set_property(bus, BT_BUS_CAN_GROUPID(HAND_GRP), bus->p->TSTOP, 0);
	    for(i = FINGER1_PUCK_NB; i<=SPREAD_PUCK_NB; i++)
	    {
	      bt_bus_can_set_property(bus->dev, i, bus->p->T, 0);
	      bt_bus_can_set_property(bus->dev, i, bus->p->MODE, MODE_TORQUE);
	    }
	    requestFeedback(0,0,0,0);
	    count_until_initialization_done++;
	  }
	  else if(count_until_initialization_done > motor_servo_rate * 4)//normal loop after init
	  {
	      requestFeedback(hand_enabled, hand_enabled, 0,0);
	  }
	  else//we are waiting during the init
	  {
	    requestFeedback(0,0,0,0);
	    count_until_initialization_done++;
	  }
	}
	else
	{
	  requestFeedback(0, 0, 0,0);
	}

	return TRUE;
}

