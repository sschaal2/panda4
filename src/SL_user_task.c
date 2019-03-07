/*!=============================================================================
  ==============================================================================

  \file    SL_user_task.c

  \author  Stefan Schaal
  \date    Nov. 2007

  ==============================================================================
  \remarks
  
  Allows running user specific computation in the main task servo loop
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

// user specific headers
#include "SL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_task_servo.h"
#include "utility.h"
#include "mdefs.h"
#include "SL_dynamics.h"
#include "SL_shared_memory.h"
#include "SL_man.h"

// global variables

// local variables
  
// local functions
static void grasp(void);
static void move(void);
static void printDyn(void);

// external functions


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_task
 \date  Nov. 2007
 
 \remarks 
 
 initializes user task functionality
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none 

 ******************************************************************************/
int
init_user_task(void)

{
  
  int i,j;

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
 \note  run_user_task
 \date  Nov. 2007
 
 \remarks 
 
 this function is clocked out of the task servo
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none 

 ******************************************************************************/
int
run_user_task(void)

{
  
  int i,j;

  addToMan("move","executes a gripper move manually",move); 
  addToMan("grasp","executes a gripper grasp manually",grasp);
  addToMan("printDyn","prints the dynamics parameters",printDyn);
  
  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  sendGripperGraspCommand
\date  Feb 2019
   
\remarks 

       send a grasp command to the gripper

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     width  : desired gripper width
 \param[in]     speed  : desired gripper speed
 \param[in]     force  : desired gripper force
 \param[in]     eps_in : tolerance for successful grasp
 \param[in]     eps_out: tolerance for successful grasp

 ******************************************************************************/
void 
sendGripperGraspCommand(double width, double speed, double force, double eps_in, double eps_out) 
{
  int i,j;
  int count = 0;
  float buf[5+1];
  unsigned char cbuf[5*sizeof(float)];

  buf[++count] = width;
  buf[++count] = speed;
  buf[++count] = force;
  buf[++count] = eps_in;
  buf[++count] = eps_out;

  memcpy(cbuf,(void *)&(buf[1]),(5)*sizeof(float));
    
  sendMessageSimulationServo("graspGripper",(void *)cbuf,5*sizeof(float));

}

/*!*****************************************************************************
 *******************************************************************************
\note  sendGripperMoveCommand
\date  Feb 2019
   
\remarks 

       send a move command to the gripper

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     width  : desired gripper width
 \param[in]     speed  : desired gripper speed

 ******************************************************************************/
void 
sendGripperMoveCommand(double width, double speed)
{
  int i,j;
  int count = 0;
  float buf[2+1];
  unsigned char cbuf[2*sizeof(float)];

  buf[++count] = width;
  buf[++count] = speed;

  memcpy(cbuf,(void *)&(buf[1]),(2)*sizeof(float));
    
  sendMessageSimulationServo("moveGripper",(void *)cbuf,2*sizeof(float));

}

/*!*****************************************************************************
 *******************************************************************************
\note  grasp
\date  Feb 2019
   
\remarks 

       manually triggers a grasp command

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

  none

 ******************************************************************************/
static void 
grasp(void)
{
  static double width=0.01;
  static double speed=0.1;
  static double force=50;
  static double eps_in=0.01;
  static double eps_out=0.01;
  double aux;

  do {
    if (!get_double("gripper width",width,&aux))
      return;
  } while (aux < 0.0 || aux > 0.08);
  width = aux;

  do {
    if (!get_double("gripper speed",speed,&aux))
      return;
  } while (aux <= 0.0 || aux > 0.1);
  speed = aux;

  do {
    if (!get_double("gripper force",force,&aux))
      return;
  } while (aux < 0.0 || aux > 100);
  force = aux;

  do {
    if (!get_double("gripper inner tolerance",eps_in,&aux))
      return;
  } while (aux < 0.0 || aux > 0.08);
  eps_in = aux;

  do {
    if (!get_double("gripper outer tolerance",eps_out,&aux))
      return;
  } while (aux < 0.0 || aux > 0.08);
  eps_out = aux;

  sendGripperGraspCommand( width,  speed,  force,  eps_in,  eps_out);


}

/*!*****************************************************************************
 *******************************************************************************
\note  move
\date  Feb 2019
   
\remarks 

       manually triggers a move command

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

  none

 ******************************************************************************/
static void 
move(void)
{
  static double width=0.01;
  static double speed=0.1;
  double aux;

  do {
    if (!get_double("gripper width",width,&aux))
      return;
  } while (aux < 0.0 || aux > 0.08);
  width = aux;

  do {
    if (!get_double("gripper speed",speed,&aux))
      return;
  } while (aux <= 0.0 || aux > 0.1);
  speed = aux;

  sendGripperMoveCommand( width,  speed);


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
  static int firsttime = TRUE;
  static Matrix rbdM;
  static Vector rbdCG;
  SL_uext ux[N_DOFS+1];

  if (firsttime) {
    firsttime = FALSE;
    
    rbdM  = my_matrix(1,N_DOFS+2*N_CART,1,N_DOFS+2*N_CART);
    rbdCG = my_vector(1,N_DOFS+2*N_CART);
    bzero((void *)&ux,sizeof(ux));

  }
  
  SL_ForDynComp(joint_state,&base_state,&base_orient,ux,endeff,rbdM,rbdCG);

  printf("RBD Inertia Matrix:\n");
  for (i=1; i<=N_DOFS; ++i) {
    for (j=1; j<=N_DOFS; ++j) {
      printf("%7.4f ",rbdM[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("RBD Coriolis+Gravity Vector:\n");
  for (i=1; i<=N_DOFS; ++i) {
    printf("%7.4f ",rbdCG[i]);
  }
  printf("\n");
  printf("\n");

}
