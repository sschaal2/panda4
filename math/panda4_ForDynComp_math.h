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



panda4_ForDynCompfunc1();

panda4_ForDynCompfunc2();

panda4_ForDynCompfunc3();

panda4_ForDynCompfunc4();

panda4_ForDynCompfunc5();

panda4_ForDynCompfunc6();

panda4_ForDynCompfunc7();

/* force/torque of base in world coordinates */
fbase[1]=f0[1]*Si00[1][1] + f0[2]*Si00[1][2] + f0[3]*Si00[1][3];
fbase[2]=f0[1]*Si00[2][1] + f0[2]*Si00[2][2] + f0[3]*Si00[2][3];
fbase[3]=f0[1]*Si00[3][1] + f0[2]*Si00[3][2] + f0[3]*Si00[3][3];
fbase[4]=f0[4]*Si00[1][1] + f0[5]*Si00[1][2] + f0[6]*Si00[1][3];
fbase[5]=f0[4]*Si00[2][1] + f0[5]*Si00[2][2] + f0[6]*Si00[2][3];
fbase[6]=f0[4]*Si00[3][1] + f0[5]*Si00[3][2] + f0[6]*Si00[3][3];

/* inverse dynamics torques */
c[1]=f1[6] + fext1[6];
c[2]=f2[6] + fext2[6];
c[3]=f3[6] + fext3[6];
c[4]=f4[6] + fext4[6];
c[5]=f5[6] + fext5[6];
c[6]=f6[6] + fext6[6];
c[7]=f7[6] + fext7[6];
c[8]=0;
c[9]=f9[6] + fext9[6];
c[10]=f10[6] + fext10[6];
c[11]=f11[6] + fext11[6];
c[12]=f12[6] + fext12[6];
c[13]=f13[6] + fext13[6];
c[14]=f14[6] + fext14[6];
c[15]=f15[6] + fext15[6];
c[16]=0;
c[17]=f17[6] + fext17[6];
c[18]=f18[6] + fext18[6];
c[19]=f19[6] + fext19[6];
c[20]=f20[6] + fext20[6];
c[21]=f21[6] + fext21[6];
c[22]=f22[6] + fext22[6];
c[23]=f23[6] + fext23[6];
c[24]=0;
c[25]=f25[6] + fext25[6];
c[26]=f26[6] + fext26[6];
c[27]=f27[6] + fext27[6];
c[28]=f28[6] + fext28[6];
c[29]=f29[6] + fext29[6];
c[30]=f30[6] + fext30[6];
c[31]=f31[6] + fext31[6];
c[32]=0;

/* torques due to external forces */
qext[1]=fext1[6];
qext[2]=fext2[6];
qext[3]=fext3[6];
qext[4]=fext4[6];
qext[5]=fext5[6];
qext[6]=fext6[6];
qext[7]=fext7[6];
qext[8]=0.;
qext[9]=fext9[6];
qext[10]=fext10[6];
qext[11]=fext11[6];
qext[12]=fext12[6];
qext[13]=fext13[6];
qext[14]=fext14[6];
qext[15]=fext15[6];
qext[16]=0.;
qext[17]=fext17[6];
qext[18]=fext18[6];
qext[19]=fext19[6];
qext[20]=fext20[6];
qext[21]=fext21[6];
qext[22]=fext22[6];
qext[23]=fext23[6];
qext[24]=0.;
qext[25]=fext25[6];
qext[26]=fext26[6];
qext[27]=fext27[6];
qext[28]=fext28[6];
qext[29]=fext29[6];
qext[30]=fext30[6];
qext[31]=fext31[6];
qext[32]=0.;

panda4func11();

panda4func12();

panda4func13();

panda4func14();

panda4func15();

panda4func16();

panda4func17();

panda4func18();

panda4func19();

panda4func20();

panda4func21();

panda4func22();

panda4func23();

panda4func24();

panda4func25();

panda4func26();

panda4func27();

panda4func28();

panda4func29();

panda4func30();

panda4func31();

panda4func32();

panda4func33();

panda4func34();

panda4func35();

panda4func36();

panda4func37();

panda4func38();

panda4func39();

panda4func40();

panda4func41();

panda4func42();

panda4func43();

panda4func44();

panda4func45();

panda4func46();

vcross[1]=-(basec[0].xd[3]*baseo[0].ad[2]) + basec[0].xd[2]*baseo[0].ad[3];
vcross[2]=basec[0].xd[3]*baseo[0].ad[1] - basec[0].xd[1]*baseo[0].ad[3];
vcross[3]=-(basec[0].xd[2]*baseo[0].ad[1]) + basec[0].xd[1]*baseo[0].ad[2];

