/*!=============================================================================
  ==============================================================================

  \file    SL_user_simulation.c

  \author  Stefan Schaal
  \date    Nov. 2007

  ==============================================================================
  \remarks
  
  This program contains all user functions for the numerical simluation of
  a robot
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

/* user specific headers */
#include "SL.h"
#include "SL_integrate.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_objects.h"
#include "SL_simulation_servo.h"
#include "utility.h"
#include "utility_macros.h"
#include "mdefs.h"
#include "SL_dynamics.h"
#include "SL_shared_memory.h"

/* global variables */

/* local variables */
  
/* local functions */

/* external functions */


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_simulation
 \date  July 1998
 
 \remarks 
 
 initializes everything needed for the numerical simulation.
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none 

 ******************************************************************************/
int
init_user_simulation(void)

{
  
  int i,j,n;

  // initalize objects in the environment
  readObjects(config_files[OBJECTS]);

  // assign contact force mappings
#include "LEKin_contact.h"

  // change numerical integration
  n_integration = 10;
  integrate_method = INTEGRATE_EULER;

  // change the freeze_base_pos[] array if needed
  freeze_base_pos[_X_] = 1.0;  

  // zero the state of the robot
  reset();
  

  return TRUE;
}


/*!*****************************************************************************
 *******************************************************************************
\note  run_user_simulation
\date  Nov. 7, 2007
   
\remarks 

      computes additional simulation values, e.g., misc sensors

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output


 ******************************************************************************/
int
run_user_simulation(void)

