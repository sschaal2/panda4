/* sine and cosine precomputation */
sstate1th=Sin(state[1].th);
cstate1th=Cos(state[1].th);

sstate2th=Sin(state[2].th);
cstate2th=Cos(state[2].th);

sstate3th=Sin(state[3].th);
cstate3th=Cos(state[3].th);

sstate4th=Sin(state[4].th);
cstate4th=Cos(state[4].th);

sstate5th=Sin(state[5].th);
cstate5th=Cos(state[5].th);

sstate6th=Sin(state[6].th);
cstate6th=Cos(state[6].th);

sstate7th=Sin(state[7].th);
cstate7th=Cos(state[7].th);

sstate8th=Sin(state[8].th);
cstate8th=Cos(state[8].th);

sstate9th=Sin(state[9].th);
cstate9th=Cos(state[9].th);

sstate10th=Sin(state[10].th);
cstate10th=Cos(state[10].th);

sstate11th=Sin(state[11].th);
cstate11th=Cos(state[11].th);

sstate12th=Sin(state[12].th);
cstate12th=Cos(state[12].th);

sstate13th=Sin(state[13].th);
cstate13th=Cos(state[13].th);

sstate14th=Sin(state[14].th);
cstate14th=Cos(state[14].th);

sstate15th=Sin(state[15].th);
cstate15th=Cos(state[15].th);

sstate16th=Sin(state[16].th);
cstate16th=Cos(state[16].th);

sstate17th=Sin(state[17].th);
cstate17th=Cos(state[17].th);

sstate18th=Sin(state[18].th);
cstate18th=Cos(state[18].th);

sstate19th=Sin(state[19].th);
cstate19th=Cos(state[19].th);

sstate20th=Sin(state[20].th);
cstate20th=Cos(state[20].th);

sstate21th=Sin(state[21].th);
cstate21th=Cos(state[21].th);

sstate22th=Sin(state[22].th);
cstate22th=Cos(state[22].th);

sstate23th=Sin(state[23].th);
cstate23th=Cos(state[23].th);

sstate24th=Sin(state[24].th);
cstate24th=Cos(state[24].th);

sstate25th=Sin(state[25].th);
cstate25th=Cos(state[25].th);

sstate26th=Sin(state[26].th);
cstate26th=Cos(state[26].th);

sstate27th=Sin(state[27].th);
cstate27th=Cos(state[27].th);

sstate28th=Sin(state[28].th);
cstate28th=Cos(state[28].th);


/* rotation matrix sine and cosine precomputation */
rsA1G=Sin(A1G);
rcA1G=Cos(A1G);








rseff1a1=Sin(eff[1].a[1]);
rceff1a1=Cos(eff[1].a[1]);

rseff1a2=Sin(eff[1].a[2]);
rceff1a2=Cos(eff[1].a[2]);

rseff1a3=Sin(eff[1].a[3]);
rceff1a3=Cos(eff[1].a[3]);


rsA2G=Sin(A2G);
rcA2G=Cos(A2G);








rseff2a1=Sin(eff[2].a[1]);
rceff2a1=Cos(eff[2].a[1]);

rseff2a2=Sin(eff[2].a[2]);
rceff2a2=Cos(eff[2].a[2]);

rseff2a3=Sin(eff[2].a[3]);
rceff2a3=Cos(eff[2].a[3]);


rsA3G=Sin(A3G);
rcA3G=Cos(A3G);








rseff3a1=Sin(eff[3].a[1]);
rceff3a1=Cos(eff[3].a[1]);

rseff3a2=Sin(eff[3].a[2]);
rceff3a2=Cos(eff[3].a[2]);

rseff3a3=Sin(eff[3].a[3]);
rceff3a3=Cos(eff[3].a[3]);


rsA4G=Sin(A4G);
rcA4G=Cos(A4G);








rseff4a1=Sin(eff[4].a[1]);
rceff4a1=Cos(eff[4].a[1]);

rseff4a2=Sin(eff[4].a[2]);
rceff4a2=Cos(eff[4].a[2]);

rseff4a3=Sin(eff[4].a[3]);
rceff4a3=Cos(eff[4].a[3]);



/* inverse spatial rotation matrices */
Xinv[0][1][1]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
Xinv[0][1][2]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][1][3]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][1][4]=0;
Xinv[0][1][5]=0;
Xinv[0][1][6]=0;

Xinv[0][2][1]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][2][2]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
Xinv[0][2][3]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][2][4]=0;
Xinv[0][2][5]=0;
Xinv[0][2][6]=0;

Xinv[0][3][1]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][3][2]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][3][3]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);
Xinv[0][3][4]=0;
Xinv[0][3][5]=0;
Xinv[0][3][6]=0;

Xinv[0][4][1]=0;
Xinv[0][4][2]=0;
Xinv[0][4][3]=0;
Xinv[0][4][4]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
Xinv[0][4][5]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][4][6]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);

Xinv[0][5][1]=0;
Xinv[0][5][2]=0;
Xinv[0][5][3]=0;
Xinv[0][5][4]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][5][5]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
Xinv[0][5][6]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);

Xinv[0][6][1]=0;
Xinv[0][6][2]=0;
Xinv[0][6][3]=0;
Xinv[0][6][4]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][6][5]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][6][6]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);


Xinv[1][1][1]=cstate1th*rcA1G - rsA1G*sstate1th;
Xinv[1][1][2]=-(cstate1th*rsA1G) - rcA1G*sstate1th;
Xinv[1][1][3]=0;
Xinv[1][1][4]=0;
Xinv[1][1][5]=0;
Xinv[1][1][6]=0;

Xinv[1][2][1]=cstate1th*rsA1G + rcA1G*sstate1th;
Xinv[1][2][2]=cstate1th*rcA1G - rsA1G*sstate1th;
Xinv[1][2][3]=0;
Xinv[1][2][4]=0;
Xinv[1][2][5]=0;
Xinv[1][2][6]=0;

Xinv[1][3][1]=0;
Xinv[1][3][2]=0;
Xinv[1][3][3]=1;
Xinv[1][3][4]=0;
Xinv[1][3][5]=0;
Xinv[1][3][6]=0;

Xinv[1][4][1]=-(DHD1*(cstate1th*rsA1G + rcA1G*sstate1th));
Xinv[1][4][2]=-(DHD1*(cstate1th*rcA1G - rsA1G*sstate1th));
Xinv[1][4][3]=A1Y;
Xinv[1][4][4]=cstate1th*rcA1G - rsA1G*sstate1th;
Xinv[1][4][5]=-(cstate1th*rsA1G) - rcA1G*sstate1th;
Xinv[1][4][6]=0;

Xinv[1][5][1]=DHD1*(cstate1th*rcA1G - rsA1G*sstate1th);
Xinv[1][5][2]=DHD1*(-(cstate1th*rsA1G) - rcA1G*sstate1th);
Xinv[1][5][3]=-A1X;
Xinv[1][5][4]=cstate1th*rsA1G + rcA1G*sstate1th;
Xinv[1][5][5]=cstate1th*rcA1G - rsA1G*sstate1th;
Xinv[1][5][6]=0;

Xinv[1][6][1]=A1X*(cstate1th*rsA1G + rcA1G*sstate1th) - A1Y*(cstate1th*rcA1G - rsA1G*sstate1th);
Xinv[1][6][2]=-(A1Y*(-(cstate1th*rsA1G) - rcA1G*sstate1th)) + A1X*(cstate1th*rcA1G - rsA1G*sstate1th);
Xinv[1][6][3]=0;
Xinv[1][6][4]=0;
Xinv[1][6][5]=0;
Xinv[1][6][6]=1;


Xinv[2][1][1]=cstate2th;
Xinv[2][1][2]=-sstate2th;
Xinv[2][1][3]=0;
Xinv[2][1][4]=0;
Xinv[2][1][5]=0;
Xinv[2][1][6]=0;

Xinv[2][2][1]=0;
Xinv[2][2][2]=0;
Xinv[2][2][3]=1;
Xinv[2][2][4]=0;
Xinv[2][2][5]=0;
Xinv[2][2][6]=0;

Xinv[2][3][1]=-sstate2th;
Xinv[2][3][2]=-cstate2th;
Xinv[2][3][3]=0;
Xinv[2][3][4]=0;
Xinv[2][3][5]=0;
Xinv[2][3][6]=0;

Xinv[2][4][1]=0;
Xinv[2][4][2]=0;
Xinv[2][4][3]=0;
Xinv[2][4][4]=cstate2th;
Xinv[2][4][5]=-sstate2th;
Xinv[2][4][6]=0;

Xinv[2][5][1]=0;
Xinv[2][5][2]=0;
Xinv[2][5][3]=0;
Xinv[2][5][4]=0;
Xinv[2][5][5]=0;
Xinv[2][5][6]=1;

Xinv[2][6][1]=0;
Xinv[2][6][2]=0;
Xinv[2][6][3]=0;
Xinv[2][6][4]=-sstate2th;
Xinv[2][6][5]=-cstate2th;
Xinv[2][6][6]=0;


Xinv[3][1][1]=cstate3th;
Xinv[3][1][2]=-sstate3th;
Xinv[3][1][3]=0;
Xinv[3][1][4]=0;
Xinv[3][1][5]=0;
Xinv[3][1][6]=0;

Xinv[3][2][1]=0;
Xinv[3][2][2]=0;
Xinv[3][2][3]=-1;
Xinv[3][2][4]=0;
Xinv[3][2][5]=0;
Xinv[3][2][6]=0;

Xinv[3][3][1]=sstate3th;
Xinv[3][3][2]=cstate3th;
Xinv[3][3][3]=0;
Xinv[3][3][4]=0;
Xinv[3][3][5]=0;
Xinv[3][3][6]=0;

Xinv[3][4][1]=-(DHD3*sstate3th);
Xinv[3][4][2]=-(cstate3th*DHD3);
Xinv[3][4][3]=0;
Xinv[3][4][4]=cstate3th;
Xinv[3][4][5]=-sstate3th;
Xinv[3][4][6]=0;

Xinv[3][5][1]=0;
Xinv[3][5][2]=0;
Xinv[3][5][3]=0;
Xinv[3][5][4]=0;
Xinv[3][5][5]=0;
Xinv[3][5][6]=-1;

Xinv[3][6][1]=cstate3th*DHD3;
Xinv[3][6][2]=-(DHD3*sstate3th);
Xinv[3][6][3]=0;
Xinv[3][6][4]=sstate3th;
Xinv[3][6][5]=cstate3th;
Xinv[3][6][6]=0;


Xinv[4][1][1]=cstate4th;
Xinv[4][1][2]=-sstate4th;
Xinv[4][1][3]=0;
Xinv[4][1][4]=0;
Xinv[4][1][5]=0;
Xinv[4][1][6]=0;

Xinv[4][2][1]=0;
Xinv[4][2][2]=0;
Xinv[4][2][3]=-1;
Xinv[4][2][4]=0;
Xinv[4][2][5]=0;
Xinv[4][2][6]=0;

Xinv[4][3][1]=sstate4th;
Xinv[4][3][2]=cstate4th;
Xinv[4][3][3]=0;
Xinv[4][3][4]=0;
Xinv[4][3][5]=0;
Xinv[4][3][6]=0;

Xinv[4][4][1]=0;
Xinv[4][4][2]=0;
Xinv[4][4][3]=0;
Xinv[4][4][4]=cstate4th;
Xinv[4][4][5]=-sstate4th;
Xinv[4][4][6]=0;

Xinv[4][5][1]=-(DHA4*sstate4th);
Xinv[4][5][2]=-(cstate4th*DHA4);
Xinv[4][5][3]=0;
Xinv[4][5][4]=0;
Xinv[4][5][5]=0;
Xinv[4][5][6]=-1;

Xinv[4][6][1]=0;
Xinv[4][6][2]=0;
Xinv[4][6][3]=-DHA4;
Xinv[4][6][4]=sstate4th;
Xinv[4][6][5]=cstate4th;
Xinv[4][6][6]=0;


Xinv[5][1][1]=cstate5th;
Xinv[5][1][2]=-sstate5th;
Xinv[5][1][3]=0;
Xinv[5][1][4]=0;
Xinv[5][1][5]=0;
Xinv[5][1][6]=0;

Xinv[5][2][1]=0;
Xinv[5][2][2]=0;
Xinv[5][2][3]=1;
Xinv[5][2][4]=0;
Xinv[5][2][5]=0;
Xinv[5][2][6]=0;

Xinv[5][3][1]=-sstate5th;
Xinv[5][3][2]=-cstate5th;
Xinv[5][3][3]=0;
Xinv[5][3][4]=0;
Xinv[5][3][5]=0;
Xinv[5][3][6]=0;

Xinv[5][4][1]=-(DHD5*sstate5th);
Xinv[5][4][2]=-(cstate5th*DHD5);
Xinv[5][4][3]=0;
Xinv[5][4][4]=cstate5th;
Xinv[5][4][5]=-sstate5th;
Xinv[5][4][6]=0;

Xinv[5][5][1]=DHA5*sstate5th;
Xinv[5][5][2]=cstate5th*DHA5;
Xinv[5][5][3]=0;
Xinv[5][5][4]=0;
Xinv[5][5][5]=0;
Xinv[5][5][6]=1;

Xinv[5][6][1]=-(cstate5th*DHD5);
Xinv[5][6][2]=DHD5*sstate5th;
Xinv[5][6][3]=DHA5;
Xinv[5][6][4]=-sstate5th;
Xinv[5][6][5]=-cstate5th;
Xinv[5][6][6]=0;


Xinv[6][1][1]=cstate6th;
Xinv[6][1][2]=-sstate6th;
Xinv[6][1][3]=0;
Xinv[6][1][4]=0;
Xinv[6][1][5]=0;
Xinv[6][1][6]=0;

Xinv[6][2][1]=0;
Xinv[6][2][2]=0;
Xinv[6][2][3]=-1;
Xinv[6][2][4]=0;
Xinv[6][2][5]=0;
Xinv[6][2][6]=0;

Xinv[6][3][1]=sstate6th;
Xinv[6][3][2]=cstate6th;
Xinv[6][3][3]=0;
Xinv[6][3][4]=0;
Xinv[6][3][5]=0;
Xinv[6][3][6]=0;

Xinv[6][4][1]=0;
Xinv[6][4][2]=0;
Xinv[6][4][3]=0;
Xinv[6][4][4]=cstate6th;
Xinv[6][4][5]=-sstate6th;
Xinv[6][4][6]=0;

Xinv[6][5][1]=0;
Xinv[6][5][2]=0;
Xinv[6][5][3]=0;
Xinv[6][5][4]=0;
Xinv[6][5][5]=0;
Xinv[6][5][6]=-1;

Xinv[6][6][1]=0;
Xinv[6][6][2]=0;
Xinv[6][6][3]=0;
Xinv[6][6][4]=sstate6th;
Xinv[6][6][5]=cstate6th;
Xinv[6][6][6]=0;


Xinv[7][1][1]=cstate7th;
Xinv[7][1][2]=-sstate7th;
Xinv[7][1][3]=0;
Xinv[7][1][4]=0;
Xinv[7][1][5]=0;
Xinv[7][1][6]=0;

Xinv[7][2][1]=0;
Xinv[7][2][2]=0;
Xinv[7][2][3]=-1;
Xinv[7][2][4]=0;
Xinv[7][2][5]=0;
Xinv[7][2][6]=0;

Xinv[7][3][1]=sstate7th;
Xinv[7][3][2]=cstate7th;
Xinv[7][3][3]=0;
Xinv[7][3][4]=0;
Xinv[7][3][5]=0;
Xinv[7][3][6]=0;

Xinv[7][4][1]=0;
Xinv[7][4][2]=0;
Xinv[7][4][3]=0;
Xinv[7][4][4]=cstate7th;
Xinv[7][4][5]=-sstate7th;
Xinv[7][4][6]=0;

Xinv[7][5][1]=-(DHA7*sstate7th);
Xinv[7][5][2]=-(cstate7th*DHA7);
Xinv[7][5][3]=0;
Xinv[7][5][4]=0;
Xinv[7][5][5]=0;
Xinv[7][5][6]=-1;

Xinv[7][6][1]=0;
Xinv[7][6][2]=0;
Xinv[7][6][3]=-DHA7;
Xinv[7][6][4]=sstate7th;
Xinv[7][6][5]=cstate7th;
Xinv[7][6][6]=0;


Xinv[8][1][1]=rceff1a2*rceff1a3;
Xinv[8][1][2]=-(rceff1a2*rseff1a3);
Xinv[8][1][3]=rseff1a2;
Xinv[8][1][4]=0;
Xinv[8][1][5]=0;
Xinv[8][1][6]=0;

Xinv[8][2][1]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
Xinv[8][2][2]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
Xinv[8][2][3]=-(rceff1a2*rseff1a1);
Xinv[8][2][4]=0;
Xinv[8][2][5]=0;
Xinv[8][2][6]=0;

Xinv[8][3][1]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;
Xinv[8][3][2]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;
Xinv[8][3][3]=rceff1a1*rceff1a2;
Xinv[8][3][4]=0;
Xinv[8][3][5]=0;
Xinv[8][3][6]=0;

Xinv[8][4][1]=(-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3];
Xinv[8][4][2]=(rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3];
Xinv[8][4][3]=rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3];
Xinv[8][4][4]=rceff1a2*rceff1a3;
Xinv[8][4][5]=-(rceff1a2*rseff1a3);
Xinv[8][4][6]=rseff1a2;

Xinv[8][5][1]=-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3];
Xinv[8][5][2]=-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3];
Xinv[8][5][3]=-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3];
Xinv[8][5][4]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
Xinv[8][5][5]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
Xinv[8][5][6]=-(rceff1a2*rseff1a1);

Xinv[8][6][1]=(rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2];
Xinv[8][6][2]=(rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2];
Xinv[8][6][3]=-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2];
Xinv[8][6][4]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;
Xinv[8][6][5]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;
Xinv[8][6][6]=rceff1a1*rceff1a2;


Xinv[9][1][1]=cstate8th*rcA2G - rsA2G*sstate8th;
Xinv[9][1][2]=-(cstate8th*rsA2G) - rcA2G*sstate8th;
Xinv[9][1][3]=0;
Xinv[9][1][4]=0;
Xinv[9][1][5]=0;
Xinv[9][1][6]=0;

Xinv[9][2][1]=cstate8th*rsA2G + rcA2G*sstate8th;
Xinv[9][2][2]=cstate8th*rcA2G - rsA2G*sstate8th;
Xinv[9][2][3]=0;
Xinv[9][2][4]=0;
Xinv[9][2][5]=0;
Xinv[9][2][6]=0;

Xinv[9][3][1]=0;
Xinv[9][3][2]=0;
Xinv[9][3][3]=1;
Xinv[9][3][4]=0;
Xinv[9][3][5]=0;
Xinv[9][3][6]=0;

Xinv[9][4][1]=-(DHD1*(cstate8th*rsA2G + rcA2G*sstate8th));
Xinv[9][4][2]=-(DHD1*(cstate8th*rcA2G - rsA2G*sstate8th));
Xinv[9][4][3]=A2Y;
Xinv[9][4][4]=cstate8th*rcA2G - rsA2G*sstate8th;
Xinv[9][4][5]=-(cstate8th*rsA2G) - rcA2G*sstate8th;
Xinv[9][4][6]=0;

Xinv[9][5][1]=DHD1*(cstate8th*rcA2G - rsA2G*sstate8th);
Xinv[9][5][2]=DHD1*(-(cstate8th*rsA2G) - rcA2G*sstate8th);
Xinv[9][5][3]=-A2X;
Xinv[9][5][4]=cstate8th*rsA2G + rcA2G*sstate8th;
Xinv[9][5][5]=cstate8th*rcA2G - rsA2G*sstate8th;
Xinv[9][5][6]=0;

Xinv[9][6][1]=A2X*(cstate8th*rsA2G + rcA2G*sstate8th) - A2Y*(cstate8th*rcA2G - rsA2G*sstate8th);
Xinv[9][6][2]=-(A2Y*(-(cstate8th*rsA2G) - rcA2G*sstate8th)) + A2X*(cstate8th*rcA2G - rsA2G*sstate8th);
Xinv[9][6][3]=0;
Xinv[9][6][4]=0;
Xinv[9][6][5]=0;
Xinv[9][6][6]=1;


Xinv[10][1][1]=cstate9th;
Xinv[10][1][2]=-sstate9th;
Xinv[10][1][3]=0;
Xinv[10][1][4]=0;
Xinv[10][1][5]=0;
Xinv[10][1][6]=0;

Xinv[10][2][1]=0;
Xinv[10][2][2]=0;
Xinv[10][2][3]=1;
Xinv[10][2][4]=0;
Xinv[10][2][5]=0;
Xinv[10][2][6]=0;

Xinv[10][3][1]=-sstate9th;
Xinv[10][3][2]=-cstate9th;
Xinv[10][3][3]=0;
Xinv[10][3][4]=0;
Xinv[10][3][5]=0;
Xinv[10][3][6]=0;

Xinv[10][4][1]=0;
Xinv[10][4][2]=0;
Xinv[10][4][3]=0;
Xinv[10][4][4]=cstate9th;
Xinv[10][4][5]=-sstate9th;
Xinv[10][4][6]=0;

Xinv[10][5][1]=0;
Xinv[10][5][2]=0;
Xinv[10][5][3]=0;
Xinv[10][5][4]=0;
Xinv[10][5][5]=0;
Xinv[10][5][6]=1;

Xinv[10][6][1]=0;
Xinv[10][6][2]=0;
Xinv[10][6][3]=0;
Xinv[10][6][4]=-sstate9th;
Xinv[10][6][5]=-cstate9th;
Xinv[10][6][6]=0;


Xinv[11][1][1]=cstate10th;
Xinv[11][1][2]=-sstate10th;
Xinv[11][1][3]=0;
Xinv[11][1][4]=0;
Xinv[11][1][5]=0;
Xinv[11][1][6]=0;

Xinv[11][2][1]=0;
Xinv[11][2][2]=0;
Xinv[11][2][3]=-1;
Xinv[11][2][4]=0;
Xinv[11][2][5]=0;
Xinv[11][2][6]=0;

Xinv[11][3][1]=sstate10th;
Xinv[11][3][2]=cstate10th;
Xinv[11][3][3]=0;
Xinv[11][3][4]=0;
Xinv[11][3][5]=0;
Xinv[11][3][6]=0;

Xinv[11][4][1]=-(DHD3*sstate10th);
Xinv[11][4][2]=-(cstate10th*DHD3);
Xinv[11][4][3]=0;
Xinv[11][4][4]=cstate10th;
Xinv[11][4][5]=-sstate10th;
Xinv[11][4][6]=0;

Xinv[11][5][1]=0;
Xinv[11][5][2]=0;
Xinv[11][5][3]=0;
Xinv[11][5][4]=0;
Xinv[11][5][5]=0;
Xinv[11][5][6]=-1;

Xinv[11][6][1]=cstate10th*DHD3;
Xinv[11][6][2]=-(DHD3*sstate10th);
Xinv[11][6][3]=0;
Xinv[11][6][4]=sstate10th;
Xinv[11][6][5]=cstate10th;
Xinv[11][6][6]=0;


Xinv[12][1][1]=cstate11th;
Xinv[12][1][2]=-sstate11th;
Xinv[12][1][3]=0;
Xinv[12][1][4]=0;
Xinv[12][1][5]=0;
Xinv[12][1][6]=0;

Xinv[12][2][1]=0;
Xinv[12][2][2]=0;
Xinv[12][2][3]=-1;
Xinv[12][2][4]=0;
Xinv[12][2][5]=0;
Xinv[12][2][6]=0;

Xinv[12][3][1]=sstate11th;
Xinv[12][3][2]=cstate11th;
Xinv[12][3][3]=0;
Xinv[12][3][4]=0;
Xinv[12][3][5]=0;
Xinv[12][3][6]=0;

Xinv[12][4][1]=0;
Xinv[12][4][2]=0;
Xinv[12][4][3]=0;
Xinv[12][4][4]=cstate11th;
Xinv[12][4][5]=-sstate11th;
Xinv[12][4][6]=0;

Xinv[12][5][1]=-(DHA4*sstate11th);
Xinv[12][5][2]=-(cstate11th*DHA4);
Xinv[12][5][3]=0;
Xinv[12][5][4]=0;
Xinv[12][5][5]=0;
Xinv[12][5][6]=-1;

Xinv[12][6][1]=0;
Xinv[12][6][2]=0;
Xinv[12][6][3]=-DHA4;
Xinv[12][6][4]=sstate11th;
Xinv[12][6][5]=cstate11th;
Xinv[12][6][6]=0;


Xinv[13][1][1]=cstate12th;
Xinv[13][1][2]=-sstate12th;
Xinv[13][1][3]=0;
Xinv[13][1][4]=0;
Xinv[13][1][5]=0;
Xinv[13][1][6]=0;

Xinv[13][2][1]=0;
Xinv[13][2][2]=0;
Xinv[13][2][3]=1;
Xinv[13][2][4]=0;
Xinv[13][2][5]=0;
Xinv[13][2][6]=0;

Xinv[13][3][1]=-sstate12th;
Xinv[13][3][2]=-cstate12th;
Xinv[13][3][3]=0;
Xinv[13][3][4]=0;
Xinv[13][3][5]=0;
Xinv[13][3][6]=0;

Xinv[13][4][1]=-(DHD5*sstate12th);
Xinv[13][4][2]=-(cstate12th*DHD5);
Xinv[13][4][3]=0;
Xinv[13][4][4]=cstate12th;
Xinv[13][4][5]=-sstate12th;
Xinv[13][4][6]=0;

Xinv[13][5][1]=DHA5*sstate12th;
Xinv[13][5][2]=cstate12th*DHA5;
Xinv[13][5][3]=0;
Xinv[13][5][4]=0;
Xinv[13][5][5]=0;
Xinv[13][5][6]=1;

Xinv[13][6][1]=-(cstate12th*DHD5);
Xinv[13][6][2]=DHD5*sstate12th;
Xinv[13][6][3]=DHA5;
Xinv[13][6][4]=-sstate12th;
Xinv[13][6][5]=-cstate12th;
Xinv[13][6][6]=0;


Xinv[14][1][1]=cstate13th;
Xinv[14][1][2]=-sstate13th;
Xinv[14][1][3]=0;
Xinv[14][1][4]=0;
Xinv[14][1][5]=0;
Xinv[14][1][6]=0;

Xinv[14][2][1]=0;
Xinv[14][2][2]=0;
Xinv[14][2][3]=-1;
Xinv[14][2][4]=0;
Xinv[14][2][5]=0;
Xinv[14][2][6]=0;

Xinv[14][3][1]=sstate13th;
Xinv[14][3][2]=cstate13th;
Xinv[14][3][3]=0;
Xinv[14][3][4]=0;
Xinv[14][3][5]=0;
Xinv[14][3][6]=0;

Xinv[14][4][1]=0;
Xinv[14][4][2]=0;
Xinv[14][4][3]=0;
Xinv[14][4][4]=cstate13th;
Xinv[14][4][5]=-sstate13th;
Xinv[14][4][6]=0;

Xinv[14][5][1]=0;
Xinv[14][5][2]=0;
Xinv[14][5][3]=0;
Xinv[14][5][4]=0;
Xinv[14][5][5]=0;
Xinv[14][5][6]=-1;

Xinv[14][6][1]=0;
Xinv[14][6][2]=0;
Xinv[14][6][3]=0;
Xinv[14][6][4]=sstate13th;
Xinv[14][6][5]=cstate13th;
Xinv[14][6][6]=0;


Xinv[15][1][1]=cstate14th;
Xinv[15][1][2]=-sstate14th;
Xinv[15][1][3]=0;
Xinv[15][1][4]=0;
Xinv[15][1][5]=0;
Xinv[15][1][6]=0;

Xinv[15][2][1]=0;
Xinv[15][2][2]=0;
Xinv[15][2][3]=-1;
Xinv[15][2][4]=0;
Xinv[15][2][5]=0;
Xinv[15][2][6]=0;

Xinv[15][3][1]=sstate14th;
Xinv[15][3][2]=cstate14th;
Xinv[15][3][3]=0;
Xinv[15][3][4]=0;
Xinv[15][3][5]=0;
Xinv[15][3][6]=0;

Xinv[15][4][1]=0;
Xinv[15][4][2]=0;
Xinv[15][4][3]=0;
Xinv[15][4][4]=cstate14th;
Xinv[15][4][5]=-sstate14th;
Xinv[15][4][6]=0;

Xinv[15][5][1]=-(DHA7*sstate14th);
Xinv[15][5][2]=-(cstate14th*DHA7);
Xinv[15][5][3]=0;
Xinv[15][5][4]=0;
Xinv[15][5][5]=0;
Xinv[15][5][6]=-1;

Xinv[15][6][1]=0;
Xinv[15][6][2]=0;
Xinv[15][6][3]=-DHA7;
Xinv[15][6][4]=sstate14th;
Xinv[15][6][5]=cstate14th;
Xinv[15][6][6]=0;


Xinv[16][1][1]=rceff2a2*rceff2a3;
Xinv[16][1][2]=-(rceff2a2*rseff2a3);
Xinv[16][1][3]=rseff2a2;
Xinv[16][1][4]=0;
Xinv[16][1][5]=0;
Xinv[16][1][6]=0;

Xinv[16][2][1]=rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3;
Xinv[16][2][2]=rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3;
Xinv[16][2][3]=-(rceff2a2*rseff2a1);
Xinv[16][2][4]=0;
Xinv[16][2][5]=0;
Xinv[16][2][6]=0;

Xinv[16][3][1]=-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3;
Xinv[16][3][2]=rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3;
Xinv[16][3][3]=rceff2a1*rceff2a2;
Xinv[16][3][4]=0;
Xinv[16][3][5]=0;
Xinv[16][3][6]=0;