c[1]=c[1] - qext[1] + vcross[1]*K[1][1] + vcross[2]*K[1][2] + vcross[3]*K[1][3];
c[2]=c[2] - qext[2] + vcross[1]*K[2][1] + vcross[2]*K[2][2] + vcross[3]*K[2][3];
c[3]=c[3] - qext[3] + vcross[1]*K[3][1] + vcross[2]*K[3][2] + vcross[3]*K[3][3];
c[4]=c[4] - qext[4] + vcross[1]*K[4][1] + vcross[2]*K[4][2] + vcross[3]*K[4][3];
c[5]=c[5] - qext[5] + vcross[1]*K[5][1] + vcross[2]*K[5][2] + vcross[3]*K[5][3];
c[6]=c[6] - qext[6] + vcross[1]*K[6][1] + vcross[2]*K[6][2] + vcross[3]*K[6][3];
c[7]=c[7] - qext[7] + vcross[1]*K[7][1] + vcross[2]*K[7][2] + vcross[3]*K[7][3];
c[8]=c[8] - qext[8] + vcross[1]*K[8][1] + vcross[2]*K[8][2] + vcross[3]*K[8][3];
c[9]=c[9] - qext[9] + vcross[1]*K[9][1] + vcross[2]*K[9][2] + vcross[3]*K[9][3];
c[10]=c[10] - qext[10] + vcross[1]*K[10][1] + vcross[2]*K[10][2] + vcross[3]*K[10][3];
c[11]=c[11] - qext[11] + vcross[1]*K[11][1] + vcross[2]*K[11][2] + vcross[3]*K[11][3];
c[12]=c[12] - qext[12] + vcross[1]*K[12][1] + vcross[2]*K[12][2] + vcross[3]*K[12][3];
c[13]=c[13] - qext[13] + vcross[1]*K[13][1] + vcross[2]*K[13][2] + vcross[3]*K[13][3];
c[14]=c[14] - qext[14] + vcross[1]*K[14][1] + vcross[2]*K[14][2] + vcross[3]*K[14][3];
c[15]=c[15] - qext[15] + vcross[1]*K[15][1] + vcross[2]*K[15][2] + vcross[3]*K[15][3];
c[16]=c[16] - qext[16] + vcross[1]*K[16][1] + vcross[2]*K[16][2] + vcross[3]*K[16][3];
c[17]=c[17] - qext[17] + vcross[1]*K[17][1] + vcross[2]*K[17][2] + vcross[3]*K[17][3];
c[18]=c[18] - qext[18] + vcross[1]*K[18][1] + vcross[2]*K[18][2] + vcross[3]*K[18][3];
c[19]=c[19] - qext[19] + vcross[1]*K[19][1] + vcross[2]*K[19][2] + vcross[3]*K[19][3];
c[20]=c[20] - qext[20] + vcross[1]*K[20][1] + vcross[2]*K[20][2] + vcross[3]*K[20][3];
c[21]=c[21] - qext[21] + vcross[1]*K[21][1] + vcross[2]*K[21][2] + vcross[3]*K[21][3];
c[22]=c[22] - qext[22] + vcross[1]*K[22][1] + vcross[2]*K[22][2] + vcross[3]*K[22][3];
c[23]=c[23] - qext[23] + vcross[1]*K[23][1] + vcross[2]*K[23][2] + vcross[3]*K[23][3];
c[24]=c[24] - qext[24] + vcross[1]*K[24][1] + vcross[2]*K[24][2] + vcross[3]*K[24][3];
c[25]=c[25] - qext[25] + vcross[1]*K[25][1] + vcross[2]*K[25][2] + vcross[3]*K[25][3];
c[26]=c[26] - qext[26] + vcross[1]*K[26][1] + vcross[2]*K[26][2] + vcross[3]*K[26][3];
c[27]=c[27] - qext[27] + vcross[1]*K[27][1] + vcross[2]*K[27][2] + vcross[3]*K[27][3];
c[28]=c[28] - qext[28] + vcross[1]*K[28][1] + vcross[2]*K[28][2] + vcross[3]*K[28][3];
c[29]=c[29] - qext[29] + vcross[1]*K[29][1] + vcross[2]*K[29][2] + vcross[3]*K[29][3];
c[30]=c[30] - qext[30] + vcross[1]*K[30][1] + vcross[2]*K[30][2] + vcross[3]*K[30][3];
c[31]=c[31] - qext[31] + vcross[1]*K[31][1] + vcross[2]*K[31][2] + vcross[3]*K[31][3];
c[32]=c[32] - qext[32] + vcross[1]*K[32][1] + vcross[2]*K[32][2] + vcross[3]*K[32][3];
c[33]=vcross[1]*Jc0[1][4] + vcross[2]*Jc0[1][5] + vcross[3]*Jc0[1][6] + f0[1]*Si00[1][1] + f0[2]*Si00[1][2] + f0[3]*Si00[1][3];
c[34]=vcross[1]*Jc0[2][4] + vcross[2]*Jc0[2][5] + vcross[3]*Jc0[2][6] + f0[1]*Si00[2][1] + f0[2]*Si00[2][2] + f0[3]*Si00[2][3];
c[35]=vcross[1]*Jc0[3][4] + vcross[2]*Jc0[3][5] + vcross[3]*Jc0[3][6] + f0[1]*Si00[3][1] + f0[2]*Si00[3][2] + f0[3]*Si00[3][3];
c[36]=vcross[1]*Jc0[4][4] + vcross[2]*Jc0[4][5] + vcross[3]*Jc0[4][6] + f0[4]*Si00[1][1] + f0[5]*Si00[1][2] + f0[6]*Si00[1][3];
c[37]=vcross[1]*Jc0[5][4] + vcross[2]*Jc0[5][5] + vcross[3]*Jc0[5][6] + f0[4]*Si00[2][1] + f0[5]*Si00[2][2] + f0[6]*Si00[2][3];
c[38]=vcross[1]*Jc0[6][4] + vcross[2]*Jc0[6][5] + vcross[3]*Jc0[6][6] + f0[4]*Si00[3][1] + f0[5]*Si00[3][2] + f0[6]*Si00[3][3];