{
  int           i,j,k;
  double        force_local[N_CART+1];
  double        torque_local[N_CART+1];
  double        force_world[N_CART+1];
  double        torque_world[N_CART+1];
  double        torque_correction[N_CART+1];
  double        offset[N_CART+1];
  int           j7_link_indices[] = {0,A1_J7_LINK,A2_J7_LINK,A3_J7_LINK,A4_J7_LINK};
  int           j7_indices[] = {0,A1_J7,A2_J7,A3_J7,A4_J7};  
  int           s_f_indices[] = {0,A1_S_FX,A2_S_FX,A3_S_FX,A4_S_FX};
  int           s_m_indices[] = {0,A1_S_MX,A2_S_MX,A3_S_MX,A4_S_MX};
  int           c_f_indices[] = {0,A1_C_FX,A2_C_FX,A3_C_FX,A4_C_FX};
  int           c_m_indices[] = {0,A1_C_MX,A2_C_MX,A3_C_MX,A4_C_MX};
  int           flange_indices[] = {0,A1_FLANGE,A2_FLANGE,A3_FLANGE,A4_FLANGE};

  // loop over all endeffectors
  for (k=1; k<=N_ENDEFFS; ++k) {
  
    // simulate the computed F/T sensor of external forces. We can use the
    // ucontact[J7] wrench info for this, which is in world coordinates.
    // Transform into J7_LINK, which identical to J7 joint coordinates
  
    for (i=1; i<=N_CART; ++i) {
      force_local[i] = torque_local[i] = 0;
      for (j=1; j<=N_CART; ++j) {
	force_local[i]  += Alink_sim[j7_link_indices[k]][j][i] * ucontact[j7_indices[k]].f[j];
	torque_local[i] += Alink_sim[j7_link_indices[k]][j][i] * ucontact[j7_indices[k]].t[j];
      }
    }

    // this force/torque is slighly wrong: it needs to be at the loadcell coordinate
    // system, and needs to take into account moments from translating from
    // J7 to the load cell coordinate. Thus, the moments need to be corrected.
    
    vec_zero_size(offset,N_CART);
    offset[_Z_] = FL+FT_OFF_Z;
    vec_mult_outer_size(offset, force_local, N_CART, torque_correction);
    
    for (i=1; i<=N_CART; ++i) {
      torque_local[i] -= torque_correction[i];
    }
    
    // the computed torque is reported in load cell coordinates.
    // Thus, we need to transform back into the world coordinate system ...
    
    for (i=1; i<=N_CART; ++i) {
      force_world[i] = torque_world[i] = 0;
      for (j=1; j<=N_CART; ++j) {
	force_world[i]  += Alink_sim[j7_link_indices[k]][i][j] * force_local[j];
	torque_world[i] += Alink_sim[j7_link_indices[k]][i][j] * torque_local[j];
      }
    }
    
    // ... and now to endeffector coordinates, which has the same orientation
    // as the load cell
    for (i=1; i<=N_CART; ++i) {
      force_local[i] = torque_local[i] = 0;
      for (j=1; j<=N_CART; ++j) {
	force_local[i]  += Alink_sim[flange_indices[k]][j][i] * force_world[j];
	torque_local[i] += Alink_sim[flange_indices[k]][j][i] * torque_world[j];
      }
    }
    
    for (i=1; i<=N_CART; ++i) {
      misc_sim_sensor[c_f_indices[k]-1+i] = force_local[i];
      misc_sim_sensor[c_m_indices[k]-1+i] = torque_local[i];
      misc_sim_sensor[s_f_indices[k]-1+i] = force_local[i];
      misc_sim_sensor[s_m_indices[k]-1+i] = torque_local[i];
    }

  }
  
  
  
  return TRUE;
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
  double width,speed,force,eps_in,eps_out; //grasp parameters

  if (strcmp(name,"graspGripperA1") == 0) { // trigger a grasp movement
    float  buf[5+1];
    
    memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	   sizeof(float)*(5));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];
      force   = buf[++j];
      eps_in  = buf[++j];
      eps_out = buf[++j];

      misc_sim_sensor[A1_G_WIDTH] = width;
      
    // -------------------------------------------------------------------------
    } else if (strcmp(name,"moveGripperA1") == 0) { // trigger a gripper movement
      float  buf[2+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(2));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];

      misc_sim_sensor[A1_G_WIDTH] = width;

    // -------------------------------------------------------------------------      
    } else if (strcmp(name,"graspGripperA2") == 0) { // trigger a grasp movement
    float  buf[5+1];
    
    memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	   sizeof(float)*(5));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];
      force   = buf[++j];
      eps_in  = buf[++j];
      eps_out = buf[++j];

      misc_sim_sensor[A2_G_WIDTH] = width;
      
    // -------------------------------------------------------------------------
    } else if (strcmp(name,"moveGripperA2") == 0) { // trigger a gripper movement
      float  buf[2+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(2));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];

      misc_sim_sensor[A2_G_WIDTH] = width;

    // -------------------------------------------------------------------------      
    } else if (strcmp(name,"graspGripperA3") == 0) { // trigger a grasp movement
    float  buf[5+1];
    
    memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	   sizeof(float)*(5));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];
      force   = buf[++j];
      eps_in  = buf[++j];
      eps_out = buf[++j];

      misc_sim_sensor[A3_G_WIDTH] = width;
      
    // -------------------------------------------------------------------------
    } else if (strcmp(name,"moveGripperA3") == 0) { // trigger a gripper movement
      float  buf[2+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(2));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];

      misc_sim_sensor[A3_G_WIDTH] = width;

    // -------------------------------------------------------------------------      
    } else if (strcmp(name,"graspGripperA4") == 0) { // trigger a grasp movement
    float  buf[5+1];
    
    memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	   sizeof(float)*(5));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];
      force   = buf[++j];
      eps_in  = buf[++j];
      eps_out = buf[++j];

      misc_sim_sensor[A4_G_WIDTH] = width;
      
    // -------------------------------------------------------------------------
    } else if (strcmp(name,"moveGripperA4") == 0) { // trigger a gripper movement
      float  buf[2+1];
      
      memcpy(&(buf[1]),sm_simulation_message->buf+sm_simulation_message->moff[k],
	     sizeof(float)*(2));
      j = 0;
      width   = buf[++j];
      speed   = buf[++j];

      misc_sim_sensor[A4_G_WIDTH] = width;

    }
    // ---------------------------------------------------------------------------

}
