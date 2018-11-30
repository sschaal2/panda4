/* this function generates simple OpenGL graphics code to draw each link */


glPushMatrix();
myDrawGLElement((int)999,(double)0.0,(int)1);
glPopMatrix();

/* JointID = 0 */

glPushMatrix();
glPushMatrix();
if (basec[0].x[1]==0 && basec[0].x[2]==0)
glRotated((GLdouble)90.*(-1. + basec[0].x[3]/Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*basec[0].x[1],(GLdouble)0.5*basec[0].x[2],(GLdouble)0.5*(basec[0].x[3] + Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2))));
myDrawGLElement((int)0,(double)Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)basec[0].x[1],(GLdouble)basec[0].x[2],(GLdouble)basec[0].x[3]);
glRotated((GLdouble)114.59155902616465*ArcCos(baseo[0].q[1]),(GLdouble)baseo[0].q[2],(GLdouble)baseo[0].q[3],(GLdouble)baseo[0].q[4]);

/* JointID = 1 */

glPushMatrix();
glPushMatrix();
if (0==0 && 0==0)
glRotated((GLdouble)90.*(-1. + DHD1/Sqrt(Power(DHD1,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.,(GLdouble)0.,(GLdouble)0.5*(DHD1 + Sqrt(Power(DHD1,2))));
myDrawGLElement((int)1,(double)Sqrt(Power(DHD1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)0,(GLdouble)DHD1);
glRotated((GLdouble)57.29577951308232*state[1].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 2 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)2,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[2].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 3 */

glPushMatrix();
glPushMatrix();
if (0==0 && -DHD3==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.,(GLdouble)-0.5*DHD3,(GLdouble)0.5*Sqrt(Power(DHD3,2)));
myDrawGLElement((int)3,(double)Sqrt(Power(DHD3,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)-DHD3,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[3].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 4 */

glPushMatrix();
glPushMatrix();
if (DHA4==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA4,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA4,2)));
myDrawGLElement((int)4,(double)Sqrt(Power(DHA4,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA4,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[4].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 5 */

glPushMatrix();
glPushMatrix();
if (DHA5==0 && DHD5==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA5,(GLdouble)0.5*DHD5,(GLdouble)0.5*Sqrt(Power(DHA5,2) + Power(DHD5,2)));
myDrawGLElement((int)5,(double)Sqrt(Power(DHA5,2) + Power(DHD5,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA5,(GLdouble)DHD5,(GLdouble)0);
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[5].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 6 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)6,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[6].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 7 */

glPushMatrix();
glPushMatrix();
if (DHA7==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA7,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA7,2)));
myDrawGLElement((int)7,(double)Sqrt(Power(DHA7,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA7,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[7].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 108 */

glPushMatrix();
glPushMatrix();
if (eff[1].x[1]==0 && eff[1].x[2]==0)
glRotated((GLdouble)90.*(-1. + eff[1].x[3]/Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*eff[1].x[1],(GLdouble)0.5*eff[1].x[2],(GLdouble)0.5*(eff[1].x[3] + Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2))));
myDrawGLElement((int)108,(double)Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2)),(int)0);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
/*glutSwapBuffers();*/

