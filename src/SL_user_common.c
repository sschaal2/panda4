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
  {"BASE"},
  
  {"A1_J1"},
  {"A1_J2"},
  {"A1_J3"},
  {"A1_J4"},
  {"A1_J5"},
  {"A1_J6"},
  {"A1_J7"},
  
  {"A2_J1"},
  {"A2_J2"},
  {"A2_J3"},
  {"A2_J4"},
  {"A2_J5"},
  {"A2_J6"},
  {"A2_J7"},
  
  {"A3_J1"},
  {"A3_J2"},
  {"A3_J3"},
  {"A3_J4"},
  {"A3_J5"},
  {"A3_J6"},
  {"A3_J7"},
  
  {"A4_J1"},
  {"A4_J2"},
  {"A4_J3"},
  {"A4_J4"},
  {"A4_J5"},
  {"A4_J6"},
  {"A4_J7"}
  
};

char cart_names[][20]= {
  {"dummy"},
  {"A1_HAND"},
  {"A2_HAND"},
  {"A3_HAND"},
  {"A4_HAND"}  
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
  
  {"A1_J1_LINK"},
  {"A1_J3_LINK"},
  {"A1_J4_LINK"},
  {"A1_J5_LINK"},
  {"A1_J7_LINK"},
  {"A1_FLANGE"},

  {"A2_J1_LINK"},
  {"A2_J3_LINK"},
  {"A2_J4_LINK"},
  {"A2_J5_LINK"},
  {"A2_J7_LINK"},
  {"A2_FLANGE"},

  {"A3_J1_LINK"},
  {"A3_J3_LINK"},
  {"A3_J4_LINK"},
  {"A3_J5_LINK"},
  {"A3_J7_LINK"},
  {"A3_FLANGE"},

  {"A4_J1_LINK"},
  {"A4_J3_LINK"},
  {"A4_J4_LINK"},
  {"A4_J5_LINK"},
  {"A4_J7_LINK"},
  {"A4_FLANGE"},
};

char misc_sensor_names[][20] = {
  {"dummy"},
  
  {"A1_C_FX"}, 
  {"A1_C_FY"}, 
  {"A1_C_FZ"}, 
  {"A1_C_MX"}, 
  {"A1_C_MY"}, 
  {"A1_C_MZ"},
  {"A1_S_FX"}, 
  {"A1_S_FY"}, 
  {"A1_S_FZ"}, 
  {"A1_S_MX"}, 
  {"A1_S_MY"}, 
  {"A1_S_MZ"},
  {"A1_G_WIDTH"},
  {"A1_G_MOTION"}, 

  {"A2_C_FX"}, 
  {"A2_C_FY"}, 
  {"A2_C_FZ"}, 
  {"A2_C_MX"}, 
  {"A2_C_MY"}, 
  {"A2_C_MZ"},
  {"A2_S_FX"}, 
  {"A2_S_FY"}, 
  {"A2_S_FZ"}, 
  {"A2_S_MX"}, 
  {"A2_S_MY"}, 
  {"A2_S_MZ"},
  {"A2_G_WIDTH"},
  {"A2_G_MOTION"}, 

  {"A3_C_FX"}, 
  {"A3_C_FY"}, 
  {"A3_C_FZ"}, 
  {"A3_C_MX"}, 
  {"A3_C_MY"}, 
  {"A3_C_MZ"},
  {"A3_S_FX"}, 
  {"A3_S_FY"}, 
  {"A3_S_FZ"}, 
  {"A3_S_MX"}, 
  {"A3_S_MY"}, 
  {"A3_S_MZ"},
  {"A3_G_WIDTH"},
  {"A3_G_MOTION"}, 

  {"A4_C_FX"}, 
  {"A4_C_FY"}, 
  {"A4_C_FZ"}, 
  {"A4_C_MX"}, 
  {"A4_C_MY"}, 
  {"A4_C_MZ"},
  {"A4_S_FX"}, 
  {"A4_S_FY"}, 
  {"A4_S_FZ"}, 
  {"A4_S_MX"}, 
  {"A4_S_MY"}, 
  {"A4_S_MZ"},
  {"A4_G_WIDTH"},
  {"A4_G_MOTION"}, 
  
};

// the 1st to 2nd finger segment angles


// initialization needs to be done for this mapping
int  link2endeffmap[] = {0,A1_FLANGE,A2_FLANGE,A3_FLANGE,A4_FLANGE};


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
#ifdef ROBOTIQ2F
    endeff[i].x[_Z_]  = FL+0.235; // this is the Axia80+Robotiq2f total length
#else
    endeff[i].x[_Z_]  = FL+FINGER_OFF+FINGER_LENGTH;
#endif
    endeff[i].a[_A_]  = 0.0;
    endeff[i].a[_B_]  = 0.0;
    endeff[i].a[_G_]  = FL_G;
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
