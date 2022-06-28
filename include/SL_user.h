/*!=============================================================================
  ==============================================================================

  \file    SL_user.h

  \author  Stefan Schaal
  \date    June 2022

  ==============================================================================
  \remarks
  
  robot specific definitions for 4 Franka Panda arm coordination
  
  ============================================================================*/
  
#ifndef _SL_user_
#define _SL_user_

//! the robot name
#define ROBOT_NAME "panda4"

// base position of the 4 robots in x,y
#define BASE_XOFF  0.620
#define BASE_YOFF  0.620

#define A1X  (BASE_XOFF)
#define A1Y  (-BASE_YOFF)
#define A1G  PI

#define A2X  (-BASE_XOFF)
#define A2Y  (-BASE_YOFF)
#define A2G  0

#define A3X  (-BASE_XOFF)
#define A3Y  (BASE_YOFF)
#define A3G  0

#define A4X  (BASE_XOFF)
#define A4Y  (BASE_YOFF)
#define A4G  PI

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
#define FL_G  2.356

// the comuterd F/T sensing is treated in location like a load cellt
// mounted at the flange. Offsets are relative to panda flange
#define FT_OFF_Z  0.0   // offset of F/T sensor (at flange)
//#define FT_OFF_Z  0.046   // offset of F/T sensor (Axia80+endeffector tooling)
#define FT_OFF_G  0.0     // orientation offset of F/T sensor (computed)

#define FINGER_OFF 0.0584
#define FINGER_LENGTH 0.045  //for Franka finger: end of finger
//#define FINGER_LENGTH 0.068     //for Franka-Robotiq finger: end of finger

// links of the robot
enum RobotLinks {
  A1_J1_LINK = 1,
  A1_J3_LINK,
  A1_J4_LINK,
  A1_J5_LINK,
  A1_J7_LINK,
  A1_FLANGE,

  A2_J1_LINK,
  A2_J3_LINK,
  A2_J4_LINK,
  A2_J5_LINK,
  A2_J7_LINK,
  A2_FLANGE,
  
  A3_J1_LINK,
  A3_J3_LINK,
  A3_J4_LINK,
  A3_J5_LINK,
  A3_J7_LINK,
  A3_FLANGE,
  
  A4_J1_LINK,
  A4_J3_LINK,
  A4_J4_LINK,
  A4_J5_LINK,
  A4_J7_LINK,
  A4_FLANGE,
  
  N_ROBOT_LINKS
};

// endeffector information
enum RobotEndeffectors {
  A1_HAND=1,
  A2_HAND,
  A3_HAND,
  A4_HAND,    

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
  
  A1_J1,
  A1_J2,
  A1_J3,
  A1_J4,
  A1_J5,
  A1_J6,
  A1_J7,

  A2_J1,
  A2_J2,
  A2_J3,
  A2_J4,
  A2_J5,
  A2_J6,
  A2_J7,

  A3_J1,
  A3_J2,
  A3_J3,
  A3_J4,
  A3_J5,
  A3_J6,
  A3_J7,

  A4_J1,
  A4_J2,
  A4_J3,
  A4_J4,
  A4_J5,
  A4_J6,
  A4_J7,

  N_ROBOT_DOFS
};

//! define miscellenous sensors of this robot
enum RobotMiscSensors {
  // the computed load cell location is a the endeffector end, in local coordinates
  A1_C_FX = 1,       //!< A1 computed load cell force in x
  A1_C_FY,           //!< A1 computed load cell force in y
  A1_C_FZ,           //!< A1 computed load cell force in z
  A1_C_MX,           //!< A1 computed load cell moment in x
  A1_C_MY,           //!< A1 computed load cell moment in y
  A1_C_MZ,           //!< A1 computed load cell moment in z

  // the load cell readings from an actual sensor
  A1_S_FX,           //!< A1 sensed load cell force in x
  A1_S_FY,           //!< A1 sensed load cell force in y
  A1_S_FZ,           //!< A1 sensed load cell force in z
  A1_S_MX,           //!< A1 sensed load cell moment in x
  A1_S_MY,           //!< A1 sensed load cell moment in y
  A1_S_MZ,           //!< A1 sensed load cell moment in z

