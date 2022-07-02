/*!=============================================================================
  ==============================================================================

  \file    SL_user_openGL.c

  \author  Stefan Schaal
  \date    May 2010

  ==============================================================================
  \remarks
  
  This program contains all graphics user functions for a particular simulation.
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

// openGL headers
#include "GL/freeglut.h"
#include <X11/Xlib.h>

// user specific headers
#include "utility.h"
#include "SL.h"
#include "SL_openGL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_unix_common.h"
#include "SL_objects.h"
#include "SL_openGL_servo.h"
#include "SL_collect_data.h"
#include "mdefs.h"
#include "SL_kinematics.h"
#include "SL_shared_memory.h"
#include "SL_userGraphics.h"

// global variables 
int print_Hmat = FALSE;

// local variables
  
// local functions
static int  createWindows(void);
static void myDrawGLElement(int num, double length, int flag);
static void drawForceTorqueSensor(void);

// global functions
void display(void);
void idle(void);

// external functions


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_openGL
 \date  July 1998
 
 \remarks 
 
 initializes everything needed for the graphics for this simulation
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     argc : number of elements in argv
 \param[in]     argv : array of argc character strings
 

 ******************************************************************************/
int
init_user_openGL(int argc, char** argv)

{
  
  int i,j,n;
  int rc;
  int ans;

  // we need the kinematics initialized
  init_kinematics();

  // read objects
  readObjects(config_files[OBJECTS]);

  // assign contact force mappings
#include "LEKin_contact.h"

  // create simulation windows
  if (!createWindows())
    return FALSE;

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
 \note  createWindows
 \date  July 1998
 
 \remarks 
 
 initializes graphic windows
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none
 

 ******************************************************************************/
static int
createWindows(void)

{

  int i;
  int width=600, height=600;
  OpenGLWPtr w;
  
  Display *disp;
  int  screen_num;
  int  display_width;
  int  display_height;

  char string[100];
  char xstring[100];

  double eye[N_CART+1];
  double focus[N_CART+1];
  
  // connect to X server using the DISPLAY environment variable
  if ( (disp=XOpenDisplay(NULL)) == NULL ) {
    printf("Cannot connect to X servo %s\n",XDisplayName(NULL));
    exit(-1);
  }
  
  // get screen size from display structure macro 
  screen_num = DefaultScreen(disp);
  display_width = DisplayWidth(disp, screen_num);
  display_height = DisplayHeight(disp, screen_num);
  
  // get a window structure, initialized with default values 
  w=getOpenGLWindow();
  if (w==NULL)
    return FALSE;

  // change viewpoint 
  w->eye[_Z_]  = 0.7;
  w->eye[_X_]  = 1.5;
  w->eye[_Y_]  = 1.;

  w->display = display;
  w->idle    = idle;
  w->width   = width;
  w->height  = height;


  // check for user parameters
  if (read_parameter_pool_string(config_files[PARAMETERPOOL], 
				 "main_window_geometry", string))
    parseWindowSpecs(string, display_width,display_height,xstring, 
		     &(w->x), 
		     &(w->y), 
		     &(w->width),
		     &(w->height));

  if (read_parameter_pool_double_array(config_files[PARAMETERPOOL], 
				       "main_window_camera_pos", N_CART, eye))
    for (i=1; i<=N_CART; ++i)
      w->eye[i] = eye[i];
  

  if (read_parameter_pool_double_array(config_files[PARAMETERPOOL], 
				       "main_window_camera_focus", N_CART, focus))
    for (i=1; i<=N_CART; ++i)
      w->center[i] = focus[i];
  

  for (i=1; i<=N_CART; ++i) {
    w->eye0[i] = w->eye[i];
    w->center0[i] = w->center[i];
  }


  if (!createWindow(w))
    return FALSE;

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  display
\date  August 7, 1992
   
\remarks 

        this function updates the OpenGL graphics

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output


 ******************************************************************************/
void 
display(void)

{
  int i,j;
  static SL_Jstate  *state = joint_sim_state;
  static SL_endeff  *eff   = endeff;
  static SL_Cstate  *basec = &base_state;
  static SL_quat    *baseo = &base_orient;
  GLfloat  objscolor[4]={(float)0.,(float)0.,(float)0.,(float)0.0};
  static double fscale = 0.1;
  static int    firsttime = TRUE;

  if (firsttime) {
    firsttime = FALSE;
    double w;
    if (read_parameter_pool_double(config_files[PARAMETERPOOL],"contact_force_scale",&w))
      fscale = w;
  }


#include "OpenGL.h"

  // the standard display functions for openGL
#include "SL_user_display_core.h"

    // draw force/torque sensor
  drawForceTorqueSensor();

}

/*!*****************************************************************************
 *******************************************************************************
\note  myDrawGLElement
\date  August 7, 1992
   
\remarks 

        draws a GL element of a particular length in z direction

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     num   : ID number of element (just for info)
 \param[in]     length: length of element
 \param[in]     flag  : draw joint element (yes, not)


 ******************************************************************************/
static void  
myDrawGLElement(int num, double length, int flag)

{
		
  static int firsttime = TRUE;
  static int link0,link1,link2,link3,link4,link5,link6,link7,hand,finger;

  GLfloat  gray[4]={(float)0.8,(float)0.8,(float)0.8,(float)1.0};
  GLfloat  green[4]={(float)0.1,(float)0.5,(float)0.5,(float)1.0};
  GLfloat  red[4]={(float)1.0,(float)0.25,(float)0.25,(float)1.0};
  GLfloat  blue[4]={(float)0.1,(float)0.1,(float)1.0,(float)1.0};
  GLfloat  black[4]={(float)0.3,(float)0.3,(float)0.3,(float)1.0};
  GLfloat  white[4]={(float)1.,(float)1.,(float)1.0,(float)1.0};
  GLfloat  yellow[4]={(float)1.0,(float)0.8,(float)0.7,(float)1.0};

  int      isphere = 10;

  double   width=0.03;

  if (solid)
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
  else
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );


  if (firsttime) {
    firsttime = FALSE;

    char *lab_root;
    char  fname[300];

    lab_root = getenv("LAB_ROOT");

    sprintf(fname,"%s/panda/3D/link0.obj",lab_root);
    link0 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link1.obj",lab_root);
    link1 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link2.obj",lab_root);
    link2 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link3.obj",lab_root);
    link3 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link4.obj",lab_root);
    link4 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link5.obj",lab_root);
    link5 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link6.obj",lab_root);
    link6 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/link7.obj",lab_root);
    link7 = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/hand.obj",lab_root);
    hand = displayListFromObjFile(fname,1.);

    sprintf(fname,"%s/panda/3D/finger.obj",lab_root);
    finger = displayListFromObjFile(fname,1.);

  }



  if (flag==1) {
    glTranslated(0.0,0.0,length); 

    if (num==999) {/* the base coordinate system */
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
      glColor4fv(blue);
    } else {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
      glColor4fv(gray);
    } 

    if (solid)
      glutSolidSphere(0.5*width,isphere,isphere);
    else
      glutWireSphere(0.5*width,isphere,isphere);

    glTranslated(0.0,0.0,-length);
  }
	

  switch (num) {

  case A1_J1:
    glPopMatrix();
    glPushMatrix();
    glTranslated(A1X,A1Y,0.0);    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glRotated((GLdouble)A1G*180./PI,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);    
    glCallList(link0);
    break;

  case A2_J1:
    glPopMatrix();
    glPushMatrix();
    glTranslated(A2X,A2Y,0.0);    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glRotated((GLdouble)A2G*180./PI,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);    
    glCallList(link0);
    break;

  case A3_J1:
    glPopMatrix();
    glPushMatrix();
    glTranslated(A3X,A3Y,0.0);    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glRotated((GLdouble)A3G*180./PI,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);    
    glCallList(link0);
    break;

  case A4_J1:     
    glPopMatrix();
    glPushMatrix();
    glTranslated(A4X,A4Y,0.0);    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glRotated((GLdouble)A4G*180./PI,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);    
    glCallList(link0);
    break;

  case A1_J2:
  case A2_J2:
  case A3_J2:
  case A4_J2:     
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    //glTranslated(0.00,0.00,0.008);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glCallList(link1);
    break;

  case A1_J3:
  case A2_J3:
  case A3_J3:
  case A4_J3:     
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)180.,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
    glCallList(link2);
    break;

  case A1_J4:
  case A2_J4:
  case A3_J4:
  case A4_J4:         
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
    glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
    glCallList(link3);
    break;

  case A1_J5:
  case A2_J5:
  case A3_J5:
  case A4_J5:     
    glPopMatrix();
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glCallList(link4);
    break;

  case A1_J6:
  case A2_J6:
  case A3_J6:
  case A4_J6:     
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glColor4fv(gray);
    glCallList(link5);
    break;

  case A1_J7:
  case A2_J7:
  case A3_J7:
  case A4_J7:    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
    glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glCallList(link6);
    break;


  case 108:
  case 115:
  case 122:
  case 129:
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glColor4fv(gray);
    glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glCallList(link7);
    glTranslated(0.0,FL,0.0);
    /*
    glRotated((GLdouble)-45.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
    glCallList(hand);
    glTranslated(0.0,FINGER_OFF,0.0);
    glTranslated(0.0,0.0,-misc_sim_sensor[A1_G_WIDTH]/2.);
    glCallList(finger);\
    glRotated((GLdouble)180.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
    if (num == 108)
      glTranslated(0.0,0.0,-misc_sim_sensor[A1_G_WIDTH]);
    else if (num == 115)
      glTranslated(0.0,0.0,-misc_sim_sensor[A2_G_WIDTH]);      
    else if (num == 122)
      glTranslated(0.0,0.0,-misc_sim_sensor[A3_G_WIDTH]);      
    else if (num == 129)
      glTranslated(0.0,0.0,-misc_sim_sensor[A4_G_WIDTH]);      
    glCallList(finger);
    glPopMatrix();
    */
    // draw little rod to show the endeffector position
    glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
    glTranslated(0.0,0.0,length/2.);
    glScaled(0.02,0.01,length);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);

    if (solid)
      glutSolidCube(1.0);
    else
      glutWireCube(1.0);

    break;
    glScaled(width/5.,width/5.,length);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidCylinder(1.0,1.0,isphere,1);
    else
      glutWireCylinder(1.0,1.0,isphere,1);
    

  default:

    glScaled(width/2.,width/2.,length);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidCylinder(1.0,1.0,isphere,1);
    else
      glutWireCylinder(1.0,1.0,isphere,1);
			
  }
}