Xinv[16][4][1]=(-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[2] - (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[3];
Xinv[16][4][2]=(rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[2] - (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[3];
Xinv[16][4][3]=rceff2a1*rceff2a2*eff[2].x[2] + rceff2a2*rseff2a1*eff[2].x[3];
Xinv[16][4][4]=rceff2a2*rceff2a3;
Xinv[16][4][5]=-(rceff2a2*rseff2a3);
Xinv[16][4][6]=rseff2a2;

Xinv[16][5][1]=-((-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[1]) + rceff2a2*rceff2a3*eff[2].x[3];
Xinv[16][5][2]=-((rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[1]) - rceff2a2*rseff2a3*eff[2].x[3];
Xinv[16][5][3]=-(rceff2a1*rceff2a2*eff[2].x[1]) + rseff2a2*eff[2].x[3];
Xinv[16][5][4]=rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3;
Xinv[16][5][5]=rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3;
Xinv[16][5][6]=-(rceff2a2*rseff2a1);

Xinv[16][6][1]=(rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[1] - rceff2a2*rceff2a3*eff[2].x[2];
Xinv[16][6][2]=(rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[1] + rceff2a2*rseff2a3*eff[2].x[2];
Xinv[16][6][3]=-(rceff2a2*rseff2a1*eff[2].x[1]) - rseff2a2*eff[2].x[2];
Xinv[16][6][4]=-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3;
Xinv[16][6][5]=rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3;
Xinv[16][6][6]=rceff2a1*rceff2a2;


Xinv[17][1][1]=cstate15th*rcA3G - rsA3G*sstate15th;
Xinv[17][1][2]=-(cstate15th*rsA3G) - rcA3G*sstate15th;
Xinv[17][1][3]=0;
Xinv[17][1][4]=0;
Xinv[17][1][5]=0;
Xinv[17][1][6]=0;

Xinv[17][2][1]=cstate15th*rsA3G + rcA3G*sstate15th;
Xinv[17][2][2]=cstate15th*rcA3G - rsA3G*sstate15th;
Xinv[17][2][3]=0;
Xinv[17][2][4]=0;
Xinv[17][2][5]=0;
Xinv[17][2][6]=0;

Xinv[17][3][1]=0;
Xinv[17][3][2]=0;
Xinv[17][3][3]=1;
Xinv[17][3][4]=0;
Xinv[17][3][5]=0;
Xinv[17][3][6]=0;

Xinv[17][4][1]=-(DHD1*(cstate15th*rsA3G + rcA3G*sstate15th));
Xinv[17][4][2]=-(DHD1*(cstate15th*rcA3G - rsA3G*sstate15th));
Xinv[17][4][3]=A3Y;
Xinv[17][4][4]=cstate15th*rcA3G - rsA3G*sstate15th;
Xinv[17][4][5]=-(cstate15th*rsA3G) - rcA3G*sstate15th;
Xinv[17][4][6]=0;

Xinv[17][5][1]=DHD1*(cstate15th*rcA3G - rsA3G*sstate15th);
Xinv[17][5][2]=DHD1*(-(cstate15th*rsA3G) - rcA3G*sstate15th);
Xinv[17][5][3]=-A3X;
Xinv[17][5][4]=cstate15th*rsA3G + rcA3G*sstate15th;
Xinv[17][5][5]=cstate15th*rcA3G - rsA3G*sstate15th;
Xinv[17][5][6]=0;

Xinv[17][6][1]=A3X*(cstate15th*rsA3G + rcA3G*sstate15th) - A3Y*(cstate15th*rcA3G - rsA3G*sstate15th);
Xinv[17][6][2]=-(A3Y*(-(cstate15th*rsA3G) - rcA3G*sstate15th)) + A3X*(cstate15th*rcA3G - rsA3G*sstate15th);
Xinv[17][6][3]=0;
Xinv[17][6][4]=0;
Xinv[17][6][5]=0;
Xinv[17][6][6]=1;


Xinv[18][1][1]=cstate16th;
Xinv[18][1][2]=-sstate16th;
Xinv[18][1][3]=0;
Xinv[18][1][4]=0;
Xinv[18][1][5]=0;
Xinv[18][1][6]=0;

Xinv[18][2][1]=0;
Xinv[18][2][2]=0;
Xinv[18][2][3]=1;
Xinv[18][2][4]=0;
Xinv[18][2][5]=0;
Xinv[18][2][6]=0;

Xinv[18][3][1]=-sstate16th;
Xinv[18][3][2]=-cstate16th;
Xinv[18][3][3]=0;
Xinv[18][3][4]=0;
Xinv[18][3][5]=0;
Xinv[18][3][6]=0;

Xinv[18][4][1]=0;
Xinv[18][4][2]=0;
Xinv[18][4][3]=0;
Xinv[18][4][4]=cstate16th;
Xinv[18][4][5]=-sstate16th;
Xinv[18][4][6]=0;

Xinv[18][5][1]=0;
Xinv[18][5][2]=0;
Xinv[18][5][3]=0;
Xinv[18][5][4]=0;
Xinv[18][5][5]=0;
Xinv[18][5][6]=1;

Xinv[18][6][1]=0;
Xinv[18][6][2]=0;
Xinv[18][6][3]=0;
Xinv[18][6][4]=-sstate16th;
Xinv[18][6][5]=-cstate16th;
Xinv[18][6][6]=0;


Xinv[19][1][1]=cstate17th;
Xinv[19][1][2]=-sstate17th;
Xinv[19][1][3]=0;
Xinv[19][1][4]=0;
Xinv[19][1][5]=0;
Xinv[19][1][6]=0;

Xinv[19][2][1]=0;
Xinv[19][2][2]=0;
Xinv[19][2][3]=-1;
Xinv[19][2][4]=0;
Xinv[19][2][5]=0;
Xinv[19][2][6]=0;

Xinv[19][3][1]=sstate17th;
Xinv[19][3][2]=cstate17th;
Xinv[19][3][3]=0;
Xinv[19][3][4]=0;
Xinv[19][3][5]=0;
Xinv[19][3][6]=0;

Xinv[19][4][1]=-(DHD3*sstate17th);
Xinv[19][4][2]=-(cstate17th*DHD3);
Xinv[19][4][3]=0;
Xinv[19][4][4]=cstate17th;
Xinv[19][4][5]=-sstate17th;
Xinv[19][4][6]=0;

Xinv[19][5][1]=0;
Xinv[19][5][2]=0;
Xinv[19][5][3]=0;
Xinv[19][5][4]=0;
Xinv[19][5][5]=0;
Xinv[19][5][6]=-1;

Xinv[19][6][1]=cstate17th*DHD3;
Xinv[19][6][2]=-(DHD3*sstate17th);
Xinv[19][6][3]=0;
Xinv[19][6][4]=sstate17th;
Xinv[19][6][5]=cstate17th;
Xinv[19][6][6]=0;


Xinv[20][1][1]=cstate18th;
Xinv[20][1][2]=-sstate18th;
Xinv[20][1][3]=0;
Xinv[20][1][4]=0;
Xinv[20][1][5]=0;
Xinv[20][1][6]=0;

Xinv[20][2][1]=0;
Xinv[20][2][2]=0;
Xinv[20][2][3]=-1;
Xinv[20][2][4]=0;
Xinv[20][2][5]=0;
Xinv[20][2][6]=0;

Xinv[20][3][1]=sstate18th;
Xinv[20][3][2]=cstate18th;
Xinv[20][3][3]=0;
Xinv[20][3][4]=0;
Xinv[20][3][5]=0;
Xinv[20][3][6]=0;

Xinv[20][4][1]=0;
Xinv[20][4][2]=0;
Xinv[20][4][3]=0;
Xinv[20][4][4]=cstate18th;
Xinv[20][4][5]=-sstate18th;
Xinv[20][4][6]=0;

Xinv[20][5][1]=-(DHA4*sstate18th);
Xinv[20][5][2]=-(cstate18th*DHA4);
Xinv[20][5][3]=0;
Xinv[20][5][4]=0;
Xinv[20][5][5]=0;
Xinv[20][5][6]=-1;

Xinv[20][6][1]=0;
Xinv[20][6][2]=0;
Xinv[20][6][3]=-DHA4;
Xinv[20][6][4]=sstate18th;
Xinv[20][6][5]=cstate18th;
Xinv[20][6][6]=0;


Xinv[21][1][1]=cstate19th;
Xinv[21][1][2]=-sstate19th;
Xinv[21][1][3]=0;
Xinv[21][1][4]=0;
Xinv[21][1][5]=0;
Xinv[21][1][6]=0;

Xinv[21][2][1]=0;
Xinv[21][2][2]=0;
Xinv[21][2][3]=1;
Xinv[21][2][4]=0;
Xinv[21][2][5]=0;
Xinv[21][2][6]=0;

Xinv[21][3][1]=-sstate19th;
Xinv[21][3][2]=-cstate19th;
Xinv[21][3][3]=0;
Xinv[21][3][4]=0;
Xinv[21][3][5]=0;
Xinv[21][3][6]=0;

Xinv[21][4][1]=-(DHD5*sstate19th);
Xinv[21][4][2]=-(cstate19th*DHD5);
Xinv[21][4][3]=0;
Xinv[21][4][4]=cstate19th;
Xinv[21][4][5]=-sstate19th;
Xinv[21][4][6]=0;

Xinv[21][5][1]=DHA5*sstate19th;
Xinv[21][5][2]=cstate19th*DHA5;
Xinv[21][5][3]=0;
Xinv[21][5][4]=0;
Xinv[21][5][5]=0;
Xinv[21][5][6]=1;

Xinv[21][6][1]=-(cstate19th*DHD5);
Xinv[21][6][2]=DHD5*sstate19th;
Xinv[21][6][3]=DHA5;
Xinv[21][6][4]=-sstate19th;
Xinv[21][6][5]=-cstate19th;
Xinv[21][6][6]=0;


Xinv[22][1][1]=cstate20th;
Xinv[22][1][2]=-sstate20th;
Xinv[22][1][3]=0;
Xinv[22][1][4]=0;
Xinv[22][1][5]=0;
Xinv[22][1][6]=0;

Xinv[22][2][1]=0;
Xinv[22][2][2]=0;
Xinv[22][2][3]=-1;
Xinv[22][2][4]=0;
Xinv[22][2][5]=0;
Xinv[22][2][6]=0;

Xinv[22][3][1]=sstate20th;
Xinv[22][3][2]=cstate20th;
Xinv[22][3][3]=0;
Xinv[22][3][4]=0;
Xinv[22][3][5]=0;
Xinv[22][3][6]=0;

Xinv[22][4][1]=0;
Xinv[22][4][2]=0;
Xinv[22][4][3]=0;
Xinv[22][4][4]=cstate20th;
Xinv[22][4][5]=-sstate20th;
Xinv[22][4][6]=0;

Xinv[22][5][1]=0;
Xinv[22][5][2]=0;
Xinv[22][5][3]=0;
Xinv[22][5][4]=0;
Xinv[22][5][5]=0;
Xinv[22][5][6]=-1;

Xinv[22][6][1]=0;
Xinv[22][6][2]=0;
Xinv[22][6][3]=0;
Xinv[22][6][4]=sstate20th;
Xinv[22][6][5]=cstate20th;
Xinv[22][6][6]=0;


Xinv[23][1][1]=cstate21th;
Xinv[23][1][2]=-sstate21th;
Xinv[23][1][3]=0;
Xinv[23][1][4]=0;
Xinv[23][1][5]=0;
Xinv[23][1][6]=0;

Xinv[23][2][1]=0;
Xinv[23][2][2]=0;
Xinv[23][2][3]=-1;
Xinv[23][2][4]=0;
Xinv[23][2][5]=0;
Xinv[23][2][6]=0;

Xinv[23][3][1]=sstate21th;
Xinv[23][3][2]=cstate21th;
Xinv[23][3][3]=0;
Xinv[23][3][4]=0;
Xinv[23][3][5]=0;
Xinv[23][3][6]=0;

Xinv[23][4][1]=0;
Xinv[23][4][2]=0;
Xinv[23][4][3]=0;
Xinv[23][4][4]=cstate21th;
Xinv[23][4][5]=-sstate21th;
Xinv[23][4][6]=0;

Xinv[23][5][1]=-(DHA7*sstate21th);
Xinv[23][5][2]=-(cstate21th*DHA7);
Xinv[23][5][3]=0;
Xinv[23][5][4]=0;
Xinv[23][5][5]=0;
Xinv[23][5][6]=-1;

Xinv[23][6][1]=0;
Xinv[23][6][2]=0;
Xinv[23][6][3]=-DHA7;
Xinv[23][6][4]=sstate21th;
Xinv[23][6][5]=cstate21th;
Xinv[23][6][6]=0;


Xinv[24][1][1]=rceff3a2*rceff3a3;
Xinv[24][1][2]=-(rceff3a2*rseff3a3);
Xinv[24][1][3]=rseff3a2;
Xinv[24][1][4]=0;
Xinv[24][1][5]=0;
Xinv[24][1][6]=0;

Xinv[24][2][1]=rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3;
Xinv[24][2][2]=rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3;
Xinv[24][2][3]=-(rceff3a2*rseff3a1);
Xinv[24][2][4]=0;
Xinv[24][2][5]=0;
Xinv[24][2][6]=0;

Xinv[24][3][1]=-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3;
Xinv[24][3][2]=rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3;
Xinv[24][3][3]=rceff3a1*rceff3a2;
Xinv[24][3][4]=0;
Xinv[24][3][5]=0;
Xinv[24][3][6]=0;

Xinv[24][4][1]=(-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[2] - (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[3];
Xinv[24][4][2]=(rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[2] - (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[3];
Xinv[24][4][3]=rceff3a1*rceff3a2*eff[3].x[2] + rceff3a2*rseff3a1*eff[3].x[3];
Xinv[24][4][4]=rceff3a2*rceff3a3;
Xinv[24][4][5]=-(rceff3a2*rseff3a3);
Xinv[24][4][6]=rseff3a2;

Xinv[24][5][1]=-((-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[1]) + rceff3a2*rceff3a3*eff[3].x[3];
Xinv[24][5][2]=-((rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[1]) - rceff3a2*rseff3a3*eff[3].x[3];
Xinv[24][5][3]=-(rceff3a1*rceff3a2*eff[3].x[1]) + rseff3a2*eff[3].x[3];
Xinv[24][5][4]=rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3;
Xinv[24][5][5]=rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3;
Xinv[24][5][6]=-(rceff3a2*rseff3a1);

Xinv[24][6][1]=(rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[1] - rceff3a2*rceff3a3*eff[3].x[2];
Xinv[24][6][2]=(rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[1] + rceff3a2*rseff3a3*eff[3].x[2];
Xinv[24][6][3]=-(rceff3a2*rseff3a1*eff[3].x[1]) - rseff3a2*eff[3].x[2];
Xinv[24][6][4]=-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3;
Xinv[24][6][5]=rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3;
Xinv[24][6][6]=rceff3a1*rceff3a2;


Xinv[25][1][1]=cstate22th*rcA4G - rsA4G*sstate22th;
Xinv[25][1][2]=-(cstate22th*rsA4G) - rcA4G*sstate22th;
Xinv[25][1][3]=0;
Xinv[25][1][4]=0;
Xinv[25][1][5]=0;
Xinv[25][1][6]=0;

Xinv[25][2][1]=cstate22th*rsA4G + rcA4G*sstate22th;
Xinv[25][2][2]=cstate22th*rcA4G - rsA4G*sstate22th;
Xinv[25][2][3]=0;
Xinv[25][2][4]=0;
Xinv[25][2][5]=0;
Xinv[25][2][6]=0;

Xinv[25][3][1]=0;
Xinv[25][3][2]=0;
Xinv[25][3][3]=1;
Xinv[25][3][4]=0;
Xinv[25][3][5]=0;
Xinv[25][3][6]=0;

Xinv[25][4][1]=-(DHD1*(cstate22th*rsA4G + rcA4G*sstate22th));
Xinv[25][4][2]=-(DHD1*(cstate22th*rcA4G - rsA4G*sstate22th));
Xinv[25][4][3]=A4Y;
Xinv[25][4][4]=cstate22th*rcA4G - rsA4G*sstate22th;
Xinv[25][4][5]=-(cstate22th*rsA4G) - rcA4G*sstate22th;
Xinv[25][4][6]=0;

Xinv[25][5][1]=DHD1*(cstate22th*rcA4G - rsA4G*sstate22th);
Xinv[25][5][2]=DHD1*(-(cstate22th*rsA4G) - rcA4G*sstate22th);
Xinv[25][5][3]=-A4X;
Xinv[25][5][4]=cstate22th*rsA4G + rcA4G*sstate22th;
Xinv[25][5][5]=cstate22th*rcA4G - rsA4G*sstate22th;
Xinv[25][5][6]=0;

Xinv[25][6][1]=A4X*(cstate22th*rsA4G + rcA4G*sstate22th) - A4Y*(cstate22th*rcA4G - rsA4G*sstate22th);
Xinv[25][6][2]=-(A4Y*(-(cstate22th*rsA4G) - rcA4G*sstate22th)) + A4X*(cstate22th*rcA4G - rsA4G*sstate22th);
Xinv[25][6][3]=0;
Xinv[25][6][4]=0;
Xinv[25][6][5]=0;
Xinv[25][6][6]=1;


Xinv[26][1][1]=cstate23th;
Xinv[26][1][2]=-sstate23th;
Xinv[26][1][3]=0;
Xinv[26][1][4]=0;
Xinv[26][1][5]=0;
Xinv[26][1][6]=0;

Xinv[26][2][1]=0;
Xinv[26][2][2]=0;
Xinv[26][2][3]=1;
Xinv[26][2][4]=0;
Xinv[26][2][5]=0;
Xinv[26][2][6]=0;

Xinv[26][3][1]=-sstate23th;
Xinv[26][3][2]=-cstate23th;
Xinv[26][3][3]=0;
Xinv[26][3][4]=0;
Xinv[26][3][5]=0;
Xinv[26][3][6]=0;

Xinv[26][4][1]=0;
Xinv[26][4][2]=0;
Xinv[26][4][3]=0;
Xinv[26][4][4]=cstate23th;
Xinv[26][4][5]=-sstate23th;
Xinv[26][4][6]=0;

Xinv[26][5][1]=0;
Xinv[26][5][2]=0;
Xinv[26][5][3]=0;
Xinv[26][5][4]=0;
Xinv[26][5][5]=0;
Xinv[26][5][6]=1;

Xinv[26][6][1]=0;
Xinv[26][6][2]=0;
Xinv[26][6][3]=0;
Xinv[26][6][4]=-sstate23th;
Xinv[26][6][5]=-cstate23th;
Xinv[26][6][6]=0;


Xinv[27][1][1]=cstate24th;
Xinv[27][1][2]=-sstate24th;
Xinv[27][1][3]=0;
Xinv[27][1][4]=0;
Xinv[27][1][5]=0;
Xinv[27][1][6]=0;

Xinv[27][2][1]=0;
Xinv[27][2][2]=0;
Xinv[27][2][3]=-1;
Xinv[27][2][4]=0;
Xinv[27][2][5]=0;
Xinv[27][2][6]=0;

Xinv[27][3][1]=sstate24th;
Xinv[27][3][2]=cstate24th;
Xinv[27][3][3]=0;
Xinv[27][3][4]=0;
Xinv[27][3][5]=0;
Xinv[27][3][6]=0;

Xinv[27][4][1]=-(DHD3*sstate24th);
Xinv[27][4][2]=-(cstate24th*DHD3);
Xinv[27][4][3]=0;
Xinv[27][4][4]=cstate24th;
Xinv[27][4][5]=-sstate24th;
Xinv[27][4][6]=0;

Xinv[27][5][1]=0;
Xinv[27][5][2]=0;
Xinv[27][5][3]=0;
Xinv[27][5][4]=0;
Xinv[27][5][5]=0;
Xinv[27][5][6]=-1;

Xinv[27][6][1]=cstate24th*DHD3;
Xinv[27][6][2]=-(DHD3*sstate24th);
Xinv[27][6][3]=0;
Xinv[27][6][4]=sstate24th;
Xinv[27][6][5]=cstate24th;
Xinv[27][6][6]=0;


Xinv[28][1][1]=cstate25th;
Xinv[28][1][2]=-sstate25th;
Xinv[28][1][3]=0;
Xinv[28][1][4]=0;
Xinv[28][1][5]=0;
Xinv[28][1][6]=0;

Xinv[28][2][1]=0;
Xinv[28][2][2]=0;
Xinv[28][2][3]=-1;
Xinv[28][2][4]=0;
Xinv[28][2][5]=0;
Xinv[28][2][6]=0;

Xinv[28][3][1]=sstate25th;
Xinv[28][3][2]=cstate25th;
Xinv[28][3][3]=0;
Xinv[28][3][4]=0;
Xinv[28][3][5]=0;
Xinv[28][3][6]=0;

Xinv[28][4][1]=0;
Xinv[28][4][2]=0;
Xinv[28][4][3]=0;
Xinv[28][4][4]=cstate25th;
Xinv[28][4][5]=-sstate25th;
Xinv[28][4][6]=0;

Xinv[28][5][1]=-(DHA4*sstate25th);
Xinv[28][5][2]=-(cstate25th*DHA4);
Xinv[28][5][3]=0;
Xinv[28][5][4]=0;
Xinv[28][5][5]=0;
Xinv[28][5][6]=-1;

Xinv[28][6][1]=0;
Xinv[28][6][2]=0;
Xinv[28][6][3]=-DHA4;
Xinv[28][6][4]=sstate25th;
Xinv[28][6][5]=cstate25th;
Xinv[28][6][6]=0;


Xinv[29][1][1]=cstate26th;
Xinv[29][1][2]=-sstate26th;
Xinv[29][1][3]=0;
Xinv[29][1][4]=0;
Xinv[29][1][5]=0;
Xinv[29][1][6]=0;

Xinv[29][2][1]=0;
Xinv[29][2][2]=0;
Xinv[29][2][3]=1;
Xinv[29][2][4]=0;
Xinv[29][2][5]=0;
Xinv[29][2][6]=0;

Xinv[29][3][1]=-sstate26th;
Xinv[29][3][2]=-cstate26th;
Xinv[29][3][3]=0;
Xinv[29][3][4]=0;
Xinv[29][3][5]=0;
Xinv[29][3][6]=0;

Xinv[29][4][1]=-(DHD5*sstate26th);
Xinv[29][4][2]=-(cstate26th*DHD5);
Xinv[29][4][3]=0;
Xinv[29][4][4]=cstate26th;
Xinv[29][4][5]=-sstate26th;
Xinv[29][4][6]=0;

Xinv[29][5][1]=DHA5*sstate26th;
Xinv[29][5][2]=cstate26th*DHA5;
Xinv[29][5][3]=0;
Xinv[29][5][4]=0;
Xinv[29][5][5]=0;
Xinv[29][5][6]=1;

Xinv[29][6][1]=-(cstate26th*DHD5);
Xinv[29][6][2]=DHD5*sstate26th;
Xinv[29][6][3]=DHA5;
Xinv[29][6][4]=-sstate26th;
Xinv[29][6][5]=-cstate26th;
Xinv[29][6][6]=0;


Xinv[30][1][1]=cstate27th;
Xinv[30][1][2]=-sstate27th;
Xinv[30][1][3]=0;
Xinv[30][1][4]=0;
Xinv[30][1][5]=0;
Xinv[30][1][6]=0;

Xinv[30][2][1]=0;
Xinv[30][2][2]=0;
Xinv[30][2][3]=-1;
Xinv[30][2][4]=0;
Xinv[30][2][5]=0;
Xinv[30][2][6]=0;

Xinv[30][3][1]=sstate27th;
Xinv[30][3][2]=cstate27th;
Xinv[30][3][3]=0;
Xinv[30][3][4]=0;
Xinv[30][3][5]=0;
Xinv[30][3][6]=0;

Xinv[30][4][1]=0;
Xinv[30][4][2]=0;
Xinv[30][4][3]=0;
Xinv[30][4][4]=cstate27th;
Xinv[30][4][5]=-sstate27th;
Xinv[30][4][6]=0;

Xinv[30][5][1]=0;
Xinv[30][5][2]=0;
Xinv[30][5][3]=0;
Xinv[30][5][4]=0;
Xinv[30][5][5]=0;
Xinv[30][5][6]=-1;

Xinv[30][6][1]=0;
Xinv[30][6][2]=0;
Xinv[30][6][3]=0;
Xinv[30][6][4]=sstate27th;
Xinv[30][6][5]=cstate27th;
Xinv[30][6][6]=0;


Xinv[31][1][1]=cstate28th;
Xinv[31][1][2]=-sstate28th;
Xinv[31][1][3]=0;
Xinv[31][1][4]=0;
Xinv[31][1][5]=0;
Xinv[31][1][6]=0;

Xinv[31][2][1]=0;
Xinv[31][2][2]=0;
Xinv[31][2][3]=-1;
Xinv[31][2][4]=0;
Xinv[31][2][5]=0;
Xinv[31][2][6]=0;

Xinv[31][3][1]=sstate28th;
Xinv[31][3][2]=cstate28th;
Xinv[31][3][3]=0;
Xinv[31][3][4]=0;
Xinv[31][3][5]=0;
Xinv[31][3][6]=0;

Xinv[31][4][1]=0;
Xinv[31][4][2]=0;
Xinv[31][4][3]=0;
Xinv[31][4][4]=cstate28th;
Xinv[31][4][5]=-sstate28th;
Xinv[31][4][6]=0;

Xinv[31][5][1]=-(DHA7*sstate28th);
Xinv[31][5][2]=-(cstate28th*DHA7);
Xinv[31][5][3]=0;
Xinv[31][5][4]=0;
Xinv[31][5][5]=0;
Xinv[31][5][6]=-1;

Xinv[31][6][1]=0;
Xinv[31][6][2]=0;
Xinv[31][6][3]=-DHA7;
Xinv[31][6][4]=sstate28th;
Xinv[31][6][5]=cstate28th;
Xinv[31][6][6]=0;


Xinv[32][1][1]=rceff4a2*rceff4a3;
Xinv[32][1][2]=-(rceff4a2*rseff4a3);
Xinv[32][1][3]=rseff4a2;
Xinv[32][1][4]=0;
Xinv[32][1][5]=0;
Xinv[32][1][6]=0;

Xinv[32][2][1]=rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3;
Xinv[32][2][2]=rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3;
Xinv[32][2][3]=-(rceff4a2*rseff4a1);
Xinv[32][2][4]=0;
Xinv[32][2][5]=0;
Xinv[32][2][6]=0;

Xinv[32][3][1]=-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3;
Xinv[32][3][2]=rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3;
Xinv[32][3][3]=rceff4a1*rceff4a2;
Xinv[32][3][4]=0;
Xinv[32][3][5]=0;
Xinv[32][3][6]=0;

Xinv[32][4][1]=(-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[2] - (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[3];
Xinv[32][4][2]=(rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[2] - (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[3];
Xinv[32][4][3]=rceff4a1*rceff4a2*eff[4].x[2] + rceff4a2*rseff4a1*eff[4].x[3];
Xinv[32][4][4]=rceff4a2*rceff4a3;
Xinv[32][4][5]=-(rceff4a2*rseff4a3);
Xinv[32][4][6]=rseff4a2;

Xinv[32][5][1]=-((-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[1]) + rceff4a2*rceff4a3*eff[4].x[3];
Xinv[32][5][2]=-((rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[1]) - rceff4a2*rseff4a3*eff[4].x[3];
Xinv[32][5][3]=-(rceff4a1*rceff4a2*eff[4].x[1]) + rseff4a2*eff[4].x[3];
Xinv[32][5][4]=rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3;
Xinv[32][5][5]=rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3;
Xinv[32][5][6]=-(rceff4a2*rseff4a1);

Xinv[32][6][1]=(rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[1] - rceff4a2*rceff4a3*eff[4].x[2];
Xinv[32][6][2]=(rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[1] + rceff4a2*rseff4a3*eff[4].x[2];
Xinv[32][6][3]=-(rceff4a2*rseff4a1*eff[4].x[1]) - rseff4a2*eff[4].x[2];
Xinv[32][6][4]=-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3;
Xinv[32][6][5]=rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3;
Xinv[32][6][6]=rceff4a1*rceff4a2;



/* spatial transpose of axis of the DOFs */
st[1][1]=0;
st[1][2]=0;
st[1][3]=0;
st[1][4]=0;
st[1][5]=0;
st[1][6]=1;

st[2][1]=0;
st[2][2]=0;
st[2][3]=0;
st[2][4]=0;
st[2][5]=0;
st[2][6]=1;

st[3][1]=0;
st[3][2]=0;
st[3][3]=0;
st[3][4]=0;
st[3][5]=0;
st[3][6]=1;

st[4][1]=0;
st[4][2]=0;
st[4][3]=0;
st[4][4]=0;
st[4][5]=0;
st[4][6]=1;

st[5][1]=0;
st[5][2]=0;
st[5][3]=0;
st[5][4]=0;
st[5][5]=0;
st[5][6]=1;

st[6][1]=0;
st[6][2]=0;
st[6][3]=0;
st[6][4]=0;
st[6][5]=0;
st[6][6]=1;

st[7][1]=0;
st[7][2]=0;
st[7][3]=0;
st[7][4]=0;
st[7][5]=0;
st[7][6]=1;

st[8][1]=0;
st[8][2]=0;
st[8][3]=0;
st[8][4]=0;
st[8][5]=0;
st[8][6]=0;

st[9][1]=0;
st[9][2]=0;
st[9][3]=0;
st[9][4]=0;
st[9][5]=0;
st[9][6]=1;

st[10][1]=0;
st[10][2]=0;
st[10][3]=0;
st[10][4]=0;
st[10][5]=0;
st[10][6]=1;

st[11][1]=0;
st[11][2]=0;
st[11][3]=0;
st[11][4]=0;
st[11][5]=0;
st[11][6]=1;

st[12][1]=0;
st[12][2]=0;
st[12][3]=0;
st[12][4]=0;
st[12][5]=0;
st[12][6]=1;

st[13][1]=0;
st[13][2]=0;
st[13][3]=0;
st[13][4]=0;
st[13][5]=0;
st[13][6]=1;

st[14][1]=0;
st[14][2]=0;
st[14][3]=0;
st[14][4]=0;
st[14][5]=0;
st[14][6]=1;

st[15][1]=0;
st[15][2]=0;
st[15][3]=0;
st[15][4]=0;
st[15][5]=0;
st[15][6]=1;

st[16][1]=0;
st[16][2]=0;
st[16][3]=0;
st[16][4]=0;
st[16][5]=0;
st[16][6]=0;

st[17][1]=0;
st[17][2]=0;
st[17][3]=0;
st[17][4]=0;
st[17][5]=0;
st[17][6]=1;

st[18][1]=0;
st[18][2]=0;
st[18][3]=0;
st[18][4]=0;
st[18][5]=0;
st[18][6]=1;

st[19][1]=0;
st[19][2]=0;
st[19][3]=0;
st[19][4]=0;
st[19][5]=0;
st[19][6]=1;

st[20][1]=0;
st[20][2]=0;
st[20][3]=0;
st[20][4]=0;
st[20][5]=0;
st[20][6]=1;

st[21][1]=0;
st[21][2]=0;
st[21][3]=0;
st[21][4]=0;
st[21][5]=0;
st[21][6]=1;

st[22][1]=0;
st[22][2]=0;
st[22][3]=0;
st[22][4]=0;
st[22][5]=0;
st[22][6]=1;

st[23][1]=0;
st[23][2]=0;
st[23][3]=0;
st[23][4]=0;
st[23][5]=0;
st[23][6]=1;

st[24][1]=0;
st[24][2]=0;
st[24][3]=0;
st[24][4]=0;
st[24][5]=0;
st[24][6]=0;

st[25][1]=0;
st[25][2]=0;
st[25][3]=0;
st[25][4]=0;
st[25][5]=0;
st[25][6]=1;

st[26][1]=0;
st[26][2]=0;
st[26][3]=0;
st[26][4]=0;
st[26][5]=0;
st[26][6]=1;

st[27][1]=0;
st[27][2]=0;
st[27][3]=0;
st[27][4]=0;
st[27][5]=0;
st[27][6]=1;

st[28][1]=0;
st[28][2]=0;
st[28][3]=0;
st[28][4]=0;
st[28][5]=0;
st[28][6]=1;

st[29][1]=0;
st[29][2]=0;
st[29][3]=0;
st[29][4]=0;
st[29][5]=0;
st[29][6]=1;

st[30][1]=0;
st[30][2]=0;
st[30][3]=0;
st[30][4]=0;
st[30][5]=0;
st[30][6]=1;

st[31][1]=0;
st[31][2]=0;
st[31][3]=0;
st[31][4]=0;
st[31][5]=0;
st[31][6]=1;

st[32][1]=0;
st[32][2]=0;
st[32][3]=0;
st[32][4]=0;
st[32][5]=0;
st[32][6]=0;


/* velocity vectors */
v0[1]=baseo[0].ad[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*baseo[0].ad[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].ad[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
v0[2]=baseo[0].ad[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*baseo[0].ad[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].ad[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
v0[3]=2*baseo[0].ad[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*baseo[0].ad[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + baseo[0].ad[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));
v0[4]=basec[0].xd[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*basec[0].xd[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*basec[0].xd[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
v0[5]=basec[0].xd[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*basec[0].xd[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*basec[0].xd[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
v0[6]=2*basec[0].xd[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*basec[0].xd[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + basec[0].xd[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));

v1[1]=(cstate1th*rcA1G - rsA1G*sstate1th)*v0[1] + (cstate1th*rsA1G + rcA1G*sstate1th)*v0[2];
v1[2]=(-(cstate1th*rsA1G) - rcA1G*sstate1th)*v0[1] + (cstate1th*rcA1G - rsA1G*sstate1th)*v0[2];
v1[3]=state[1].thd + v0[3];
v1[4]=-(DHD1*(cstate1th*rsA1G + rcA1G*sstate1th)*v0[1]) + DHD1*(cstate1th*rcA1G - rsA1G*sstate1th)*v0[2] + (A1X*(cstate1th*rsA1G + rcA1G*sstate1th) - A1Y*(cstate1th*rcA1G - rsA1G*sstate1th))*v0[3] + (cstate1th*rcA1G - rsA1G*sstate1th)*v0[4] + (cstate1th*rsA1G + rcA1G*sstate1th)*v0[5];
v1[5]=-(DHD1*(cstate1th*rcA1G - rsA1G*sstate1th)*v0[1]) + DHD1*(-(cstate1th*rsA1G) - rcA1G*sstate1th)*v0[2] + (-(A1Y*(-(cstate1th*rsA1G) - rcA1G*sstate1th)) + A1X*(cstate1th*rcA1G - rsA1G*sstate1th))*v0[3] + (-(cstate1th*rsA1G) - rcA1G*sstate1th)*v0[4] + (cstate1th*rcA1G - rsA1G*sstate1th)*v0[5];
v1[6]=A1Y*v0[1] - A1X*v0[2] + v0[6];

v2[1]=cstate2th*v1[1] - sstate2th*v1[3];
v2[2]=-(sstate2th*v1[1]) - cstate2th*v1[3];
v2[3]=state[2].thd + v1[2];
v2[4]=cstate2th*v1[4] - sstate2th*v1[6];
v2[5]=-(sstate2th*v1[4]) - cstate2th*v1[6];
v2[6]=v1[5];

v3[1]=cstate3th*v2[1] + sstate3th*v2[3];
v3[2]=-(sstate3th*v2[1]) + cstate3th*v2[3];
v3[3]=state[3].thd - v2[2];
v3[4]=-(DHD3*sstate3th*v2[1]) + cstate3th*DHD3*v2[3] + cstate3th*v2[4] + sstate3th*v2[6];
v3[5]=-(cstate3th*DHD3*v2[1]) - DHD3*sstate3th*v2[3] - sstate3th*v2[4] + cstate3th*v2[6];
v3[6]=-v2[5];

v4[1]=cstate4th*v3[1] + sstate4th*v3[3];
v4[2]=-(sstate4th*v3[1]) + cstate4th*v3[3];
v4[3]=state[4].thd - v3[2];
v4[4]=-(DHA4*sstate4th*v3[2]) + cstate4th*v3[4] + sstate4th*v3[6];
v4[5]=-(cstate4th*DHA4*v3[2]) - sstate4th*v3[4] + cstate4th*v3[6];
v4[6]=-(DHA4*v3[3]) - v3[5];

v5[1]=cstate5th*v4[1] - sstate5th*v4[3];
v5[2]=-(sstate5th*v4[1]) - cstate5th*v4[3];
v5[3]=state[5].thd + v4[2];
v5[4]=-(DHD5*sstate5th*v4[1]) + DHA5*sstate5th*v4[2] - cstate5th*DHD5*v4[3] + cstate5th*v4[4] - sstate5th*v4[6];
v5[5]=-(cstate5th*DHD5*v4[1]) + cstate5th*DHA5*v4[2] + DHD5*sstate5th*v4[3] - sstate5th*v4[4] - cstate5th*v4[6];
v5[6]=DHA5*v4[3] + v4[5];

v6[1]=cstate6th*v5[1] + sstate6th*v5[3];
v6[2]=-(sstate6th*v5[1]) + cstate6th*v5[3];
v6[3]=state[6].thd - v5[2];
v6[4]=cstate6th*v5[4] + sstate6th*v5[6];
v6[5]=-(sstate6th*v5[4]) + cstate6th*v5[6];
v6[6]=-v5[5];

v7[1]=cstate7th*v6[1] + sstate7th*v6[3];
v7[2]=-(sstate7th*v6[1]) + cstate7th*v6[3];
v7[3]=state[7].thd - v6[2];
v7[4]=-(DHA7*sstate7th*v6[2]) + cstate7th*v6[4] + sstate7th*v6[6];
v7[5]=-(cstate7th*DHA7*v6[2]) - sstate7th*v6[4] + cstate7th*v6[6];
v7[6]=-(DHA7*v6[3]) - v6[5];

v8[1]=rceff1a2*rceff1a3*v7[1] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*v7[2] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*v7[3];
v8[2]=-(rceff1a2*rseff1a3*v7[1]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*v7[2] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*v7[3];
v8[3]=rseff1a2*v7[1] - rceff1a2*rseff1a1*v7[2] + rceff1a1*rceff1a2*v7[3];
v8[4]=((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3])*v7[1] + (-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3])*v7[2] + ((rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2])*v7[3] + rceff1a2*rceff1a3*v7[4] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*v7[5] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*v7[6];
v8[5]=((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3])*v7[1] + (-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3])*v7[2] + ((rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2])*v7[3] - rceff1a2*rseff1a3*v7[4] + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*v7[5] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*v7[6];
v8[6]=(rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3])*v7[1] + (-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3])*v7[2] + (-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2])*v7[3] + rseff1a2*v7[4] - rceff1a2*rseff1a1*v7[5] + rceff1a1*rceff1a2*v7[6];

v9[1]=(cstate8th*rcA2G - rsA2G*sstate8th)*v0[1] + (cstate8th*rsA2G + rcA2G*sstate8th)*v0[2];
v9[2]=(-(cstate8th*rsA2G) - rcA2G*sstate8th)*v0[1] + (cstate8th*rcA2G - rsA2G*sstate8th)*v0[2];
v9[3]=state[8].thd + v0[3];
v9[4]=-(DHD1*(cstate8th*rsA2G + rcA2G*sstate8th)*v0[1]) + DHD1*(cstate8th*rcA2G - rsA2G*sstate8th)*v0[2] + (A2X*(cstate8th*rsA2G + rcA2G*sstate8th) - A2Y*(cstate8th*rcA2G - rsA2G*sstate8th))*v0[3] + (cstate8th*rcA2G - rsA2G*sstate8th)*v0[4] + (cstate8th*rsA2G + rcA2G*sstate8th)*v0[5];
v9[5]=-(DHD1*(cstate8th*rcA2G - rsA2G*sstate8th)*v0[1]) + DHD1*(-(cstate8th*rsA2G) - rcA2G*sstate8th)*v0[2] + (-(A2Y*(-(cstate8th*rsA2G) - rcA2G*sstate8th)) + A2X*(cstate8th*rcA2G - rsA2G*sstate8th))*v0[3] + (-(cstate8th*rsA2G) - rcA2G*sstate8th)*v0[4] + (cstate8th*rcA2G - rsA2G*sstate8th)*v0[5];
v9[6]=A2Y*v0[1] - A2X*v0[2] + v0[6];

v10[1]=cstate9th*v9[1] - sstate9th*v9[3];
v10[2]=-(sstate9th*v9[1]) - cstate9th*v9[3];
v10[3]=state[9].thd + v9[2];
v10[4]=cstate9th*v9[4] - sstate9th*v9[6];
v10[5]=-(sstate9th*v9[4]) - cstate9th*v9[6];
v10[6]=v9[5];

v11[1]=cstate10th*v10[1] + sstate10th*v10[3];
v11[2]=-(sstate10th*v10[1]) + cstate10th*v10[3];
v11[3]=state[10].thd - v10[2];
v11[4]=-(DHD3*sstate10th*v10[1]) + cstate10th*DHD3*v10[3] + cstate10th*v10[4] + sstate10th*v10[6];
v11[5]=-(cstate10th*DHD3*v10[1]) - DHD3*sstate10th*v10[3] - sstate10th*v10[4] + cstate10th*v10[6];
v11[6]=-v10[5];

v12[1]=cstate11th*v11[1] + sstate11th*v11[3];
v12[2]=-(sstate11th*v11[1]) + cstate11th*v11[3];
v12[3]=state[11].thd - v11[2];
v12[4]=-(DHA4*sstate11th*v11[2]) + cstate11th*v11[4] + sstate11th*v11[6];
v12[5]=-(cstate11th*DHA4*v11[2]) - sstate11th*v11[4] + cstate11th*v11[6];
v12[6]=-(DHA4*v11[3]) - v11[5];

v13[1]=cstate12th*v12[1] - sstate12th*v12[3];
v13[2]=-(sstate12th*v12[1]) - cstate12th*v12[3];
v13[3]=state[12].thd + v12[2];
v13[4]=-(DHD5*sstate12th*v12[1]) + DHA5*sstate12th*v12[2] - cstate12th*DHD5*v12[3] + cstate12th*v12[4] - sstate12th*v12[6];
v13[5]=-(cstate12th*DHD5*v12[1]) + cstate12th*DHA5*v12[2] + DHD5*sstate12th*v12[3] - sstate12th*v12[4] - cstate12th*v12[6];
v13[6]=DHA5*v12[3] + v12[5];

v14[1]=cstate13th*v13[1] + sstate13th*v13[3];
v14[2]=-(sstate13th*v13[1]) + cstate13th*v13[3];
v14[3]=state[13].thd - v13[2];
v14[4]=cstate13th*v13[4] + sstate13th*v13[6];
v14[5]=-(sstate13th*v13[4]) + cstate13th*v13[6];
v14[6]=-v13[5];

v15[1]=cstate14th*v14[1] + sstate14th*v14[3];
v15[2]=-(sstate14th*v14[1]) + cstate14th*v14[3];
v15[3]=state[14].thd - v14[2];
v15[4]=-(DHA7*sstate14th*v14[2]) + cstate14th*v14[4] + sstate14th*v14[6];
v15[5]=-(cstate14th*DHA7*v14[2]) - sstate14th*v14[4] + cstate14th*v14[6];
v15[6]=-(DHA7*v14[3]) - v14[5];

v16[1]=rceff2a2*rceff2a3*v15[1] + (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*v15[2] + (-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*v15[3];
v16[2]=-(rceff2a2*rseff2a3*v15[1]) + (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*v15[2] + (rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*v15[3];
v16[3]=rseff2a2*v15[1] - rceff2a2*rseff2a1*v15[2] + rceff2a1*rceff2a2*v15[3];
v16[4]=((-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[2] - (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[3])*v15[1] + (-((-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[1]) + rceff2a2*rceff2a3*eff[2].x[3])*v15[2] + ((rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[1] - rceff2a2*rceff2a3*eff[2].x[2])*v15[3] + rceff2a2*rceff2a3*v15[4] + (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*v15[5] + (-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*v15[6];
v16[5]=((rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[2] - (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[3])*v15[1] + (-((rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[1]) - rceff2a2*rseff2a3*eff[2].x[3])*v15[2] + ((rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[1] + rceff2a2*rseff2a3*eff[2].x[2])*v15[3] - rceff2a2*rseff2a3*v15[4] + (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*v15[5] + (rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*v15[6];
v16[6]=(rceff2a1*rceff2a2*eff[2].x[2] + rceff2a2*rseff2a1*eff[2].x[3])*v15[1] + (-(rceff2a1*rceff2a2*eff[2].x[1]) + rseff2a2*eff[2].x[3])*v15[2] + (-(rceff2a2*rseff2a1*eff[2].x[1]) - rseff2a2*eff[2].x[2])*v15[3] + rseff2a2*v15[4] - rceff2a2*rseff2a1*v15[5] + rceff2a1*rceff2a2*v15[6];

v17[1]=(cstate15th*rcA3G - rsA3G*sstate15th)*v0[1] + (cstate15th*rsA3G + rcA3G*sstate15th)*v0[2];
v17[2]=(-(cstate15th*rsA3G) - rcA3G*sstate15th)*v0[1] + (cstate15th*rcA3G - rsA3G*sstate15th)*v0[2];
v17[3]=state[15].thd + v0[3];
v17[4]=-(DHD1*(cstate15th*rsA3G + rcA3G*sstate15th)*v0[1]) + DHD1*(cstate15th*rcA3G - rsA3G*sstate15th)*v0[2] + (A3X*(cstate15th*rsA3G + rcA3G*sstate15th) - A3Y*(cstate15th*rcA3G - rsA3G*sstate15th))*v0[3] + (cstate15th*rcA3G - rsA3G*sstate15th)*v0[4] + (cstate15th*rsA3G + rcA3G*sstate15th)*v0[5];
v17[5]=-(DHD1*(cstate15th*rcA3G - rsA3G*sstate15th)*v0[1]) + DHD1*(-(cstate15th*rsA3G) - rcA3G*sstate15th)*v0[2] + (-(A3Y*(-(cstate15th*rsA3G) - rcA3G*sstate15th)) + A3X*(cstate15th*rcA3G - rsA3G*sstate15th))*v0[3] + (-(cstate15th*rsA3G) - rcA3G*sstate15th)*v0[4] + (cstate15th*rcA3G - rsA3G*sstate15th)*v0[5];
v17[6]=A3Y*v0[1] - A3X*v0[2] + v0[6];

v18[1]=cstate16th*v17[1] - sstate16th*v17[3];
v18[2]=-(sstate16th*v17[1]) - cstate16th*v17[3];
v18[3]=state[16].thd + v17[2];
v18[4]=cstate16th*v17[4] - sstate16th*v17[6];
v18[5]=-(sstate16th*v17[4]) - cstate16th*v17[6];
v18[6]=v17[5];

v19[1]=cstate17th*v18[1] + sstate17th*v18[3];
v19[2]=-(sstate17th*v18[1]) + cstate17th*v18[3];
v19[3]=state[17].thd - v18[2];
v19[4]=-(DHD3*sstate17th*v18[1]) + cstate17th*DHD3*v18[3] + cstate17th*v18[4] + sstate17th*v18[6];
v19[5]=-(cstate17th*DHD3*v18[1]) - DHD3*sstate17th*v18[3] - sstate17th*v18[4] + cstate17th*v18[6];
v19[6]=-v18[5];

v20[1]=cstate18th*v19[1] + sstate18th*v19[3];
v20[2]=-(sstate18th*v19[1]) + cstate18th*v19[3];
v20[3]=state[18].thd - v19[2];
v20[4]=-(DHA4*sstate18th*v19[2]) + cstate18th*v19[4] + sstate18th*v19[6];
v20[5]=-(cstate18th*DHA4*v19[2]) - sstate18th*v19[4] + cstate18th*v19[6];
v20[6]=-(DHA4*v19[3]) - v19[5];

v21[1]=cstate19th*v20[1] - sstate19th*v20[3];
v21[2]=-(sstate19th*v20[1]) - cstate19th*v20[3];
v21[3]=state[19].thd + v20[2];
v21[4]=-(DHD5*sstate19th*v20[1]) + DHA5*sstate19th*v20[2] - cstate19th*DHD5*v20[3] + cstate19th*v20[4] - sstate19th*v20[6];
v21[5]=-(cstate19th*DHD5*v20[1]) + cstate19th*DHA5*v20[2] + DHD5*sstate19th*v20[3] - sstate19th*v20[4] - cstate19th*v20[6];
v21[6]=DHA5*v20[3] + v20[5];

v22[1]=cstate20th*v21[1] + sstate20th*v21[3];
v22[2]=-(sstate20th*v21[1]) + cstate20th*v21[3];
v22[3]=state[20].thd - v21[2];
v22[4]=cstate20th*v21[4] + sstate20th*v21[6];
v22[5]=-(sstate20th*v21[4]) + cstate20th*v21[6];
v22[6]=-v21[5];

v23[1]=cstate21th*v22[1] + sstate21th*v22[3];
v23[2]=-(sstate21th*v22[1]) + cstate21th*v22[3];
v23[3]=state[21].thd - v22[2];
v23[4]=-(DHA7*sstate21th*v22[2]) + cstate21th*v22[4] + sstate21th*v22[6];
v23[5]=-(cstate21th*DHA7*v22[2]) - sstate21th*v22[4] + cstate21th*v22[6];
v23[6]=-(DHA7*v22[3]) - v22[5];

v24[1]=rceff3a2*rceff3a3*v23[1] + (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*v23[2] + (-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*v23[3];
v24[2]=-(rceff3a2*rseff3a3*v23[1]) + (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*v23[2] + (rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*v23[3];
v24[3]=rseff3a2*v23[1] - rceff3a2*rseff3a1*v23[2] + rceff3a1*rceff3a2*v23[3];
v24[4]=((-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[2] - (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[3])*v23[1] + (-((-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[1]) + rceff3a2*rceff3a3*eff[3].x[3])*v23[2] + ((rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[1] - rceff3a2*rceff3a3*eff[3].x[2])*v23[3] + rceff3a2*rceff3a3*v23[4] + (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*v23[5] + (-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*v23[6];
v24[5]=((rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[2] - (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[3])*v23[1] + (-((rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[1]) - rceff3a2*rseff3a3*eff[3].x[3])*v23[2] + ((rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[1] + rceff3a2*rseff3a3*eff[3].x[2])*v23[3] - rceff3a2*rseff3a3*v23[4] + (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*v23[5] + (rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*v23[6];
v24[6]=(rceff3a1*rceff3a2*eff[3].x[2] + rceff3a2*rseff3a1*eff[3].x[3])*v23[1] + (-(rceff3a1*rceff3a2*eff[3].x[1]) + rseff3a2*eff[3].x[3])*v23[2] + (-(rceff3a2*rseff3a1*eff[3].x[1]) - rseff3a2*eff[3].x[2])*v23[3] + rseff3a2*v23[4] - rceff3a2*rseff3a1*v23[5] + rceff3a1*rceff3a2*v23[6];

v25[1]=(cstate22th*rcA4G - rsA4G*sstate22th)*v0[1] + (cstate22th*rsA4G + rcA4G*sstate22th)*v0[2];
v25[2]=(-(cstate22th*rsA4G) - rcA4G*sstate22th)*v0[1] + (cstate22th*rcA4G - rsA4G*sstate22th)*v0[2];
v25[3]=state[22].thd + v0[3];
v25[4]=-(DHD1*(cstate22th*rsA4G + rcA4G*sstate22th)*v0[1]) + DHD1*(cstate22th*rcA4G - rsA4G*sstate22th)*v0[2] + (A4X*(cstate22th*rsA4G + rcA4G*sstate22th) - A4Y*(cstate22th*rcA4G - rsA4G*sstate22th))*v0[3] + (cstate22th*rcA4G - rsA4G*sstate22th)*v0[4] + (cstate22th*rsA4G + rcA4G*sstate22th)*v0[5];
v25[5]=-(DHD1*(cstate22th*rcA4G - rsA4G*sstate22th)*v0[1]) + DHD1*(-(cstate22th*rsA4G) - rcA4G*sstate22th)*v0[2] + (-(A4Y*(-(cstate22th*rsA4G) - rcA4G*sstate22th)) + A4X*(cstate22th*rcA4G - rsA4G*sstate22th))*v0[3] + (-(cstate22th*rsA4G) - rcA4G*sstate22th)*v0[4] + (cstate22th*rcA4G - rsA4G*sstate22th)*v0[5];
v25[6]=A4Y*v0[1] - A4X*v0[2] + v0[6];

v26[1]=cstate23th*v25[1] - sstate23th*v25[3];
v26[2]=-(sstate23th*v25[1]) - cstate23th*v25[3];
v26[3]=state[23].thd + v25[2];
v26[4]=cstate23th*v25[4] - sstate23th*v25[6];
v26[5]=-(sstate23th*v25[4]) - cstate23th*v25[6];
v26[6]=v25[5];

v27[1]=cstate24th*v26[1] + sstate24th*v26[3];
v27[2]=-(sstate24th*v26[1]) + cstate24th*v26[3];
v27[3]=state[24].thd - v26[2];
v27[4]=-(DHD3*sstate24th*v26[1]) + cstate24th*DHD3*v26[3] + cstate24th*v26[4] + sstate24th*v26[6];
v27[5]=-(cstate24th*DHD3*v26[1]) - DHD3*sstate24th*v26[3] - sstate24th*v26[4] + cstate24th*v26[6];
v27[6]=-v26[5];

v28[1]=cstate25th*v27[1] + sstate25th*v27[3];
v28[2]=-(sstate25th*v27[1]) + cstate25th*v27[3];
v28[3]=state[25].thd - v27[2];
v28[4]=-(DHA4*sstate25th*v27[2]) + cstate25th*v27[4] + sstate25th*v27[6];
v28[5]=-(cstate25th*DHA4*v27[2]) - sstate25th*v27[4] + cstate25th*v27[6];
v28[6]=-(DHA4*v27[3]) - v27[5];

v29[1]=cstate26th*v28[1] - sstate26th*v28[3];
v29[2]=-(sstate26th*v28[1]) - cstate26th*v28[3];
v29[3]=state[26].thd + v28[2];
v29[4]=-(DHD5*sstate26th*v28[1]) + DHA5*sstate26th*v28[2] - cstate26th*DHD5*v28[3] + cstate26th*v28[4] - sstate26th*v28[6];
v29[5]=-(cstate26th*DHD5*v28[1]) + cstate26th*DHA5*v28[2] + DHD5*sstate26th*v28[3] - sstate26th*v28[4] - cstate26th*v28[6];
v29[6]=DHA5*v28[3] + v28[5];

v30[1]=cstate27th*v29[1] + sstate27th*v29[3];
v30[2]=-(sstate27th*v29[1]) + cstate27th*v29[3];
v30[3]=state[27].thd - v29[2];
v30[4]=cstate27th*v29[4] + sstate27th*v29[6];
v30[5]=-(sstate27th*v29[4]) + cstate27th*v29[6];
v30[6]=-v29[5];

v31[1]=cstate28th*v30[1] + sstate28th*v30[3];
v31[2]=-(sstate28th*v30[1]) + cstate28th*v30[3];
v31[3]=state[28].thd - v30[2];
v31[4]=-(DHA7*sstate28th*v30[2]) + cstate28th*v30[4] + sstate28th*v30[6];
v31[5]=-(cstate28th*DHA7*v30[2]) - sstate28th*v30[4] + cstate28th*v30[6];
v31[6]=-(DHA7*v30[3]) - v30[5];

v32[1]=rceff4a2*rceff4a3*v31[1] + (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*v31[2] + (-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*v31[3];
v32[2]=-(rceff4a2*rseff4a3*v31[1]) + (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*v31[2] + (rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*v31[3];
v32[3]=rseff4a2*v31[1] - rceff4a2*rseff4a1*v31[2] + rceff4a1*rceff4a2*v31[3];
v32[4]=((-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[2] - (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[3])*v31[1] + (-((-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[1]) + rceff4a2*rceff4a3*eff[4].x[3])*v31[2] + ((rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[1] - rceff4a2*rceff4a3*eff[4].x[2])*v31[3] + rceff4a2*rceff4a3*v31[4] + (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*v31[5] + (-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*v31[6];
v32[5]=((rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[2] - (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[3])*v31[1] + (-((rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[1]) - rceff4a2*rseff4a3*eff[4].x[3])*v31[2] + ((rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[1] + rceff4a2*rseff4a3*eff[4].x[2])*v31[3] - rceff4a2*rseff4a3*v31[4] + (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*v31[5] + (rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*v31[6];
v32[6]=(rceff4a1*rceff4a2*eff[4].x[2] + rceff4a2*rseff4a1*eff[4].x[3])*v31[1] + (-(rceff4a1*rceff4a2*eff[4].x[1]) + rseff4a2*eff[4].x[3])*v31[2] + (-(rceff4a2*rseff4a1*eff[4].x[1]) - rseff4a2*eff[4].x[2])*v31[3] + rseff4a2*v31[4] - rceff4a2*rseff4a1*v31[5] + rceff4a1*rceff4a2*v31[6];


/* acceleration vectors */
a0[1]=baseo[0].add[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*baseo[0].add[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].add[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
a0[2]=baseo[0].add[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*baseo[0].add[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].add[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
a0[3]=2*baseo[0].add[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*baseo[0].add[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + baseo[0].add[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));
a0[4]=basec[0].xdd[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*basec[0].xdd[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*(gravity + basec[0].xdd[3])*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
a0[5]=basec[0].xdd[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*basec[0].xdd[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*(gravity + basec[0].xdd[3])*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
a0[6]=2*basec[0].xdd[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*basec[0].xdd[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + (gravity + basec[0].xdd[3])*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));

a1[1]=(cstate1th*rcA1G - rsA1G*sstate1th)*a0[1] + (cstate1th*rsA1G + rcA1G*sstate1th)*a0[2] + state[1].thd*v1[2];
a1[2]=(-(cstate1th*rsA1G) - rcA1G*sstate1th)*a0[1] + (cstate1th*rcA1G - rsA1G*sstate1th)*a0[2] - state[1].thd*v1[1];
a1[3]=state[1].thdd + a0[3];
a1[4]=-(DHD1*(cstate1th*rsA1G + rcA1G*sstate1th)*a0[1]) + DHD1*(cstate1th*rcA1G - rsA1G*sstate1th)*a0[2] + (A1X*(cstate1th*rsA1G + rcA1G*sstate1th) - A1Y*(cstate1th*rcA1G - rsA1G*sstate1th))*a0[3] + (cstate1th*rcA1G - rsA1G*sstate1th)*a0[4] + (cstate1th*rsA1G + rcA1G*sstate1th)*a0[5] + state[1].thd*v1[5];
a1[5]=-(DHD1*(cstate1th*rcA1G - rsA1G*sstate1th)*a0[1]) + DHD1*(-(cstate1th*rsA1G) - rcA1G*sstate1th)*a0[2] + (-(A1Y*(-(cstate1th*rsA1G) - rcA1G*sstate1th)) + A1X*(cstate1th*rcA1G - rsA1G*sstate1th))*a0[3] + (-(cstate1th*rsA1G) - rcA1G*sstate1th)*a0[4] + (cstate1th*rcA1G - rsA1G*sstate1th)*a0[5] - state[1].thd*v1[4];
a1[6]=A1Y*a0[1] - A1X*a0[2] + a0[6];

a2[1]=cstate2th*a1[1] - sstate2th*a1[3] + state[2].thd*v2[2];
a2[2]=-(sstate2th*a1[1]) - cstate2th*a1[3] - state[2].thd*v2[1];
a2[3]=state[2].thdd + a1[2];
a2[4]=cstate2th*a1[4] - sstate2th*a1[6] + state[2].thd*v2[5];
a2[5]=-(sstate2th*a1[4]) - cstate2th*a1[6] - state[2].thd*v2[4];
a2[6]=a1[5];

a3[1]=cstate3th*a2[1] + sstate3th*a2[3] + state[3].thd*v3[2];
a3[2]=-(sstate3th*a2[1]) + cstate3th*a2[3] - state[3].thd*v3[1];
a3[3]=state[3].thdd - a2[2];
a3[4]=-(DHD3*sstate3th*a2[1]) + cstate3th*DHD3*a2[3] + cstate3th*a2[4] + sstate3th*a2[6] + state[3].thd*v3[5];
a3[5]=-(cstate3th*DHD3*a2[1]) - DHD3*sstate3th*a2[3] - sstate3th*a2[4] + cstate3th*a2[6] - state[3].thd*v3[4];
a3[6]=-a2[5];

a4[1]=cstate4th*a3[1] + sstate4th*a3[3] + state[4].thd*v4[2];
a4[2]=-(sstate4th*a3[1]) + cstate4th*a3[3] - state[4].thd*v4[1];
a4[3]=state[4].thdd - a3[2];
a4[4]=-(DHA4*sstate4th*a3[2]) + cstate4th*a3[4] + sstate4th*a3[6] + state[4].thd*v4[5];
a4[5]=-(cstate4th*DHA4*a3[2]) - sstate4th*a3[4] + cstate4th*a3[6] - state[4].thd*v4[4];
a4[6]=-(DHA4*a3[3]) - a3[5];

a5[1]=cstate5th*a4[1] - sstate5th*a4[3] + state[5].thd*v5[2];
a5[2]=-(sstate5th*a4[1]) - cstate5th*a4[3] - state[5].thd*v5[1];
a5[3]=state[5].thdd + a4[2];
a5[4]=-(DHD5*sstate5th*a4[1]) + DHA5*sstate5th*a4[2] - cstate5th*DHD5*a4[3] + cstate5th*a4[4] - sstate5th*a4[6] + state[5].thd*v5[5];
a5[5]=-(cstate5th*DHD5*a4[1]) + cstate5th*DHA5*a4[2] + DHD5*sstate5th*a4[3] - sstate5th*a4[4] - cstate5th*a4[6] - state[5].thd*v5[4];
a5[6]=DHA5*a4[3] + a4[5];

a6[1]=cstate6th*a5[1] + sstate6th*a5[3] + state[6].thd*v6[2];
a6[2]=-(sstate6th*a5[1]) + cstate6th*a5[3] - state[6].thd*v6[1];
a6[3]=state[6].thdd - a5[2];
a6[4]=cstate6th*a5[4] + sstate6th*a5[6] + state[6].thd*v6[5];
a6[5]=-(sstate6th*a5[4]) + cstate6th*a5[6] - state[6].thd*v6[4];
a6[6]=-a5[5];

a7[1]=cstate7th*a6[1] + sstate7th*a6[3] + state[7].thd*v7[2];
a7[2]=-(sstate7th*a6[1]) + cstate7th*a6[3] - state[7].thd*v7[1];
a7[3]=state[7].thdd - a6[2];
a7[4]=-(DHA7*sstate7th*a6[2]) + cstate7th*a6[4] + sstate7th*a6[6] + state[7].thd*v7[5];
a7[5]=-(cstate7th*DHA7*a6[2]) - sstate7th*a6[4] + cstate7th*a6[6] - state[7].thd*v7[4];
a7[6]=-(DHA7*a6[3]) - a6[5];

a8[1]=rceff1a2*rceff1a3*a7[1] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*a7[2] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*a7[3];
a8[2]=-(rceff1a2*rseff1a3*a7[1]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*a7[2] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*a7[3];
a8[3]=rseff1a2*a7[1] - rceff1a2*rseff1a1*a7[2] + rceff1a1*rceff1a2*a7[3];
a8[4]=rceff1a2*rceff1a3*a7[4] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*a7[5] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*a7[6] + a7[3]*((rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2]) + a7[2]*(-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3]) + a7[1]*((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3]);
a8[5]=-(rceff1a2*rseff1a3*a7[4]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*a7[5] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*a7[6] + a7[3]*((rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2]) + a7[2]*(-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3]) + a7[1]*((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3]);
a8[6]=rseff1a2*a7[4] - rceff1a2*rseff1a1*a7[5] + rceff1a1*rceff1a2*a7[6] + a7[3]*(-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2]) + a7[1]*(rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3]) + a7[2]*(-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3]);

a9[1]=(cstate8th*rcA2G - rsA2G*sstate8th)*a0[1] + (cstate8th*rsA2G + rcA2G*sstate8th)*a0[2] + state[8].thd*v9[2];
a9[2]=(-(cstate8th*rsA2G) - rcA2G*sstate8th)*a0[1] + (cstate8th*rcA2G - rsA2G*sstate8th)*a0[2] - state[8].thd*v9[1];
a9[3]=state[8].thdd + a0[3];
a9[4]=-(DHD1*(cstate8th*rsA2G + rcA2G*sstate8th)*a0[1]) + DHD1*(cstate8th*rcA2G - rsA2G*sstate8th)*a0[2] + (A2X*(cstate8th*rsA2G + rcA2G*sstate8th) - A2Y*(cstate8th*rcA2G - rsA2G*sstate8th))*a0[3] + (cstate8th*rcA2G - rsA2G*sstate8th)*a0[4] + (cstate8th*rsA2G + rcA2G*sstate8th)*a0[5] + state[8].thd*v9[5];
a9[5]=-(DHD1*(cstate8th*rcA2G - rsA2G*sstate8th)*a0[1]) + DHD1*(-(cstate8th*rsA2G) - rcA2G*sstate8th)*a0[2] + (-(A2Y*(-(cstate8th*rsA2G) - rcA2G*sstate8th)) + A2X*(cstate8th*rcA2G - rsA2G*sstate8th))*a0[3] + (-(cstate8th*rsA2G) - rcA2G*sstate8th)*a0[4] + (cstate8th*rcA2G - rsA2G*sstate8th)*a0[5] - state[8].thd*v9[4];
a9[6]=A2Y*a0[1] - A2X*a0[2] + a0[6];

a10[1]=cstate9th*a9[1] - sstate9th*a9[3] + state[9].thd*v10[2];
a10[2]=-(sstate9th*a9[1]) - cstate9th*a9[3] - state[9].thd*v10[1];
a10[3]=state[9].thdd + a9[2];
a10[4]=cstate9th*a9[4] - sstate9th*a9[6] + state[9].thd*v10[5];
a10[5]=-(sstate9th*a9[4]) - cstate9th*a9[6] - state[9].thd*v10[4];
a10[6]=a9[5];

a11[1]=cstate10th*a10[1] + sstate10th*a10[3] + state[10].thd*v11[2];
a11[2]=-(sstate10th*a10[1]) + cstate10th*a10[3] - state[10].thd*v11[1];
a11[3]=state[10].thdd - a10[2];
a11[4]=-(DHD3*sstate10th*a10[1]) + cstate10th*DHD3*a10[3] + cstate10th*a10[4] + sstate10th*a10[6] + state[10].thd*v11[5];
a11[5]=-(cstate10th*DHD3*a10[1]) - DHD3*sstate10th*a10[3] - sstate10th*a10[4] + cstate10th*a10[6] - state[10].thd*v11[4];
a11[6]=-a10[5];

a12[1]=cstate11th*a11[1] + sstate11th*a11[3] + state[11].thd*v12[2];
a12[2]=-(sstate11th*a11[1]) + cstate11th*a11[3] - state[11].thd*v12[1];
a12[3]=state[11].thdd - a11[2];
a12[4]=-(DHA4*sstate11th*a11[2]) + cstate11th*a11[4] + sstate11th*a11[6] + state[11].thd*v12[5];
a12[5]=-(cstate11th*DHA4*a11[2]) - sstate11th*a11[4] + cstate11th*a11[6] - state[11].thd*v12[4];
a12[6]=-(DHA4*a11[3]) - a11[5];

a13[1]=cstate12th*a12[1] - sstate12th*a12[3] + state[12].thd*v13[2];
a13[2]=-(sstate12th*a12[1]) - cstate12th*a12[3] - state[12].thd*v13[1];
a13[3]=state[12].thdd + a12[2];
a13[4]=-(DHD5*sstate12th*a12[1]) + DHA5*sstate12th*a12[2] - cstate12th*DHD5*a12[3] + cstate12th*a12[4] - sstate12th*a12[6] + state[12].thd*v13[5];
a13[5]=-(cstate12th*DHD5*a12[1]) + cstate12th*DHA5*a12[2] + DHD5*sstate12th*a12[3] - sstate12th*a12[4] - cstate12th*a12[6] - state[12].thd*v13[4];
a13[6]=DHA5*a12[3] + a12[5];

a14[1]=cstate13th*a13[1] + sstate13th*a13[3] + state[13].thd*v14[2];
a14[2]=-(sstate13th*a13[1]) + cstate13th*a13[3] - state[13].thd*v14[1];
a14[3]=state[13].thdd - a13[2];
a14[4]=cstate13th*a13[4] + sstate13th*a13[6] + state[13].thd*v14[5];
a14[5]=-(sstate13th*a13[4]) + cstate13th*a13[6] - state[13].thd*v14[4];
a14[6]=-a13[5];

a15[1]=cstate14th*a14[1] + sstate14th*a14[3] + state[14].thd*v15[2];
a15[2]=-(sstate14th*a14[1]) + cstate14th*a14[3] - state[14].thd*v15[1];
a15[3]=state[14].thdd - a14[2];
a15[4]=-(DHA7*sstate14th*a14[2]) + cstate14th*a14[4] + sstate14th*a14[6] + state[14].thd*v15[5];
a15[5]=-(cstate14th*DHA7*a14[2]) - sstate14th*a14[4] + cstate14th*a14[6] - state[14].thd*v15[4];
a15[6]=-(DHA7*a14[3]) - a14[5];

a16[1]=rceff2a2*rceff2a3*a15[1] + (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*a15[2] + (-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*a15[3];
a16[2]=-(rceff2a2*rseff2a3*a15[1]) + (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*a15[2] + (rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*a15[3];
a16[3]=rseff2a2*a15[1] - rceff2a2*rseff2a1*a15[2] + rceff2a1*rceff2a2*a15[3];
a16[4]=rceff2a2*rceff2a3*a15[4] + (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*a15[5] + (-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*a15[6] + a15[3]*((rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[1] - rceff2a2*rceff2a3*eff[2].x[2]) + a15[2]*(-((-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[1]) + rceff2a2*rceff2a3*eff[2].x[3]) + a15[1]*((-(rceff2a1*rceff2a3*rseff2a2) + rseff2a1*rseff2a3)*eff[2].x[2] - (rceff2a3*rseff2a1*rseff2a2 + rceff2a1*rseff2a3)*eff[2].x[3]);
a16[5]=-(rceff2a2*rseff2a3*a15[4]) + (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*a15[5] + (rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*a15[6] + a15[3]*((rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[1] + rceff2a2*rseff2a3*eff[2].x[2]) + a15[2]*(-((rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[1]) - rceff2a2*rseff2a3*eff[2].x[3]) + a15[1]*((rceff2a3*rseff2a1 + rceff2a1*rseff2a2*rseff2a3)*eff[2].x[2] - (rceff2a1*rceff2a3 - rseff2a1*rseff2a2*rseff2a3)*eff[2].x[3]);
a16[6]=rseff2a2*a15[4] - rceff2a2*rseff2a1*a15[5] + rceff2a1*rceff2a2*a15[6] + a15[3]*(-(rceff2a2*rseff2a1*eff[2].x[1]) - rseff2a2*eff[2].x[2]) + a15[1]*(rceff2a1*rceff2a2*eff[2].x[2] + rceff2a2*rseff2a1*eff[2].x[3]) + a15[2]*(-(rceff2a1*rceff2a2*eff[2].x[1]) + rseff2a2*eff[2].x[3]);

a17[1]=(cstate15th*rcA3G - rsA3G*sstate15th)*a0[1] + (cstate15th*rsA3G + rcA3G*sstate15th)*a0[2] + state[15].thd*v17[2];
a17[2]=(-(cstate15th*rsA3G) - rcA3G*sstate15th)*a0[1] + (cstate15th*rcA3G - rsA3G*sstate15th)*a0[2] - state[15].thd*v17[1];
a17[3]=state[15].thdd + a0[3];
a17[4]=-(DHD1*(cstate15th*rsA3G + rcA3G*sstate15th)*a0[1]) + DHD1*(cstate15th*rcA3G - rsA3G*sstate15th)*a0[2] + (A3X*(cstate15th*rsA3G + rcA3G*sstate15th) - A3Y*(cstate15th*rcA3G - rsA3G*sstate15th))*a0[3] + (cstate15th*rcA3G - rsA3G*sstate15th)*a0[4] + (cstate15th*rsA3G + rcA3G*sstate15th)*a0[5] + state[15].thd*v17[5];
a17[5]=-(DHD1*(cstate15th*rcA3G - rsA3G*sstate15th)*a0[1]) + DHD1*(-(cstate15th*rsA3G) - rcA3G*sstate15th)*a0[2] + (-(A3Y*(-(cstate15th*rsA3G) - rcA3G*sstate15th)) + A3X*(cstate15th*rcA3G - rsA3G*sstate15th))*a0[3] + (-(cstate15th*rsA3G) - rcA3G*sstate15th)*a0[4] + (cstate15th*rcA3G - rsA3G*sstate15th)*a0[5] - state[15].thd*v17[4];
a17[6]=A3Y*a0[1] - A3X*a0[2] + a0[6];

a18[1]=cstate16th*a17[1] - sstate16th*a17[3] + state[16].thd*v18[2];
a18[2]=-(sstate16th*a17[1]) - cstate16th*a17[3] - state[16].thd*v18[1];
a18[3]=state[16].thdd + a17[2];
a18[4]=cstate16th*a17[4] - sstate16th*a17[6] + state[16].thd*v18[5];
a18[5]=-(sstate16th*a17[4]) - cstate16th*a17[6] - state[16].thd*v18[4];
a18[6]=a17[5];

a19[1]=cstate17th*a18[1] + sstate17th*a18[3] + state[17].thd*v19[2];
a19[2]=-(sstate17th*a18[1]) + cstate17th*a18[3] - state[17].thd*v19[1];
a19[3]=state[17].thdd - a18[2];
a19[4]=-(DHD3*sstate17th*a18[1]) + cstate17th*DHD3*a18[3] + cstate17th*a18[4] + sstate17th*a18[6] + state[17].thd*v19[5];
a19[5]=-(cstate17th*DHD3*a18[1]) - DHD3*sstate17th*a18[3] - sstate17th*a18[4] + cstate17th*a18[6] - state[17].thd*v19[4];
a19[6]=-a18[5];

a20[1]=cstate18th*a19[1] + sstate18th*a19[3] + state[18].thd*v20[2];
a20[2]=-(sstate18th*a19[1]) + cstate18th*a19[3] - state[18].thd*v20[1];
a20[3]=state[18].thdd - a19[2];
a20[4]=-(DHA4*sstate18th*a19[2]) + cstate18th*a19[4] + sstate18th*a19[6] + state[18].thd*v20[5];
a20[5]=-(cstate18th*DHA4*a19[2]) - sstate18th*a19[4] + cstate18th*a19[6] - state[18].thd*v20[4];
a20[6]=-(DHA4*a19[3]) - a19[5];

a21[1]=cstate19th*a20[1] - sstate19th*a20[3] + state[19].thd*v21[2];
a21[2]=-(sstate19th*a20[1]) - cstate19th*a20[3] - state[19].thd*v21[1];
a21[3]=state[19].thdd + a20[2];
a21[4]=-(DHD5*sstate19th*a20[1]) + DHA5*sstate19th*a20[2] - cstate19th*DHD5*a20[3] + cstate19th*a20[4] - sstate19th*a20[6] + state[19].thd*v21[5];
a21[5]=-(cstate19th*DHD5*a20[1]) + cstate19th*DHA5*a20[2] + DHD5*sstate19th*a20[3] - sstate19th*a20[4] - cstate19th*a20[6] - state[19].thd*v21[4];
a21[6]=DHA5*a20[3] + a20[5];

a22[1]=cstate20th*a21[1] + sstate20th*a21[3] + state[20].thd*v22[2];
a22[2]=-(sstate20th*a21[1]) + cstate20th*a21[3] - state[20].thd*v22[1];
a22[3]=state[20].thdd - a21[2];
a22[4]=cstate20th*a21[4] + sstate20th*a21[6] + state[20].thd*v22[5];
a22[5]=-(sstate20th*a21[4]) + cstate20th*a21[6] - state[20].thd*v22[4];
a22[6]=-a21[5];

a23[1]=cstate21th*a22[1] + sstate21th*a22[3] + state[21].thd*v23[2];
a23[2]=-(sstate21th*a22[1]) + cstate21th*a22[3] - state[21].thd*v23[1];
a23[3]=state[21].thdd - a22[2];
a23[4]=-(DHA7*sstate21th*a22[2]) + cstate21th*a22[4] + sstate21th*a22[6] + state[21].thd*v23[5];
a23[5]=-(cstate21th*DHA7*a22[2]) - sstate21th*a22[4] + cstate21th*a22[6] - state[21].thd*v23[4];
a23[6]=-(DHA7*a22[3]) - a22[5];

a24[1]=rceff3a2*rceff3a3*a23[1] + (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*a23[2] + (-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*a23[3];
a24[2]=-(rceff3a2*rseff3a3*a23[1]) + (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*a23[2] + (rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*a23[3];
a24[3]=rseff3a2*a23[1] - rceff3a2*rseff3a1*a23[2] + rceff3a1*rceff3a2*a23[3];
a24[4]=rceff3a2*rceff3a3*a23[4] + (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*a23[5] + (-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*a23[6] + a23[3]*((rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[1] - rceff3a2*rceff3a3*eff[3].x[2]) + a23[2]*(-((-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[1]) + rceff3a2*rceff3a3*eff[3].x[3]) + a23[1]*((-(rceff3a1*rceff3a3*rseff3a2) + rseff3a1*rseff3a3)*eff[3].x[2] - (rceff3a3*rseff3a1*rseff3a2 + rceff3a1*rseff3a3)*eff[3].x[3]);
a24[5]=-(rceff3a2*rseff3a3*a23[4]) + (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*a23[5] + (rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*a23[6] + a23[3]*((rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[1] + rceff3a2*rseff3a3*eff[3].x[2]) + a23[2]*(-((rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[1]) - rceff3a2*rseff3a3*eff[3].x[3]) + a23[1]*((rceff3a3*rseff3a1 + rceff3a1*rseff3a2*rseff3a3)*eff[3].x[2] - (rceff3a1*rceff3a3 - rseff3a1*rseff3a2*rseff3a3)*eff[3].x[3]);
a24[6]=rseff3a2*a23[4] - rceff3a2*rseff3a1*a23[5] + rceff3a1*rceff3a2*a23[6] + a23[3]*(-(rceff3a2*rseff3a1*eff[3].x[1]) - rseff3a2*eff[3].x[2]) + a23[1]*(rceff3a1*rceff3a2*eff[3].x[2] + rceff3a2*rseff3a1*eff[3].x[3]) + a23[2]*(-(rceff3a1*rceff3a2*eff[3].x[1]) + rseff3a2*eff[3].x[3]);

a25[1]=(cstate22th*rcA4G - rsA4G*sstate22th)*a0[1] + (cstate22th*rsA4G + rcA4G*sstate22th)*a0[2] + state[22].thd*v25[2];
a25[2]=(-(cstate22th*rsA4G) - rcA4G*sstate22th)*a0[1] + (cstate22th*rcA4G - rsA4G*sstate22th)*a0[2] - state[22].thd*v25[1];
a25[3]=state[22].thdd + a0[3];
a25[4]=-(DHD1*(cstate22th*rsA4G + rcA4G*sstate22th)*a0[1]) + DHD1*(cstate22th*rcA4G - rsA4G*sstate22th)*a0[2] + (A4X*(cstate22th*rsA4G + rcA4G*sstate22th) - A4Y*(cstate22th*rcA4G - rsA4G*sstate22th))*a0[3] + (cstate22th*rcA4G - rsA4G*sstate22th)*a0[4] + (cstate22th*rsA4G + rcA4G*sstate22th)*a0[5] + state[22].thd*v25[5];
a25[5]=-(DHD1*(cstate22th*rcA4G - rsA4G*sstate22th)*a0[1]) + DHD1*(-(cstate22th*rsA4G) - rcA4G*sstate22th)*a0[2] + (-(A4Y*(-(cstate22th*rsA4G) - rcA4G*sstate22th)) + A4X*(cstate22th*rcA4G - rsA4G*sstate22th))*a0[3] + (-(cstate22th*rsA4G) - rcA4G*sstate22th)*a0[4] + (cstate22th*rcA4G - rsA4G*sstate22th)*a0[5] - state[22].thd*v25[4];
a25[6]=A4Y*a0[1] - A4X*a0[2] + a0[6];

a26[1]=cstate23th*a25[1] - sstate23th*a25[3] + state[23].thd*v26[2];
a26[2]=-(sstate23th*a25[1]) - cstate23th*a25[3] - state[23].thd*v26[1];
a26[3]=state[23].thdd + a25[2];
a26[4]=cstate23th*a25[4] - sstate23th*a25[6] + state[23].thd*v26[5];
a26[5]=-(sstate23th*a25[4]) - cstate23th*a25[6] - state[23].thd*v26[4];
a26[6]=a25[5];

a27[1]=cstate24th*a26[1] + sstate24th*a26[3] + state[24].thd*v27[2];
a27[2]=-(sstate24th*a26[1]) + cstate24th*a26[3] - state[24].thd*v27[1];
a27[3]=state[24].thdd - a26[2];
a27[4]=-(DHD3*sstate24th*a26[1]) + cstate24th*DHD3*a26[3] + cstate24th*a26[4] + sstate24th*a26[6] + state[24].thd*v27[5];
a27[5]=-(cstate24th*DHD3*a26[1]) - DHD3*sstate24th*a26[3] - sstate24th*a26[4] + cstate24th*a26[6] - state[24].thd*v27[4];
a27[6]=-a26[5];

a28[1]=cstate25th*a27[1] + sstate25th*a27[3] + state[25].thd*v28[2];
a28[2]=-(sstate25th*a27[1]) + cstate25th*a27[3] - state[25].thd*v28[1];
a28[3]=state[25].thdd - a27[2];
a28[4]=-(DHA4*sstate25th*a27[2]) + cstate25th*a27[4] + sstate25th*a27[6] + state[25].thd*v28[5];
a28[5]=-(cstate25th*DHA4*a27[2]) - sstate25th*a27[4] + cstate25th*a27[6] - state[25].thd*v28[4];
a28[6]=-(DHA4*a27[3]) - a27[5];

a29[1]=cstate26th*a28[1] - sstate26th*a28[3] + state[26].thd*v29[2];
a29[2]=-(sstate26th*a28[1]) - cstate26th*a28[3] - state[26].thd*v29[1];
a29[3]=state[26].thdd + a28[2];
a29[4]=-(DHD5*sstate26th*a28[1]) + DHA5*sstate26th*a28[2] - cstate26th*DHD5*a28[3] + cstate26th*a28[4] - sstate26th*a28[6] + state[26].thd*v29[5];
a29[5]=-(cstate26th*DHD5*a28[1]) + cstate26th*DHA5*a28[2] + DHD5*sstate26th*a28[3] - sstate26th*a28[4] - cstate26th*a28[6] - state[26].thd*v29[4];
a29[6]=DHA5*a28[3] + a28[5];

a30[1]=cstate27th*a29[1] + sstate27th*a29[3] + state[27].thd*v30[2];
a30[2]=-(sstate27th*a29[1]) + cstate27th*a29[3] - state[27].thd*v30[1];
a30[3]=state[27].thdd - a29[2];
a30[4]=cstate27th*a29[4] + sstate27th*a29[6] + state[27].thd*v30[5];
a30[5]=-(sstate27th*a29[4]) + cstate27th*a29[6] - state[27].thd*v30[4];
a30[6]=-a29[5];

a31[1]=cstate28th*a30[1] + sstate28th*a30[3] + state[28].thd*v31[2];
a31[2]=-(sstate28th*a30[1]) + cstate28th*a30[3] - state[28].thd*v31[1];
a31[3]=state[28].thdd - a30[2];
a31[4]=-(DHA7*sstate28th*a30[2]) + cstate28th*a30[4] + sstate28th*a30[6] + state[28].thd*v31[5];
a31[5]=-(cstate28th*DHA7*a30[2]) - sstate28th*a30[4] + cstate28th*a30[6] - state[28].thd*v31[4];
a31[6]=-(DHA7*a30[3]) - a30[5];

a32[1]=rceff4a2*rceff4a3*a31[1] + (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*a31[2] + (-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*a31[3];
a32[2]=-(rceff4a2*rseff4a3*a31[1]) + (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*a31[2] + (rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*a31[3];
a32[3]=rseff4a2*a31[1] - rceff4a2*rseff4a1*a31[2] + rceff4a1*rceff4a2*a31[3];
a32[4]=rceff4a2*rceff4a3*a31[4] + (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*a31[5] + (-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*a31[6] + a31[3]*((rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[1] - rceff4a2*rceff4a3*eff[4].x[2]) + a31[2]*(-((-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[1]) + rceff4a2*rceff4a3*eff[4].x[3]) + a31[1]*((-(rceff4a1*rceff4a3*rseff4a2) + rseff4a1*rseff4a3)*eff[4].x[2] - (rceff4a3*rseff4a1*rseff4a2 + rceff4a1*rseff4a3)*eff[4].x[3]);
a32[5]=-(rceff4a2*rseff4a3*a31[4]) + (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*a31[5] + (rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*a31[6] + a31[3]*((rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[1] + rceff4a2*rseff4a3*eff[4].x[2]) + a31[2]*(-((rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[1]) - rceff4a2*rseff4a3*eff[4].x[3]) + a31[1]*((rceff4a3*rseff4a1 + rceff4a1*rseff4a2*rseff4a3)*eff[4].x[2] - (rceff4a1*rceff4a3 - rseff4a1*rseff4a2*rseff4a3)*eff[4].x[3]);
a32[6]=rseff4a2*a31[4] - rceff4a2*rseff4a1*a31[5] + rceff4a1*rceff4a2*a31[6] + a31[3]*(-(rceff4a2*rseff4a1*eff[4].x[1]) - rseff4a2*eff[4].x[2]) + a31[1]*(rceff4a1*rceff4a2*eff[4].x[2] + rceff4a2*rseff4a1*eff[4].x[3]) + a31[2]*(-(rceff4a1*rceff4a2*eff[4].x[1]) + rseff4a2*eff[4].x[3]);


/* kinematic matrices */
bzero((void *)A,sizeof(double)*(32+1)*(6+1)*(N_RBD_PARMS+1));
A[0][1][1]=a0[4] - v0[3]*v0[5] + v0[2]*v0[6];
A[0][1][2]=-Power(v0[2],2) - Power(v0[3],2);
A[0][1][3]=-a0[3] + v0[1]*v0[2];
A[0][1][4]=a0[2] + v0[1]*v0[3];
A[0][1][5]=0;
A[0][1][6]=0;
A[0][1][7]=0;
A[0][1][8]=0;
A[0][1][9]=0;
A[0][1][10]=0;
A[0][1][11]=0;
A[0][1][12]=0;
A[0][1][13]=0;
A[0][1][14]=0;

A[0][2][1]=a0[5] + v0[3]*v0[4] - v0[1]*v0[6];
A[0][2][2]=a0[3] + v0[1]*v0[2];
A[0][2][3]=-Power(v0[1],2) - Power(v0[3],2);
A[0][2][4]=-a0[1] + v0[2]*v0[3];
A[0][2][5]=0;
A[0][2][6]=0;
A[0][2][7]=0;
A[0][2][8]=0;
A[0][2][9]=0;
A[0][2][10]=0;
A[0][2][11]=0;
A[0][2][12]=0;
A[0][2][13]=0;
A[0][2][14]=0;

A[0][3][1]=a0[6] - v0[2]*v0[4] + v0[1]*v0[5];
A[0][3][2]=-a0[2] + v0[1]*v0[3];
A[0][3][3]=a0[1] + v0[2]*v0[3];
A[0][3][4]=-Power(v0[1],2) - Power(v0[2],2);
A[0][3][5]=0;
A[0][3][6]=0;
A[0][3][7]=0;
A[0][3][8]=0;
A[0][3][9]=0;
A[0][3][10]=0;
A[0][3][11]=0;
A[0][3][12]=0;
A[0][3][13]=0;
A[0][3][14]=0;

A[0][4][1]=0;
A[0][4][2]=0;
A[0][4][3]=a0[6] - v0[2]*v0[4] + v0[1]*v0[5];
A[0][4][4]=-a0[5] - v0[3]*v0[4] + v0[1]*v0[6];
A[0][4][5]=a0[1];
A[0][4][6]=a0[2] - v0[1]*v0[3];
A[0][4][7]=a0[3] + v0[1]*v0[2];
A[0][4][8]=-(v0[2]*v0[3]);
A[0][4][9]=Power(v0[2],2) - Power(v0[3],2);
A[0][4][10]=v0[2]*v0[3];
A[0][4][11]=0;
A[0][4][12]=0;
A[0][4][13]=0;
A[0][4][14]=0;

A[0][5][1]=0;
A[0][5][2]=-a0[6] + v0[2]*v0[4] - v0[1]*v0[5];
A[0][5][3]=0;
A[0][5][4]=a0[4] - v0[3]*v0[5] + v0[2]*v0[6];
A[0][5][5]=v0[1]*v0[3];
A[0][5][6]=a0[1] + v0[2]*v0[3];
A[0][5][7]=-Power(v0[1],2) + Power(v0[3],2);
A[0][5][8]=a0[2];
A[0][5][9]=a0[3] - v0[1]*v0[2];
A[0][5][10]=-(v0[1]*v0[3]);
A[0][5][11]=0;
A[0][5][12]=0;
A[0][5][13]=0;
A[0][5][14]=0;

A[0][6][1]=0;
A[0][6][2]=a0[5] + v0[3]*v0[4] - v0[1]*v0[6];
A[0][6][3]=-a0[4] + v0[3]*v0[5] - v0[2]*v0[6];
A[0][6][4]=0;
A[0][6][5]=-(v0[1]*v0[2]);
A[0][6][6]=Power(v0[1],2) - Power(v0[2],2);
A[0][6][7]=a0[1] - v0[2]*v0[3];
A[0][6][8]=v0[1]*v0[2];
A[0][6][9]=a0[2] + v0[1]*v0[3];
A[0][6][10]=a0[3];
A[0][6][11]=0;
A[0][6][12]=0;
A[0][6][13]=0;
A[0][6][14]=0;


A[1][1][1]=a1[4] - v1[3]*v1[5] + v1[2]*v1[6];
A[1][1][2]=-Power(v1[2],2) - Power(v1[3],2);
A[1][1][3]=-a1[3] + v1[1]*v1[2];
A[1][1][4]=a1[2] + v1[1]*v1[3];
A[1][1][5]=0;
A[1][1][6]=0;
A[1][1][7]=0;
A[1][1][8]=0;
A[1][1][9]=0;
A[1][1][10]=0;
A[1][1][11]=0;
A[1][1][12]=0;
A[1][1][13]=0;
A[1][1][14]=0;

A[1][2][1]=a1[5] + v1[3]*v1[4] - v1[1]*v1[6];
A[1][2][2]=a1[3] + v1[1]*v1[2];
A[1][2][3]=-Power(v1[1],2) - Power(v1[3],2);
A[1][2][4]=-a1[1] + v1[2]*v1[3];
A[1][2][5]=0;
A[1][2][6]=0;
A[1][2][7]=0;
A[1][2][8]=0;
A[1][2][9]=0;
A[1][2][10]=0;
A[1][2][11]=0;
A[1][2][12]=0;
A[1][2][13]=0;
A[1][2][14]=0;

A[1][3][1]=a1[6] - v1[2]*v1[4] + v1[1]*v1[5];
A[1][3][2]=-a1[2] + v1[1]*v1[3];
A[1][3][3]=a1[1] + v1[2]*v1[3];
A[1][3][4]=-Power(v1[1],2) - Power(v1[2],2);
A[1][3][5]=0;
A[1][3][6]=0;
A[1][3][7]=0;
A[1][3][8]=0;
A[1][3][9]=0;
A[1][3][10]=0;
A[1][3][11]=0;
A[1][3][12]=0;
A[1][3][13]=0;
A[1][3][14]=0;

A[1][4][1]=0;
A[1][4][2]=0;
A[1][4][3]=a1[6] - v1[2]*v1[4] + v1[1]*v1[5];
A[1][4][4]=-a1[5] - v1[3]*v1[4] + v1[1]*v1[6];
A[1][4][5]=a1[1];
A[1][4][6]=a1[2] - v1[1]*v1[3];
A[1][4][7]=a1[3] + v1[1]*v1[2];
A[1][4][8]=-(v1[2]*v1[3]);
A[1][4][9]=Power(v1[2],2) - Power(v1[3],2);
A[1][4][10]=v1[2]*v1[3];
A[1][4][11]=0;
A[1][4][12]=0;
A[1][4][13]=0;
A[1][4][14]=0;

A[1][5][1]=0;
A[1][5][2]=-a1[6] + v1[2]*v1[4] - v1[1]*v1[5];
A[1][5][3]=0;
A[1][5][4]=a1[4] - v1[3]*v1[5] + v1[2]*v1[6];
A[1][5][5]=v1[1]*v1[3];
A[1][5][6]=a1[1] + v1[2]*v1[3];
A[1][5][7]=-Power(v1[1],2) + Power(v1[3],2);
A[1][5][8]=a1[2];
A[1][5][9]=a1[3] - v1[1]*v1[2];
A[1][5][10]=-(v1[1]*v1[3]);
A[1][5][11]=0;
A[1][5][12]=0;
A[1][5][13]=0;
A[1][5][14]=0;

A[1][6][1]=0;
A[1][6][2]=a1[5] + v1[3]*v1[4] - v1[1]*v1[6];
A[1][6][3]=-a1[4] + v1[3]*v1[5] - v1[2]*v1[6];
A[1][6][4]=0;
A[1][6][5]=-(v1[1]*v1[2]);
A[1][6][6]=Power(v1[1],2) - Power(v1[2],2);
A[1][6][7]=a1[1] - v1[2]*v1[3];
A[1][6][8]=v1[1]*v1[2];
A[1][6][9]=a1[2] + v1[1]*v1[3];
A[1][6][10]=a1[3];
A[1][6][11]=0;
A[1][6][12]=0;
A[1][6][13]=0;
A[1][6][14]=0;


A[2][1][1]=a2[4] - v2[3]*v2[5] + v2[2]*v2[6];
A[2][1][2]=-Power(v2[2],2) - Power(v2[3],2);
A[2][1][3]=-a2[3] + v2[1]*v2[2];
A[2][1][4]=a2[2] + v2[1]*v2[3];
A[2][1][5]=0;
A[2][1][6]=0;
A[2][1][7]=0;
A[2][1][8]=0;
A[2][1][9]=0;
A[2][1][10]=0;
A[2][1][11]=0;
A[2][1][12]=0;
A[2][1][13]=0;
A[2][1][14]=0;

A[2][2][1]=a2[5] + v2[3]*v2[4] - v2[1]*v2[6];
A[2][2][2]=a2[3] + v2[1]*v2[2];
A[2][2][3]=-Power(v2[1],2) - Power(v2[3],2);
A[2][2][4]=-a2[1] + v2[2]*v2[3];
A[2][2][5]=0;
A[2][2][6]=0;
A[2][2][7]=0;
A[2][2][8]=0;
A[2][2][9]=0;
A[2][2][10]=0;
A[2][2][11]=0;
A[2][2][12]=0;
A[2][2][13]=0;
A[2][2][14]=0;

A[2][3][1]=a2[6] - v2[2]*v2[4] + v2[1]*v2[5];
A[2][3][2]=-a2[2] + v2[1]*v2[3];
A[2][3][3]=a2[1] + v2[2]*v2[3];
A[2][3][4]=-Power(v2[1],2) - Power(v2[2],2);
A[2][3][5]=0;
A[2][3][6]=0;
A[2][3][7]=0;
A[2][3][8]=0;
A[2][3][9]=0;
A[2][3][10]=0;
A[2][3][11]=0;
A[2][3][12]=0;
A[2][3][13]=0;
A[2][3][14]=0;

A[2][4][1]=0;
A[2][4][2]=0;
A[2][4][3]=a2[6] - v2[2]*v2[4] + v2[1]*v2[5];
A[2][4][4]=-a2[5] - v2[3]*v2[4] + v2[1]*v2[6];
A[2][4][5]=a2[1];
A[2][4][6]=a2[2] - v2[1]*v2[3];
A[2][4][7]=a2[3] + v2[1]*v2[2];
A[2][4][8]=-(v2[2]*v2[3]);
A[2][4][9]=Power(v2[2],2) - Power(v2[3],2);
A[2][4][10]=v2[2]*v2[3];
A[2][4][11]=0;
A[2][4][12]=0;
A[2][4][13]=0;
A[2][4][14]=0;

A[2][5][1]=0;
A[2][5][2]=-a2[6] + v2[2]*v2[4] - v2[1]*v2[5];
A[2][5][3]=0;
A[2][5][4]=a2[4] - v2[3]*v2[5] + v2[2]*v2[6];
A[2][5][5]=v2[1]*v2[3];
A[2][5][6]=a2[1] + v2[2]*v2[3];
A[2][5][7]=-Power(v2[1],2) + Power(v2[3],2);
A[2][5][8]=a2[2];
A[2][5][9]=a2[3] - v2[1]*v2[2];
A[2][5][10]=-(v2[1]*v2[3]);
A[2][5][11]=0;
A[2][5][12]=0;
A[2][5][13]=0;
A[2][5][14]=0;

A[2][6][1]=0;
A[2][6][2]=a2[5] + v2[3]*v2[4] - v2[1]*v2[6];
A[2][6][3]=-a2[4] + v2[3]*v2[5] - v2[2]*v2[6];
A[2][6][4]=0;
A[2][6][5]=-(v2[1]*v2[2]);
A[2][6][6]=Power(v2[1],2) - Power(v2[2],2);
A[2][6][7]=a2[1] - v2[2]*v2[3];
A[2][6][8]=v2[1]*v2[2];
A[2][6][9]=a2[2] + v2[1]*v2[3];
A[2][6][10]=a2[3];
A[2][6][11]=0;
A[2][6][12]=0;
A[2][6][13]=0;
A[2][6][14]=0;


A[3][1][1]=a3[4] - v3[3]*v3[5] + v3[2]*v3[6];
A[3][1][2]=-Power(v3[2],2) - Power(v3[3],2);
A[3][1][3]=-a3[3] + v3[1]*v3[2];
A[3][1][4]=a3[2] + v3[1]*v3[3];
A[3][1][5]=0;
A[3][1][6]=0;
A[3][1][7]=0;
A[3][1][8]=0;
A[3][1][9]=0;
A[3][1][10]=0;
A[3][1][11]=0;
A[3][1][12]=0;
A[3][1][13]=0;
A[3][1][14]=0;

A[3][2][1]=a3[5] + v3[3]*v3[4] - v3[1]*v3[6];
A[3][2][2]=a3[3] + v3[1]*v3[2];
A[3][2][3]=-Power(v3[1],2) - Power(v3[3],2);
A[3][2][4]=-a3[1] + v3[2]*v3[3];
A[3][2][5]=0;
A[3][2][6]=0;
A[3][2][7]=0;
A[3][2][8]=0;
A[3][2][9]=0;
A[3][2][10]=0;
A[3][2][11]=0;
A[3][2][12]=0;
A[3][2][13]=0;
A[3][2][14]=0;

A[3][3][1]=a3[6] - v3[2]*v3[4] + v3[1]*v3[5];
A[3][3][2]=-a3[2] + v3[1]*v3[3];
A[3][3][3]=a3[1] + v3[2]*v3[3];
A[3][3][4]=-Power(v3[1],2) - Power(v3[2],2);
A[3][3][5]=0;
A[3][3][6]=0;
A[3][3][7]=0;
A[3][3][8]=0;
A[3][3][9]=0;
A[3][3][10]=0;
A[3][3][11]=0;
A[3][3][12]=0;
A[3][3][13]=0;
A[3][3][14]=0;

A[3][4][1]=0;
A[3][4][2]=0;
A[3][4][3]=a3[6] - v3[2]*v3[4] + v3[1]*v3[5];
A[3][4][4]=-a3[5] - v3[3]*v3[4] + v3[1]*v3[6];
A[3][4][5]=a3[1];
A[3][4][6]=a3[2] - v3[1]*v3[3];
A[3][4][7]=a3[3] + v3[1]*v3[2];
A[3][4][8]=-(v3[2]*v3[3]);
A[3][4][9]=Power(v3[2],2) - Power(v3[3],2);
A[3][4][10]=v3[2]*v3[3];
A[3][4][11]=0;
A[3][4][12]=0;
A[3][4][13]=0;
A[3][4][14]=0;

A[3][5][1]=0;
A[3][5][2]=-a3[6] + v3[2]*v3[4] - v3[1]*v3[5];
A[3][5][3]=0;
A[3][5][4]=a3[4] - v3[3]*v3[5] + v3[2]*v3[6];
A[3][5][5]=v3[1]*v3[3];
A[3][5][6]=a3[1] + v3[2]*v3[3];
A[3][5][7]=-Power(v3[1],2) + Power(v3[3],2);
A[3][5][8]=a3[2];
A[3][5][9]=a3[3] - v3[1]*v3[2];
A[3][5][10]=-(v3[1]*v3[3]);
A[3][5][11]=0;
A[3][5][12]=0;
A[3][5][13]=0;
A[3][5][14]=0;

A[3][6][1]=0;
A[3][6][2]=a3[5] + v3[3]*v3[4] - v3[1]*v3[6];
A[3][6][3]=-a3[4] + v3[3]*v3[5] - v3[2]*v3[6];
A[3][6][4]=0;
A[3][6][5]=-(v3[1]*v3[2]);
A[3][6][6]=Power(v3[1],2) - Power(v3[2],2);
A[3][6][7]=a3[1] - v3[2]*v3[3];
A[3][6][8]=v3[1]*v3[2];
A[3][6][9]=a3[2] + v3[1]*v3[3];
A[3][6][10]=a3[3];
A[3][6][11]=0;
A[3][6][12]=0;
A[3][6][13]=0;
A[3][6][14]=0;


A[4][1][1]=a4[4] - v4[3]*v4[5] + v4[2]*v4[6];
A[4][1][2]=-Power(v4[2],2) - Power(v4[3],2);
A[4][1][3]=-a4[3] + v4[1]*v4[2];
A[4][1][4]=a4[2] + v4[1]*v4[3];
A[4][1][5]=0;
A[4][1][6]=0;
A[4][1][7]=0;
A[4][1][8]=0;
A[4][1][9]=0;
A[4][1][10]=0;
A[4][1][11]=0;
A[4][1][12]=0;
A[4][1][13]=0;
A[4][1][14]=0;

A[4][2][1]=a4[5] + v4[3]*v4[4] - v4[1]*v4[6];
A[4][2][2]=a4[3] + v4[1]*v4[2];
A[4][2][3]=-Power(v4[1],2) - Power(v4[3],2);
A[4][2][4]=-a4[1] + v4[2]*v4[3];
A[4][2][5]=0;
A[4][2][6]=0;
A[4][2][7]=0;
A[4][2][8]=0;
A[4][2][9]=0;
A[4][2][10]=0;
A[4][2][11]=0;
A[4][2][12]=0;
A[4][2][13]=0;
A[4][2][14]=0;

A[4][3][1]=a4[6] - v4[2]*v4[4] + v4[1]*v4[5];
A[4][3][2]=-a4[2] + v4[1]*v4[3];
A[4][3][3]=a4[1] + v4[2]*v4[3];
A[4][3][4]=-Power(v4[1],2) - Power(v4[2],2);
A[4][3][5]=0;
A[4][3][6]=0;
A[4][3][7]=0;
A[4][3][8]=0;
A[4][3][9]=0;
A[4][3][10]=0;
A[4][3][11]=0;
A[4][3][12]=0;
A[4][3][13]=0;
A[4][3][14]=0;

A[4][4][1]=0;
A[4][4][2]=0;
A[4][4][3]=a4[6] - v4[2]*v4[4] + v4[1]*v4[5];
A[4][4][4]=-a4[5] - v4[3]*v4[4] + v4[1]*v4[6];
A[4][4][5]=a4[1];
A[4][4][6]=a4[2] - v4[1]*v4[3];
A[4][4][7]=a4[3] + v4[1]*v4[2];
A[4][4][8]=-(v4[2]*v4[3]);
A[4][4][9]=Power(v4[2],2) - Power(v4[3],2);
A[4][4][10]=v4[2]*v4[3];
A[4][4][11]=0;
A[4][4][12]=0;
A[4][4][13]=0;
A[4][4][14]=0;

A[4][5][1]=0;
A[4][5][2]=-a4[6] + v4[2]*v4[4] - v4[1]*v4[5];
A[4][5][3]=0;
A[4][5][4]=a4[4] - v4[3]*v4[5] + v4[2]*v4[6];
A[4][5][5]=v4[1]*v4[3];
A[4][5][6]=a4[1] + v4[2]*v4[3];
A[4][5][7]=-Power(v4[1],2) + Power(v4[3],2);
A[4][5][8]=a4[2];
A[4][5][9]=a4[3] - v4[1]*v4[2];
A[4][5][10]=-(v4[1]*v4[3]);
A[4][5][11]=0;
A[4][5][12]=0;
A[4][5][13]=0;
A[4][5][14]=0;

A[4][6][1]=0;
A[4][6][2]=a4[5] + v4[3]*v4[4] - v4[1]*v4[6];
A[4][6][3]=-a4[4] + v4[3]*v4[5] - v4[2]*v4[6];
A[4][6][4]=0;
A[4][6][5]=-(v4[1]*v4[2]);
A[4][6][6]=Power(v4[1],2) - Power(v4[2],2);
A[4][6][7]=a4[1] - v4[2]*v4[3];
A[4][6][8]=v4[1]*v4[2];
A[4][6][9]=a4[2] + v4[1]*v4[3];
A[4][6][10]=a4[3];
A[4][6][11]=0;
A[4][6][12]=0;
A[4][6][13]=0;
A[4][6][14]=0;


A[5][1][1]=a5[4] - v5[3]*v5[5] + v5[2]*v5[6];
A[5][1][2]=-Power(v5[2],2) - Power(v5[3],2);
A[5][1][3]=-a5[3] + v5[1]*v5[2];
A[5][1][4]=a5[2] + v5[1]*v5[3];
A[5][1][5]=0;
A[5][1][6]=0;
A[5][1][7]=0;
A[5][1][8]=0;
A[5][1][9]=0;
A[5][1][10]=0;
A[5][1][11]=0;
A[5][1][12]=0;
A[5][1][13]=0;
A[5][1][14]=0;

A[5][2][1]=a5[5] + v5[3]*v5[4] - v5[1]*v5[6];
A[5][2][2]=a5[3] + v5[1]*v5[2];
A[5][2][3]=-Power(v5[1],2) - Power(v5[3],2);
A[5][2][4]=-a5[1] + v5[2]*v5[3];
A[5][2][5]=0;
A[5][2][6]=0;
A[5][2][7]=0;
A[5][2][8]=0;
A[5][2][9]=0;
A[5][2][10]=0;
A[5][2][11]=0;
A[5][2][12]=0;
A[5][2][13]=0;
A[5][2][14]=0;

A[5][3][1]=a5[6] - v5[2]*v5[4] + v5[1]*v5[5];
A[5][3][2]=-a5[2] + v5[1]*v5[3];
A[5][3][3]=a5[1] + v5[2]*v5[3];
A[5][3][4]=-Power(v5[1],2) - Power(v5[2],2);
A[5][3][5]=0;
A[5][3][6]=0;
A[5][3][7]=0;
A[5][3][8]=0;
A[5][3][9]=0;
A[5][3][10]=0;
A[5][3][11]=0;
A[5][3][12]=0;
A[5][3][13]=0;
A[5][3][14]=0;

A[5][4][1]=0;
A[5][4][2]=0;
A[5][4][3]=a5[6] - v5[2]*v5[4] + v5[1]*v5[5];
A[5][4][4]=-a5[5] - v5[3]*v5[4] + v5[1]*v5[6];
A[5][4][5]=a5[1];
A[5][4][6]=a5[2] - v5[1]*v5[3];
A[5][4][7]=a5[3] + v5[1]*v5[2];
A[5][4][8]=-(v5[2]*v5[3]);
A[5][4][9]=Power(v5[2],2) - Power(v5[3],2);
A[5][4][10]=v5[2]*v5[3];
A[5][4][11]=0;
A[5][4][12]=0;
A[5][4][13]=0;
A[5][4][14]=0;

A[5][5][1]=0;
A[5][5][2]=-a5[6] + v5[2]*v5[4] - v5[1]*v5[5];
A[5][5][3]=0;
A[5][5][4]=a5[4] - v5[3]*v5[5] + v5[2]*v5[6];
A[5][5][5]=v5[1]*v5[3];
A[5][5][6]=a5[1] + v5[2]*v5[3];
A[5][5][7]=-Power(v5[1],2) + Power(v5[3],2);
A[5][5][8]=a5[2];
A[5][5][9]=a5[3] - v5[1]*v5[2];
A[5][5][10]=-(v5[1]*v5[3]);
A[5][5][11]=0;
A[5][5][12]=0;
A[5][5][13]=0;
A[5][5][14]=0;

A[5][6][1]=0;
A[5][6][2]=a5[5] + v5[3]*v5[4] - v5[1]*v5[6];
A[5][6][3]=-a5[4] + v5[3]*v5[5] - v5[2]*v5[6];
A[5][6][4]=0;
A[5][6][5]=-(v5[1]*v5[2]);
A[5][6][6]=Power(v5[1],2) - Power(v5[2],2);
A[5][6][7]=a5[1] - v5[2]*v5[3];
A[5][6][8]=v5[1]*v5[2];
A[5][6][9]=a5[2] + v5[1]*v5[3];
A[5][6][10]=a5[3];
A[5][6][11]=0;
A[5][6][12]=0;
A[5][6][13]=0;
A[5][6][14]=0;


A[6][1][1]=a6[4] - v6[3]*v6[5] + v6[2]*v6[6];
A[6][1][2]=-Power(v6[2],2) - Power(v6[3],2);
A[6][1][3]=-a6[3] + v6[1]*v6[2];
A[6][1][4]=a6[2] + v6[1]*v6[3];
A[6][1][5]=0;
A[6][1][6]=0;
A[6][1][7]=0;
A[6][1][8]=0;
A[6][1][9]=0;
A[6][1][10]=0;
A[6][1][11]=0;
A[6][1][12]=0;
A[6][1][13]=0;
A[6][1][14]=0;

A[6][2][1]=a6[5] + v6[3]*v6[4] - v6[1]*v6[6];
A[6][2][2]=a6[3] + v6[1]*v6[2];
A[6][2][3]=-Power(v6[1],2) - Power(v6[3],2);
A[6][2][4]=-a6[1] + v6[2]*v6[3];
A[6][2][5]=0;
A[6][2][6]=0;
A[6][2][7]=0;
A[6][2][8]=0;
A[6][2][9]=0;
A[6][2][10]=0;
A[6][2][11]=0;
A[6][2][12]=0;
A[6][2][13]=0;
A[6][2][14]=0;

A[6][3][1]=a6[6] - v6[2]*v6[4] + v6[1]*v6[5];
A[6][3][2]=-a6[2] + v6[1]*v6[3];
A[6][3][3]=a6[1] + v6[2]*v6[3];
A[6][3][4]=-Power(v6[1],2) - Power(v6[2],2);
A[6][3][5]=0;
A[6][3][6]=0;
A[6][3][7]=0;
A[6][3][8]=0;
A[6][3][9]=0;
A[6][3][10]=0;
A[6][3][11]=0;
A[6][3][12]=0;
A[6][3][13]=0;
A[6][3][14]=0;

A[6][4][1]=0;
A[6][4][2]=0;
A[6][4][3]=a6[6] - v6[2]*v6[4] + v6[1]*v6[5];
A[6][4][4]=-a6[5] - v6[3]*v6[4] + v6[1]*v6[6];
A[6][4][5]=a6[1];
A[6][4][6]=a6[2] - v6[1]*v6[3];
A[6][4][7]=a6[3] + v6[1]*v6[2];
A[6][4][8]=-(v6[2]*v6[3]);
A[6][4][9]=Power(v6[2],2) - Power(v6[3],2);
A[6][4][10]=v6[2]*v6[3];
A[6][4][11]=0;
A[6][4][12]=0;
A[6][4][13]=0;
A[6][4][14]=0;

A[6][5][1]=0;
A[6][5][2]=-a6[6] + v6[2]*v6[4] - v6[1]*v6[5];
A[6][5][3]=0;
A[6][5][4]=a6[4] - v6[3]*v6[5] + v6[2]*v6[6];
A[6][5][5]=v6[1]*v6[3];
A[6][5][6]=a6[1] + v6[2]*v6[3];
A[6][5][7]=-Power(v6[1],2) + Power(v6[3],2);
A[6][5][8]=a6[2];
A[6][5][9]=a6[3] - v6[1]*v6[2];
A[6][5][10]=-(v6[1]*v6[3]);
A[6][5][11]=0;
A[6][5][12]=0;
A[6][5][13]=0;
A[6][5][14]=0;

A[6][6][1]=0;
A[6][6][2]=a6[5] + v6[3]*v6[4] - v6[1]*v6[6];
A[6][6][3]=-a6[4] + v6[3]*v6[5] - v6[2]*v6[6];
A[6][6][4]=0;
A[6][6][5]=-(v6[1]*v6[2]);
A[6][6][6]=Power(v6[1],2) - Power(v6[2],2);
A[6][6][7]=a6[1] - v6[2]*v6[3];
A[6][6][8]=v6[1]*v6[2];
A[6][6][9]=a6[2] + v6[1]*v6[3];
A[6][6][10]=a6[3];
A[6][6][11]=0;
A[6][6][12]=0;
A[6][6][13]=0;
A[6][6][14]=0;


A[7][1][1]=a7[4] - v7[3]*v7[5] + v7[2]*v7[6];
A[7][1][2]=-Power(v7[2],2) - Power(v7[3],2);
A[7][1][3]=-a7[3] + v7[1]*v7[2];
A[7][1][4]=a7[2] + v7[1]*v7[3];
A[7][1][5]=0;
A[7][1][6]=0;
A[7][1][7]=0;
A[7][1][8]=0;
A[7][1][9]=0;
A[7][1][10]=0;
A[7][1][11]=0;
A[7][1][12]=0;
A[7][1][13]=0;
A[7][1][14]=0;

A[7][2][1]=a7[5] + v7[3]*v7[4] - v7[1]*v7[6];
A[7][2][2]=a7[3] + v7[1]*v7[2];
A[7][2][3]=-Power(v7[1],2) - Power(v7[3],2);
A[7][2][4]=-a7[1] + v7[2]*v7[3];
A[7][2][5]=0;
A[7][2][6]=0;
A[7][2][7]=0;
A[7][2][8]=0;
A[7][2][9]=0;
A[7][2][10]=0;
A[7][2][11]=0;
A[7][2][12]=0;
A[7][2][13]=0;
A[7][2][14]=0;

A[7][3][1]=a7[6] - v7[2]*v7[4] + v7[1]*v7[5];
A[7][3][2]=-a7[2] + v7[1]*v7[3];
A[7][3][3]=a7[1] + v7[2]*v7[3];
A[7][3][4]=-Power(v7[1],2) - Power(v7[2],2);
A[7][3][5]=0;
A[7][3][6]=0;
A[7][3][7]=0;
A[7][3][8]=0;
A[7][3][9]=0;
A[7][3][10]=0;
A[7][3][11]=0;
A[7][3][12]=0;
A[7][3][13]=0;
A[7][3][14]=0;

A[7][4][1]=0;
A[7][4][2]=0;
A[7][4][3]=a7[6] - v7[2]*v7[4] + v7[1]*v7[5];
A[7][4][4]=-a7[5] - v7[3]*v7[4] + v7[1]*v7[6];
A[7][4][5]=a7[1];
A[7][4][6]=a7[2] - v7[1]*v7[3];
A[7][4][7]=a7[3] + v7[1]*v7[2];
A[7][4][8]=-(v7[2]*v7[3]);
A[7][4][9]=Power(v7[2],2) - Power(v7[3],2);
A[7][4][10]=v7[2]*v7[3];
A[7][4][11]=0;
A[7][4][12]=0;
A[7][4][13]=0;
A[7][4][14]=0;

A[7][5][1]=0;
A[7][5][2]=-a7[6] + v7[2]*v7[4] - v7[1]*v7[5];
A[7][5][3]=0;
A[7][5][4]=a7[4] - v7[3]*v7[5] + v7[2]*v7[6];
A[7][5][5]=v7[1]*v7[3];
A[7][5][6]=a7[1] + v7[2]*v7[3];
A[7][5][7]=-Power(v7[1],2) + Power(v7[3],2);
A[7][5][8]=a7[2];
A[7][5][9]=a7[3] - v7[1]*v7[2];
A[7][5][10]=-(v7[1]*v7[3]);
A[7][5][11]=0;
A[7][5][12]=0;
A[7][5][13]=0;
A[7][5][14]=0;

A[7][6][1]=0;
A[7][6][2]=a7[5] + v7[3]*v7[4] - v7[1]*v7[6];
A[7][6][3]=-a7[4] + v7[3]*v7[5] - v7[2]*v7[6];
A[7][6][4]=0;
A[7][6][5]=-(v7[1]*v7[2]);
A[7][6][6]=Power(v7[1],2) - Power(v7[2],2);
A[7][6][7]=a7[1] - v7[2]*v7[3];
A[7][6][8]=v7[1]*v7[2];
A[7][6][9]=a7[2] + v7[1]*v7[3];
A[7][6][10]=a7[3];
A[7][6][11]=0;
A[7][6][12]=0;
A[7][6][13]=0;
A[7][6][14]=0;


A[8][1][1]=a8[4] - v8[3]*v8[5] + v8[2]*v8[6];
A[8][1][2]=-Power(v8[2],2) - Power(v8[3],2);
A[8][1][3]=-a8[3] + v8[1]*v8[2];
A[8][1][4]=a8[2] + v8[1]*v8[3];
A[8][1][5]=0;
A[8][1][6]=0;
A[8][1][7]=0;
A[8][1][8]=0;
A[8][1][9]=0;
A[8][1][10]=0;
A[8][1][11]=0;
A[8][1][12]=0;
A[8][1][13]=0;
A[8][1][14]=0;

A[8][2][1]=a8[5] + v8[3]*v8[4] - v8[1]*v8[6];
A[8][2][2]=a8[3] + v8[1]*v8[2];
A[8][2][3]=-Power(v8[1],2) - Power(v8[3],2);
A[8][2][4]=-a8[1] + v8[2]*v8[3];
A[8][2][5]=0;
A[8][2][6]=0;
A[8][2][7]=0;
A[8][2][8]=0;
A[8][2][9]=0;
A[8][2][10]=0;
A[8][2][11]=0;
A[8][2][12]=0;
A[8][2][13]=0;
A[8][2][14]=0;

A[8][3][1]=a8[6] - v8[2]*v8[4] + v8[1]*v8[5];
A[8][3][2]=-a8[2] + v8[1]*v8[3];
A[8][3][3]=a8[1] + v8[2]*v8[3];
A[8][3][4]=-Power(v8[1],2) - Power(v8[2],2);
A[8][3][5]=0;
A[8][3][6]=0;
A[8][3][7]=0;
A[8][3][8]=0;
A[8][3][9]=0;
A[8][3][10]=0;
A[8][3][11]=0;
A[8][3][12]=0;
A[8][3][13]=0;
A[8][3][14]=0;

A[8][4][1]=0;
A[8][4][2]=0;
A[8][4][3]=a8[6] - v8[2]*v8[4] + v8[1]*v8[5];
A[8][4][4]=-a8[5] - v8[3]*v8[4] + v8[1]*v8[6];
A[8][4][5]=a8[1];
A[8][4][6]=a8[2] - v8[1]*v8[3];
A[8][4][7]=a8[3] + v8[1]*v8[2];
A[8][4][8]=-(v8[2]*v8[3]);
A[8][4][9]=Power(v8[2],2) - Power(v8[3],2);
A[8][4][10]=v8[2]*v8[3];
A[8][4][11]=0;
A[8][4][12]=0;
A[8][4][13]=0;
A[8][4][14]=0;

A[8][5][1]=0;
A[8][5][2]=-a8[6] + v8[2]*v8[4] - v8[1]*v8[5];
A[8][5][3]=0;
A[8][5][4]=a8[4] - v8[3]*v8[5] + v8[2]*v8[6];
A[8][5][5]=v8[1]*v8[3];
A[8][5][6]=a8[1] + v8[2]*v8[3];
A[8][5][7]=-Power(v8[1],2) + Power(v8[3],2);
A[8][5][8]=a8[2];
A[8][5][9]=a8[3] - v8[1]*v8[2];
A[8][5][10]=-(v8[1]*v8[3]);
A[8][5][11]=0;
A[8][5][12]=0;
A[8][5][13]=0;
A[8][5][14]=0;

A[8][6][1]=0;
A[8][6][2]=a8[5] + v8[3]*v8[4] - v8[1]*v8[6];
A[8][6][3]=-a8[4] + v8[3]*v8[5] - v8[2]*v8[6];
A[8][6][4]=0;
A[8][6][5]=-(v8[1]*v8[2]);
A[8][6][6]=Power(v8[1],2) - Power(v8[2],2);
A[8][6][7]=a8[1] - v8[2]*v8[3];
A[8][6][8]=v8[1]*v8[2];
A[8][6][9]=a8[2] + v8[1]*v8[3];
A[8][6][10]=a8[3];
A[8][6][11]=0;
A[8][6][12]=0;
A[8][6][13]=0;
A[8][6][14]=0;


A[9][1][1]=a9[4] - v9[3]*v9[5] + v9[2]*v9[6];
A[9][1][2]=-Power(v9[2],2) - Power(v9[3],2);
A[9][1][3]=-a9[3] + v9[1]*v9[2];
A[9][1][4]=a9[2] + v9[1]*v9[3];
A[9][1][5]=0;
A[9][1][6]=0;
A[9][1][7]=0;
A[9][1][8]=0;
A[9][1][9]=0;
A[9][1][10]=0;
A[9][1][11]=0;
A[9][1][12]=0;
A[9][1][13]=0;
A[9][1][14]=0;

A[9][2][1]=a9[5] + v9[3]*v9[4] - v9[1]*v9[6];
A[9][2][2]=a9[3] + v9[1]*v9[2];
A[9][2][3]=-Power(v9[1],2) - Power(v9[3],2);
A[9][2][4]=-a9[1] + v9[2]*v9[3];
A[9][2][5]=0;
A[9][2][6]=0;
A[9][2][7]=0;
A[9][2][8]=0;
A[9][2][9]=0;
A[9][2][10]=0;
A[9][2][11]=0;
A[9][2][12]=0;
A[9][2][13]=0;
A[9][2][14]=0;

A[9][3][1]=a9[6] - v9[2]*v9[4] + v9[1]*v9[5];
A[9][3][2]=-a9[2] + v9[1]*v9[3];
A[9][3][3]=a9[1] + v9[2]*v9[3];
A[9][3][4]=-Power(v9[1],2) - Power(v9[2],2);
A[9][3][5]=0;
A[9][3][6]=0;
A[9][3][7]=0;
A[9][3][8]=0;
A[9][3][9]=0;
A[9][3][10]=0;
A[9][3][11]=0;
A[9][3][12]=0;
A[9][3][13]=0;
A[9][3][14]=0;

A[9][4][1]=0;
A[9][4][2]=0;
A[9][4][3]=a9[6] - v9[2]*v9[4] + v9[1]*v9[5];
A[9][4][4]=-a9[5] - v9[3]*v9[4] + v9[1]*v9[6];
A[9][4][5]=a9[1];
A[9][4][6]=a9[2] - v9[1]*v9[3];
A[9][4][7]=a9[3] + v9[1]*v9[2];
A[9][4][8]=-(v9[2]*v9[3]);
A[9][4][9]=Power(v9[2],2) - Power(v9[3],2);
A[9][4][10]=v9[2]*v9[3];
A[9][4][11]=0;
A[9][4][12]=0;
A[9][4][13]=0;
A[9][4][14]=0;

A[9][5][1]=0;
A[9][5][2]=-a9[6] + v9[2]*v9[4] - v9[1]*v9[5];
A[9][5][3]=0;
A[9][5][4]=a9[4] - v9[3]*v9[5] + v9[2]*v9[6];
A[9][5][5]=v9[1]*v9[3];
A[9][5][6]=a9[1] + v9[2]*v9[3];
A[9][5][7]=-Power(v9[1],2) + Power(v9[3],2);
A[9][5][8]=a9[2];
A[9][5][9]=a9[3] - v9[1]*v9[2];
A[9][5][10]=-(v9[1]*v9[3]);
A[9][5][11]=0;
A[9][5][12]=0;
A[9][5][13]=0;
A[9][5][14]=0;

A[9][6][1]=0;
A[9][6][2]=a9[5] + v9[3]*v9[4] - v9[1]*v9[6];
A[9][6][3]=-a9[4] + v9[3]*v9[5] - v9[2]*v9[6];
A[9][6][4]=0;
A[9][6][5]=-(v9[1]*v9[2]);
A[9][6][6]=Power(v9[1],2) - Power(v9[2],2);
A[9][6][7]=a9[1] - v9[2]*v9[3];
A[9][6][8]=v9[1]*v9[2];
A[9][6][9]=a9[2] + v9[1]*v9[3];
A[9][6][10]=a9[3];
A[9][6][11]=0;
A[9][6][12]=0;
A[9][6][13]=0;
A[9][6][14]=0;


A[10][1][1]=a10[4] - v10[3]*v10[5] + v10[2]*v10[6];
A[10][1][2]=-Power(v10[2],2) - Power(v10[3],2);
A[10][1][3]=-a10[3] + v10[1]*v10[2];
A[10][1][4]=a10[2] + v10[1]*v10[3];
A[10][1][5]=0;
A[10][1][6]=0;
A[10][1][7]=0;
A[10][1][8]=0;
A[10][1][9]=0;
A[10][1][10]=0;
A[10][1][11]=0;
A[10][1][12]=0;
A[10][1][13]=0;
A[10][1][14]=0;

A[10][2][1]=a10[5] + v10[3]*v10[4] - v10[1]*v10[6];
A[10][2][2]=a10[3] + v10[1]*v10[2];
A[10][2][3]=-Power(v10[1],2) - Power(v10[3],2);
A[10][2][4]=-a10[1] + v10[2]*v10[3];
A[10][2][5]=0;
A[10][2][6]=0;
A[10][2][7]=0;
A[10][2][8]=0;
A[10][2][9]=0;
A[10][2][10]=0;
A[10][2][11]=0;
A[10][2][12]=0;
A[10][2][13]=0;
A[10][2][14]=0;

A[10][3][1]=a10[6] - v10[2]*v10[4] + v10[1]*v10[5];
A[10][3][2]=-a10[2] + v10[1]*v10[3];
A[10][3][3]=a10[1] + v10[2]*v10[3];
A[10][3][4]=-Power(v10[1],2) - Power(v10[2],2);
A[10][3][5]=0;
A[10][3][6]=0;
A[10][3][7]=0;
A[10][3][8]=0;
A[10][3][9]=0;
A[10][3][10]=0;
A[10][3][11]=0;
A[10][3][12]=0;
A[10][3][13]=0;
A[10][3][14]=0;

A[10][4][1]=0;
A[10][4][2]=0;
A[10][4][3]=a10[6] - v10[2]*v10[4] + v10[1]*v10[5];
A[10][4][4]=-a10[5] - v10[3]*v10[4] + v10[1]*v10[6];
A[10][4][5]=a10[1];
A[10][4][6]=a10[2] - v10[1]*v10[3];
A[10][4][7]=a10[3] + v10[1]*v10[2];
A[10][4][8]=-(v10[2]*v10[3]);
A[10][4][9]=Power(v10[2],2) - Power(v10[3],2);
A[10][4][10]=v10[2]*v10[3];
A[10][4][11]=0;
A[10][4][12]=0;
A[10][4][13]=0;
A[10][4][14]=0;

A[10][5][1]=0;
A[10][5][2]=-a10[6] + v10[2]*v10[4] - v10[1]*v10[5];
A[10][5][3]=0;
A[10][5][4]=a10[4] - v10[3]*v10[5] + v10[2]*v10[6];
A[10][5][5]=v10[1]*v10[3];
A[10][5][6]=a10[1] + v10[2]*v10[3];
A[10][5][7]=-Power(v10[1],2) + Power(v10[3],2);
A[10][5][8]=a10[2];
A[10][5][9]=a10[3] - v10[1]*v10[2];
A[10][5][10]=-(v10[1]*v10[3]);
A[10][5][11]=0;
A[10][5][12]=0;
A[10][5][13]=0;
A[10][5][14]=0;

A[10][6][1]=0;
A[10][6][2]=a10[5] + v10[3]*v10[4] - v10[1]*v10[6];
A[10][6][3]=-a10[4] + v10[3]*v10[5] - v10[2]*v10[6];
A[10][6][4]=0;
A[10][6][5]=-(v10[1]*v10[2]);
A[10][6][6]=Power(v10[1],2) - Power(v10[2],2);
A[10][6][7]=a10[1] - v10[2]*v10[3];
A[10][6][8]=v10[1]*v10[2];
A[10][6][9]=a10[2] + v10[1]*v10[3];
A[10][6][10]=a10[3];
A[10][6][11]=0;
A[10][6][12]=0;
A[10][6][13]=0;
A[10][6][14]=0;


A[11][1][1]=a11[4] - v11[3]*v11[5] + v11[2]*v11[6];
A[11][1][2]=-Power(v11[2],2) - Power(v11[3],2);
A[11][1][3]=-a11[3] + v11[1]*v11[2];
A[11][1][4]=a11[2] + v11[1]*v11[3];
A[11][1][5]=0;
A[11][1][6]=0;
A[11][1][7]=0;
A[11][1][8]=0;
A[11][1][9]=0;
A[11][1][10]=0;
A[11][1][11]=0;
A[11][1][12]=0;
A[11][1][13]=0;
A[11][1][14]=0;

A[11][2][1]=a11[5] + v11[3]*v11[4] - v11[1]*v11[6];
A[11][2][2]=a11[3] + v11[1]*v11[2];
A[11][2][3]=-Power(v11[1],2) - Power(v11[3],2);
A[11][2][4]=-a11[1] + v11[2]*v11[3];
A[11][2][5]=0;
A[11][2][6]=0;
A[11][2][7]=0;
A[11][2][8]=0;
A[11][2][9]=0;
A[11][2][10]=0;
A[11][2][11]=0;
A[11][2][12]=0;
A[11][2][13]=0;
A[11][2][14]=0;

A[11][3][1]=a11[6] - v11[2]*v11[4] + v11[1]*v11[5];
A[11][3][2]=-a11[2] + v11[1]*v11[3];
A[11][3][3]=a11[1] + v11[2]*v11[3];
A[11][3][4]=-Power(v11[1],2) - Power(v11[2],2);
A[11][3][5]=0;
A[11][3][6]=0;
A[11][3][7]=0;
A[11][3][8]=0;
A[11][3][9]=0;
A[11][3][10]=0;
A[11][3][11]=0;
A[11][3][12]=0;
A[11][3][13]=0;
A[11][3][14]=0;

A[11][4][1]=0;
A[11][4][2]=0;
A[11][4][3]=a11[6] - v11[2]*v11[4] + v11[1]*v11[5];
A[11][4][4]=-a11[5] - v11[3]*v11[4] + v11[1]*v11[6];
A[11][4][5]=a11[1];
A[11][4][6]=a11[2] - v11[1]*v11[3];
A[11][4][7]=a11[3] + v11[1]*v11[2];
A[11][4][8]=-(v11[2]*v11[3]);
A[11][4][9]=Power(v11[2],2) - Power(v11[3],2);
A[11][4][10]=v11[2]*v11[3];
A[11][4][11]=0;
A[11][4][12]=0;
A[11][4][13]=0;
A[11][4][14]=0;

A[11][5][1]=0;
A[11][5][2]=-a11[6] + v11[2]*v11[4] - v11[1]*v11[5];
A[11][5][3]=0;
A[11][5][4]=a11[4] - v11[3]*v11[5] + v11[2]*v11[6];
A[11][5][5]=v11[1]*v11[3];
A[11][5][6]=a11[1] + v11[2]*v11[3];
A[11][5][7]=-Power(v11[1],2) + Power(v11[3],2);
A[11][5][8]=a11[2];
A[11][5][9]=a11[3] - v11[1]*v11[2];
A[11][5][10]=-(v11[1]*v11[3]);
A[11][5][11]=0;
A[11][5][12]=0;
A[11][5][13]=0;
A[11][5][14]=0;

A[11][6][1]=0;
A[11][6][2]=a11[5] + v11[3]*v11[4] - v11[1]*v11[6];
A[11][6][3]=-a11[4] + v11[3]*v11[5] - v11[2]*v11[6];
A[11][6][4]=0;
A[11][6][5]=-(v11[1]*v11[2]);
A[11][6][6]=Power(v11[1],2) - Power(v11[2],2);
A[11][6][7]=a11[1] - v11[2]*v11[3];
A[11][6][8]=v11[1]*v11[2];
A[11][6][9]=a11[2] + v11[1]*v11[3];
A[11][6][10]=a11[3];
A[11][6][11]=0;
A[11][6][12]=0;
A[11][6][13]=0;
A[11][6][14]=0;


A[12][1][1]=a12[4] - v12[3]*v12[5] + v12[2]*v12[6];
A[12][1][2]=-Power(v12[2],2) - Power(v12[3],2);
A[12][1][3]=-a12[3] + v12[1]*v12[2];
A[12][1][4]=a12[2] + v12[1]*v12[3];
A[12][1][5]=0;
A[12][1][6]=0;
A[12][1][7]=0;
A[12][1][8]=0;
A[12][1][9]=0;
A[12][1][10]=0;
A[12][1][11]=0;
A[12][1][12]=0;
A[12][1][13]=0;
A[12][1][14]=0;

A[12][2][1]=a12[5] + v12[3]*v12[4] - v12[1]*v12[6];
A[12][2][2]=a12[3] + v12[1]*v12[2];
A[12][2][3]=-Power(v12[1],2) - Power(v12[3],2);
A[12][2][4]=-a12[1] + v12[2]*v12[3];
A[12][2][5]=0;
A[12][2][6]=0;
A[12][2][7]=0;
A[12][2][8]=0;
A[12][2][9]=0;
A[12][2][10]=0;
A[12][2][11]=0;
A[12][2][12]=0;
A[12][2][13]=0;
A[12][2][14]=0;

A[12][3][1]=a12[6] - v12[2]*v12[4] + v12[1]*v12[5];
A[12][3][2]=-a12[2] + v12[1]*v12[3];
A[12][3][3]=a12[1] + v12[2]*v12[3];
A[12][3][4]=-Power(v12[1],2) - Power(v12[2],2);
A[12][3][5]=0;
A[12][3][6]=0;
A[12][3][7]=0;
A[12][3][8]=0;
A[12][3][9]=0;
A[12][3][10]=0;
A[12][3][11]=0;
A[12][3][12]=0;
A[12][3][13]=0;
A[12][3][14]=0;

A[12][4][1]=0;
A[12][4][2]=0;
A[12][4][3]=a12[6] - v12[2]*v12[4] + v12[1]*v12[5];
A[12][4][4]=-a12[5] - v12[3]*v12[4] + v12[1]*v12[6];
A[12][4][5]=a12[1];
A[12][4][6]=a12[2] - v12[1]*v12[3];
A[12][4][7]=a12[3] + v12[1]*v12[2];
A[12][4][8]=-(v12[2]*v12[3]);
A[12][4][9]=Power(v12[2],2) - Power(v12[3],2);
A[12][4][10]=v12[2]*v12[3];
A[12][4][11]=0;
A[12][4][12]=0;
A[12][4][13]=0;
A[12][4][14]=0;

A[12][5][1]=0;
A[12][5][2]=-a12[6] + v12[2]*v12[4] - v12[1]*v12[5];
A[12][5][3]=0;
A[12][5][4]=a12[4] - v12[3]*v12[5] + v12[2]*v12[6];
A[12][5][5]=v12[1]*v12[3];
A[12][5][6]=a12[1] + v12[2]*v12[3];
A[12][5][7]=-Power(v12[1],2) + Power(v12[3],2);
A[12][5][8]=a12[2];
A[12][5][9]=a12[3] - v12[1]*v12[2];
A[12][5][10]=-(v12[1]*v12[3]);
A[12][5][11]=0;
A[12][5][12]=0;
A[12][5][13]=0;
A[12][5][14]=0;

A[12][6][1]=0;
A[12][6][2]=a12[5] + v12[3]*v12[4] - v12[1]*v12[6];
A[12][6][3]=-a12[4] + v12[3]*v12[5] - v12[2]*v12[6];
A[12][6][4]=0;
A[12][6][5]=-(v12[1]*v12[2]);
A[12][6][6]=Power(v12[1],2) - Power(v12[2],2);
A[12][6][7]=a12[1] - v12[2]*v12[3];
A[12][6][8]=v12[1]*v12[2];
A[12][6][9]=a12[2] + v12[1]*v12[3];
A[12][6][10]=a12[3];
A[12][6][11]=0;
A[12][6][12]=0;
A[12][6][13]=0;
A[12][6][14]=0;


A[13][1][1]=a13[4] - v13[3]*v13[5] + v13[2]*v13[6];
A[13][1][2]=-Power(v13[2],2) - Power(v13[3],2);
A[13][1][3]=-a13[3] + v13[1]*v13[2];
A[13][1][4]=a13[2] + v13[1]*v13[3];
A[13][1][5]=0;
A[13][1][6]=0;
A[13][1][7]=0;
A[13][1][8]=0;
A[13][1][9]=0;
A[13][1][10]=0;
A[13][1][11]=0;
A[13][1][12]=0;
A[13][1][13]=0;
A[13][1][14]=0;

A[13][2][1]=a13[5] + v13[3]*v13[4] - v13[1]*v13[6];
A[13][2][2]=a13[3] + v13[1]*v13[2];
A[13][2][3]=-Power(v13[1],2) - Power(v13[3],2);
A[13][2][4]=-a13[1] + v13[2]*v13[3];
A[13][2][5]=0;
A[13][2][6]=0;
A[13][2][7]=0;
A[13][2][8]=0;
A[13][2][9]=0;
A[13][2][10]=0;
A[13][2][11]=0;
A[13][2][12]=0;
A[13][2][13]=0;
A[13][2][14]=0;

A[13][3][1]=a13[6] - v13[2]*v13[4] + v13[1]*v13[5];
A[13][3][2]=-a13[2] + v13[1]*v13[3];
A[13][3][3]=a13[1] + v13[2]*v13[3];
A[13][3][4]=-Power(v13[1],2) - Power(v13[2],2);
A[13][3][5]=0;
A[13][3][6]=0;
A[13][3][7]=0;
A[13][3][8]=0;
A[13][3][9]=0;
A[13][3][10]=0;
A[13][3][11]=0;
A[13][3][12]=0;
A[13][3][13]=0;
A[13][3][14]=0;

A[13][4][1]=0;
A[13][4][2]=0;
A[13][4][3]=a13[6] - v13[2]*v13[4] + v13[1]*v13[5];
A[13][4][4]=-a13[5] - v13[3]*v13[4] + v13[1]*v13[6];
A[13][4][5]=a13[1];
A[13][4][6]=a13[2] - v13[1]*v13[3];
A[13][4][7]=a13[3] + v13[1]*v13[2];
A[13][4][8]=-(v13[2]*v13[3]);
A[13][4][9]=Power(v13[2],2) - Power(v13[3],2);
A[13][4][10]=v13[2]*v13[3];
A[13][4][11]=0;
A[13][4][12]=0;
A[13][4][13]=0;
A[13][4][14]=0;

A[13][5][1]=0;
A[13][5][2]=-a13[6] + v13[2]*v13[4] - v13[1]*v13[5];
A[13][5][3]=0;
A[13][5][4]=a13[4] - v13[3]*v13[5] + v13[2]*v13[6];
A[13][5][5]=v13[1]*v13[3];
A[13][5][6]=a13[1] + v13[2]*v13[3];
A[13][5][7]=-Power(v13[1],2) + Power(v13[3],2);
A[13][5][8]=a13[2];
A[13][5][9]=a13[3] - v13[1]*v13[2];
A[13][5][10]=-(v13[1]*v13[3]);
A[13][5][11]=0;
A[13][5][12]=0;
A[13][5][13]=0;
A[13][5][14]=0;

A[13][6][1]=0;
A[13][6][2]=a13[5] + v13[3]*v13[4] - v13[1]*v13[6];
A[13][6][3]=-a13[4] + v13[3]*v13[5] - v13[2]*v13[6];
A[13][6][4]=0;
A[13][6][5]=-(v13[1]*v13[2]);
A[13][6][6]=Power(v13[1],2) - Power(v13[2],2);
A[13][6][7]=a13[1] - v13[2]*v13[3];
A[13][6][8]=v13[1]*v13[2];
A[13][6][9]=a13[2] + v13[1]*v13[3];
A[13][6][10]=a13[3];
A[13][6][11]=0;
A[13][6][12]=0;
A[13][6][13]=0;
A[13][6][14]=0;


A[14][1][1]=a14[4] - v14[3]*v14[5] + v14[2]*v14[6];
A[14][1][2]=-Power(v14[2],2) - Power(v14[3],2);
A[14][1][3]=-a14[3] + v14[1]*v14[2];
A[14][1][4]=a14[2] + v14[1]*v14[3];
A[14][1][5]=0;
A[14][1][6]=0;
A[14][1][7]=0;
A[14][1][8]=0;
A[14][1][9]=0;
A[14][1][10]=0;
A[14][1][11]=0;
A[14][1][12]=0;
A[14][1][13]=0;
A[14][1][14]=0;

A[14][2][1]=a14[5] + v14[3]*v14[4] - v14[1]*v14[6];
A[14][2][2]=a14[3] + v14[1]*v14[2];
A[14][2][3]=-Power(v14[1],2) - Power(v14[3],2);
A[14][2][4]=-a14[1] + v14[2]*v14[3];
A[14][2][5]=0;
A[14][2][6]=0;
A[14][2][7]=0;
A[14][2][8]=0;
A[14][2][9]=0;
A[14][2][10]=0;
A[14][2][11]=0;
A[14][2][12]=0;
A[14][2][13]=0;
A[14][2][14]=0;

A[14][3][1]=a14[6] - v14[2]*v14[4] + v14[1]*v14[5];
A[14][3][2]=-a14[2] + v14[1]*v14[3];
A[14][3][3]=a14[1] + v14[2]*v14[3];
A[14][3][4]=-Power(v14[1],2) - Power(v14[2],2);
A[14][3][5]=0;
A[14][3][6]=0;
A[14][3][7]=0;
A[14][3][8]=0;
A[14][3][9]=0;
A[14][3][10]=0;
A[14][3][11]=0;
A[14][3][12]=0;
A[14][3][13]=0;
A[14][3][14]=0;

A[14][4][1]=0;
A[14][4][2]=0;
A[14][4][3]=a14[6] - v14[2]*v14[4] + v14[1]*v14[5];
A[14][4][4]=-a14[5] - v14[3]*v14[4] + v14[1]*v14[6];
A[14][4][5]=a14[1];
A[14][4][6]=a14[2] - v14[1]*v14[3];
A[14][4][7]=a14[3] + v14[1]*v14[2];
A[14][4][8]=-(v14[2]*v14[3]);
A[14][4][9]=Power(v14[2],2) - Power(v14[3],2);
A[14][4][10]=v14[2]*v14[3];
A[14][4][11]=0;
A[14][4][12]=0;
A[14][4][13]=0;
A[14][4][14]=0;

A[14][5][1]=0;
A[14][5][2]=-a14[6] + v14[2]*v14[4] - v14[1]*v14[5];
A[14][5][3]=0;
A[14][5][4]=a14[4] - v14[3]*v14[5] + v14[2]*v14[6];
A[14][5][5]=v14[1]*v14[3];
A[14][5][6]=a14[1] + v14[2]*v14[3];
A[14][5][7]=-Power(v14[1],2) + Power(v14[3],2);
A[14][5][8]=a14[2];
A[14][5][9]=a14[3] - v14[1]*v14[2];
A[14][5][10]=-(v14[1]*v14[3]);
A[14][5][11]=0;
A[14][5][12]=0;
A[14][5][13]=0;
A[14][5][14]=0;

A[14][6][1]=0;
A[14][6][2]=a14[5] + v14[3]*v14[4] - v14[1]*v14[6];
A[14][6][3]=-a14[4] + v14[3]*v14[5] - v14[2]*v14[6];
A[14][6][4]=0;
A[14][6][5]=-(v14[1]*v14[2]);
A[14][6][6]=Power(v14[1],2) - Power(v14[2],2);
A[14][6][7]=a14[1] - v14[2]*v14[3];
A[14][6][8]=v14[1]*v14[2];
A[14][6][9]=a14[2] + v14[1]*v14[3];
A[14][6][10]=a14[3];
A[14][6][11]=0;
A[14][6][12]=0;
A[14][6][13]=0;
A[14][6][14]=0;


A[15][1][1]=a15[4] - v15[3]*v15[5] + v15[2]*v15[6];
A[15][1][2]=-Power(v15[2],2) - Power(v15[3],2);
A[15][1][3]=-a15[3] + v15[1]*v15[2];
A[15][1][4]=a15[2] + v15[1]*v15[3];
A[15][1][5]=0;
A[15][1][6]=0;
A[15][1][7]=0;
A[15][1][8]=0;
A[15][1][9]=0;
A[15][1][10]=0;
A[15][1][11]=0;
A[15][1][12]=0;
A[15][1][13]=0;
A[15][1][14]=0;

A[15][2][1]=a15[5] + v15[3]*v15[4] - v15[1]*v15[6];
A[15][2][2]=a15[3] + v15[1]*v15[2];
A[15][2][3]=-Power(v15[1],2) - Power(v15[3],2);
A[15][2][4]=-a15[1] + v15[2]*v15[3];
A[15][2][5]=0;
A[15][2][6]=0;
A[15][2][7]=0;
A[15][2][8]=0;
A[15][2][9]=0;
A[15][2][10]=0;
A[15][2][11]=0;
A[15][2][12]=0;
A[15][2][13]=0;
A[15][2][14]=0;

A[15][3][1]=a15[6] - v15[2]*v15[4] + v15[1]*v15[5];
A[15][3][2]=-a15[2] + v15[1]*v15[3];
A[15][3][3]=a15[1] + v15[2]*v15[3];
A[15][3][4]=-Power(v15[1],2) - Power(v15[2],2);
A[15][3][5]=0;
A[15][3][6]=0;
A[15][3][7]=0;
A[15][3][8]=0;
A[15][3][9]=0;
A[15][3][10]=0;
A[15][3][11]=0;
A[15][3][12]=0;
A[15][3][13]=0;
A[15][3][14]=0;

A[15][4][1]=0;
A[15][4][2]=0;
A[15][4][3]=a15[6] - v15[2]*v15[4] + v15[1]*v15[5];
A[15][4][4]=-a15[5] - v15[3]*v15[4] + v15[1]*v15[6];
A[15][4][5]=a15[1];
A[15][4][6]=a15[2] - v15[1]*v15[3];
A[15][4][7]=a15[3] + v15[1]*v15[2];
A[15][4][8]=-(v15[2]*v15[3]);
A[15][4][9]=Power(v15[2],2) - Power(v15[3],2);
A[15][4][10]=v15[2]*v15[3];
A[15][4][11]=0;
A[15][4][12]=0;
A[15][4][13]=0;
A[15][4][14]=0;

A[15][5][1]=0;
A[15][5][2]=-a15[6] + v15[2]*v15[4] - v15[1]*v15[5];
A[15][5][3]=0;
A[15][5][4]=a15[4] - v15[3]*v15[5] + v15[2]*v15[6];
A[15][5][5]=v15[1]*v15[3];
A[15][5][6]=a15[1] + v15[2]*v15[3];
A[15][5][7]=-Power(v15[1],2) + Power(v15[3],2);
A[15][5][8]=a15[2];
A[15][5][9]=a15[3] - v15[1]*v15[2];
A[15][5][10]=-(v15[1]*v15[3]);
A[15][5][11]=0;
A[15][5][12]=0;
A[15][5][13]=0;
A[15][5][14]=0;

A[15][6][1]=0;
A[15][6][2]=a15[5] + v15[3]*v15[4] - v15[1]*v15[6];
A[15][6][3]=-a15[4] + v15[3]*v15[5] - v15[2]*v15[6];
A[15][6][4]=0;
A[15][6][5]=-(v15[1]*v15[2]);
A[15][6][6]=Power(v15[1],2) - Power(v15[2],2);
A[15][6][7]=a15[1] - v15[2]*v15[3];
A[15][6][8]=v15[1]*v15[2];
A[15][6][9]=a15[2] + v15[1]*v15[3];
A[15][6][10]=a15[3];
A[15][6][11]=0;
A[15][6][12]=0;
A[15][6][13]=0;
A[15][6][14]=0;


A[16][1][1]=a16[4] - v16[3]*v16[5] + v16[2]*v16[6];
A[16][1][2]=-Power(v16[2],2) - Power(v16[3],2);
A[16][1][3]=-a16[3] + v16[1]*v16[2];
A[16][1][4]=a16[2] + v16[1]*v16[3];
A[16][1][5]=0;
A[16][1][6]=0;
A[16][1][7]=0;
A[16][1][8]=0;
A[16][1][9]=0;
A[16][1][10]=0;
A[16][1][11]=0;
A[16][1][12]=0;
A[16][1][13]=0;
A[16][1][14]=0;

A[16][2][1]=a16[5] + v16[3]*v16[4] - v16[1]*v16[6];
A[16][2][2]=a16[3] + v16[1]*v16[2];
A[16][2][3]=-Power(v16[1],2) - Power(v16[3],2);
A[16][2][4]=-a16[1] + v16[2]*v16[3];
A[16][2][5]=0;
A[16][2][6]=0;
A[16][2][7]=0;
A[16][2][8]=0;
A[16][2][9]=0;
A[16][2][10]=0;
A[16][2][11]=0;
A[16][2][12]=0;
A[16][2][13]=0;
A[16][2][14]=0;

A[16][3][1]=a16[6] - v16[2]*v16[4] + v16[1]*v16[5];
A[16][3][2]=-a16[2] + v16[1]*v16[3];
A[16][3][3]=a16[1] + v16[2]*v16[3];
A[16][3][4]=-Power(v16[1],2) - Power(v16[2],2);
A[16][3][5]=0;
A[16][3][6]=0;
A[16][3][7]=0;
A[16][3][8]=0;
A[16][3][9]=0;
A[16][3][10]=0;
A[16][3][11]=0;
A[16][3][12]=0;
A[16][3][13]=0;
A[16][3][14]=0;

A[16][4][1]=0;
A[16][4][2]=0;
A[16][4][3]=a16[6] - v16[2]*v16[4] + v16[1]*v16[5];
A[16][4][4]=-a16[5] - v16[3]*v16[4] + v16[1]*v16[6];
A[16][4][5]=a16[1];
A[16][4][6]=a16[2] - v16[1]*v16[3];
A[16][4][7]=a16[3] + v16[1]*v16[2];
A[16][4][8]=-(v16[2]*v16[3]);
A[16][4][9]=Power(v16[2],2) - Power(v16[3],2);
A[16][4][10]=v16[2]*v16[3];
A[16][4][11]=0;
A[16][4][12]=0;
A[16][4][13]=0;
A[16][4][14]=0;

A[16][5][1]=0;
A[16][5][2]=-a16[6] + v16[2]*v16[4] - v16[1]*v16[5];
A[16][5][3]=0;
A[16][5][4]=a16[4] - v16[3]*v16[5] + v16[2]*v16[6];
A[16][5][5]=v16[1]*v16[3];
A[16][5][6]=a16[1] + v16[2]*v16[3];
A[16][5][7]=-Power(v16[1],2) + Power(v16[3],2);
A[16][5][8]=a16[2];
A[16][5][9]=a16[3] - v16[1]*v16[2];
A[16][5][10]=-(v16[1]*v16[3]);
A[16][5][11]=0;
A[16][5][12]=0;
A[16][5][13]=0;
A[16][5][14]=0;

A[16][6][1]=0;
A[16][6][2]=a16[5] + v16[3]*v16[4] - v16[1]*v16[6];
A[16][6][3]=-a16[4] + v16[3]*v16[5] - v16[2]*v16[6];
A[16][6][4]=0;
A[16][6][5]=-(v16[1]*v16[2]);
A[16][6][6]=Power(v16[1],2) - Power(v16[2],2);
A[16][6][7]=a16[1] - v16[2]*v16[3];
A[16][6][8]=v16[1]*v16[2];
A[16][6][9]=a16[2] + v16[1]*v16[3];
A[16][6][10]=a16[3];
A[16][6][11]=0;
A[16][6][12]=0;
A[16][6][13]=0;
A[16][6][14]=0;


A[17][1][1]=a17[4] - v17[3]*v17[5] + v17[2]*v17[6];
A[17][1][2]=-Power(v17[2],2) - Power(v17[3],2);
A[17][1][3]=-a17[3] + v17[1]*v17[2];
A[17][1][4]=a17[2] + v17[1]*v17[3];
A[17][1][5]=0;
A[17][1][6]=0;
A[17][1][7]=0;
A[17][1][8]=0;
A[17][1][9]=0;
A[17][1][10]=0;
A[17][1][11]=0;
A[17][1][12]=0;
A[17][1][13]=0;
A[17][1][14]=0;

A[17][2][1]=a17[5] + v17[3]*v17[4] - v17[1]*v17[6];
A[17][2][2]=a17[3] + v17[1]*v17[2];
A[17][2][3]=-Power(v17[1],2) - Power(v17[3],2);
A[17][2][4]=-a17[1] + v17[2]*v17[3];
A[17][2][5]=0;
A[17][2][6]=0;
A[17][2][7]=0;
A[17][2][8]=0;
A[17][2][9]=0;
A[17][2][10]=0;
A[17][2][11]=0;
A[17][2][12]=0;
A[17][2][13]=0;
A[17][2][14]=0;

A[17][3][1]=a17[6] - v17[2]*v17[4] + v17[1]*v17[5];
A[17][3][2]=-a17[2] + v17[1]*v17[3];
A[17][3][3]=a17[1] + v17[2]*v17[3];
A[17][3][4]=-Power(v17[1],2) - Power(v17[2],2);
A[17][3][5]=0;
A[17][3][6]=0;
A[17][3][7]=0;
A[17][3][8]=0;
A[17][3][9]=0;
A[17][3][10]=0;
A[17][3][11]=0;
A[17][3][12]=0;
A[17][3][13]=0;
A[17][3][14]=0;

A[17][4][1]=0;
A[17][4][2]=0;
A[17][4][3]=a17[6] - v17[2]*v17[4] + v17[1]*v17[5];
A[17][4][4]=-a17[5] - v17[3]*v17[4] + v17[1]*v17[6];
A[17][4][5]=a17[1];
A[17][4][6]=a17[2] - v17[1]*v17[3];
A[17][4][7]=a17[3] + v17[1]*v17[2];
A[17][4][8]=-(v17[2]*v17[3]);
A[17][4][9]=Power(v17[2],2) - Power(v17[3],2);
A[17][4][10]=v17[2]*v17[3];
A[17][4][11]=0;
A[17][4][12]=0;
A[17][4][13]=0;
A[17][4][14]=0;

A[17][5][1]=0;
A[17][5][2]=-a17[6] + v17[2]*v17[4] - v17[1]*v17[5];
A[17][5][3]=0;
A[17][5][4]=a17[4] - v17[3]*v17[5] + v17[2]*v17[6];
A[17][5][5]=v17[1]*v17[3];
A[17][5][6]=a17[1] + v17[2]*v17[3];
A[17][5][7]=-Power(v17[1],2) + Power(v17[3],2);
A[17][5][8]=a17[2];
A[17][5][9]=a17[3] - v17[1]*v17[2];
A[17][5][10]=-(v17[1]*v17[3]);
A[17][5][11]=0;
A[17][5][12]=0;
A[17][5][13]=0;
A[17][5][14]=0;

A[17][6][1]=0;
A[17][6][2]=a17[5] + v17[3]*v17[4] - v17[1]*v17[6];
A[17][6][3]=-a17[4] + v17[3]*v17[5] - v17[2]*v17[6];
A[17][6][4]=0;
A[17][6][5]=-(v17[1]*v17[2]);
A[17][6][6]=Power(v17[1],2) - Power(v17[2],2);
A[17][6][7]=a17[1] - v17[2]*v17[3];
A[17][6][8]=v17[1]*v17[2];
A[17][6][9]=a17[2] + v17[1]*v17[3];
A[17][6][10]=a17[3];
A[17][6][11]=0;
A[17][6][12]=0;
A[17][6][13]=0;
A[17][6][14]=0;


A[18][1][1]=a18[4] - v18[3]*v18[5] + v18[2]*v18[6];
A[18][1][2]=-Power(v18[2],2) - Power(v18[3],2);
A[18][1][3]=-a18[3] + v18[1]*v18[2];
A[18][1][4]=a18[2] + v18[1]*v18[3];
A[18][1][5]=0;
A[18][1][6]=0;
A[18][1][7]=0;
A[18][1][8]=0;
A[18][1][9]=0;
A[18][1][10]=0;
A[18][1][11]=0;
A[18][1][12]=0;
A[18][1][13]=0;
A[18][1][14]=0;

A[18][2][1]=a18[5] + v18[3]*v18[4] - v18[1]*v18[6];
A[18][2][2]=a18[3] + v18[1]*v18[2];
A[18][2][3]=-Power(v18[1],2) - Power(v18[3],2);
A[18][2][4]=-a18[1] + v18[2]*v18[3];
A[18][2][5]=0;
A[18][2][6]=0;
A[18][2][7]=0;
A[18][2][8]=0;
A[18][2][9]=0;
A[18][2][10]=0;
A[18][2][11]=0;
A[18][2][12]=0;
A[18][2][13]=0;
A[18][2][14]=0;

A[18][3][1]=a18[6] - v18[2]*v18[4] + v18[1]*v18[5];
A[18][3][2]=-a18[2] + v18[1]*v18[3];
A[18][3][3]=a18[1] + v18[2]*v18[3];
A[18][3][4]=-Power(v18[1],2) - Power(v18[2],2);
A[18][3][5]=0;
A[18][3][6]=0;
A[18][3][7]=0;
A[18][3][8]=0;
A[18][3][9]=0;
A[18][3][10]=0;
A[18][3][11]=0;
A[18][3][12]=0;
A[18][3][13]=0;
A[18][3][14]=0;

A[18][4][1]=0;
A[18][4][2]=0;
A[18][4][3]=a18[6] - v18[2]*v18[4] + v18[1]*v18[5];
A[18][4][4]=-a18[5] - v18[3]*v18[4] + v18[1]*v18[6];
A[18][4][5]=a18[1];
A[18][4][6]=a18[2] - v18[1]*v18[3];
A[18][4][7]=a18[3] + v18[1]*v18[2];
A[18][4][8]=-(v18[2]*v18[3]);
A[18][4][9]=Power(v18[2],2) - Power(v18[3],2);
A[18][4][10]=v18[2]*v18[3];
A[18][4][11]=0;
A[18][4][12]=0;
A[18][4][13]=0;
A[18][4][14]=0;

A[18][5][1]=0;
A[18][5][2]=-a18[6] + v18[2]*v18[4] - v18[1]*v18[5];
A[18][5][3]=0;
A[18][5][4]=a18[4] - v18[3]*v18[5] + v18[2]*v18[6];
A[18][5][5]=v18[1]*v18[3];
A[18][5][6]=a18[1] + v18[2]*v18[3];
A[18][5][7]=-Power(v18[1],2) + Power(v18[3],2);
A[18][5][8]=a18[2];
A[18][5][9]=a18[3] - v18[1]*v18[2];
A[18][5][10]=-(v18[1]*v18[3]);
A[18][5][11]=0;
A[18][5][12]=0;
A[18][5][13]=0;
A[18][5][14]=0;

A[18][6][1]=0;
A[18][6][2]=a18[5] + v18[3]*v18[4] - v18[1]*v18[6];
A[18][6][3]=-a18[4] + v18[3]*v18[5] - v18[2]*v18[6];
A[18][6][4]=0;
A[18][6][5]=-(v18[1]*v18[2]);
A[18][6][6]=Power(v18[1],2) - Power(v18[2],2);
A[18][6][7]=a18[1] - v18[2]*v18[3];
A[18][6][8]=v18[1]*v18[2];
A[18][6][9]=a18[2] + v18[1]*v18[3];
A[18][6][10]=a18[3];
A[18][6][11]=0;
A[18][6][12]=0;
A[18][6][13]=0;
A[18][6][14]=0;


A[19][1][1]=a19[4] - v19[3]*v19[5] + v19[2]*v19[6];
A[19][1][2]=-Power(v19[2],2) - Power(v19[3],2);
A[19][1][3]=-a19[3] + v19[1]*v19[2];
A[19][1][4]=a19[2] + v19[1]*v19[3];
A[19][1][5]=0;
A[19][1][6]=0;
A[19][1][7]=0;
A[19][1][8]=0;
A[19][1][9]=0;
A[19][1][10]=0;
A[19][1][11]=0;
A[19][1][12]=0;
A[19][1][13]=0;
A[19][1][14]=0;

A[19][2][1]=a19[5] + v19[3]*v19[4] - v19[1]*v19[6];
A[19][2][2]=a19[3] + v19[1]*v19[2];
A[19][2][3]=-Power(v19[1],2) - Power(v19[3],2);
A[19][2][4]=-a19[1] + v19[2]*v19[3];
A[19][2][5]=0;
A[19][2][6]=0;
A[19][2][7]=0;
A[19][2][8]=0;
A[19][2][9]=0;
A[19][2][10]=0;
A[19][2][11]=0;
A[19][2][12]=0;
A[19][2][13]=0;
A[19][2][14]=0;

A[19][3][1]=a19[6] - v19[2]*v19[4] + v19[1]*v19[5];
A[19][3][2]=-a19[2] + v19[1]*v19[3];
A[19][3][3]=a19[1] + v19[2]*v19[3];
A[19][3][4]=-Power(v19[1],2) - Power(v19[2],2);
A[19][3][5]=0;
A[19][3][6]=0;
A[19][3][7]=0;
A[19][3][8]=0;
A[19][3][9]=0;
A[19][3][10]=0;
A[19][3][11]=0;
A[19][3][12]=0;
A[19][3][13]=0;
A[19][3][14]=0;

A[19][4][1]=0;
A[19][4][2]=0;
A[19][4][3]=a19[6] - v19[2]*v19[4] + v19[1]*v19[5];
A[19][4][4]=-a19[5] - v19[3]*v19[4] + v19[1]*v19[6];
A[19][4][5]=a19[1];
A[19][4][6]=a19[2] - v19[1]*v19[3];
A[19][4][7]=a19[3] + v19[1]*v19[2];
A[19][4][8]=-(v19[2]*v19[3]);
A[19][4][9]=Power(v19[2],2) - Power(v19[3],2);
A[19][4][10]=v19[2]*v19[3];
A[19][4][11]=0;
A[19][4][12]=0;
A[19][4][13]=0;
A[19][4][14]=0;

A[19][5][1]=0;
A[19][5][2]=-a19[6] + v19[2]*v19[4] - v19[1]*v19[5];
A[19][5][3]=0;
A[19][5][4]=a19[4] - v19[3]*v19[5] + v19[2]*v19[6];
A[19][5][5]=v19[1]*v19[3];
A[19][5][6]=a19[1] + v19[2]*v19[3];
A[19][5][7]=-Power(v19[1],2) + Power(v19[3],2);
A[19][5][8]=a19[2];
A[19][5][9]=a19[3] - v19[1]*v19[2];
A[19][5][10]=-(v19[1]*v19[3]);
A[19][5][11]=0;
A[19][5][12]=0;
A[19][5][13]=0;
A[19][5][14]=0;

A[19][6][1]=0;
A[19][6][2]=a19[5] + v19[3]*v19[4] - v19[1]*v19[6];
A[19][6][3]=-a19[4] + v19[3]*v19[5] - v19[2]*v19[6];
A[19][6][4]=0;
A[19][6][5]=-(v19[1]*v19[2]);
A[19][6][6]=Power(v19[1],2) - Power(v19[2],2);
A[19][6][7]=a19[1] - v19[2]*v19[3];
A[19][6][8]=v19[1]*v19[2];
A[19][6][9]=a19[2] + v19[1]*v19[3];
A[19][6][10]=a19[3];
A[19][6][11]=0;
A[19][6][12]=0;
A[19][6][13]=0;
A[19][6][14]=0;


A[20][1][1]=a20[4] - v20[3]*v20[5] + v20[2]*v20[6];
A[20][1][2]=-Power(v20[2],2) - Power(v20[3],2);
A[20][1][3]=-a20[3] + v20[1]*v20[2];
A[20][1][4]=a20[2] + v20[1]*v20[3];
A[20][1][5]=0;
A[20][1][6]=0;
A[20][1][7]=0;
A[20][1][8]=0;
A[20][1][9]=0;
A[20][1][10]=0;
A[20][1][11]=0;
A[20][1][12]=0;
A[20][1][13]=0;
A[20][1][14]=0;

A[20][2][1]=a20[5] + v20[3]*v20[4] - v20[1]*v20[6];
A[20][2][2]=a20[3] + v20[1]*v20[2];
A[20][2][3]=-Power(v20[1],2) - Power(v20[3],2);
A[20][2][4]=-a20[1] + v20[2]*v20[3];
A[20][2][5]=0;
A[20][2][6]=0;
A[20][2][7]=0;
A[20][2][8]=0;
A[20][2][9]=0;
A[20][2][10]=0;
A[20][2][11]=0;
A[20][2][12]=0;
A[20][2][13]=0;
A[20][2][14]=0;

A[20][3][1]=a20[6] - v20[2]*v20[4] + v20[1]*v20[5];
A[20][3][2]=-a20[2] + v20[1]*v20[3];
A[20][3][3]=a20[1] + v20[2]*v20[3];
A[20][3][4]=-Power(v20[1],2) - Power(v20[2],2);
A[20][3][5]=0;
A[20][3][6]=0;
A[20][3][7]=0;
A[20][3][8]=0;
A[20][3][9]=0;
A[20][3][10]=0;
A[20][3][11]=0;
A[20][3][12]=0;
A[20][3][13]=0;
A[20][3][14]=0;

A[20][4][1]=0;
A[20][4][2]=0;
A[20][4][3]=a20[6] - v20[2]*v20[4] + v20[1]*v20[5];
A[20][4][4]=-a20[5] - v20[3]*v20[4] + v20[1]*v20[6];
A[20][4][5]=a20[1];
A[20][4][6]=a20[2] - v20[1]*v20[3];
A[20][4][7]=a20[3] + v20[1]*v20[2];
A[20][4][8]=-(v20[2]*v20[3]);
A[20][4][9]=Power(v20[2],2) - Power(v20[3],2);
A[20][4][10]=v20[2]*v20[3];
A[20][4][11]=0;
A[20][4][12]=0;
A[20][4][13]=0;
A[20][4][14]=0;

A[20][5][1]=0;
A[20][5][2]=-a20[6] + v20[2]*v20[4] - v20[1]*v20[5];
A[20][5][3]=0;
A[20][5][4]=a20[4] - v20[3]*v20[5] + v20[2]*v20[6];
A[20][5][5]=v20[1]*v20[3];
A[20][5][6]=a20[1] + v20[2]*v20[3];
A[20][5][7]=-Power(v20[1],2) + Power(v20[3],2);
A[20][5][8]=a20[2];
A[20][5][9]=a20[3] - v20[1]*v20[2];
A[20][5][10]=-(v20[1]*v20[3]);
A[20][5][11]=0;
A[20][5][12]=0;
A[20][5][13]=0;
A[20][5][14]=0;

A[20][6][1]=0;
A[20][6][2]=a20[5] + v20[3]*v20[4] - v20[1]*v20[6];
A[20][6][3]=-a20[4] + v20[3]*v20[5] - v20[2]*v20[6];
A[20][6][4]=0;
A[20][6][5]=-(v20[1]*v20[2]);
A[20][6][6]=Power(v20[1],2) - Power(v20[2],2);
A[20][6][7]=a20[1] - v20[2]*v20[3];
A[20][6][8]=v20[1]*v20[2];
A[20][6][9]=a20[2] + v20[1]*v20[3];
A[20][6][10]=a20[3];
A[20][6][11]=0;
A[20][6][12]=0;
A[20][6][13]=0;
A[20][6][14]=0;


A[21][1][1]=a21[4] - v21[3]*v21[5] + v21[2]*v21[6];
A[21][1][2]=-Power(v21[2],2) - Power(v21[3],2);
A[21][1][3]=-a21[3] + v21[1]*v21[2];
A[21][1][4]=a21[2] + v21[1]*v21[3];
A[21][1][5]=0;
A[21][1][6]=0;
A[21][1][7]=0;
A[21][1][8]=0;
A[21][1][9]=0;
A[21][1][10]=0;
A[21][1][11]=0;
A[21][1][12]=0;
A[21][1][13]=0;
A[21][1][14]=0;

A[21][2][1]=a21[5] + v21[3]*v21[4] - v21[1]*v21[6];
A[21][2][2]=a21[3] + v21[1]*v21[2];
A[21][2][3]=-Power(v21[1],2) - Power(v21[3],2);
A[21][2][4]=-a21[1] + v21[2]*v21[3];
A[21][2][5]=0;
A[21][2][6]=0;
A[21][2][7]=0;
A[21][2][8]=0;
A[21][2][9]=0;
A[21][2][10]=0;
A[21][2][11]=0;
A[21][2][12]=0;
A[21][2][13]=0;
A[21][2][14]=0;

A[21][3][1]=a21[6] - v21[2]*v21[4] + v21[1]*v21[5];
A[21][3][2]=-a21[2] + v21[1]*v21[3];
A[21][3][3]=a21[1] + v21[2]*v21[3];
A[21][3][4]=-Power(v21[1],2) - Power(v21[2],2);
A[21][3][5]=0;
A[21][3][6]=0;
A[21][3][7]=0;
A[21][3][8]=0;
A[21][3][9]=0;
A[21][3][10]=0;
A[21][3][11]=0;
A[21][3][12]=0;
A[21][3][13]=0;
A[21][3][14]=0;

A[21][4][1]=0;
A[21][4][2]=0;
A[21][4][3]=a21[6] - v21[2]*v21[4] + v21[1]*v21[5];
A[21][4][4]=-a21[5] - v21[3]*v21[4] + v21[1]*v21[6];
A[21][4][5]=a21[1];
A[21][4][6]=a21[2] - v21[1]*v21[3];
A[21][4][7]=a21[3] + v21[1]*v21[2];
A[21][4][8]=-(v21[2]*v21[3]);
A[21][4][9]=Power(v21[2],2) - Power(v21[3],2);
A[21][4][10]=v21[2]*v21[3];
A[21][4][11]=0;
A[21][4][12]=0;
A[21][4][13]=0;
A[21][4][14]=0;

A[21][5][1]=0;
A[21][5][2]=-a21[6] + v21[2]*v21[4] - v21[1]*v21[5];
A[21][5][3]=0;
A[21][5][4]=a21[4] - v21[3]*v21[5] + v21[2]*v21[6];
A[21][5][5]=v21[1]*v21[3];
A[21][5][6]=a21[1] + v21[2]*v21[3];
A[21][5][7]=-Power(v21[1],2) + Power(v21[3],2);
A[21][5][8]=a21[2];
A[21][5][9]=a21[3] - v21[1]*v21[2];
A[21][5][10]=-(v21[1]*v21[3]);
A[21][5][11]=0;
A[21][5][12]=0;
A[21][5][13]=0;
A[21][5][14]=0;

A[21][6][1]=0;
A[21][6][2]=a21[5] + v21[3]*v21[4] - v21[1]*v21[6];
A[21][6][3]=-a21[4] + v21[3]*v21[5] - v21[2]*v21[6];
A[21][6][4]=0;
A[21][6][5]=-(v21[1]*v21[2]);
A[21][6][6]=Power(v21[1],2) - Power(v21[2],2);
A[21][6][7]=a21[1] - v21[2]*v21[3];
A[21][6][8]=v21[1]*v21[2];
A[21][6][9]=a21[2] + v21[1]*v21[3];
A[21][6][10]=a21[3];
A[21][6][11]=0;
A[21][6][12]=0;
A[21][6][13]=0;
A[21][6][14]=0;


A[22][1][1]=a22[4] - v22[3]*v22[5] + v22[2]*v22[6];
A[22][1][2]=-Power(v22[2],2) - Power(v22[3],2);
A[22][1][3]=-a22[3] + v22[1]*v22[2];
A[22][1][4]=a22[2] + v22[1]*v22[3];
A[22][1][5]=0;
A[22][1][6]=0;
A[22][1][7]=0;
A[22][1][8]=0;
A[22][1][9]=0;
A[22][1][10]=0;
A[22][1][11]=0;
A[22][1][12]=0;
A[22][1][13]=0;
A[22][1][14]=0;

A[22][2][1]=a22[5] + v22[3]*v22[4] - v22[1]*v22[6];
A[22][2][2]=a22[3] + v22[1]*v22[2];
A[22][2][3]=-Power(v22[1],2) - Power(v22[3],2);
A[22][2][4]=-a22[1] + v22[2]*v22[3];
A[22][2][5]=0;
A[22][2][6]=0;
A[22][2][7]=0;
A[22][2][8]=0;
A[22][2][9]=0;
A[22][2][10]=0;
A[22][2][11]=0;
A[22][2][12]=0;
A[22][2][13]=0;
A[22][2][14]=0;

A[22][3][1]=a22[6] - v22[2]*v22[4] + v22[1]*v22[5];
A[22][3][2]=-a22[2] + v22[1]*v22[3];
A[22][3][3]=a22[1] + v22[2]*v22[3];
A[22][3][4]=-Power(v22[1],2) - Power(v22[2],2);
A[22][3][5]=0;
A[22][3][6]=0;
A[22][3][7]=0;
A[22][3][8]=0;
A[22][3][9]=0;
A[22][3][10]=0;
A[22][3][11]=0;
A[22][3][12]=0;
A[22][3][13]=0;
A[22][3][14]=0;

A[22][4][1]=0;
A[22][4][2]=0;
A[22][4][3]=a22[6] - v22[2]*v22[4] + v22[1]*v22[5];
A[22][4][4]=-a22[5] - v22[3]*v22[4] + v22[1]*v22[6];
A[22][4][5]=a22[1];
A[22][4][6]=a22[2] - v22[1]*v22[3];
A[22][4][7]=a22[3] + v22[1]*v22[2];
A[22][4][8]=-(v22[2]*v22[3]);
A[22][4][9]=Power(v22[2],2) - Power(v22[3],2);
A[22][4][10]=v22[2]*v22[3];
A[22][4][11]=0;
A[22][4][12]=0;
A[22][4][13]=0;
A[22][4][14]=0;

A[22][5][1]=0;
A[22][5][2]=-a22[6] + v22[2]*v22[4] - v22[1]*v22[5];
A[22][5][3]=0;
A[22][5][4]=a22[4] - v22[3]*v22[5] + v22[2]*v22[6];
A[22][5][5]=v22[1]*v22[3];
A[22][5][6]=a22[1] + v22[2]*v22[3];
A[22][5][7]=-Power(v22[1],2) + Power(v22[3],2);
A[22][5][8]=a22[2];
A[22][5][9]=a22[3] - v22[1]*v22[2];
A[22][5][10]=-(v22[1]*v22[3]);
A[22][5][11]=0;
A[22][5][12]=0;
A[22][5][13]=0;
A[22][5][14]=0;

A[22][6][1]=0;
A[22][6][2]=a22[5] + v22[3]*v22[4] - v22[1]*v22[6];
A[22][6][3]=-a22[4] + v22[3]*v22[5] - v22[2]*v22[6];
A[22][6][4]=0;
A[22][6][5]=-(v22[1]*v22[2]);
A[22][6][6]=Power(v22[1],2) - Power(v22[2],2);
A[22][6][7]=a22[1] - v22[2]*v22[3];
A[22][6][8]=v22[1]*v22[2];
A[22][6][9]=a22[2] + v22[1]*v22[3];
A[22][6][10]=a22[3];
A[22][6][11]=0;
A[22][6][12]=0;
A[22][6][13]=0;
A[22][6][14]=0;


A[23][1][1]=a23[4] - v23[3]*v23[5] + v23[2]*v23[6];
A[23][1][2]=-Power(v23[2],2) - Power(v23[3],2);
A[23][1][3]=-a23[3] + v23[1]*v23[2];
A[23][1][4]=a23[2] + v23[1]*v23[3];
A[23][1][5]=0;
A[23][1][6]=0;
A[23][1][7]=0;
A[23][1][8]=0;
A[23][1][9]=0;
A[23][1][10]=0;
A[23][1][11]=0;
A[23][1][12]=0;
A[23][1][13]=0;
A[23][1][14]=0;

A[23][2][1]=a23[5] + v23[3]*v23[4] - v23[1]*v23[6];
A[23][2][2]=a23[3] + v23[1]*v23[2];
A[23][2][3]=-Power(v23[1],2) - Power(v23[3],2);
A[23][2][4]=-a23[1] + v23[2]*v23[3];
A[23][2][5]=0;
A[23][2][6]=0;
A[23][2][7]=0;
A[23][2][8]=0;
A[23][2][9]=0;
A[23][2][10]=0;
A[23][2][11]=0;
A[23][2][12]=0;
A[23][2][13]=0;
A[23][2][14]=0;

A[23][3][1]=a23[6] - v23[2]*v23[4] + v23[1]*v23[5];
A[23][3][2]=-a23[2] + v23[1]*v23[3];
A[23][3][3]=a23[1] + v23[2]*v23[3];
A[23][3][4]=-Power(v23[1],2) - Power(v23[2],2);
A[23][3][5]=0;
A[23][3][6]=0;
A[23][3][7]=0;
A[23][3][8]=0;
A[23][3][9]=0;
A[23][3][10]=0;
A[23][3][11]=0;
A[23][3][12]=0;
A[23][3][13]=0;
A[23][3][14]=0;

A[23][4][1]=0;
A[23][4][2]=0;
A[23][4][3]=a23[6] - v23[2]*v23[4] + v23[1]*v23[5];
A[23][4][4]=-a23[5] - v23[3]*v23[4] + v23[1]*v23[6];
A[23][4][5]=a23[1];
A[23][4][6]=a23[2] - v23[1]*v23[3];
A[23][4][7]=a23[3] + v23[1]*v23[2];
A[23][4][8]=-(v23[2]*v23[3]);
A[23][4][9]=Power(v23[2],2) - Power(v23[3],2);
A[23][4][10]=v23[2]*v23[3];
A[23][4][11]=0;
A[23][4][12]=0;
A[23][4][13]=0;
A[23][4][14]=0;

A[23][5][1]=0;
A[23][5][2]=-a23[6] + v23[2]*v23[4] - v23[1]*v23[5];
A[23][5][3]=0;
A[23][5][4]=a23[4] - v23[3]*v23[5] + v23[2]*v23[6];
A[23][5][5]=v23[1]*v23[3];
A[23][5][6]=a23[1] + v23[2]*v23[3];
A[23][5][7]=-Power(v23[1],2) + Power(v23[3],2);
A[23][5][8]=a23[2];
A[23][5][9]=a23[3] - v23[1]*v23[2];
A[23][5][10]=-(v23[1]*v23[3]);
A[23][5][11]=0;
A[23][5][12]=0;
A[23][5][13]=0;
A[23][5][14]=0;

A[23][6][1]=0;
A[23][6][2]=a23[5] + v23[3]*v23[4] - v23[1]*v23[6];
A[23][6][3]=-a23[4] + v23[3]*v23[5] - v23[2]*v23[6];
A[23][6][4]=0;
A[23][6][5]=-(v23[1]*v23[2]);
A[23][6][6]=Power(v23[1],2) - Power(v23[2],2);
A[23][6][7]=a23[1] - v23[2]*v23[3];
A[23][6][8]=v23[1]*v23[2];
A[23][6][9]=a23[2] + v23[1]*v23[3];
A[23][6][10]=a23[3];
A[23][6][11]=0;
A[23][6][12]=0;
A[23][6][13]=0;
A[23][6][14]=0;


A[24][1][1]=a24[4] - v24[3]*v24[5] + v24[2]*v24[6];
A[24][1][2]=-Power(v24[2],2) - Power(v24[3],2);
A[24][1][3]=-a24[3] + v24[1]*v24[2];
A[24][1][4]=a24[2] + v24[1]*v24[3];
A[24][1][5]=0;
A[24][1][6]=0;
A[24][1][7]=0;
A[24][1][8]=0;
A[24][1][9]=0;
A[24][1][10]=0;
A[24][1][11]=0;
A[24][1][12]=0;
A[24][1][13]=0;
A[24][1][14]=0;

A[24][2][1]=a24[5] + v24[3]*v24[4] - v24[1]*v24[6];
A[24][2][2]=a24[3] + v24[1]*v24[2];
A[24][2][3]=-Power(v24[1],2) - Power(v24[3],2);
A[24][2][4]=-a24[1] + v24[2]*v24[3];
A[24][2][5]=0;
A[24][2][6]=0;
A[24][2][7]=0;
A[24][2][8]=0;
A[24][2][9]=0;
A[24][2][10]=0;
A[24][2][11]=0;
A[24][2][12]=0;
A[24][2][13]=0;
A[24][2][14]=0;

A[24][3][1]=a24[6] - v24[2]*v24[4] + v24[1]*v24[5];
A[24][3][2]=-a24[2] + v24[1]*v24[3];
A[24][3][3]=a24[1] + v24[2]*v24[3];
A[24][3][4]=-Power(v24[1],2) - Power(v24[2],2);
A[24][3][5]=0;
A[24][3][6]=0;
A[24][3][7]=0;
A[24][3][8]=0;
A[24][3][9]=0;
A[24][3][10]=0;
A[24][3][11]=0;
A[24][3][12]=0;
A[24][3][13]=0;
A[24][3][14]=0;

A[24][4][1]=0;
A[24][4][2]=0;
A[24][4][3]=a24[6] - v24[2]*v24[4] + v24[1]*v24[5];
A[24][4][4]=-a24[5] - v24[3]*v24[4] + v24[1]*v24[6];
A[24][4][5]=a24[1];
A[24][4][6]=a24[2] - v24[1]*v24[3];
A[24][4][7]=a24[3] + v24[1]*v24[2];
A[24][4][8]=-(v24[2]*v24[3]);
A[24][4][9]=Power(v24[2],2) - Power(v24[3],2);
A[24][4][10]=v24[2]*v24[3];
A[24][4][11]=0;
A[24][4][12]=0;
A[24][4][13]=0;
A[24][4][14]=0;

A[24][5][1]=0;
A[24][5][2]=-a24[6] + v24[2]*v24[4] - v24[1]*v24[5];
A[24][5][3]=0;
A[24][5][4]=a24[4] - v24[3]*v24[5] + v24[2]*v24[6];
A[24][5][5]=v24[1]*v24[3];
A[24][5][6]=a24[1] + v24[2]*v24[3];
A[24][5][7]=-Power(v24[1],2) + Power(v24[3],2);
A[24][5][8]=a24[2];
A[24][5][9]=a24[3] - v24[1]*v24[2];
A[24][5][10]=-(v24[1]*v24[3]);
A[24][5][11]=0;
A[24][5][12]=0;
A[24][5][13]=0;
A[24][5][14]=0;

A[24][6][1]=0;
A[24][6][2]=a24[5] + v24[3]*v24[4] - v24[1]*v24[6];
A[24][6][3]=-a24[4] + v24[3]*v24[5] - v24[2]*v24[6];
A[24][6][4]=0;
A[24][6][5]=-(v24[1]*v24[2]);
A[24][6][6]=Power(v24[1],2) - Power(v24[2],2);
A[24][6][7]=a24[1] - v24[2]*v24[3];
A[24][6][8]=v24[1]*v24[2];
A[24][6][9]=a24[2] + v24[1]*v24[3];
A[24][6][10]=a24[3];
A[24][6][11]=0;
A[24][6][12]=0;
A[24][6][13]=0;
A[24][6][14]=0;


A[25][1][1]=a25[4] - v25[3]*v25[5] + v25[2]*v25[6];
A[25][1][2]=-Power(v25[2],2) - Power(v25[3],2);
A[25][1][3]=-a25[3] + v25[1]*v25[2];
A[25][1][4]=a25[2] + v25[1]*v25[3];
A[25][1][5]=0;
A[25][1][6]=0;
A[25][1][7]=0;
A[25][1][8]=0;
A[25][1][9]=0;
A[25][1][10]=0;
A[25][1][11]=0;
A[25][1][12]=0;
A[25][1][13]=0;
A[25][1][14]=0;

A[25][2][1]=a25[5] + v25[3]*v25[4] - v25[1]*v25[6];
A[25][2][2]=a25[3] + v25[1]*v25[2];
A[25][2][3]=-Power(v25[1],2) - Power(v25[3],2);
A[25][2][4]=-a25[1] + v25[2]*v25[3];
A[25][2][5]=0;
A[25][2][6]=0;
A[25][2][7]=0;
A[25][2][8]=0;
A[25][2][9]=0;
A[25][2][10]=0;
A[25][2][11]=0;
A[25][2][12]=0;
A[25][2][13]=0;
A[25][2][14]=0;

A[25][3][1]=a25[6] - v25[2]*v25[4] + v25[1]*v25[5];
A[25][3][2]=-a25[2] + v25[1]*v25[3];
A[25][3][3]=a25[1] + v25[2]*v25[3];
A[25][3][4]=-Power(v25[1],2) - Power(v25[2],2);
A[25][3][5]=0;
A[25][3][6]=0;
A[25][3][7]=0;
A[25][3][8]=0;
A[25][3][9]=0;
A[25][3][10]=0;
A[25][3][11]=0;
A[25][3][12]=0;
A[25][3][13]=0;
A[25][3][14]=0;

A[25][4][1]=0;
A[25][4][2]=0;
A[25][4][3]=a25[6] - v25[2]*v25[4] + v25[1]*v25[5];
A[25][4][4]=-a25[5] - v25[3]*v25[4] + v25[1]*v25[6];
A[25][4][5]=a25[1];
A[25][4][6]=a25[2] - v25[1]*v25[3];
A[25][4][7]=a25[3] + v25[1]*v25[2];
A[25][4][8]=-(v25[2]*v25[3]);
A[25][4][9]=Power(v25[2],2) - Power(v25[3],2);
A[25][4][10]=v25[2]*v25[3];
A[25][4][11]=0;
A[25][4][12]=0;
A[25][4][13]=0;
A[25][4][14]=0;

A[25][5][1]=0;
A[25][5][2]=-a25[6] + v25[2]*v25[4] - v25[1]*v25[5];
A[25][5][3]=0;
A[25][5][4]=a25[4] - v25[3]*v25[5] + v25[2]*v25[6];
A[25][5][5]=v25[1]*v25[3];
A[25][5][6]=a25[1] + v25[2]*v25[3];
A[25][5][7]=-Power(v25[1],2) + Power(v25[3],2);
A[25][5][8]=a25[2];
A[25][5][9]=a25[3] - v25[1]*v25[2];
A[25][5][10]=-(v25[1]*v25[3]);
A[25][5][11]=0;
A[25][5][12]=0;
A[25][5][13]=0;
A[25][5][14]=0;

A[25][6][1]=0;
A[25][6][2]=a25[5] + v25[3]*v25[4] - v25[1]*v25[6];
A[25][6][3]=-a25[4] + v25[3]*v25[5] - v25[2]*v25[6];
A[25][6][4]=0;
A[25][6][5]=-(v25[1]*v25[2]);
A[25][6][6]=Power(v25[1],2) - Power(v25[2],2);
A[25][6][7]=a25[1] - v25[2]*v25[3];
A[25][6][8]=v25[1]*v25[2];
A[25][6][9]=a25[2] + v25[1]*v25[3];
A[25][6][10]=a25[3];
A[25][6][11]=0;
A[25][6][12]=0;
A[25][6][13]=0;
A[25][6][14]=0;


A[26][1][1]=a26[4] - v26[3]*v26[5] + v26[2]*v26[6];
A[26][1][2]=-Power(v26[2],2) - Power(v26[3],2);
A[26][1][3]=-a26[3] + v26[1]*v26[2];
A[26][1][4]=a26[2] + v26[1]*v26[3];
A[26][1][5]=0;
A[26][1][6]=0;
A[26][1][7]=0;
A[26][1][8]=0;
A[26][1][9]=0;
A[26][1][10]=0;
A[26][1][11]=0;
A[26][1][12]=0;
A[26][1][13]=0;
A[26][1][14]=0;

A[26][2][1]=a26[5] + v26[3]*v26[4] - v26[1]*v26[6];
A[26][2][2]=a26[3] + v26[1]*v26[2];
A[26][2][3]=-Power(v26[1],2) - Power(v26[3],2);
A[26][2][4]=-a26[1] + v26[2]*v26[3];
A[26][2][5]=0;
A[26][2][6]=0;
A[26][2][7]=0;
A[26][2][8]=0;
A[26][2][9]=0;
A[26][2][10]=0;
A[26][2][11]=0;
A[26][2][12]=0;
A[26][2][13]=0;
A[26][2][14]=0;

A[26][3][1]=a26[6] - v26[2]*v26[4] + v26[1]*v26[5];
A[26][3][2]=-a26[2] + v26[1]*v26[3];
A[26][3][3]=a26[1] + v26[2]*v26[3];
A[26][3][4]=-Power(v26[1],2) - Power(v26[2],2);
A[26][3][5]=0;
A[26][3][6]=0;
A[26][3][7]=0;
A[26][3][8]=0;
A[26][3][9]=0;
A[26][3][10]=0;
A[26][3][11]=0;
A[26][3][12]=0;
A[26][3][13]=0;
A[26][3][14]=0;

A[26][4][1]=0;
A[26][4][2]=0;
A[26][4][3]=a26[6] - v26[2]*v26[4] + v26[1]*v26[5];
A[26][4][4]=-a26[5] - v26[3]*v26[4] + v26[1]*v26[6];
A[26][4][5]=a26[1];
A[26][4][6]=a26[2] - v26[1]*v26[3];
A[26][4][7]=a26[3] + v26[1]*v26[2];
A[26][4][8]=-(v26[2]*v26[3]);
A[26][4][9]=Power(v26[2],2) - Power(v26[3],2);
A[26][4][10]=v26[2]*v26[3];
A[26][4][11]=0;
A[26][4][12]=0;
A[26][4][13]=0;
A[26][4][14]=0;

A[26][5][1]=0;
A[26][5][2]=-a26[6] + v26[2]*v26[4] - v26[1]*v26[5];
A[26][5][3]=0;
A[26][5][4]=a26[4] - v26[3]*v26[5] + v26[2]*v26[6];
A[26][5][5]=v26[1]*v26[3];
A[26][5][6]=a26[1] + v26[2]*v26[3];
A[26][5][7]=-Power(v26[1],2) + Power(v26[3],2);
A[26][5][8]=a26[2];
A[26][5][9]=a26[3] - v26[1]*v26[2];
A[26][5][10]=-(v26[1]*v26[3]);
A[26][5][11]=0;
A[26][5][12]=0;
A[26][5][13]=0;
A[26][5][14]=0;

A[26][6][1]=0;
A[26][6][2]=a26[5] + v26[3]*v26[4] - v26[1]*v26[6];
A[26][6][3]=-a26[4] + v26[3]*v26[5] - v26[2]*v26[6];
A[26][6][4]=0;
A[26][6][5]=-(v26[1]*v26[2]);
A[26][6][6]=Power(v26[1],2) - Power(v26[2],2);
A[26][6][7]=a26[1] - v26[2]*v26[3];
A[26][6][8]=v26[1]*v26[2];
A[26][6][9]=a26[2] + v26[1]*v26[3];
A[26][6][10]=a26[3];
A[26][6][11]=0;
A[26][6][12]=0;
A[26][6][13]=0;
A[26][6][14]=0;


A[27][1][1]=a27[4] - v27[3]*v27[5] + v27[2]*v27[6];
A[27][1][2]=-Power(v27[2],2) - Power(v27[3],2);
A[27][1][3]=-a27[3] + v27[1]*v27[2];
A[27][1][4]=a27[2] + v27[1]*v27[3];
A[27][1][5]=0;
A[27][1][6]=0;
A[27][1][7]=0;
A[27][1][8]=0;
A[27][1][9]=0;
A[27][1][10]=0;
A[27][1][11]=0;
A[27][1][12]=0;
A[27][1][13]=0;
A[27][1][14]=0;

A[27][2][1]=a27[5] + v27[3]*v27[4] - v27[1]*v27[6];
A[27][2][2]=a27[3] + v27[1]*v27[2];
A[27][2][3]=-Power(v27[1],2) - Power(v27[3],2);
A[27][2][4]=-a27[1] + v27[2]*v27[3];
A[27][2][5]=0;
A[27][2][6]=0;
A[27][2][7]=0;
A[27][2][8]=0;
A[27][2][9]=0;
A[27][2][10]=0;
A[27][2][11]=0;
A[27][2][12]=0;
A[27][2][13]=0;
A[27][2][14]=0;

A[27][3][1]=a27[6] - v27[2]*v27[4] + v27[1]*v27[5];
A[27][3][2]=-a27[2] + v27[1]*v27[3];
A[27][3][3]=a27[1] + v27[2]*v27[3];
A[27][3][4]=-Power(v27[1],2) - Power(v27[2],2);
A[27][3][5]=0;
A[27][3][6]=0;
A[27][3][7]=0;
A[27][3][8]=0;
A[27][3][9]=0;
A[27][3][10]=0;
A[27][3][11]=0;
A[27][3][12]=0;
A[27][3][13]=0;
A[27][3][14]=0;

A[27][4][1]=0;
A[27][4][2]=0;
A[27][4][3]=a27[6] - v27[2]*v27[4] + v27[1]*v27[5];
A[27][4][4]=-a27[5] - v27[3]*v27[4] + v27[1]*v27[6];
A[27][4][5]=a27[1];
A[27][4][6]=a27[2] - v27[1]*v27[3];
A[27][4][7]=a27[3] + v27[1]*v27[2];
A[27][4][8]=-(v27[2]*v27[3]);
A[27][4][9]=Power(v27[2],2) - Power(v27[3],2);
A[27][4][10]=v27[2]*v27[3];
A[27][4][11]=0;
A[27][4][12]=0;
A[27][4][13]=0;
A[27][4][14]=0;

A[27][5][1]=0;
A[27][5][2]=-a27[6] + v27[2]*v27[4] - v27[1]*v27[5];
A[27][5][3]=0;
A[27][5][4]=a27[4] - v27[3]*v27[5] + v27[2]*v27[6];
A[27][5][5]=v27[1]*v27[3];
A[27][5][6]=a27[1] + v27[2]*v27[3];
A[27][5][7]=-Power(v27[1],2) + Power(v27[3],2);
A[27][5][8]=a27[2];
A[27][5][9]=a27[3] - v27[1]*v27[2];
A[27][5][10]=-(v27[1]*v27[3]);
A[27][5][11]=0;
A[27][5][12]=0;
A[27][5][13]=0;
A[27][5][14]=0;

A[27][6][1]=0;
A[27][6][2]=a27[5] + v27[3]*v27[4] - v27[1]*v27[6];
A[27][6][3]=-a27[4] + v27[3]*v27[5] - v27[2]*v27[6];
A[27][6][4]=0;
A[27][6][5]=-(v27[1]*v27[2]);
A[27][6][6]=Power(v27[1],2) - Power(v27[2],2);
A[27][6][7]=a27[1] - v27[2]*v27[3];
A[27][6][8]=v27[1]*v27[2];
A[27][6][9]=a27[2] + v27[1]*v27[3];
A[27][6][10]=a27[3];
A[27][6][11]=0;
A[27][6][12]=0;
A[27][6][13]=0;
A[27][6][14]=0;


A[28][1][1]=a28[4] - v28[3]*v28[5] + v28[2]*v28[6];
A[28][1][2]=-Power(v28[2],2) - Power(v28[3],2);
A[28][1][3]=-a28[3] + v28[1]*v28[2];
A[28][1][4]=a28[2] + v28[1]*v28[3];
A[28][1][5]=0;
A[28][1][6]=0;
A[28][1][7]=0;
A[28][1][8]=0;
A[28][1][9]=0;
A[28][1][10]=0;
A[28][1][11]=0;
A[28][1][12]=0;
A[28][1][13]=0;
A[28][1][14]=0;

A[28][2][1]=a28[5] + v28[3]*v28[4] - v28[1]*v28[6];
A[28][2][2]=a28[3] + v28[1]*v28[2];
A[28][2][3]=-Power(v28[1],2) - Power(v28[3],2);
A[28][2][4]=-a28[1] + v28[2]*v28[3];
A[28][2][5]=0;
A[28][2][6]=0;
A[28][2][7]=0;
A[28][2][8]=0;
A[28][2][9]=0;
A[28][2][10]=0;
A[28][2][11]=0;
A[28][2][12]=0;
A[28][2][13]=0;
A[28][2][14]=0;

A[28][3][1]=a28[6] - v28[2]*v28[4] + v28[1]*v28[5];
A[28][3][2]=-a28[2] + v28[1]*v28[3];
A[28][3][3]=a28[1] + v28[2]*v28[3];
A[28][3][4]=-Power(v28[1],2) - Power(v28[2],2);
A[28][3][5]=0;
A[28][3][6]=0;
A[28][3][7]=0;
A[28][3][8]=0;
A[28][3][9]=0;
A[28][3][10]=0;
A[28][3][11]=0;
A[28][3][12]=0;
A[28][3][13]=0;
A[28][3][14]=0;

A[28][4][1]=0;
A[28][4][2]=0;
A[28][4][3]=a28[6] - v28[2]*v28[4] + v28[1]*v28[5];
A[28][4][4]=-a28[5] - v28[3]*v28[4] + v28[1]*v28[6];
A[28][4][5]=a28[1];
A[28][4][6]=a28[2] - v28[1]*v28[3];
A[28][4][7]=a28[3] + v28[1]*v28[2];
A[28][4][8]=-(v28[2]*v28[3]);
A[28][4][9]=Power(v28[2],2) - Power(v28[3],2);
A[28][4][10]=v28[2]*v28[3];
A[28][4][11]=0;
A[28][4][12]=0;
A[28][4][13]=0;
A[28][4][14]=0;

A[28][5][1]=0;
A[28][5][2]=-a28[6] + v28[2]*v28[4] - v28[1]*v28[5];
A[28][5][3]=0;
A[28][5][4]=a28[4] - v28[3]*v28[5] + v28[2]*v28[6];
A[28][5][5]=v28[1]*v28[3];
A[28][5][6]=a28[1] + v28[2]*v28[3];
A[28][5][7]=-Power(v28[1],2) + Power(v28[3],2);
A[28][5][8]=a28[2];
A[28][5][9]=a28[3] - v28[1]*v28[2];
A[28][5][10]=-(v28[1]*v28[3]);
A[28][5][11]=0;
A[28][5][12]=0;
A[28][5][13]=0;
A[28][5][14]=0;

A[28][6][1]=0;
A[28][6][2]=a28[5] + v28[3]*v28[4] - v28[1]*v28[6];
A[28][6][3]=-a28[4] + v28[3]*v28[5] - v28[2]*v28[6];
A[28][6][4]=0;
A[28][6][5]=-(v28[1]*v28[2]);
A[28][6][6]=Power(v28[1],2) - Power(v28[2],2);
A[28][6][7]=a28[1] - v28[2]*v28[3];
A[28][6][8]=v28[1]*v28[2];
A[28][6][9]=a28[2] + v28[1]*v28[3];
A[28][6][10]=a28[3];
A[28][6][11]=0;
A[28][6][12]=0;
A[28][6][13]=0;
A[28][6][14]=0;


A[29][1][1]=a29[4] - v29[3]*v29[5] + v29[2]*v29[6];
A[29][1][2]=-Power(v29[2],2) - Power(v29[3],2);
A[29][1][3]=-a29[3] + v29[1]*v29[2];
A[29][1][4]=a29[2] + v29[1]*v29[3];
A[29][1][5]=0;
A[29][1][6]=0;
A[29][1][7]=0;
A[29][1][8]=0;
A[29][1][9]=0;
A[29][1][10]=0;
A[29][1][11]=0;
A[29][1][12]=0;
A[29][1][13]=0;
A[29][1][14]=0;

A[29][2][1]=a29[5] + v29[3]*v29[4] - v29[1]*v29[6];
A[29][2][2]=a29[3] + v29[1]*v29[2];
A[29][2][3]=-Power(v29[1],2) - Power(v29[3],2);
A[29][2][4]=-a29[1] + v29[2]*v29[3];
A[29][2][5]=0;
A[29][2][6]=0;
A[29][2][7]=0;
A[29][2][8]=0;
A[29][2][9]=0;
A[29][2][10]=0;
A[29][2][11]=0;
A[29][2][12]=0;
A[29][2][13]=0;
A[29][2][14]=0;

A[29][3][1]=a29[6] - v29[2]*v29[4] + v29[1]*v29[5];
A[29][3][2]=-a29[2] + v29[1]*v29[3];
A[29][3][3]=a29[1] + v29[2]*v29[3];
A[29][3][4]=-Power(v29[1],2) - Power(v29[2],2);
A[29][3][5]=0;
A[29][3][6]=0;
A[29][3][7]=0;
A[29][3][8]=0;
A[29][3][9]=0;
A[29][3][10]=0;
A[29][3][11]=0;
A[29][3][12]=0;
A[29][3][13]=0;
A[29][3][14]=0;

A[29][4][1]=0;
A[29][4][2]=0;
A[29][4][3]=a29[6] - v29[2]*v29[4] + v29[1]*v29[5];
A[29][4][4]=-a29[5] - v29[3]*v29[4] + v29[1]*v29[6];
A[29][4][5]=a29[1];
A[29][4][6]=a29[2] - v29[1]*v29[3];
A[29][4][7]=a29[3] + v29[1]*v29[2];
A[29][4][8]=-(v29[2]*v29[3]);
A[29][4][9]=Power(v29[2],2) - Power(v29[3],2);
A[29][4][10]=v29[2]*v29[3];
A[29][4][11]=0;
A[29][4][12]=0;
A[29][4][13]=0;
A[29][4][14]=0;

A[29][5][1]=0;
A[29][5][2]=-a29[6] + v29[2]*v29[4] - v29[1]*v29[5];
A[29][5][3]=0;
A[29][5][4]=a29[4] - v29[3]*v29[5] + v29[2]*v29[6];
A[29][5][5]=v29[1]*v29[3];
A[29][5][6]=a29[1] + v29[2]*v29[3];
A[29][5][7]=-Power(v29[1],2) + Power(v29[3],2);
A[29][5][8]=a29[2];
A[29][5][9]=a29[3] - v29[1]*v29[2];
A[29][5][10]=-(v29[1]*v29[3]);
A[29][5][11]=0;
A[29][5][12]=0;
A[29][5][13]=0;
A[29][5][14]=0;

A[29][6][1]=0;
A[29][6][2]=a29[5] + v29[3]*v29[4] - v29[1]*v29[6];
A[29][6][3]=-a29[4] + v29[3]*v29[5] - v29[2]*v29[6];
A[29][6][4]=0;
A[29][6][5]=-(v29[1]*v29[2]);
A[29][6][6]=Power(v29[1],2) - Power(v29[2],2);
A[29][6][7]=a29[1] - v29[2]*v29[3];
A[29][6][8]=v29[1]*v29[2];
A[29][6][9]=a29[2] + v29[1]*v29[3];
A[29][6][10]=a29[3];
A[29][6][11]=0;
A[29][6][12]=0;
A[29][6][13]=0;
A[29][6][14]=0;


A[30][1][1]=a30[4] - v30[3]*v30[5] + v30[2]*v30[6];
A[30][1][2]=-Power(v30[2],2) - Power(v30[3],2);
A[30][1][3]=-a30[3] + v30[1]*v30[2];
A[30][1][4]=a30[2] + v30[1]*v30[3];
A[30][1][5]=0;
A[30][1][6]=0;
A[30][1][7]=0;
A[30][1][8]=0;
A[30][1][9]=0;
A[30][1][10]=0;
A[30][1][11]=0;
A[30][1][12]=0;
A[30][1][13]=0;
A[30][1][14]=0;

A[30][2][1]=a30[5] + v30[3]*v30[4] - v30[1]*v30[6];
A[30][2][2]=a30[3] + v30[1]*v30[2];
A[30][2][3]=-Power(v30[1],2) - Power(v30[3],2);
A[30][2][4]=-a30[1] + v30[2]*v30[3];
A[30][2][5]=0;
A[30][2][6]=0;
A[30][2][7]=0;
A[30][2][8]=0;
A[30][2][9]=0;
A[30][2][10]=0;
A[30][2][11]=0;
A[30][2][12]=0;
A[30][2][13]=0;
A[30][2][14]=0;

A[30][3][1]=a30[6] - v30[2]*v30[4] + v30[1]*v30[5];
A[30][3][2]=-a30[2] + v30[1]*v30[3];
A[30][3][3]=a30[1] + v30[2]*v30[3];
A[30][3][4]=-Power(v30[1],2) - Power(v30[2],2);
A[30][3][5]=0;
A[30][3][6]=0;
A[30][3][7]=0;
A[30][3][8]=0;
A[30][3][9]=0;
A[30][3][10]=0;
A[30][3][11]=0;
A[30][3][12]=0;
A[30][3][13]=0;
A[30][3][14]=0;

A[30][4][1]=0;
A[30][4][2]=0;
A[30][4][3]=a30[6] - v30[2]*v30[4] + v30[1]*v30[5];
A[30][4][4]=-a30[5] - v30[3]*v30[4] + v30[1]*v30[6];
A[30][4][5]=a30[1];
A[30][4][6]=a30[2] - v30[1]*v30[3];
A[30][4][7]=a30[3] + v30[1]*v30[2];
A[30][4][8]=-(v30[2]*v30[3]);
A[30][4][9]=Power(v30[2],2) - Power(v30[3],2);
A[30][4][10]=v30[2]*v30[3];
A[30][4][11]=0;
A[30][4][12]=0;
A[30][4][13]=0;
A[30][4][14]=0;

A[30][5][1]=0;
A[30][5][2]=-a30[6] + v30[2]*v30[4] - v30[1]*v30[5];
A[30][5][3]=0;
A[30][5][4]=a30[4] - v30[3]*v30[5] + v30[2]*v30[6];
A[30][5][5]=v30[1]*v30[3];
A[30][5][6]=a30[1] + v30[2]*v30[3];
A[30][5][7]=-Power(v30[1],2) + Power(v30[3],2);
A[30][5][8]=a30[2];
A[30][5][9]=a30[3] - v30[1]*v30[2];
A[30][5][10]=-(v30[1]*v30[3]);
A[30][5][11]=0;
A[30][5][12]=0;
A[30][5][13]=0;
A[30][5][14]=0;

A[30][6][1]=0;
A[30][6][2]=a30[5] + v30[3]*v30[4] - v30[1]*v30[6];
A[30][6][3]=-a30[4] + v30[3]*v30[5] - v30[2]*v30[6];
A[30][6][4]=0;
A[30][6][5]=-(v30[1]*v30[2]);
A[30][6][6]=Power(v30[1],2) - Power(v30[2],2);
A[30][6][7]=a30[1] - v30[2]*v30[3];
A[30][6][8]=v30[1]*v30[2];
A[30][6][9]=a30[2] + v30[1]*v30[3];
A[30][6][10]=a30[3];
A[30][6][11]=0;
A[30][6][12]=0;
A[30][6][13]=0;
A[30][6][14]=0;


A[31][1][1]=a31[4] - v31[3]*v31[5] + v31[2]*v31[6];
A[31][1][2]=-Power(v31[2],2) - Power(v31[3],2);
A[31][1][3]=-a31[3] + v31[1]*v31[2];
A[31][1][4]=a31[2] + v31[1]*v31[3];
A[31][1][5]=0;
A[31][1][6]=0;
A[31][1][7]=0;
A[31][1][8]=0;
A[31][1][9]=0;
A[31][1][10]=0;
A[31][1][11]=0;
A[31][1][12]=0;
A[31][1][13]=0;
A[31][1][14]=0;

A[31][2][1]=a31[5] + v31[3]*v31[4] - v31[1]*v31[6];
A[31][2][2]=a31[3] + v31[1]*v31[2];
A[31][2][3]=-Power(v31[1],2) - Power(v31[3],2);
A[31][2][4]=-a31[1] + v31[2]*v31[3];
A[31][2][5]=0;
A[31][2][6]=0;
A[31][2][7]=0;
A[31][2][8]=0;
A[31][2][9]=0;
A[31][2][10]=0;
A[31][2][11]=0;
A[31][2][12]=0;
A[31][2][13]=0;
A[31][2][14]=0;

A[31][3][1]=a31[6] - v31[2]*v31[4] + v31[1]*v31[5];
A[31][3][2]=-a31[2] + v31[1]*v31[3];
A[31][3][3]=a31[1] + v31[2]*v31[3];
A[31][3][4]=-Power(v31[1],2) - Power(v31[2],2);
A[31][3][5]=0;
A[31][3][6]=0;
A[31][3][7]=0;
A[31][3][8]=0;
A[31][3][9]=0;
A[31][3][10]=0;
A[31][3][11]=0;
A[31][3][12]=0;
A[31][3][13]=0;
A[31][3][14]=0;

A[31][4][1]=0;
A[31][4][2]=0;
A[31][4][3]=a31[6] - v31[2]*v31[4] + v31[1]*v31[5];
A[31][4][4]=-a31[5] - v31[3]*v31[4] + v31[1]*v31[6];
A[31][4][5]=a31[1];
A[31][4][6]=a31[2] - v31[1]*v31[3];
A[31][4][7]=a31[3] + v31[1]*v31[2];
A[31][4][8]=-(v31[2]*v31[3]);
A[31][4][9]=Power(v31[2],2) - Power(v31[3],2);
A[31][4][10]=v31[2]*v31[3];
A[31][4][11]=0;
A[31][4][12]=0;
A[31][4][13]=0;
A[31][4][14]=0;

A[31][5][1]=0;
A[31][5][2]=-a31[6] + v31[2]*v31[4] - v31[1]*v31[5];
A[31][5][3]=0;
A[31][5][4]=a31[4] - v31[3]*v31[5] + v31[2]*v31[6];
A[31][5][5]=v31[1]*v31[3];
A[31][5][6]=a31[1] + v31[2]*v31[3];
A[31][5][7]=-Power(v31[1],2) + Power(v31[3],2);
A[31][5][8]=a31[2];
A[31][5][9]=a31[3] - v31[1]*v31[2];
A[31][5][10]=-(v31[1]*v31[3]);
A[31][5][11]=0;
A[31][5][12]=0;
A[31][5][13]=0;
A[31][5][14]=0;

A[31][6][1]=0;
A[31][6][2]=a31[5] + v31[3]*v31[4] - v31[1]*v31[6];
A[31][6][3]=-a31[4] + v31[3]*v31[5] - v31[2]*v31[6];
A[31][6][4]=0;
A[31][6][5]=-(v31[1]*v31[2]);
A[31][6][6]=Power(v31[1],2) - Power(v31[2],2);
A[31][6][7]=a31[1] - v31[2]*v31[3];
A[31][6][8]=v31[1]*v31[2];
A[31][6][9]=a31[2] + v31[1]*v31[3];
A[31][6][10]=a31[3];
A[31][6][11]=0;
A[31][6][12]=0;
A[31][6][13]=0;
A[31][6][14]=0;


A[32][1][1]=a32[4] - v32[3]*v32[5] + v32[2]*v32[6];
A[32][1][2]=-Power(v32[2],2) - Power(v32[3],2);
A[32][1][3]=-a32[3] + v32[1]*v32[2];
A[32][1][4]=a32[2] + v32[1]*v32[3];
A[32][1][5]=0;
A[32][1][6]=0;
A[32][1][7]=0;
A[32][1][8]=0;
A[32][1][9]=0;
A[32][1][10]=0;
A[32][1][11]=0;
A[32][1][12]=0;
A[32][1][13]=0;
A[32][1][14]=0;

A[32][2][1]=a32[5] + v32[3]*v32[4] - v32[1]*v32[6];
A[32][2][2]=a32[3] + v32[1]*v32[2];
A[32][2][3]=-Power(v32[1],2) - Power(v32[3],2);
A[32][2][4]=-a32[1] + v32[2]*v32[3];
A[32][2][5]=0;
A[32][2][6]=0;
A[32][2][7]=0;
A[32][2][8]=0;
A[32][2][9]=0;
A[32][2][10]=0;
A[32][2][11]=0;
A[32][2][12]=0;
A[32][2][13]=0;
A[32][2][14]=0;

A[32][3][1]=a32[6] - v32[2]*v32[4] + v32[1]*v32[5];
A[32][3][2]=-a32[2] + v32[1]*v32[3];
A[32][3][3]=a32[1] + v32[2]*v32[3];
A[32][3][4]=-Power(v32[1],2) - Power(v32[2],2);
A[32][3][5]=0;
A[32][3][6]=0;
A[32][3][7]=0;
A[32][3][8]=0;
A[32][3][9]=0;
A[32][3][10]=0;
A[32][3][11]=0;
A[32][3][12]=0;
A[32][3][13]=0;
A[32][3][14]=0;

A[32][4][1]=0;
A[32][4][2]=0;
A[32][4][3]=a32[6] - v32[2]*v32[4] + v32[1]*v32[5];
A[32][4][4]=-a32[5] - v32[3]*v32[4] + v32[1]*v32[6];
A[32][4][5]=a32[1];
A[32][4][6]=a32[2] - v32[1]*v32[3];
A[32][4][7]=a32[3] + v32[1]*v32[2];
A[32][4][8]=-(v32[2]*v32[3]);
A[32][4][9]=Power(v32[2],2) - Power(v32[3],2);
A[32][4][10]=v32[2]*v32[3];
A[32][4][11]=0;
A[32][4][12]=0;
A[32][4][13]=0;
A[32][4][14]=0;

A[32][5][1]=0;
A[32][5][2]=-a32[6] + v32[2]*v32[4] - v32[1]*v32[5];
A[32][5][3]=0;
A[32][5][4]=a32[4] - v32[3]*v32[5] + v32[2]*v32[6];
A[32][5][5]=v32[1]*v32[3];
A[32][5][6]=a32[1] + v32[2]*v32[3];
A[32][5][7]=-Power(v32[1],2) + Power(v32[3],2);
A[32][5][8]=a32[2];
A[32][5][9]=a32[3] - v32[1]*v32[2];
A[32][5][10]=-(v32[1]*v32[3]);
A[32][5][11]=0;
A[32][5][12]=0;
A[32][5][13]=0;
A[32][5][14]=0;

A[32][6][1]=0;
A[32][6][2]=a32[5] + v32[3]*v32[4] - v32[1]*v32[6];
A[32][6][3]=-a32[4] + v32[3]*v32[5] - v32[2]*v32[6];
A[32][6][4]=0;
A[32][6][5]=-(v32[1]*v32[2]);
A[32][6][6]=Power(v32[1],2) - Power(v32[2],2);
A[32][6][7]=a32[1] - v32[2]*v32[3];
A[32][6][8]=v32[1]*v32[2];
A[32][6][9]=a32[2] + v32[1]*v32[3];
A[32][6][10]=a32[3];
A[32][6][11]=0;
A[32][6][12]=0;
A[32][6][13]=0;
A[32][6][14]=0;



/* predecessor vectors */
pred[1]=0;
pred[2]=1;
pred[3]=2;
pred[4]=3;
pred[5]=4;
pred[6]=5;
pred[7]=6;
pred[8]=7;
pred[9]=0;
pred[10]=9;
pred[11]=10;
pred[12]=11;
pred[13]=12;
pred[14]=13;
pred[15]=14;
pred[16]=15;
pred[17]=0;
pred[18]=17;
pred[19]=18;
pred[20]=19;
pred[21]=20;
pred[22]=21;
pred[23]=22;
pred[24]=23;
pred[25]=0;
pred[26]=25;
pred[27]=26;
pred[28]=27;
pred[29]=28;
pred[30]=29;
pred[31]=30;
pred[32]=31;

/* output mapping, i.e, which joint is where */
map[0]=0;
map[1]=1;
map[2]=2;
map[3]=3;
map[4]=4;
map[5]=5;
map[6]=6;
map[7]=7;
map[108]=8;
map[8]=9;
map[9]=10;
map[10]=11;
map[11]=12;
map[12]=13;
map[13]=14;
map[14]=15;
map[115]=16;
map[15]=17;
map[16]=18;
map[17]=19;
map[18]=20;
map[19]=21;
map[20]=22;
map[21]=23;
map[122]=24;
map[22]=25;
map[23]=26;
map[24]=27;
map[25]=28;
map[26]=29;
map[27]=30;
map[28]=31;
map[129]=32;

{                                                           
  int ii;                                                   
  int jj;                                                   
  int nn;                                                   
  int mm;                                                   
  int level;                                                
  int xnj=32;                           
  int fbflag=0;                        
                                                            
  for ( ii=xnj; ii>=0; --ii) {                              
    level = ii;                                             
    while (1) {                                             
                                                            
      if (level==ii)                                        
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            U[nn][mm]=A[ii][nn][mm];                        
      else                                                  
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            U[nn][mm]=Unew[nn][mm];                         
                                                            
      if (level == 0) {                                     
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm) {                 
            Unew[nn][mm]=0;                                 
            for (jj=1;jj<=6;++jj)                           
              Unew[nn][mm]+=Xinv[level][nn][jj]*U[jj][mm];  
          }                                                 
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            K[xnj+nn][ii*N_RBD_PARMS+mm]=Unew[nn][mm]*fbflag;
        break;                                              
      } else {                                              
        for (mm=1;mm<=N_RBD_PARMS;++mm) {                   
          K[level][ii*N_RBD_PARMS+mm]=0;                    
          for (nn=1;nn<=6;++nn)                             
            K[level][ii*N_RBD_PARMS+mm]+=st[level][nn]*U[nn][mm];
        }                                                   
      }                                                     
                                                            
      for (nn=1;nn<=6;++nn)                                 
        for (mm=1;mm<=N_RBD_PARMS;++mm) {                   
          Unew[nn][mm]=0;                                   
          for (jj=1;jj<=6;++jj)                             
            Unew[nn][mm]+=Xinv[level][nn][jj]*U[jj][mm];    
        }                                                   
      level=pred[level];                                    
    }                                                       
  }                                                         
}                                                           
                                                            
/* The outputs that are associate with each row of K */
Y[1]=state[1].u;
Y[2]=state[2].u;
Y[3]=state[3].u;
Y[4]=state[4].u;
Y[5]=state[5].u;
Y[6]=state[6].u;
Y[7]=state[7].u;
Y[9]=state[8].u;
Y[10]=state[9].u;
Y[11]=state[10].u;
Y[12]=state[11].u;
Y[13]=state[12].u;
Y[14]=state[13].u;
Y[15]=state[14].u;
Y[17]=state[15].u;
Y[18]=state[16].u;
Y[19]=state[17].u;
Y[20]=state[18].u;
Y[21]=state[19].u;
Y[22]=state[20].u;
Y[23]=state[21].u;
Y[25]=state[22].u;
Y[26]=state[23].u;
Y[27]=state[24].u;
Y[28]=state[25].u;
Y[29]=state[26].u;
Y[30]=state[27].u;
Y[31]=state[28].u;