  // gripper information
  A1_G_WIDTH,        //!< A1 gripper width
  A1_G_MOTION,       //!< A1 gripper is moving: yes/no
  
  // the computed load cell location is a the endeffector end, in local coordinates
  A2_C_FX,           //!< A2 computed load cell force in x
  A2_C_FY,           //!< A2 computed load cell force in y
  A2_C_FZ,           //!< A2 computed load cell force in z
  A2_C_MX,           //!< A2 computed load cell moment in x
  A2_C_MY,           //!< A2 computed load cell moment in y
  A2_C_MZ,           //!< A2 computed load cell moment in z

  // the load cell readings from an actual sensor
  A2_S_FX,           //!< A2 sensed load cell force in x
  A2_S_FY,           //!< A2 sensed load cell force in y
  A2_S_FZ,           //!< A2 sensed load cell force in z
  A2_S_MX,           //!< A2 sensed load cell moment in x
  A2_S_MY,           //!< A2 sensed load cell moment in y
  A2_S_MZ,           //!< A2 sensed load cell moment in z

  // gripper information
  A2_G_WIDTH,        //!< A2 gripper width
  A2_G_MOTION,       //!< A2 gripper is moving: yes/no
  
  // the computed load cell location is a the endeffector end, in local coordinates
  A3_C_FX,           //!< A3 computed load cell force in x
  A3_C_FY,           //!< A3 computed load cell force in y
  A3_C_FZ,           //!< A3 computed load cell force in z
  A3_C_MX,           //!< A3 computed load cell moment in x
  A3_C_MY,           //!< A3 computed load cell moment in y
  A3_C_MZ,           //!< A3 computed load cell moment in z

  // the load cell readings from an actual sensor
  A3_S_FX,           //!< A3 sensed load cell force in x
  A3_S_FY,           //!< A3 sensed load cell force in y
  A3_S_FZ,           //!< A3 sensed load cell force in z
  A3_S_MX,           //!< A3 sensed load cell moment in x
  A3_S_MY,           //!< A3 sensed load cell moment in y
  A3_S_MZ,           //!< A3 sensed load cell moment in z

  // gripper information
  A3_G_WIDTH,        //!< A3 gripper width
  A3_G_MOTION,       //!< A3 gripper is moving: yes/no
  
  // the computed load cell location is a the endeffector end, in local coordinates
  A4_C_FX,           //!< A4 computed load cell force in x
  A4_C_FY,           //!< A4 computed load cell force in y
  A4_C_FZ,           //!< A4 computed load cell force in z
  A4_C_MX,           //!< A4 computed load cell moment in x
  A4_C_MY,           //!< A4 computed load cell moment in y
  A4_C_MZ,           //!< A4 computed load cell moment in z

  // the load cell readings from an actual sensor
  A4_S_FX,           //!< A4 sensed load cell force in x
  A4_S_FY,           //!< A4 sensed load cell force in y
  A4_S_FZ,           //!< A4 sensed load cell force in z
  A4_S_MX,           //!< A4 sensed load cell moment in x
  A4_S_MY,           //!< A4 sensed load cell moment in y
  A4_S_MZ,           //!< A4 sensed load cell moment in z

  // gripper information
  A4_G_WIDTH,        //!< A4 gripper width
  A4_G_MOTION,       //!< A4 gripper is moving: yes/no
  
  N_ROBOT_MISC_SENSORS
};

//! number of degrees-of-freedom of robot
#define N_DOFS (N_ROBOT_DOFS-1)

//! N_DOFS + fake DOFS, needed for parameter estimation; 
//   fake DOFS come from creating endeffector information
#define N_DOFS_EST (N_DOFS+4)

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
#define  TASK_SERVO_RATIO   R1TO1

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

  void sendCalibrateFTCommand(void);

// external variables

#ifdef __cplusplus
}
#endif


#endif  /* _SL_user_ */
