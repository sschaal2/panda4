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



panda4_InvDynNEfunc1();

panda4_InvDynNEfunc2();

panda4_InvDynNEfunc3();

panda4_InvDynNEfunc4();

panda4_InvDynNEfunc5();

panda4_InvDynNEfunc6();

panda4_InvDynNEfunc7();

/* force/torque of base in world coordinates */
fbase[1]=f0[1]*Si00[1][1] + f0[2]*Si00[1][2] + f0[3]*Si00[1][3];
fbase[2]=f0[1]*Si00[2][1] + f0[2]*Si00[2][2] + f0[3]*Si00[2][3];
fbase[3]=f0[1]*Si00[3][1] + f0[2]*Si00[3][2] + f0[3]*Si00[3][3];
fbase[4]=f0[4]*Si00[1][1] + f0[5]*Si00[1][2] + f0[6]*Si00[1][3];
fbase[5]=f0[4]*Si00[2][1] + f0[5]*Si00[2][2] + f0[6]*Si00[2][3];
fbase[6]=f0[4]*Si00[3][1] + f0[5]*Si00[3][2] + f0[6]*Si00[3][3];

/* inverse dynamics torques */
state[1].uff=-state[1].uex + f1[6] + fext1[6];
state[2].uff=-state[2].uex + f2[6] + fext2[6];
state[3].uff=-state[3].uex + f3[6] + fext3[6];
state[4].uff=-state[4].uex + f4[6] + fext4[6];
state[5].uff=-state[5].uex + f5[6] + fext5[6];
state[6].uff=-state[6].uex + f6[6] + fext6[6];
state[7].uff=-state[7].uex + f7[6] + fext7[6];
state[8].uff=-state[8].uex + f9[6] + fext9[6];
state[9].uff=-state[9].uex + f10[6] + fext10[6];
state[10].uff=-state[10].uex + f11[6] + fext11[6];
state[11].uff=-state[11].uex + f12[6] + fext12[6];
state[12].uff=-state[12].uex + f13[6] + fext13[6];
state[13].uff=-state[13].uex + f14[6] + fext14[6];
state[14].uff=-state[14].uex + f15[6] + fext15[6];
state[15].uff=-state[15].uex + f17[6] + fext17[6];
state[16].uff=-state[16].uex + f18[6] + fext18[6];
state[17].uff=-state[17].uex + f19[6] + fext19[6];
state[18].uff=-state[18].uex + f20[6] + fext20[6];
state[19].uff=-state[19].uex + f21[6] + fext21[6];
state[20].uff=-state[20].uex + f22[6] + fext22[6];
state[21].uff=-state[21].uex + f23[6] + fext23[6];
state[22].uff=-state[22].uex + f25[6] + fext25[6];
state[23].uff=-state[23].uex + f26[6] + fext26[6];
state[24].uff=-state[24].uex + f27[6] + fext27[6];
state[25].uff=-state[25].uex + f28[6] + fext28[6];
state[26].uff=-state[26].uex + f29[6] + fext29[6];
state[27].uff=-state[27].uex + f30[6] + fext30[6];
state[28].uff=-state[28].uex + f31[6] + fext31[6];

/* torques due to external forces */
qext[1]=-state[1].uex + fext1[6];
qext[2]=-state[2].uex + fext2[6];
qext[3]=-state[3].uex + fext3[6];
qext[4]=-state[4].uex + fext4[6];
qext[5]=-state[5].uex + fext5[6];
qext[6]=-state[6].uex + fext6[6];
qext[7]=-state[7].uex + fext7[6];
qext[8]=0.;
qext[9]=-state[8].uex + fext9[6];
qext[10]=-state[9].uex + fext10[6];
qext[11]=-state[10].uex + fext11[6];
qext[12]=-state[11].uex + fext12[6];
qext[13]=-state[12].uex + fext13[6];
qext[14]=-state[13].uex + fext14[6];
qext[15]=-state[14].uex + fext15[6];
qext[16]=0.;
qext[17]=-state[15].uex + fext17[6];
qext[18]=-state[16].uex + fext18[6];
qext[19]=-state[17].uex + fext19[6];
qext[20]=-state[18].uex + fext20[6];
qext[21]=-state[19].uex + fext21[6];
qext[22]=-state[20].uex + fext22[6];
qext[23]=-state[21].uex + fext23[6];
qext[24]=0.;
qext[25]=-state[22].uex + fext25[6];
qext[26]=-state[23].uex + fext26[6];
qext[27]=-state[24].uex + fext27[6];
qext[28]=-state[25].uex + fext28[6];
qext[29]=-state[26].uex + fext29[6];
qext[30]=-state[27].uex + fext30[6];
qext[31]=-state[28].uex + fext31[6];
qext[32]=0.;

