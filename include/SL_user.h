/*!=============================================================================
  ==============================================================================

  \file    SL_user.h

  \author  Stefan Schaal
  \date    Dec. 2018

  ==============================================================================
  \remarks
  
  robot specific definitions for the Franka Panda arm
  
  ============================================================================*/
  
#ifndef _SL_user_
#define _SL_user_

//! the robot name
#define ROBOT_NAME "panda"

// dimensions of the robot
#define DHD1  0.333
#define DHD2  0.0
#define DHD3  0.316
#define DHD4  0.0
#define DHD5  0.384
#define DHD6  0.0
#define DHD7  0.0

#define DHA1  0.0
#define DHA2  0.0
#define DHA3  0.0
#define DHA4  0.0825
#define DHA5 -0.0825
#define DHA6  0.0
#define DHA7  0.088

#define FL    0.107

#define FINGER_OFF 0.0584
#define FINGER_LENGTH 0.045

// links of the robot
enum RobotLinks {
  J2_LINK = 1,
  J3_LINK,
  J4_LINK,
  J5_LINK,
  J7_LINK,
  FLANGE,
  
  N_ROBOT_LINKS
};

// endeffector information
enum RobotEndeffectors {
  HAND=1,

  N_ROBOT_ENDEFFECTORS
};

// vision variables
enum VisionCameras {
  CAMERA_1=1,
  CAMERA_2,

  N_VISION_CAMERAS
};

enum ColorBlobs {
  BLOB1=1,
  BLOB2,
  BLOB3,
  BLOB4,
  BLOB5,
  BLOB6,

  N_COLOR_BLOBS
};

// define the DOFs of this robot
enum RobotDOFs {
  BASE=0,
  
  J1,
  J2,
  J3,
  J4,
  J5,
  J6,
  J7,

  N_ROBOT_DOFS
};

//! define miscellenous sensors of this robot
enum RobotMiscSensors {
  // the computed load cell location is a the endeffector end, in local coordinates
  C_FX = 1,       //!< computed load cell force in x
  C_FY,           //!< computed load cell force in y
  C_FZ,           //!< computed load cell force in z
  C_MX,           //!< computed load cell moment in x
  C_MY,           //!< computed load cell moment in y
  C_MZ,           //!< computed load cell moment in z

  G_WIDTH,        //!< gripper width
  
  N_ROBOT_MISC_SENSORS
};

//! number of degrees-of-freedom of robot
#define N_DOFS (N_ROBOT_DOFS-1)

//! N_DOFS + fake DOFS, needed for parameter estimation; 
//   fake DOFS come from creating endeffector information
#define N_DOFS_EST (N_DOFS+1)

//! N_DOFS to be excluded from parameter estimation (e.g., eye joints);
//  these DOFS must be the last DOFS in the arrays
#define N_DOFS_EST_SKIP 0

//! number of links of the robot
#define N_LINKS    (N_ROBOT_LINKS-1)

//! number of miscellaneous sensors
#define N_MISC_SENSORS   (N_ROBOT_MISC_SENSORS-1)

//! number of endeffectors
#define N_ENDEFFS  (N_ROBOT_ENDEFFECTORS-1)

//! number of cameras used
#define N_CAMERAS (N_VISION_CAMERAS-1)

//! number of blobs that can be tracked by vision system
#define MAX_BLOBS (N_COLOR_BLOBS-1)

//! vision default post processing
#define VISION_DEFAULT_PP "vision_default.pp"

//! the servo rate used by the I/O with robot: this limits the
//  servo rates of all other servos 
#define  SERVO_BASE_RATE 1000

//! divisor to obtain task servo rate (task servo can run slower than
//  base rate, but only in integer fractions */
#define  TASK_SERVO_RATIO   R1TO2

// settings for D/A debugging information -- see SL_oscilloscope.c 
#define   D2A_CM      1
#define   D2A_CT      2
#define   D2A_CV      3
#define   D2A_CR      4


#ifdef __cplusplus
extern "C" {
#endif

  // function prototype
  void sendGripperGraspCommand(double width, double speed, double force,
			       double eps_in, double eps_out) ;
  void sendGripperMoveCommand(double width, double speed);

  // external variables

#ifdef __cplusplus
}
#endif


#endif  /* _SL_user_ */
