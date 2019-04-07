/*!=============================================================================
  ==============================================================================

  \file    SL_user_common.c

  \author 
  \date   

  ==============================================================================
  \remarks

      User file to declare common variables and functions shared by many 
      SL modules. This is a good place to declare global variables 

  ============================================================================*/

// SL general includes of system headers
#include "SL_system_headers.h"

// SL headers
#include "SL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_dynamics.h"

// global variables
char joint_names[][20]= {
  {"dummy"},
  {"J1"},
  {"J2"},
  {"J3"},
  {"J4"},
  {"J5"},
  {"J6"},
  {"J7"}
};

char cart_names[][20]= {
  {"dummy"},
  {"HAND"},
};

char blob_names[][20]= {
  {"dummy"},
  {"BLOB1"},
  {"BLOB2"},
  {"BLOB3"},
  {"BLOB4"},
  {"BLOB5"},
  {"BLOB6"}
};

char link_names[][20]= {
  {"BASE"},
  {"J2_LINK"},
  {"J3_LINK"},
  {"J4_LINK"},
  {"J5_LINK"},
  {"J7_LINK"},
  {"FLANGE"}
};

char misc_sensor_names[][20] = {
  {"dummy"},
  {"C_FX"}, 
  {"C_FY"}, 
  {"C_FZ"}, 
  {"C_MX"}, 
  {"C_MY"}, 
  {"C_MZ"},
  {"G_WIDTH"},
  {"G_MOTION"}, 

};

// the 1st to 2nd finger segment angles


// initialization needs to be done for this mapping
int  link2endeffmap[] = {0,FLANGE};


/* the following include must be the last line of the variable declaration section */
#include "SL_user_common.h"   /* do not erase!!! */


/*!*****************************************************************************
 *******************************************************************************
\note  setDefaultEndeffector
\date  May 2010
   
\remarks 

assigns default values to the endeffector parameters

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
void 
setDefaultEndeffector(void) {

  int i;

  for (i=1; i<=N_ENDEFFS; ++i) {
    endeff[i].m       = 0.0;
    endeff[i].mcm[_X_]= 0.0;
    endeff[i].mcm[_Y_]= 0.0;
    endeff[i].mcm[_Z_]= 0.0;
    endeff[i].x[_X_]  = 0.0;
    endeff[i].x[_Y_]  = 0.0;
    endeff[i].x[_Z_]  = FL+FINGER_OFF+FINGER_LENGTH; 
    endeff[i].a[_A_]  = 0.0;
    endeff[i].a[_B_]  = 0.0;
    endeff[i].a[_G_]  = 3.*PI/4.;
  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  setRealRobotOptions
\date  June 1999
   
\remarks 

        allows parameter changes if SL runs for a real robot instead
        of a simulation

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
void
setRealRobotOptions(void) 
{

  if (!real_robot_flag)
    sprintf(config_files[CONFIGFILES],"ConfigFilesSim.cf");
  else
    sprintf(config_files[CONFIGFILES],"ConfigFiles.cf");

  // update the config file names
  read_config_files(config_files[CONFIGFILES]);

  // set NE gravity to zero to mimic the way Franke is automically adding gravity comp
  set_NE_local_gravity(0.0);
  
  return;

}