/*!*****************************************************************************
 *******************************************************************************
\note  idle
\date  June 1999
   
\remarks 

      The function called by openGL whenever processing time available.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output


 ******************************************************************************/
void
idle(void)

{
  int i;
  struct timeval t;
  static double last_draw_time = 0.0;
  double current_time;

  //-------------------------------------------------------------------------
  // the main functions are the most handy in an include file

#include "SL_user_idle_core.h"


  //-------------------------------------------------------------------------
  // refresh display

  gettimeofday(&t,NULL);
  current_time = (double) t.tv_sec + ((double)t.tv_usec)/1.e6;

  if (current_time-last_draw_time >= 1./window_update_rate) {
    glutPostRedisplayAll();
    last_draw_time = current_time; 
  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  drawForceTorqueSensor
\date  Jan. 2011
   
\remarks 

visualizes the force and torque vector at the wrist

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

 ******************************************************************************/
static void
drawForceTorqueSensor(void)
{
  int i,j,n,k;
  double f[N_CART+1];
  double t[N_CART+1];
  double fscale_N=0.025;
  double fscale_Nm=0.15;
  double s[N_CART+1];
  double e[N_CART+1];
  double arrow_width = 0.01;
  double off_local[N_CART+1];
  double off_global[N_CART+1];
  int    s_f_indices[] = {0,A1_S_FX,A2_S_FX,A3_S_FX,A4_S_FX};
  int    s_m_indices[] = {0,A1_S_MX,A2_S_MX,A3_S_MX,A4_S_MX};
  int    flange_indices[] = {0,A1_FLANGE,A2_FLANGE,A3_FLANGE,A4_FLANGE};
  int    j7_link_indices[] = {0,A1_J7_LINK,A2_J7_LINK,A3_J7_LINK,A4_J7_LINK};

  // loop over all endeffectors
  for (k=1; k<=N_ENDEFFS; ++k) {

    // rotate the force torque info to world coordinates
    for (i=1; i<=N_CART; ++i) {
      f[i] = 0.;
      t[i] = 0.;
      for (j=1; j<=N_CART; ++j) {
	f[i] += Alink_sim[flange_indices[k]][i][j]*misc_sim_sensor[s_f_indices[k]-1+j];
	t[i] += Alink_sim[flange_indices[k]][i][j]*misc_sim_sensor[s_m_indices[k]-1+j];
      }
    }

    // offset vector of load cell relative to J7_LINK
    vec_zero_size(off_local,N_CART);
    off_local[_Z_] = FL+FT_OFF_Z;
    for (i=1; i<=N_CART; ++i) {
      off_global[i] = 0.;
      for (j=1; j<=N_CART; ++j) {
	off_global[i] += Alink_sim[flange_indices[k]][i][j]*off_local[j];
      }
    }

    glPushMatrix();
    
    // move to the force torque sensor
    glTranslated(link_pos_sim[j7_link_indices[k]][_X_],
		 link_pos_sim[j7_link_indices[k]][_Y_],
		 link_pos_sim[j7_link_indices[k]][_Z_]);
    glTranslated(off_global[_X_],off_global[_Y_],off_global[_Z_]);


    // the start and end point of the force vector
    s[_X_] =  0.0;
    s[_Y_] =  0.0;
    s[_Z_] =  0.0;
    
    e[_X_] = s[_X_] + f[_X_]*fscale_N;
    e[_Y_] = s[_Y_] + f[_Y_]*fscale_N;
    e[_Z_] = s[_Z_] + f[_Z_]*fscale_N;
    
    
    glColor4f (0.8,1.0,1.0,1.0);      
    drawArrow(s,e,arrow_width);
    
    e[_X_] = s[_X_] + t[_X_]*fscale_Nm;
    e[_Y_] = s[_Y_] + t[_Y_]*fscale_Nm;
    e[_Z_] = s[_Z_] + t[_Z_]*fscale_Nm;
    
    
    glColor4f (0.8,0.4,0.0,1.0);
    drawArrow(s,e,arrow_width);
    
    glPopMatrix();

  }

}