uc[1]=state[1].u - c[1] - qext[1];
uc[2]=state[2].u - c[2] - qext[2];
uc[3]=state[3].u - c[3] - qext[3];
uc[4]=state[4].u - c[4] - qext[4];
uc[5]=state[5].u - c[5] - qext[5];
uc[6]=state[6].u - c[6] - qext[6];
uc[7]=state[7].u - c[7] - qext[7];
uc[8]=-c[8] - qext[8];
uc[9]=state[8].u - c[9] - qext[9];
uc[10]=state[9].u - c[10] - qext[10];
uc[11]=state[10].u - c[11] - qext[11];
uc[12]=state[11].u - c[12] - qext[12];
uc[13]=state[12].u - c[13] - qext[13];
uc[14]=state[13].u - c[14] - qext[14];
uc[15]=state[14].u - c[15] - qext[15];
uc[16]=-c[16] - qext[16];
uc[17]=state[15].u - c[17] - qext[17];
uc[18]=state[16].u - c[18] - qext[18];
uc[19]=state[17].u - c[19] - qext[19];
uc[20]=state[18].u - c[20] - qext[20];
uc[21]=state[19].u - c[21] - qext[21];
uc[22]=state[20].u - c[22] - qext[22];
uc[23]=state[21].u - c[23] - qext[23];
uc[24]=-c[24] - qext[24];
uc[25]=state[22].u - c[25] - qext[25];
uc[26]=state[23].u - c[26] - qext[26];
uc[27]=state[24].u - c[27] - qext[27];
uc[28]=state[25].u - c[28] - qext[28];
uc[29]=state[26].u - c[29] - qext[29];
uc[30]=state[27].u - c[30] - qext[30];
uc[31]=state[28].u - c[31] - qext[31];
uc[32]=-c[32] - qext[32];
uc[33]=-c[33] - fext0[1]*Si00[1][1] - fext0[2]*Si00[1][2] - fext0[3]*Si00[1][3];
uc[34]=-c[34] - fext0[1]*Si00[2][1] - fext0[2]*Si00[2][2] - fext0[3]*Si00[2][3];
uc[35]=-c[35] - fext0[1]*Si00[3][1] - fext0[2]*Si00[3][2] - fext0[3]*Si00[3][3];
uc[36]=-c[36] - fext0[4]*Si00[1][1] - fext0[5]*Si00[1][2] - fext0[6]*Si00[1][3];
uc[37]=-c[37] - fext0[4]*Si00[2][1] - fext0[5]*Si00[2][2] - fext0[6]*Si00[2][3];
uc[38]=-c[38] - fext0[4]*Si00[3][1] - fext0[5]*Si00[3][2] - fext0[6]*Si00[3][3];

