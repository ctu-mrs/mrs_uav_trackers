/* Produced by CVXGEN, 2018-03-26 08:37:08 -0400.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap_xy(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 640; i++)
    gap += workXY.z[i]*workXY.s[i];
  return gap;
}
void set_defaults_xy(void) {
  settingsXY.resid_tol = 1e-6;
  settingsXY.eps = 1e-4;
  settingsXY.max_iters = 25;
  settingsXY.refine_steps = 1;
  settingsXY.s_init = 1;
  settingsXY.z_init = 1;
  settingsXY.debug = 0;
  settingsXY.verbose = 1;
  settingsXY.verbose_refinement = 0;
  settingsXY.better_start = 1;
  settingsXY.kkt_reg = 1e-7;
}
void setup_pointers_xy(void) {
  workXY.y = workXY.x + 320;
  workXY.s = workXY.x + 560;
  workXY.z = workXY.x + 1200;
  varsXY.u_0 = workXY.x + 0;
  varsXY.u_1 = workXY.x + 2;
  varsXY.u_2 = workXY.x + 4;
  varsXY.u_3 = workXY.x + 6;
  varsXY.u_4 = workXY.x + 8;
  varsXY.u_5 = workXY.x + 10;
  varsXY.u_6 = workXY.x + 12;
  varsXY.u_7 = workXY.x + 14;
  varsXY.u_8 = workXY.x + 16;
  varsXY.u_9 = workXY.x + 18;
  varsXY.u_10 = workXY.x + 20;
  varsXY.u_11 = workXY.x + 22;
  varsXY.u_12 = workXY.x + 24;
  varsXY.u_13 = workXY.x + 26;
  varsXY.u_14 = workXY.x + 28;
  varsXY.u_15 = workXY.x + 30;
  varsXY.u_16 = workXY.x + 32;
  varsXY.u_17 = workXY.x + 34;
  varsXY.u_18 = workXY.x + 36;
  varsXY.u_19 = workXY.x + 38;
  varsXY.u_20 = workXY.x + 40;
  varsXY.u_21 = workXY.x + 42;
  varsXY.u_22 = workXY.x + 44;
  varsXY.u_23 = workXY.x + 46;
  varsXY.u_24 = workXY.x + 48;
  varsXY.u_25 = workXY.x + 50;
  varsXY.u_26 = workXY.x + 52;
  varsXY.u_27 = workXY.x + 54;
  varsXY.u_28 = workXY.x + 56;
  varsXY.u_29 = workXY.x + 58;
  varsXY.u_30 = workXY.x + 60;
  varsXY.u_31 = workXY.x + 62;
  varsXY.u_32 = workXY.x + 64;
  varsXY.u_33 = workXY.x + 66;
  varsXY.u_34 = workXY.x + 68;
  varsXY.u_35 = workXY.x + 70;
  varsXY.u_36 = workXY.x + 72;
  varsXY.u_37 = workXY.x + 74;
  varsXY.u_38 = workXY.x + 76;
  varsXY.u_39 = workXY.x + 78;
  varsXY.x_1 = workXY.x + 80;
  varsXY.x_2 = workXY.x + 86;
  varsXY.x_3 = workXY.x + 92;
  varsXY.x_4 = workXY.x + 98;
  varsXY.x_5 = workXY.x + 104;
  varsXY.x_6 = workXY.x + 110;
  varsXY.x_7 = workXY.x + 116;
  varsXY.x_8 = workXY.x + 122;
  varsXY.x_9 = workXY.x + 128;
  varsXY.x_10 = workXY.x + 134;
  varsXY.x_11 = workXY.x + 140;
  varsXY.x_12 = workXY.x + 146;
  varsXY.x_13 = workXY.x + 152;
  varsXY.x_14 = workXY.x + 158;
  varsXY.x_15 = workXY.x + 164;
  varsXY.x_16 = workXY.x + 170;
  varsXY.x_17 = workXY.x + 176;
  varsXY.x_18 = workXY.x + 182;
  varsXY.x_19 = workXY.x + 188;
  varsXY.x_20 = workXY.x + 194;
  varsXY.x_21 = workXY.x + 200;
  varsXY.x_22 = workXY.x + 206;
  varsXY.x_23 = workXY.x + 212;
  varsXY.x_24 = workXY.x + 218;
  varsXY.x_25 = workXY.x + 224;
  varsXY.x_26 = workXY.x + 230;
  varsXY.x_27 = workXY.x + 236;
  varsXY.x_28 = workXY.x + 242;
  varsXY.x_29 = workXY.x + 248;
  varsXY.x_30 = workXY.x + 254;
  varsXY.x_31 = workXY.x + 260;
  varsXY.x_32 = workXY.x + 266;
  varsXY.x_33 = workXY.x + 272;
  varsXY.x_34 = workXY.x + 278;
  varsXY.x_35 = workXY.x + 284;
  varsXY.x_36 = workXY.x + 290;
  varsXY.x_37 = workXY.x + 296;
  varsXY.x_38 = workXY.x + 302;
  varsXY.x_39 = workXY.x + 308;
  varsXY.x_40 = workXY.x + 314;
}
void setup_indexed_paramsXY_xy(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  paramsXY.x_ss[1] = paramsXY.x_ss_1;
  paramsXY.x_ss[2] = paramsXY.x_ss_2;
  paramsXY.x_ss[3] = paramsXY.x_ss_3;
  paramsXY.x_ss[4] = paramsXY.x_ss_4;
  paramsXY.x_ss[5] = paramsXY.x_ss_5;
  paramsXY.x_ss[6] = paramsXY.x_ss_6;
  paramsXY.x_ss[7] = paramsXY.x_ss_7;
  paramsXY.x_ss[8] = paramsXY.x_ss_8;
  paramsXY.x_ss[9] = paramsXY.x_ss_9;
  paramsXY.x_ss[10] = paramsXY.x_ss_10;
  paramsXY.x_ss[11] = paramsXY.x_ss_11;
  paramsXY.x_ss[12] = paramsXY.x_ss_12;
  paramsXY.x_ss[13] = paramsXY.x_ss_13;
  paramsXY.x_ss[14] = paramsXY.x_ss_14;
  paramsXY.x_ss[15] = paramsXY.x_ss_15;
  paramsXY.x_ss[16] = paramsXY.x_ss_16;
  paramsXY.x_ss[17] = paramsXY.x_ss_17;
  paramsXY.x_ss[18] = paramsXY.x_ss_18;
  paramsXY.x_ss[19] = paramsXY.x_ss_19;
  paramsXY.x_ss[20] = paramsXY.x_ss_20;
  paramsXY.x_ss[21] = paramsXY.x_ss_21;
  paramsXY.x_ss[22] = paramsXY.x_ss_22;
  paramsXY.x_ss[23] = paramsXY.x_ss_23;
  paramsXY.x_ss[24] = paramsXY.x_ss_24;
  paramsXY.x_ss[25] = paramsXY.x_ss_25;
  paramsXY.x_ss[26] = paramsXY.x_ss_26;
  paramsXY.x_ss[27] = paramsXY.x_ss_27;
  paramsXY.x_ss[28] = paramsXY.x_ss_28;
  paramsXY.x_ss[29] = paramsXY.x_ss_29;
  paramsXY.x_ss[30] = paramsXY.x_ss_30;
  paramsXY.x_ss[31] = paramsXY.x_ss_31;
  paramsXY.x_ss[32] = paramsXY.x_ss_32;
  paramsXY.x_ss[33] = paramsXY.x_ss_33;
  paramsXY.x_ss[34] = paramsXY.x_ss_34;
  paramsXY.x_ss[35] = paramsXY.x_ss_35;
  paramsXY.x_ss[36] = paramsXY.x_ss_36;
  paramsXY.x_ss[37] = paramsXY.x_ss_37;
  paramsXY.x_ss[38] = paramsXY.x_ss_38;
  paramsXY.x_ss[39] = paramsXY.x_ss_39;
  paramsXY.x_ss[40] = paramsXY.x_ss_40;
  paramsXY.x[0] = paramsXY.x_0;
  paramsXY.x_max_3[1] = paramsXY.x_max_3_1;
  paramsXY.x_max_3[2] = paramsXY.x_max_3_2;
  paramsXY.x_max_3[3] = paramsXY.x_max_3_3;
  paramsXY.x_max_3[4] = paramsXY.x_max_3_4;
  paramsXY.x_max_3[5] = paramsXY.x_max_3_5;
  paramsXY.x_max_3[6] = paramsXY.x_max_3_6;
  paramsXY.x_max_3[7] = paramsXY.x_max_3_7;
  paramsXY.x_max_3[8] = paramsXY.x_max_3_8;
  paramsXY.x_max_3[9] = paramsXY.x_max_3_9;
  paramsXY.x_max_3[10] = paramsXY.x_max_3_10;
  paramsXY.x_max_3[11] = paramsXY.x_max_3_11;
  paramsXY.x_max_3[12] = paramsXY.x_max_3_12;
  paramsXY.x_max_3[13] = paramsXY.x_max_3_13;
  paramsXY.x_max_3[14] = paramsXY.x_max_3_14;
  paramsXY.x_max_3[15] = paramsXY.x_max_3_15;
  paramsXY.x_max_3[16] = paramsXY.x_max_3_16;
  paramsXY.x_max_3[17] = paramsXY.x_max_3_17;
  paramsXY.x_max_3[18] = paramsXY.x_max_3_18;
  paramsXY.x_max_3[19] = paramsXY.x_max_3_19;
  paramsXY.x_max_3[20] = paramsXY.x_max_3_20;
  paramsXY.x_max_3[21] = paramsXY.x_max_3_21;
  paramsXY.x_max_3[22] = paramsXY.x_max_3_22;
  paramsXY.x_max_3[23] = paramsXY.x_max_3_23;
  paramsXY.x_max_3[24] = paramsXY.x_max_3_24;
  paramsXY.x_max_3[25] = paramsXY.x_max_3_25;
  paramsXY.x_max_3[26] = paramsXY.x_max_3_26;
  paramsXY.x_max_3[27] = paramsXY.x_max_3_27;
  paramsXY.x_max_3[28] = paramsXY.x_max_3_28;
  paramsXY.x_max_3[29] = paramsXY.x_max_3_29;
  paramsXY.x_max_3[30] = paramsXY.x_max_3_30;
  paramsXY.x_max_3[31] = paramsXY.x_max_3_31;
  paramsXY.x_max_3[32] = paramsXY.x_max_3_32;
  paramsXY.x_max_3[33] = paramsXY.x_max_3_33;
  paramsXY.x_max_3[34] = paramsXY.x_max_3_34;
  paramsXY.x_max_3[35] = paramsXY.x_max_3_35;
  paramsXY.x_max_3[36] = paramsXY.x_max_3_36;
  paramsXY.x_max_3[37] = paramsXY.x_max_3_37;
  paramsXY.x_max_3[38] = paramsXY.x_max_3_38;
  paramsXY.x_max_3[39] = paramsXY.x_max_3_39;
  paramsXY.x_max_3[40] = paramsXY.x_max_3_40;
  paramsXY.x_max_2[1] = paramsXY.x_max_2_1;
  paramsXY.x_max_2[2] = paramsXY.x_max_2_2;
  paramsXY.x_max_2[3] = paramsXY.x_max_2_3;
  paramsXY.x_max_2[4] = paramsXY.x_max_2_4;
  paramsXY.x_max_2[5] = paramsXY.x_max_2_5;
  paramsXY.x_max_2[6] = paramsXY.x_max_2_6;
  paramsXY.x_max_2[7] = paramsXY.x_max_2_7;
  paramsXY.x_max_2[8] = paramsXY.x_max_2_8;
  paramsXY.x_max_2[9] = paramsXY.x_max_2_9;
  paramsXY.x_max_2[10] = paramsXY.x_max_2_10;
  paramsXY.x_max_2[11] = paramsXY.x_max_2_11;
  paramsXY.x_max_2[12] = paramsXY.x_max_2_12;
  paramsXY.x_max_2[13] = paramsXY.x_max_2_13;
  paramsXY.x_max_2[14] = paramsXY.x_max_2_14;
  paramsXY.x_max_2[15] = paramsXY.x_max_2_15;
  paramsXY.x_max_2[16] = paramsXY.x_max_2_16;
  paramsXY.x_max_2[17] = paramsXY.x_max_2_17;
  paramsXY.x_max_2[18] = paramsXY.x_max_2_18;
  paramsXY.x_max_2[19] = paramsXY.x_max_2_19;
  paramsXY.x_max_2[20] = paramsXY.x_max_2_20;
  paramsXY.x_max_2[21] = paramsXY.x_max_2_21;
  paramsXY.x_max_2[22] = paramsXY.x_max_2_22;
  paramsXY.x_max_2[23] = paramsXY.x_max_2_23;
  paramsXY.x_max_2[24] = paramsXY.x_max_2_24;
  paramsXY.x_max_2[25] = paramsXY.x_max_2_25;
  paramsXY.x_max_2[26] = paramsXY.x_max_2_26;
  paramsXY.x_max_2[27] = paramsXY.x_max_2_27;
  paramsXY.x_max_2[28] = paramsXY.x_max_2_28;
  paramsXY.x_max_2[29] = paramsXY.x_max_2_29;
  paramsXY.x_max_2[30] = paramsXY.x_max_2_30;
  paramsXY.x_max_2[31] = paramsXY.x_max_2_31;
  paramsXY.x_max_2[32] = paramsXY.x_max_2_32;
  paramsXY.x_max_2[33] = paramsXY.x_max_2_33;
  paramsXY.x_max_2[34] = paramsXY.x_max_2_34;
  paramsXY.x_max_2[35] = paramsXY.x_max_2_35;
  paramsXY.x_max_2[36] = paramsXY.x_max_2_36;
  paramsXY.x_max_2[37] = paramsXY.x_max_2_37;
  paramsXY.x_max_2[38] = paramsXY.x_max_2_38;
  paramsXY.x_max_2[39] = paramsXY.x_max_2_39;
  paramsXY.x_max_2[40] = paramsXY.x_max_2_40;
}
void setup_indexed_optvarsXY_xy(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  varsXY.x[1] = varsXY.x_1;
  varsXY.x[2] = varsXY.x_2;
  varsXY.x[3] = varsXY.x_3;
  varsXY.x[4] = varsXY.x_4;
  varsXY.x[5] = varsXY.x_5;
  varsXY.x[6] = varsXY.x_6;
  varsXY.x[7] = varsXY.x_7;
  varsXY.x[8] = varsXY.x_8;
  varsXY.x[9] = varsXY.x_9;
  varsXY.x[10] = varsXY.x_10;
  varsXY.x[11] = varsXY.x_11;
  varsXY.x[12] = varsXY.x_12;
  varsXY.x[13] = varsXY.x_13;
  varsXY.x[14] = varsXY.x_14;
  varsXY.x[15] = varsXY.x_15;
  varsXY.x[16] = varsXY.x_16;
  varsXY.x[17] = varsXY.x_17;
  varsXY.x[18] = varsXY.x_18;
  varsXY.x[19] = varsXY.x_19;
  varsXY.x[20] = varsXY.x_20;
  varsXY.x[21] = varsXY.x_21;
  varsXY.x[22] = varsXY.x_22;
  varsXY.x[23] = varsXY.x_23;
  varsXY.x[24] = varsXY.x_24;
  varsXY.x[25] = varsXY.x_25;
  varsXY.x[26] = varsXY.x_26;
  varsXY.x[27] = varsXY.x_27;
  varsXY.x[28] = varsXY.x_28;
  varsXY.x[29] = varsXY.x_29;
  varsXY.x[30] = varsXY.x_30;
  varsXY.x[31] = varsXY.x_31;
  varsXY.x[32] = varsXY.x_32;
  varsXY.x[33] = varsXY.x_33;
  varsXY.x[34] = varsXY.x_34;
  varsXY.x[35] = varsXY.x_35;
  varsXY.x[36] = varsXY.x_36;
  varsXY.x[37] = varsXY.x_37;
  varsXY.x[38] = varsXY.x_38;
  varsXY.x[39] = varsXY.x_39;
  varsXY.x[40] = varsXY.x_40;
  varsXY.u[1] = varsXY.u_1;
  varsXY.u[2] = varsXY.u_2;
  varsXY.u[3] = varsXY.u_3;
  varsXY.u[4] = varsXY.u_4;
  varsXY.u[5] = varsXY.u_5;
  varsXY.u[6] = varsXY.u_6;
  varsXY.u[7] = varsXY.u_7;
  varsXY.u[8] = varsXY.u_8;
  varsXY.u[9] = varsXY.u_9;
  varsXY.u[10] = varsXY.u_10;
  varsXY.u[11] = varsXY.u_11;
  varsXY.u[12] = varsXY.u_12;
  varsXY.u[13] = varsXY.u_13;
  varsXY.u[14] = varsXY.u_14;
  varsXY.u[15] = varsXY.u_15;
  varsXY.u[16] = varsXY.u_16;
  varsXY.u[17] = varsXY.u_17;
  varsXY.u[18] = varsXY.u_18;
  varsXY.u[19] = varsXY.u_19;
  varsXY.u[20] = varsXY.u_20;
  varsXY.u[21] = varsXY.u_21;
  varsXY.u[22] = varsXY.u_22;
  varsXY.u[23] = varsXY.u_23;
  varsXY.u[24] = varsXY.u_24;
  varsXY.u[25] = varsXY.u_25;
  varsXY.u[26] = varsXY.u_26;
  varsXY.u[27] = varsXY.u_27;
  varsXY.u[28] = varsXY.u_28;
  varsXY.u[29] = varsXY.u_29;
  varsXY.u[30] = varsXY.u_30;
  varsXY.u[31] = varsXY.u_31;
  varsXY.u[32] = varsXY.u_32;
  varsXY.u[33] = varsXY.u_33;
  varsXY.u[34] = varsXY.u_34;
  varsXY.u[35] = varsXY.u_35;
  varsXY.u[36] = varsXY.u_36;
  varsXY.u[37] = varsXY.u_37;
  varsXY.u[38] = varsXY.u_38;
  varsXY.u[39] = varsXY.u_39;
  varsXY.u[0] = varsXY.u_0;
}
void setup_indexing_xy(void) {
  setup_pointers_xy();
  setup_indexed_paramsXY_xy();
  setup_indexed_optvarsXY_xy();
}
void set_start_xy(void) {
  int i;
  for (i = 0; i < 320; i++)
    workXY.x[i] = 0;
  for (i = 0; i < 240; i++)
    workXY.y[i] = 0;
  for (i = 0; i < 640; i++)
    workXY.s[i] = (workXY.h[i] > 0) ? workXY.h[i] : settingsXY.s_init;
  for (i = 0; i < 640; i++)
    workXY.z[i] = settingsXY.z_init;
}
double eval_objv_xy(void) {
  int i;
  double objv;
  /* Borrow space in workXY.rhs. */
  multbyP_xy(workXY.rhs, workXY.x);
  objv = 0;
  for (i = 0; i < 320; i++)
    objv += workXY.x[i]*workXY.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 320; i++)
    objv += workXY.q[i]*workXY.x[i];
  objv += workXY.quad_600568381440[0]+workXY.quad_898851794944[0]+workXY.quad_88433618944[0]+workXY.quad_240204779520[0]+workXY.quad_635618762752[0]+workXY.quad_732753989632[0]+workXY.quad_427523055616[0]+workXY.quad_976046530560[0]+workXY.quad_688550678528[0]+workXY.quad_304816418816[0]+workXY.quad_819339411456[0]+workXY.quad_101800079360[0]+workXY.quad_976903761920[0]+workXY.quad_141299838976[0]+workXY.quad_343404097536[0]+workXY.quad_815806124032[0]+workXY.quad_997002137600[0]+workXY.quad_141630619648[0]+workXY.quad_835263414272[0]+workXY.quad_962643562496[0]+workXY.quad_928463360000[0]+workXY.quad_380101586944[0]+workXY.quad_150659375104[0]+workXY.quad_392524365824[0]+workXY.quad_653656117248[0]+workXY.quad_70101270528[0]+workXY.quad_514920816640[0]+workXY.quad_674593345536[0]+workXY.quad_563078742016[0]+workXY.quad_758829424640[0]+workXY.quad_779426672640[0]+workXY.quad_59167404032[0]+workXY.quad_532283006976[0]+workXY.quad_792751730688[0]+workXY.quad_677500567552[0]+workXY.quad_848330452992[0]+workXY.quad_31841603584[0]+workXY.quad_193524883456[0]+workXY.quad_637564002304[0]+workXY.quad_646561718272[0];
  return objv;
}
void fillrhs_aff_xy(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workXY.rhs;
  r2 = workXY.rhs + 320;
  r3 = workXY.rhs + 960;
  r4 = workXY.rhs + 1600;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT_xy(r1, workXY.y);
  multbymGT_xy(workXY.buffer, workXY.z);
  for (i = 0; i < 320; i++)
    r1[i] += workXY.buffer[i];
  multbyP_xy(workXY.buffer, workXY.x);
  for (i = 0; i < 320; i++)
    r1[i] -= workXY.buffer[i] + workXY.q[i];
  /* r2 = -z. */
  for (i = 0; i < 640; i++)
    r2[i] = -workXY.z[i];
  /* r3 = -Gx - s + h. */
  multbymG_xy(r3, workXY.x);
  for (i = 0; i < 640; i++)
    r3[i] += -workXY.s[i] + workXY.h[i];
  /* r4 = -Ax + b. */
  multbymA_xy(r4, workXY.x);
  for (i = 0; i < 240; i++)
    r4[i] += workXY.b[i];
}
void fillrhs_cc_xy(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = workXY.rhs + 320;
  ds_aff = workXY.lhs_aff + 320;
  dz_aff = workXY.lhs_aff + 960;
  mu = 0;
  for (i = 0; i < 640; i++)
    mu += workXY.s[i]*workXY.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 640; i++)
    if (ds_aff[i] < minval*workXY.s[i])
      minval = ds_aff[i]/workXY.s[i];
  for (i = 0; i < 640; i++)
    if (dz_aff[i] < minval*workXY.z[i])
      minval = dz_aff[i]/workXY.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 640; i++)
    sigma += (workXY.s[i] + alpha*ds_aff[i])*
      (workXY.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.0015625;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 320; i++)
    workXY.rhs[i] = 0;
  for (i = 960; i < 1840; i++)
    workXY.rhs[i] = 0;
  for (i = 0; i < 640; i++)
    r2[i] = workXY.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine_xy(double *target, double *var) {
  int i, j;
  double *residual = workXY.buffer;
  double norm2;
  double *new_var = workXY.buffer2;
  for (j = 0; j < settingsXY.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply_xy(residual, var);
    for (i = 0; i < 1840; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settingsXY.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve_xy(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 1840; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settingsXY.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply_xy(residual, var);
    for (i = 0; i < 1840; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
    if (j == 0)
      printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
    else
      printf("After refinement we get squared norm %.6g.\n", norm2);
  }
#endif
}
double calc_ineq_resid_squared_xy(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG_xy(workXY.buffer, workXY.x);
  /* Add -s + h. */
  for (i = 0; i < 640; i++)
    workXY.buffer[i] += -workXY.s[i] + workXY.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 640; i++)
    norm2_squared += workXY.buffer[i]*workXY.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared_xy(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA_xy(workXY.buffer, workXY.x);
  /* Add +b. */
  for (i = 0; i < 240; i++)
    workXY.buffer[i] += workXY.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 240; i++)
    norm2_squared += workXY.buffer[i]*workXY.buffer[i];
  return norm2_squared;
}
void better_start_xy(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  workXY.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 640; i++)
    workXY.s_inv_z[i] = 1;
  fill_KKT_xy();
  ldl_factor_xy();
  fillrhs_start_xy();
  /* Borrow workXY.lhs_aff for the solution. */
  ldl_solve_xy(workXY.rhs, workXY.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = workXY.lhs_aff;
  s = workXY.lhs_aff + 320;
  z = workXY.lhs_aff + 960;
  y = workXY.lhs_aff + 1600;
  /* Just set x and y as is. */
  for (i = 0; i < 320; i++)
    workXY.x[i] = x[i];
  for (i = 0; i < 240; i++)
    workXY.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 640; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 640; i++)
      workXY.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 640; i++)
      workXY.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 640; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 640; i++)
      workXY.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 640; i++)
      workXY.z[i] = z[i] + alpha;
  }
}
void fillrhs_start_xy(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workXY.rhs;
  r2 = workXY.rhs + 320;
  r3 = workXY.rhs + 960;
  r4 = workXY.rhs + 1600;
  for (i = 0; i < 320; i++)
    r1[i] = -workXY.q[i];
  for (i = 0; i < 640; i++)
    r2[i] = 0;
  for (i = 0; i < 640; i++)
    r3[i] = workXY.h[i];
  for (i = 0; i < 240; i++)
    r4[i] = workXY.b[i];
}
long solve_xy(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  workXY.converged = 0;
  setup_pointers_xy();
  pre_ops_xy();
#ifndef ZERO_LIBRARY_MODE
  if (settingsXY.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq_xy();
  fillh_xy();
  fillb_xy();
  if (settingsXY.better_start)
    better_start_xy();
  else
    set_start_xy();
  for (iter = 0; iter < settingsXY.max_iters; iter++) {
    for (i = 0; i < 640; i++) {
      workXY.s_inv[i] = 1.0 / workXY.s[i];
      workXY.s_inv_z[i] = workXY.s_inv[i]*workXY.z[i];
    }
    workXY.block_33[0] = 0;
    fill_KKT_xy();
    ldl_factor_xy();
    /* Affine scaling directions. */
    fillrhs_aff_xy();
    ldl_solve_xy(workXY.rhs, workXY.lhs_aff);
    refine_xy(workXY.rhs, workXY.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc_xy();
    ldl_solve_xy(workXY.rhs, workXY.lhs_cc);
    refine_xy(workXY.rhs, workXY.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 1840; i++)
      workXY.lhs_aff[i] += workXY.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = workXY.lhs_aff;
    ds = workXY.lhs_aff + 320;
    dz = workXY.lhs_aff + 960;
    dy = workXY.lhs_aff + 1600;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 640; i++)
      if (ds[i] < minval*workXY.s[i])
        minval = ds[i]/workXY.s[i];
    for (i = 0; i < 640; i++)
      if (dz[i] < minval*workXY.z[i])
        minval = dz[i]/workXY.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 320; i++)
      workXY.x[i] += alpha*dx[i];
    for (i = 0; i < 640; i++)
      workXY.s[i] += alpha*ds[i];
    for (i = 0; i < 640; i++)
      workXY.z[i] += alpha*dz[i];
    for (i = 0; i < 240; i++)
      workXY.y[i] += alpha*dy[i];
    workXY.gap = eval_gap_xy();
    workXY.eq_resid_squared = calc_eq_resid_squared_xy();
    workXY.ineq_resid_squared = calc_ineq_resid_squared_xy();
#ifndef ZERO_LIBRARY_MODE
    if (settingsXY.verbose) {
      workXY.optval = eval_objv_xy();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, workXY.optval, workXY.gap, sqrt(workXY.eq_resid_squared),
          sqrt(workXY.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (workXY.gap < settingsXY.eps)
        && (workXY.eq_resid_squared <= settingsXY.resid_tol*settingsXY.resid_tol)
        && (workXY.ineq_resid_squared <= settingsXY.resid_tol*settingsXY.resid_tol)
       ) {
      workXY.converged = 1;
      workXY.optval = eval_objv_xy();
      return iter+1;
    }
  }
  return iter;
}
