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
if (A1X==0 && A1Y==0)
glRotated((GLdouble)90.*(-1. + DHD1/Sqrt(Power(A1X,2) + Power(A1Y,2) + Power(DHD1,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*A1X,(GLdouble)0.5*A1Y,(GLdouble)0.5*(DHD1 + Sqrt(Power(A1X,2) + Power(A1Y,2) + Power(DHD1,2))));
myDrawGLElement((int)1,(double)Sqrt(Power(A1X,2) + Power(A1Y,2) + Power(DHD1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)A1X,(GLdouble)A1Y,(GLdouble)DHD1);
glRotated((GLdouble)57.29577951308232*A1G,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
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

/* JointID = 8 */

glPushMatrix();
glPushMatrix();
if (A2X==0 && A2Y==0)
glRotated((GLdouble)90.*(-1. + DHD1/Sqrt(Power(A2X,2) + Power(A2Y,2) + Power(DHD1,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*A2X,(GLdouble)0.5*A2Y,(GLdouble)0.5*(DHD1 + Sqrt(Power(A2X,2) + Power(A2Y,2) + Power(DHD1,2))));
myDrawGLElement((int)8,(double)Sqrt(Power(A2X,2) + Power(A2Y,2) + Power(DHD1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)A2X,(GLdouble)A2Y,(GLdouble)DHD1);
glRotated((GLdouble)57.29577951308232*A2G,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[8].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 9 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)9,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[9].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 10 */

glPushMatrix();
glPushMatrix();
if (0==0 && -DHD3==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.,(GLdouble)-0.5*DHD3,(GLdouble)0.5*Sqrt(Power(DHD3,2)));
myDrawGLElement((int)10,(double)Sqrt(Power(DHD3,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)-DHD3,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[10].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 11 */

glPushMatrix();
glPushMatrix();
if (DHA4==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA4,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA4,2)));
myDrawGLElement((int)11,(double)Sqrt(Power(DHA4,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA4,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[11].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 12 */

glPushMatrix();
glPushMatrix();
if (DHA5==0 && DHD5==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA5,(GLdouble)0.5*DHD5,(GLdouble)0.5*Sqrt(Power(DHA5,2) + Power(DHD5,2)));
myDrawGLElement((int)12,(double)Sqrt(Power(DHA5,2) + Power(DHD5,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA5,(GLdouble)DHD5,(GLdouble)0);
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[12].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 13 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)13,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[13].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 14 */

glPushMatrix();
glPushMatrix();
if (DHA7==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA7,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA7,2)));
myDrawGLElement((int)14,(double)Sqrt(Power(DHA7,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA7,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[14].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 115 */

glPushMatrix();
glPushMatrix();
if (eff[2].x[1]==0 && eff[2].x[2]==0)
glRotated((GLdouble)90.*(-1. + eff[2].x[3]/Sqrt(Power(eff[2].x[1],2) + Power(eff[2].x[2],2) + Power(eff[2].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*eff[2].x[1],(GLdouble)0.5*eff[2].x[2],(GLdouble)0.5*(eff[2].x[3] + Sqrt(Power(eff[2].x[1],2) + Power(eff[2].x[2],2) + Power(eff[2].x[3],2))));
myDrawGLElement((int)115,(double)Sqrt(Power(eff[2].x[1],2) + Power(eff[2].x[2],2) + Power(eff[2].x[3],2)),(int)0);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();

/* JointID = 15 */

glPushMatrix();
glPushMatrix();
if (A3X==0 && A3Y==0)
glRotated((GLdouble)90.*(-1. + DHD1/Sqrt(Power(A3X,2) + Power(A3Y,2) + Power(DHD1,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*A3X,(GLdouble)0.5*A3Y,(GLdouble)0.5*(DHD1 + Sqrt(Power(A3X,2) + Power(A3Y,2) + Power(DHD1,2))));
myDrawGLElement((int)15,(double)Sqrt(Power(A3X,2) + Power(A3Y,2) + Power(DHD1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)A3X,(GLdouble)A3Y,(GLdouble)DHD1);
glRotated((GLdouble)57.29577951308232*A3G,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[15].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 16 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)16,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[16].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 17 */

glPushMatrix();
glPushMatrix();
if (0==0 && -DHD3==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.,(GLdouble)-0.5*DHD3,(GLdouble)0.5*Sqrt(Power(DHD3,2)));
myDrawGLElement((int)17,(double)Sqrt(Power(DHD3,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)-DHD3,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[17].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 18 */

glPushMatrix();
glPushMatrix();
if (DHA4==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA4,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA4,2)));
myDrawGLElement((int)18,(double)Sqrt(Power(DHA4,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA4,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[18].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 19 */

glPushMatrix();
glPushMatrix();
if (DHA5==0 && DHD5==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA5,(GLdouble)0.5*DHD5,(GLdouble)0.5*Sqrt(Power(DHA5,2) + Power(DHD5,2)));
myDrawGLElement((int)19,(double)Sqrt(Power(DHA5,2) + Power(DHD5,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA5,(GLdouble)DHD5,(GLdouble)0);
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[19].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 20 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)20,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[20].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 21 */

glPushMatrix();
glPushMatrix();
if (DHA7==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA7,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA7,2)));
myDrawGLElement((int)21,(double)Sqrt(Power(DHA7,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA7,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[21].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 122 */

glPushMatrix();
glPushMatrix();
if (eff[3].x[1]==0 && eff[3].x[2]==0)
glRotated((GLdouble)90.*(-1. + eff[3].x[3]/Sqrt(Power(eff[3].x[1],2) + Power(eff[3].x[2],2) + Power(eff[3].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*eff[3].x[1],(GLdouble)0.5*eff[3].x[2],(GLdouble)0.5*(eff[3].x[3] + Sqrt(Power(eff[3].x[1],2) + Power(eff[3].x[2],2) + Power(eff[3].x[3],2))));
myDrawGLElement((int)122,(double)Sqrt(Power(eff[3].x[1],2) + Power(eff[3].x[2],2) + Power(eff[3].x[3],2)),(int)0);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();

/* JointID = 22 */

glPushMatrix();
glPushMatrix();
if (A4X==0 && A4Y==0)
glRotated((GLdouble)90.*(-1. + DHD1/Sqrt(Power(A4X,2) + Power(A4Y,2) + Power(DHD1,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*A4X,(GLdouble)0.5*A4Y,(GLdouble)0.5*(DHD1 + Sqrt(Power(A4X,2) + Power(A4Y,2) + Power(DHD1,2))));
myDrawGLElement((int)22,(double)Sqrt(Power(A4X,2) + Power(A4Y,2) + Power(DHD1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)A4X,(GLdouble)A4Y,(GLdouble)DHD1);
glRotated((GLdouble)57.29577951308232*A4G,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[22].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 23 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)23,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[23].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 24 */

glPushMatrix();
glPushMatrix();
if (0==0 && -DHD3==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.,(GLdouble)-0.5*DHD3,(GLdouble)0.5*Sqrt(Power(DHD3,2)));
myDrawGLElement((int)24,(double)Sqrt(Power(DHD3,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)-DHD3,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[24].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 25 */

glPushMatrix();
glPushMatrix();
if (DHA4==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA4,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA4,2)));
myDrawGLElement((int)25,(double)Sqrt(Power(DHA4,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA4,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[25].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 26 */

glPushMatrix();
glPushMatrix();
if (DHA5==0 && DHD5==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA5,(GLdouble)0.5*DHD5,(GLdouble)0.5*Sqrt(Power(DHA5,2) + Power(DHD5,2)));
myDrawGLElement((int)26,(double)Sqrt(Power(DHA5,2) + Power(DHD5,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA5,(GLdouble)DHD5,(GLdouble)0);
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[26].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 27 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)27,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[27].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 28 */

glPushMatrix();
glPushMatrix();
if (DHA7==0 && 0==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*DHA7,(GLdouble)0.,(GLdouble)0.5*Sqrt(Power(DHA7,2)));
myDrawGLElement((int)28,(double)Sqrt(Power(DHA7,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)DHA7,(GLdouble)0,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[28].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 129 */

glPushMatrix();
glPushMatrix();
if (eff[4].x[1]==0 && eff[4].x[2]==0)
glRotated((GLdouble)90.*(-1. + eff[4].x[3]/Sqrt(Power(eff[4].x[1],2) + Power(eff[4].x[2],2) + Power(eff[4].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*eff[4].x[1],(GLdouble)0.5*eff[4].x[2],(GLdouble)0.5*(eff[4].x[3] + Sqrt(Power(eff[4].x[1],2) + Power(eff[4].x[2],2) + Power(eff[4].x[3],2))));
myDrawGLElement((int)129,(double)Sqrt(Power(eff[4].x[1],2) + Power(eff[4].x[2],2) + Power(eff[4].x[3],2)),(int)0);
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