/* now solve for accelerations: uc = H * thdd           */
/* Note: uc and H are calculated above */
Hmat[1][1] = H[1][1];
Hmat[1][2] = Hmat[2][1] = H[2][1];
Hmat[1][3] = Hmat[3][1] = H[3][1];
Hmat[1][4] = Hmat[4][1] = H[4][1];
Hmat[1][5] = Hmat[5][1] = H[5][1];
Hmat[1][6] = Hmat[6][1] = H[6][1];
Hmat[1][7] = Hmat[7][1] = H[7][1];
Hmat[1][8] = Hmat[8][1] = H[9][1];
Hmat[1][9] = Hmat[9][1] = H[10][1];
Hmat[1][10] = Hmat[10][1] = H[11][1];
Hmat[1][11] = Hmat[11][1] = H[12][1];
Hmat[1][12] = Hmat[12][1] = H[13][1];
Hmat[1][13] = Hmat[13][1] = H[14][1];
Hmat[1][14] = Hmat[14][1] = H[15][1];
Hmat[1][15] = Hmat[15][1] = H[17][1];
Hmat[1][16] = Hmat[16][1] = H[18][1];
Hmat[1][17] = Hmat[17][1] = H[19][1];
Hmat[1][18] = Hmat[18][1] = H[20][1];
Hmat[1][19] = Hmat[19][1] = H[21][1];
Hmat[1][20] = Hmat[20][1] = H[22][1];
Hmat[1][21] = Hmat[21][1] = H[23][1];
Hmat[1][22] = Hmat[22][1] = H[25][1];
Hmat[1][23] = Hmat[23][1] = H[26][1];
Hmat[1][24] = Hmat[24][1] = H[27][1];
Hmat[1][25] = Hmat[25][1] = H[28][1];
Hmat[1][26] = Hmat[26][1] = H[29][1];
Hmat[1][27] = Hmat[27][1] = H[30][1];
Hmat[1][28] = Hmat[28][1] = H[31][1];
Hmat[2][2] = H[2][2];
Hmat[2][3] = Hmat[3][2] = H[3][2];
Hmat[2][4] = Hmat[4][2] = H[4][2];
Hmat[2][5] = Hmat[5][2] = H[5][2];
Hmat[2][6] = Hmat[6][2] = H[6][2];
Hmat[2][7] = Hmat[7][2] = H[7][2];
Hmat[2][8] = Hmat[8][2] = H[9][2];
Hmat[2][9] = Hmat[9][2] = H[10][2];
Hmat[2][10] = Hmat[10][2] = H[11][2];
Hmat[2][11] = Hmat[11][2] = H[12][2];
Hmat[2][12] = Hmat[12][2] = H[13][2];
Hmat[2][13] = Hmat[13][2] = H[14][2];
Hmat[2][14] = Hmat[14][2] = H[15][2];
Hmat[2][15] = Hmat[15][2] = H[17][2];
Hmat[2][16] = Hmat[16][2] = H[18][2];
Hmat[2][17] = Hmat[17][2] = H[19][2];
Hmat[2][18] = Hmat[18][2] = H[20][2];
Hmat[2][19] = Hmat[19][2] = H[21][2];
Hmat[2][20] = Hmat[20][2] = H[22][2];
Hmat[2][21] = Hmat[21][2] = H[23][2];
Hmat[2][22] = Hmat[22][2] = H[25][2];
Hmat[2][23] = Hmat[23][2] = H[26][2];
Hmat[2][24] = Hmat[24][2] = H[27][2];
Hmat[2][25] = Hmat[25][2] = H[28][2];
Hmat[2][26] = Hmat[26][2] = H[29][2];
Hmat[2][27] = Hmat[27][2] = H[30][2];
Hmat[2][28] = Hmat[28][2] = H[31][2];
Hmat[3][3] = H[3][3];
Hmat[3][4] = Hmat[4][3] = H[4][3];
Hmat[3][5] = Hmat[5][3] = H[5][3];
Hmat[3][6] = Hmat[6][3] = H[6][3];
Hmat[3][7] = Hmat[7][3] = H[7][3];
Hmat[3][8] = Hmat[8][3] = H[9][3];
Hmat[3][9] = Hmat[9][3] = H[10][3];
Hmat[3][10] = Hmat[10][3] = H[11][3];
Hmat[3][11] = Hmat[11][3] = H[12][3];
Hmat[3][12] = Hmat[12][3] = H[13][3];
Hmat[3][13] = Hmat[13][3] = H[14][3];
Hmat[3][14] = Hmat[14][3] = H[15][3];
Hmat[3][15] = Hmat[15][3] = H[17][3];
Hmat[3][16] = Hmat[16][3] = H[18][3];
Hmat[3][17] = Hmat[17][3] = H[19][3];
Hmat[3][18] = Hmat[18][3] = H[20][3];
Hmat[3][19] = Hmat[19][3] = H[21][3];
Hmat[3][20] = Hmat[20][3] = H[22][3];
Hmat[3][21] = Hmat[21][3] = H[23][3];
Hmat[3][22] = Hmat[22][3] = H[25][3];
Hmat[3][23] = Hmat[23][3] = H[26][3];
Hmat[3][24] = Hmat[24][3] = H[27][3];
Hmat[3][25] = Hmat[25][3] = H[28][3];
Hmat[3][26] = Hmat[26][3] = H[29][3];
Hmat[3][27] = Hmat[27][3] = H[30][3];
Hmat[3][28] = Hmat[28][3] = H[31][3];
Hmat[4][4] = H[4][4];
Hmat[4][5] = Hmat[5][4] = H[5][4];
Hmat[4][6] = Hmat[6][4] = H[6][4];
Hmat[4][7] = Hmat[7][4] = H[7][4];
Hmat[4][8] = Hmat[8][4] = H[9][4];
Hmat[4][9] = Hmat[9][4] = H[10][4];
Hmat[4][10] = Hmat[10][4] = H[11][4];
Hmat[4][11] = Hmat[11][4] = H[12][4];
Hmat[4][12] = Hmat[12][4] = H[13][4];
Hmat[4][13] = Hmat[13][4] = H[14][4];
Hmat[4][14] = Hmat[14][4] = H[15][4];
Hmat[4][15] = Hmat[15][4] = H[17][4];
Hmat[4][16] = Hmat[16][4] = H[18][4];
Hmat[4][17] = Hmat[17][4] = H[19][4];
Hmat[4][18] = Hmat[18][4] = H[20][4];
Hmat[4][19] = Hmat[19][4] = H[21][4];
Hmat[4][20] = Hmat[20][4] = H[22][4];
Hmat[4][21] = Hmat[21][4] = H[23][4];
Hmat[4][22] = Hmat[22][4] = H[25][4];
Hmat[4][23] = Hmat[23][4] = H[26][4];
Hmat[4][24] = Hmat[24][4] = H[27][4];
Hmat[4][25] = Hmat[25][4] = H[28][4];
Hmat[4][26] = Hmat[26][4] = H[29][4];
Hmat[4][27] = Hmat[27][4] = H[30][4];
Hmat[4][28] = Hmat[28][4] = H[31][4];
Hmat[5][5] = H[5][5];
Hmat[5][6] = Hmat[6][5] = H[6][5];
Hmat[5][7] = Hmat[7][5] = H[7][5];
Hmat[5][8] = Hmat[8][5] = H[9][5];
Hmat[5][9] = Hmat[9][5] = H[10][5];
Hmat[5][10] = Hmat[10][5] = H[11][5];
Hmat[5][11] = Hmat[11][5] = H[12][5];
Hmat[5][12] = Hmat[12][5] = H[13][5];
Hmat[5][13] = Hmat[13][5] = H[14][5];
Hmat[5][14] = Hmat[14][5] = H[15][5];
Hmat[5][15] = Hmat[15][5] = H[17][5];
Hmat[5][16] = Hmat[16][5] = H[18][5];
Hmat[5][17] = Hmat[17][5] = H[19][5];
Hmat[5][18] = Hmat[18][5] = H[20][5];
Hmat[5][19] = Hmat[19][5] = H[21][5];
Hmat[5][20] = Hmat[20][5] = H[22][5];
Hmat[5][21] = Hmat[21][5] = H[23][5];
Hmat[5][22] = Hmat[22][5] = H[25][5];
Hmat[5][23] = Hmat[23][5] = H[26][5];
Hmat[5][24] = Hmat[24][5] = H[27][5];
Hmat[5][25] = Hmat[25][5] = H[28][5];
Hmat[5][26] = Hmat[26][5] = H[29][5];
Hmat[5][27] = Hmat[27][5] = H[30][5];
Hmat[5][28] = Hmat[28][5] = H[31][5];
Hmat[6][6] = H[6][6];
Hmat[6][7] = Hmat[7][6] = H[7][6];
Hmat[6][8] = Hmat[8][6] = H[9][6];
Hmat[6][9] = Hmat[9][6] = H[10][6];
Hmat[6][10] = Hmat[10][6] = H[11][6];
Hmat[6][11] = Hmat[11][6] = H[12][6];
Hmat[6][12] = Hmat[12][6] = H[13][6];
Hmat[6][13] = Hmat[13][6] = H[14][6];
Hmat[6][14] = Hmat[14][6] = H[15][6];
Hmat[6][15] = Hmat[15][6] = H[17][6];
Hmat[6][16] = Hmat[16][6] = H[18][6];
Hmat[6][17] = Hmat[17][6] = H[19][6];
Hmat[6][18] = Hmat[18][6] = H[20][6];
Hmat[6][19] = Hmat[19][6] = H[21][6];
Hmat[6][20] = Hmat[20][6] = H[22][6];
Hmat[6][21] = Hmat[21][6] = H[23][6];
Hmat[6][22] = Hmat[22][6] = H[25][6];
Hmat[6][23] = Hmat[23][6] = H[26][6];
Hmat[6][24] = Hmat[24][6] = H[27][6];
Hmat[6][25] = Hmat[25][6] = H[28][6];
Hmat[6][26] = Hmat[26][6] = H[29][6];
Hmat[6][27] = Hmat[27][6] = H[30][6];
Hmat[6][28] = Hmat[28][6] = H[31][6];
Hmat[7][7] = H[7][7];
Hmat[7][8] = Hmat[8][7] = H[9][7];
Hmat[7][9] = Hmat[9][7] = H[10][7];
Hmat[7][10] = Hmat[10][7] = H[11][7];
Hmat[7][11] = Hmat[11][7] = H[12][7];
Hmat[7][12] = Hmat[12][7] = H[13][7];
Hmat[7][13] = Hmat[13][7] = H[14][7];
Hmat[7][14] = Hmat[14][7] = H[15][7];
Hmat[7][15] = Hmat[15][7] = H[17][7];
Hmat[7][16] = Hmat[16][7] = H[18][7];
Hmat[7][17] = Hmat[17][7] = H[19][7];
Hmat[7][18] = Hmat[18][7] = H[20][7];
Hmat[7][19] = Hmat[19][7] = H[21][7];
Hmat[7][20] = Hmat[20][7] = H[22][7];
Hmat[7][21] = Hmat[21][7] = H[23][7];
Hmat[7][22] = Hmat[22][7] = H[25][7];
Hmat[7][23] = Hmat[23][7] = H[26][7];
Hmat[7][24] = Hmat[24][7] = H[27][7];
Hmat[7][25] = Hmat[25][7] = H[28][7];
Hmat[7][26] = Hmat[26][7] = H[29][7];
Hmat[7][27] = Hmat[27][7] = H[30][7];
Hmat[7][28] = Hmat[28][7] = H[31][7];
Hmat[8][8] = H[9][9];
Hmat[8][9] = Hmat[9][8] = H[10][9];
Hmat[8][10] = Hmat[10][8] = H[11][9];
Hmat[8][11] = Hmat[11][8] = H[12][9];
Hmat[8][12] = Hmat[12][8] = H[13][9];
Hmat[8][13] = Hmat[13][8] = H[14][9];
Hmat[8][14] = Hmat[14][8] = H[15][9];
Hmat[8][15] = Hmat[15][8] = H[17][9];
Hmat[8][16] = Hmat[16][8] = H[18][9];
Hmat[8][17] = Hmat[17][8] = H[19][9];
Hmat[8][18] = Hmat[18][8] = H[20][9];
Hmat[8][19] = Hmat[19][8] = H[21][9];
Hmat[8][20] = Hmat[20][8] = H[22][9];
Hmat[8][21] = Hmat[21][8] = H[23][9];
Hmat[8][22] = Hmat[22][8] = H[25][9];
Hmat[8][23] = Hmat[23][8] = H[26][9];
Hmat[8][24] = Hmat[24][8] = H[27][9];
Hmat[8][25] = Hmat[25][8] = H[28][9];
Hmat[8][26] = Hmat[26][8] = H[29][9];
Hmat[8][27] = Hmat[27][8] = H[30][9];
Hmat[8][28] = Hmat[28][8] = H[31][9];
Hmat[9][9] = H[10][10];
Hmat[9][10] = Hmat[10][9] = H[11][10];
Hmat[9][11] = Hmat[11][9] = H[12][10];
Hmat[9][12] = Hmat[12][9] = H[13][10];
Hmat[9][13] = Hmat[13][9] = H[14][10];
Hmat[9][14] = Hmat[14][9] = H[15][10];
Hmat[9][15] = Hmat[15][9] = H[17][10];
Hmat[9][16] = Hmat[16][9] = H[18][10];
Hmat[9][17] = Hmat[17][9] = H[19][10];
Hmat[9][18] = Hmat[18][9] = H[20][10];
Hmat[9][19] = Hmat[19][9] = H[21][10];
Hmat[9][20] = Hmat[20][9] = H[22][10];
Hmat[9][21] = Hmat[21][9] = H[23][10];
Hmat[9][22] = Hmat[22][9] = H[25][10];
Hmat[9][23] = Hmat[23][9] = H[26][10];
Hmat[9][24] = Hmat[24][9] = H[27][10];
Hmat[9][25] = Hmat[25][9] = H[28][10];
Hmat[9][26] = Hmat[26][9] = H[29][10];
Hmat[9][27] = Hmat[27][9] = H[30][10];
Hmat[9][28] = Hmat[28][9] = H[31][10];
Hmat[10][10] = H[11][11];
Hmat[10][11] = Hmat[11][10] = H[12][11];
Hmat[10][12] = Hmat[12][10] = H[13][11];
Hmat[10][13] = Hmat[13][10] = H[14][11];
Hmat[10][14] = Hmat[14][10] = H[15][11];
Hmat[10][15] = Hmat[15][10] = H[17][11];
Hmat[10][16] = Hmat[16][10] = H[18][11];
Hmat[10][17] = Hmat[17][10] = H[19][11];
Hmat[10][18] = Hmat[18][10] = H[20][11];
Hmat[10][19] = Hmat[19][10] = H[21][11];
Hmat[10][20] = Hmat[20][10] = H[22][11];
Hmat[10][21] = Hmat[21][10] = H[23][11];
Hmat[10][22] = Hmat[22][10] = H[25][11];
Hmat[10][23] = Hmat[23][10] = H[26][11];
Hmat[10][24] = Hmat[24][10] = H[27][11];
Hmat[10][25] = Hmat[25][10] = H[28][11];
Hmat[10][26] = Hmat[26][10] = H[29][11];
Hmat[10][27] = Hmat[27][10] = H[30][11];
Hmat[10][28] = Hmat[28][10] = H[31][11];
Hmat[11][11] = H[12][12];
Hmat[11][12] = Hmat[12][11] = H[13][12];
Hmat[11][13] = Hmat[13][11] = H[14][12];
Hmat[11][14] = Hmat[14][11] = H[15][12];
Hmat[11][15] = Hmat[15][11] = H[17][12];
Hmat[11][16] = Hmat[16][11] = H[18][12];
Hmat[11][17] = Hmat[17][11] = H[19][12];
Hmat[11][18] = Hmat[18][11] = H[20][12];
Hmat[11][19] = Hmat[19][11] = H[21][12];
Hmat[11][20] = Hmat[20][11] = H[22][12];
Hmat[11][21] = Hmat[21][11] = H[23][12];
Hmat[11][22] = Hmat[22][11] = H[25][12];
Hmat[11][23] = Hmat[23][11] = H[26][12];
Hmat[11][24] = Hmat[24][11] = H[27][12];
Hmat[11][25] = Hmat[25][11] = H[28][12];
Hmat[11][26] = Hmat[26][11] = H[29][12];
Hmat[11][27] = Hmat[27][11] = H[30][12];
Hmat[11][28] = Hmat[28][11] = H[31][12];
Hmat[12][12] = H[13][13];
Hmat[12][13] = Hmat[13][12] = H[14][13];
Hmat[12][14] = Hmat[14][12] = H[15][13];
Hmat[12][15] = Hmat[15][12] = H[17][13];
Hmat[12][16] = Hmat[16][12] = H[18][13];
Hmat[12][17] = Hmat[17][12] = H[19][13];
Hmat[12][18] = Hmat[18][12] = H[20][13];
Hmat[12][19] = Hmat[19][12] = H[21][13];
Hmat[12][20] = Hmat[20][12] = H[22][13];
Hmat[12][21] = Hmat[21][12] = H[23][13];
Hmat[12][22] = Hmat[22][12] = H[25][13];
Hmat[12][23] = Hmat[23][12] = H[26][13];
Hmat[12][24] = Hmat[24][12] = H[27][13];
Hmat[12][25] = Hmat[25][12] = H[28][13];
Hmat[12][26] = Hmat[26][12] = H[29][13];
Hmat[12][27] = Hmat[27][12] = H[30][13];
Hmat[12][28] = Hmat[28][12] = H[31][13];
Hmat[13][13] = H[14][14];
Hmat[13][14] = Hmat[14][13] = H[15][14];
Hmat[13][15] = Hmat[15][13] = H[17][14];
Hmat[13][16] = Hmat[16][13] = H[18][14];
Hmat[13][17] = Hmat[17][13] = H[19][14];
Hmat[13][18] = Hmat[18][13] = H[20][14];
Hmat[13][19] = Hmat[19][13] = H[21][14];
Hmat[13][20] = Hmat[20][13] = H[22][14];
Hmat[13][21] = Hmat[21][13] = H[23][14];
Hmat[13][22] = Hmat[22][13] = H[25][14];
Hmat[13][23] = Hmat[23][13] = H[26][14];
Hmat[13][24] = Hmat[24][13] = H[27][14];
Hmat[13][25] = Hmat[25][13] = H[28][14];
Hmat[13][26] = Hmat[26][13] = H[29][14];
Hmat[13][27] = Hmat[27][13] = H[30][14];
Hmat[13][28] = Hmat[28][13] = H[31][14];
Hmat[14][14] = H[15][15];
Hmat[14][15] = Hmat[15][14] = H[17][15];
Hmat[14][16] = Hmat[16][14] = H[18][15];
Hmat[14][17] = Hmat[17][14] = H[19][15];
Hmat[14][18] = Hmat[18][14] = H[20][15];
Hmat[14][19] = Hmat[19][14] = H[21][15];
Hmat[14][20] = Hmat[20][14] = H[22][15];
Hmat[14][21] = Hmat[21][14] = H[23][15];
Hmat[14][22] = Hmat[22][14] = H[25][15];
Hmat[14][23] = Hmat[23][14] = H[26][15];
Hmat[14][24] = Hmat[24][14] = H[27][15];
Hmat[14][25] = Hmat[25][14] = H[28][15];
Hmat[14][26] = Hmat[26][14] = H[29][15];
Hmat[14][27] = Hmat[27][14] = H[30][15];
Hmat[14][28] = Hmat[28][14] = H[31][15];
Hmat[15][15] = H[17][17];
Hmat[15][16] = Hmat[16][15] = H[18][17];
Hmat[15][17] = Hmat[17][15] = H[19][17];
Hmat[15][18] = Hmat[18][15] = H[20][17];
Hmat[15][19] = Hmat[19][15] = H[21][17];
Hmat[15][20] = Hmat[20][15] = H[22][17];
Hmat[15][21] = Hmat[21][15] = H[23][17];
Hmat[15][22] = Hmat[22][15] = H[25][17];
Hmat[15][23] = Hmat[23][15] = H[26][17];
Hmat[15][24] = Hmat[24][15] = H[27][17];
Hmat[15][25] = Hmat[25][15] = H[28][17];
Hmat[15][26] = Hmat[26][15] = H[29][17];
Hmat[15][27] = Hmat[27][15] = H[30][17];
Hmat[15][28] = Hmat[28][15] = H[31][17];
Hmat[16][16] = H[18][18];
Hmat[16][17] = Hmat[17][16] = H[19][18];
Hmat[16][18] = Hmat[18][16] = H[20][18];
Hmat[16][19] = Hmat[19][16] = H[21][18];
Hmat[16][20] = Hmat[20][16] = H[22][18];
Hmat[16][21] = Hmat[21][16] = H[23][18];
Hmat[16][22] = Hmat[22][16] = H[25][18];
Hmat[16][23] = Hmat[23][16] = H[26][18];
Hmat[16][24] = Hmat[24][16] = H[27][18];
Hmat[16][25] = Hmat[25][16] = H[28][18];
Hmat[16][26] = Hmat[26][16] = H[29][18];
Hmat[16][27] = Hmat[27][16] = H[30][18];
Hmat[16][28] = Hmat[28][16] = H[31][18];
Hmat[17][17] = H[19][19];
Hmat[17][18] = Hmat[18][17] = H[20][19];
Hmat[17][19] = Hmat[19][17] = H[21][19];
Hmat[17][20] = Hmat[20][17] = H[22][19];
Hmat[17][21] = Hmat[21][17] = H[23][19];
Hmat[17][22] = Hmat[22][17] = H[25][19];
Hmat[17][23] = Hmat[23][17] = H[26][19];
Hmat[17][24] = Hmat[24][17] = H[27][19];
Hmat[17][25] = Hmat[25][17] = H[28][19];
Hmat[17][26] = Hmat[26][17] = H[29][19];
Hmat[17][27] = Hmat[27][17] = H[30][19];
Hmat[17][28] = Hmat[28][17] = H[31][19];
Hmat[18][18] = H[20][20];
Hmat[18][19] = Hmat[19][18] = H[21][20];
Hmat[18][20] = Hmat[20][18] = H[22][20];
Hmat[18][21] = Hmat[21][18] = H[23][20];
Hmat[18][22] = Hmat[22][18] = H[25][20];
Hmat[18][23] = Hmat[23][18] = H[26][20];
Hmat[18][24] = Hmat[24][18] = H[27][20];
Hmat[18][25] = Hmat[25][18] = H[28][20];
Hmat[18][26] = Hmat[26][18] = H[29][20];
Hmat[18][27] = Hmat[27][18] = H[30][20];
Hmat[18][28] = Hmat[28][18] = H[31][20];
Hmat[19][19] = H[21][21];
Hmat[19][20] = Hmat[20][19] = H[22][21];
Hmat[19][21] = Hmat[21][19] = H[23][21];
Hmat[19][22] = Hmat[22][19] = H[25][21];
Hmat[19][23] = Hmat[23][19] = H[26][21];
Hmat[19][24] = Hmat[24][19] = H[27][21];
Hmat[19][25] = Hmat[25][19] = H[28][21];
Hmat[19][26] = Hmat[26][19] = H[29][21];
Hmat[19][27] = Hmat[27][19] = H[30][21];
Hmat[19][28] = Hmat[28][19] = H[31][21];
Hmat[20][20] = H[22][22];
Hmat[20][21] = Hmat[21][20] = H[23][22];
Hmat[20][22] = Hmat[22][20] = H[25][22];
Hmat[20][23] = Hmat[23][20] = H[26][22];
Hmat[20][24] = Hmat[24][20] = H[27][22];
Hmat[20][25] = Hmat[25][20] = H[28][22];
Hmat[20][26] = Hmat[26][20] = H[29][22];
Hmat[20][27] = Hmat[27][20] = H[30][22];
Hmat[20][28] = Hmat[28][20] = H[31][22];
Hmat[21][21] = H[23][23];
Hmat[21][22] = Hmat[22][21] = H[25][23];
Hmat[21][23] = Hmat[23][21] = H[26][23];
Hmat[21][24] = Hmat[24][21] = H[27][23];
Hmat[21][25] = Hmat[25][21] = H[28][23];
Hmat[21][26] = Hmat[26][21] = H[29][23];
Hmat[21][27] = Hmat[27][21] = H[30][23];
Hmat[21][28] = Hmat[28][21] = H[31][23];
Hmat[22][22] = H[25][25];
Hmat[22][23] = Hmat[23][22] = H[26][25];
Hmat[22][24] = Hmat[24][22] = H[27][25];
Hmat[22][25] = Hmat[25][22] = H[28][25];
Hmat[22][26] = Hmat[26][22] = H[29][25];
Hmat[22][27] = Hmat[27][22] = H[30][25];
Hmat[22][28] = Hmat[28][22] = H[31][25];
Hmat[23][23] = H[26][26];
Hmat[23][24] = Hmat[24][23] = H[27][26];
Hmat[23][25] = Hmat[25][23] = H[28][26];
Hmat[23][26] = Hmat[26][23] = H[29][26];
Hmat[23][27] = Hmat[27][23] = H[30][26];
Hmat[23][28] = Hmat[28][23] = H[31][26];
Hmat[24][24] = H[27][27];
Hmat[24][25] = Hmat[25][24] = H[28][27];
Hmat[24][26] = Hmat[26][24] = H[29][27];
Hmat[24][27] = Hmat[27][24] = H[30][27];
Hmat[24][28] = Hmat[28][24] = H[31][27];
Hmat[25][25] = H[28][28];
Hmat[25][26] = Hmat[26][25] = H[29][28];
Hmat[25][27] = Hmat[27][25] = H[30][28];
Hmat[25][28] = Hmat[28][25] = H[31][28];
Hmat[26][26] = H[29][29];
Hmat[26][27] = Hmat[27][26] = H[30][29];
Hmat[26][28] = Hmat[28][26] = H[31][29];
Hmat[27][27] = H[30][30];
Hmat[27][28] = Hmat[28][27] = H[31][30];
Hmat[28][28] = H[31][31];
cvec[1]  = c[1];
ucvec[1] = uc[1];
cvec[2]  = c[2];
ucvec[2] = uc[2];
cvec[3]  = c[3];
ucvec[3] = uc[3];
cvec[4]  = c[4];
ucvec[4] = uc[4];
cvec[5]  = c[5];
ucvec[5] = uc[5];
cvec[6]  = c[6];
ucvec[6] = uc[6];
cvec[7]  = c[7];
ucvec[7] = uc[7];
cvec[8]  = c[9];
ucvec[8] = uc[9];
cvec[9]  = c[10];
ucvec[9] = uc[10];
cvec[10]  = c[11];
ucvec[10] = uc[11];
cvec[11]  = c[12];
ucvec[11] = uc[12];
cvec[12]  = c[13];
ucvec[12] = uc[13];
cvec[13]  = c[14];
ucvec[13] = uc[14];
cvec[14]  = c[15];
ucvec[14] = uc[15];
cvec[15]  = c[17];
ucvec[15] = uc[17];
cvec[16]  = c[18];
ucvec[16] = uc[18];
cvec[17]  = c[19];
ucvec[17] = uc[19];
cvec[18]  = c[20];
ucvec[18] = uc[20];
cvec[19]  = c[21];
ucvec[19] = uc[21];
cvec[20]  = c[22];
ucvec[20] = uc[22];
cvec[21]  = c[23];
ucvec[21] = uc[23];
cvec[22]  = c[25];
ucvec[22] = uc[25];
cvec[23]  = c[26];
ucvec[23] = uc[26];
cvec[24]  = c[27];
ucvec[24] = uc[27];
cvec[25]  = c[28];
ucvec[25] = uc[28];
cvec[26]  = c[29];
ucvec[26] = uc[29];
cvec[27]  = c[30];
ucvec[27] = uc[30];
cvec[28]  = c[31];
ucvec[28] = uc[31];
 for (i=1; i<=6; ++i) 
      cvec[28+i]=c[32+i];
 for (i=1; i<=6; ++i) 
      ucvec[28+i]=uc[32+i];
my_inv_ldlt(Hmat,ucvec,28,thdd);

state[1].thdd=thdd[1];
state[2].thdd=thdd[2];
state[3].thdd=thdd[3];
state[4].thdd=thdd[4];
state[5].thdd=thdd[5];
state[6].thdd=thdd[6];
state[7].thdd=thdd[7];
state[8].thdd=thdd[8];
state[9].thdd=thdd[9];
state[10].thdd=thdd[10];
state[11].thdd=thdd[11];
state[12].thdd=thdd[12];
state[13].thdd=thdd[13];
state[14].thdd=thdd[14];
state[15].thdd=thdd[15];
state[16].thdd=thdd[16];
state[17].thdd=thdd[17];
state[18].thdd=thdd[18];
state[19].thdd=thdd[19];
state[20].thdd=thdd[20];
state[21].thdd=thdd[21];
state[22].thdd=thdd[22];
state[23].thdd=thdd[23];
state[24].thdd=thdd[24];
state[25].thdd=thdd[25];
state[26].thdd=thdd[26];
state[27].thdd=thdd[27];
state[28].thdd=thdd[28];

