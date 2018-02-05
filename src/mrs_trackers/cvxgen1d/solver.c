/* Produced by CVXGEN, 2018-02-05 04:47:17 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 320; i++)
    gap += work1d.z[i]*work1d.s[i];
  return gap;
}
void set_defaults(void) {
  settings1d.resid_tol = 1e-6;
  settings1d.eps = 1e-4;
  settings1d.max_iters = 25;
  settings1d.refine_steps = 1;
  settings1d.s_init = 1;
  settings1d.z_init = 1;
  settings1d.debug = 0;
  settings1d.verbose = 1;
  settings1d.verbose_refinement = 0;
  settings1d.better_start = 1;
  settings1d.kkt_reg = 1e-7;
}
void setup_pointers(void) {
  work1d.y = work1d.x + 241;
  work1d.s = work1d.x + 361;
  work1d.z = work1d.x + 681;
  vars1d.u_0 = work1d.x + 80;
  vars1d.u_1 = work1d.x + 81;
  vars1d.u_2 = work1d.x + 82;
  vars1d.u_3 = work1d.x + 83;
  vars1d.u_4 = work1d.x + 84;
  vars1d.u_5 = work1d.x + 85;
  vars1d.u_6 = work1d.x + 86;
  vars1d.u_7 = work1d.x + 87;
  vars1d.u_8 = work1d.x + 88;
  vars1d.u_9 = work1d.x + 89;
  vars1d.u_10 = work1d.x + 90;
  vars1d.u_11 = work1d.x + 91;
  vars1d.u_12 = work1d.x + 92;
  vars1d.u_13 = work1d.x + 93;
  vars1d.u_14 = work1d.x + 94;
  vars1d.u_15 = work1d.x + 95;
  vars1d.u_16 = work1d.x + 96;
  vars1d.u_17 = work1d.x + 97;
  vars1d.u_18 = work1d.x + 98;
  vars1d.u_19 = work1d.x + 99;
  vars1d.u_20 = work1d.x + 100;
  vars1d.u_21 = work1d.x + 101;
  vars1d.u_22 = work1d.x + 102;
  vars1d.u_23 = work1d.x + 103;
  vars1d.u_24 = work1d.x + 104;
  vars1d.u_25 = work1d.x + 105;
  vars1d.u_26 = work1d.x + 106;
  vars1d.u_27 = work1d.x + 107;
  vars1d.u_28 = work1d.x + 108;
  vars1d.u_29 = work1d.x + 109;
  vars1d.u_30 = work1d.x + 110;
  vars1d.u_31 = work1d.x + 111;
  vars1d.u_32 = work1d.x + 112;
  vars1d.u_33 = work1d.x + 113;
  vars1d.u_34 = work1d.x + 114;
  vars1d.u_35 = work1d.x + 115;
  vars1d.u_36 = work1d.x + 116;
  vars1d.u_37 = work1d.x + 117;
  vars1d.u_38 = work1d.x + 118;
  vars1d.u_39 = work1d.x + 119;
  vars1d.u_40 = work1d.x + 120;
  vars1d.x_1 = work1d.x + 121;
  vars1d.x_2 = work1d.x + 124;
  vars1d.x_3 = work1d.x + 127;
  vars1d.x_4 = work1d.x + 130;
  vars1d.x_5 = work1d.x + 133;
  vars1d.x_6 = work1d.x + 136;
  vars1d.x_7 = work1d.x + 139;
  vars1d.x_8 = work1d.x + 142;
  vars1d.x_9 = work1d.x + 145;
  vars1d.x_10 = work1d.x + 148;
  vars1d.x_11 = work1d.x + 151;
  vars1d.x_12 = work1d.x + 154;
  vars1d.x_13 = work1d.x + 157;
  vars1d.x_14 = work1d.x + 160;
  vars1d.x_15 = work1d.x + 163;
  vars1d.x_16 = work1d.x + 166;
  vars1d.x_17 = work1d.x + 169;
  vars1d.x_18 = work1d.x + 172;
  vars1d.x_19 = work1d.x + 175;
  vars1d.x_20 = work1d.x + 178;
  vars1d.x_21 = work1d.x + 181;
  vars1d.x_22 = work1d.x + 184;
  vars1d.x_23 = work1d.x + 187;
  vars1d.x_24 = work1d.x + 190;
  vars1d.x_25 = work1d.x + 193;
  vars1d.x_26 = work1d.x + 196;
  vars1d.x_27 = work1d.x + 199;
  vars1d.x_28 = work1d.x + 202;
  vars1d.x_29 = work1d.x + 205;
  vars1d.x_30 = work1d.x + 208;
  vars1d.x_31 = work1d.x + 211;
  vars1d.x_32 = work1d.x + 214;
  vars1d.x_33 = work1d.x + 217;
  vars1d.x_34 = work1d.x + 220;
  vars1d.x_35 = work1d.x + 223;
  vars1d.x_36 = work1d.x + 226;
  vars1d.x_37 = work1d.x + 229;
  vars1d.x_38 = work1d.x + 232;
  vars1d.x_39 = work1d.x + 235;
  vars1d.x_40 = work1d.x + 238;
}
void setup_indexed_params1d(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  params1d.x_ss[1] = params1d.x_ss_1;
  params1d.x_ss[2] = params1d.x_ss_2;
  params1d.x_ss[3] = params1d.x_ss_3;
  params1d.x_ss[4] = params1d.x_ss_4;
  params1d.x_ss[5] = params1d.x_ss_5;
  params1d.x_ss[6] = params1d.x_ss_6;
  params1d.x_ss[7] = params1d.x_ss_7;
  params1d.x_ss[8] = params1d.x_ss_8;
  params1d.x_ss[9] = params1d.x_ss_9;
  params1d.x_ss[10] = params1d.x_ss_10;
  params1d.x_ss[11] = params1d.x_ss_11;
  params1d.x_ss[12] = params1d.x_ss_12;
  params1d.x_ss[13] = params1d.x_ss_13;
  params1d.x_ss[14] = params1d.x_ss_14;
  params1d.x_ss[15] = params1d.x_ss_15;
  params1d.x_ss[16] = params1d.x_ss_16;
  params1d.x_ss[17] = params1d.x_ss_17;
  params1d.x_ss[18] = params1d.x_ss_18;
  params1d.x_ss[19] = params1d.x_ss_19;
  params1d.x_ss[20] = params1d.x_ss_20;
  params1d.x_ss[21] = params1d.x_ss_21;
  params1d.x_ss[22] = params1d.x_ss_22;
  params1d.x_ss[23] = params1d.x_ss_23;
  params1d.x_ss[24] = params1d.x_ss_24;
  params1d.x_ss[25] = params1d.x_ss_25;
  params1d.x_ss[26] = params1d.x_ss_26;
  params1d.x_ss[27] = params1d.x_ss_27;
  params1d.x_ss[28] = params1d.x_ss_28;
  params1d.x_ss[29] = params1d.x_ss_29;
  params1d.x_ss[30] = params1d.x_ss_30;
  params1d.x_ss[31] = params1d.x_ss_31;
  params1d.x_ss[32] = params1d.x_ss_32;
  params1d.x_ss[33] = params1d.x_ss_33;
  params1d.x_ss[34] = params1d.x_ss_34;
  params1d.x_ss[35] = params1d.x_ss_35;
  params1d.x_ss[36] = params1d.x_ss_36;
  params1d.x_ss[37] = params1d.x_ss_37;
  params1d.x_ss[38] = params1d.x_ss_38;
  params1d.x_ss[39] = params1d.x_ss_39;
  params1d.x_ss[40] = params1d.x_ss_40;
  params1d.x[0] = params1d.x_0;
}
void setup_indexed_optvars1d(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  vars1d.x[1] = vars1d.x_1;
  vars1d.x[2] = vars1d.x_2;
  vars1d.x[3] = vars1d.x_3;
  vars1d.x[4] = vars1d.x_4;
  vars1d.x[5] = vars1d.x_5;
  vars1d.x[6] = vars1d.x_6;
  vars1d.x[7] = vars1d.x_7;
  vars1d.x[8] = vars1d.x_8;
  vars1d.x[9] = vars1d.x_9;
  vars1d.x[10] = vars1d.x_10;
  vars1d.x[11] = vars1d.x_11;
  vars1d.x[12] = vars1d.x_12;
  vars1d.x[13] = vars1d.x_13;
  vars1d.x[14] = vars1d.x_14;
  vars1d.x[15] = vars1d.x_15;
  vars1d.x[16] = vars1d.x_16;
  vars1d.x[17] = vars1d.x_17;
  vars1d.x[18] = vars1d.x_18;
  vars1d.x[19] = vars1d.x_19;
  vars1d.x[20] = vars1d.x_20;
  vars1d.x[21] = vars1d.x_21;
  vars1d.x[22] = vars1d.x_22;
  vars1d.x[23] = vars1d.x_23;
  vars1d.x[24] = vars1d.x_24;
  vars1d.x[25] = vars1d.x_25;
  vars1d.x[26] = vars1d.x_26;
  vars1d.x[27] = vars1d.x_27;
  vars1d.x[28] = vars1d.x_28;
  vars1d.x[29] = vars1d.x_29;
  vars1d.x[30] = vars1d.x_30;
  vars1d.x[31] = vars1d.x_31;
  vars1d.x[32] = vars1d.x_32;
  vars1d.x[33] = vars1d.x_33;
  vars1d.x[34] = vars1d.x_34;
  vars1d.x[35] = vars1d.x_35;
  vars1d.x[36] = vars1d.x_36;
  vars1d.x[37] = vars1d.x_37;
  vars1d.x[38] = vars1d.x_38;
  vars1d.x[39] = vars1d.x_39;
  vars1d.x[40] = vars1d.x_40;
  vars1d.u[1] = vars1d.u_1;
  vars1d.u[2] = vars1d.u_2;
  vars1d.u[3] = vars1d.u_3;
  vars1d.u[4] = vars1d.u_4;
  vars1d.u[5] = vars1d.u_5;
  vars1d.u[6] = vars1d.u_6;
  vars1d.u[7] = vars1d.u_7;
  vars1d.u[8] = vars1d.u_8;
  vars1d.u[9] = vars1d.u_9;
  vars1d.u[10] = vars1d.u_10;
  vars1d.u[11] = vars1d.u_11;
  vars1d.u[12] = vars1d.u_12;
  vars1d.u[13] = vars1d.u_13;
  vars1d.u[14] = vars1d.u_14;
  vars1d.u[15] = vars1d.u_15;
  vars1d.u[16] = vars1d.u_16;
  vars1d.u[17] = vars1d.u_17;
  vars1d.u[18] = vars1d.u_18;
  vars1d.u[19] = vars1d.u_19;
  vars1d.u[20] = vars1d.u_20;
  vars1d.u[21] = vars1d.u_21;
  vars1d.u[22] = vars1d.u_22;
  vars1d.u[23] = vars1d.u_23;
  vars1d.u[24] = vars1d.u_24;
  vars1d.u[25] = vars1d.u_25;
  vars1d.u[26] = vars1d.u_26;
  vars1d.u[27] = vars1d.u_27;
  vars1d.u[28] = vars1d.u_28;
  vars1d.u[29] = vars1d.u_29;
  vars1d.u[30] = vars1d.u_30;
  vars1d.u[31] = vars1d.u_31;
  vars1d.u[32] = vars1d.u_32;
  vars1d.u[33] = vars1d.u_33;
  vars1d.u[34] = vars1d.u_34;
  vars1d.u[35] = vars1d.u_35;
  vars1d.u[36] = vars1d.u_36;
  vars1d.u[37] = vars1d.u_37;
  vars1d.u[38] = vars1d.u_38;
  vars1d.u[39] = vars1d.u_39;
  vars1d.u[40] = vars1d.u_40;
  vars1d.u[0] = vars1d.u_0;
}
void setup_indexing(void) {
  setup_pointers();
  setup_indexed_params1d();
  setup_indexed_optvars1d();
}
void set_start(void) {
  int i;
  for (i = 0; i < 241; i++)
    work1d.x[i] = 0;
  for (i = 0; i < 120; i++)
    work1d.y[i] = 0;
  for (i = 0; i < 320; i++)
    work1d.s[i] = (work1d.h[i] > 0) ? work1d.h[i] : settings1d.s_init;
  for (i = 0; i < 320; i++)
    work1d.z[i] = settings1d.z_init;
}
double eval_objv(void) {
  int i;
  double objv;
  /* Borrow space in work1d.rhs. */
  multbyP(work1d.rhs, work1d.x);
  objv = 0;
  for (i = 0; i < 241; i++)
    objv += work1d.x[i]*work1d.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 241; i++)
    objv += work1d.q[i]*work1d.x[i];
  objv += work1d.quad_600568381440[0]+work1d.quad_898851794944[0]+work1d.quad_88433618944[0]+work1d.quad_240204779520[0]+work1d.quad_635618762752[0]+work1d.quad_732753989632[0]+work1d.quad_427523055616[0]+work1d.quad_976046530560[0]+work1d.quad_688550678528[0]+work1d.quad_304816418816[0]+work1d.quad_819339411456[0]+work1d.quad_101800079360[0]+work1d.quad_976903761920[0]+work1d.quad_141299838976[0]+work1d.quad_343404097536[0]+work1d.quad_815806124032[0]+work1d.quad_997002137600[0]+work1d.quad_141630619648[0]+work1d.quad_835263414272[0]+work1d.quad_962643562496[0]+work1d.quad_928463360000[0]+work1d.quad_380101586944[0]+work1d.quad_150659375104[0]+work1d.quad_392524365824[0]+work1d.quad_653656117248[0]+work1d.quad_70101270528[0]+work1d.quad_514920816640[0]+work1d.quad_674593345536[0]+work1d.quad_563078742016[0]+work1d.quad_758829424640[0]+work1d.quad_779426672640[0]+work1d.quad_59167404032[0]+work1d.quad_532283006976[0]+work1d.quad_792751730688[0]+work1d.quad_677500567552[0]+work1d.quad_848330452992[0]+work1d.quad_31841603584[0]+work1d.quad_193524883456[0]+work1d.quad_637564002304[0]+work1d.quad_646561718272[0];
  return objv;
}
void fillrhs_aff(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work1d.rhs;
  r2 = work1d.rhs + 241;
  r3 = work1d.rhs + 561;
  r4 = work1d.rhs + 881;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT(r1, work1d.y);
  multbymGT(work1d.buffer, work1d.z);
  for (i = 0; i < 241; i++)
    r1[i] += work1d.buffer[i];
  multbyP(work1d.buffer, work1d.x);
  for (i = 0; i < 241; i++)
    r1[i] -= work1d.buffer[i] + work1d.q[i];
  /* r2 = -z. */
  for (i = 0; i < 320; i++)
    r2[i] = -work1d.z[i];
  /* r3 = -Gx - s + h. */
  multbymG(r3, work1d.x);
  for (i = 0; i < 320; i++)
    r3[i] += -work1d.s[i] + work1d.h[i];
  /* r4 = -Ax + b. */
  multbymA(r4, work1d.x);
  for (i = 0; i < 120; i++)
    r4[i] += work1d.b[i];
}
void fillrhs_cc(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = work1d.rhs + 241;
  ds_aff = work1d.lhs_aff + 241;
  dz_aff = work1d.lhs_aff + 561;
  mu = 0;
  for (i = 0; i < 320; i++)
    mu += work1d.s[i]*work1d.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 320; i++)
    if (ds_aff[i] < minval*work1d.s[i])
      minval = ds_aff[i]/work1d.s[i];
  for (i = 0; i < 320; i++)
    if (dz_aff[i] < minval*work1d.z[i])
      minval = dz_aff[i]/work1d.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 320; i++)
    sigma += (work1d.s[i] + alpha*ds_aff[i])*
      (work1d.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.003125;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 241; i++)
    work1d.rhs[i] = 0;
  for (i = 561; i < 1001; i++)
    work1d.rhs[i] = 0;
  for (i = 0; i < 320; i++)
    r2[i] = work1d.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine(double *target, double *var) {
  int i, j;
  double *residual = work1d.buffer;
  double norm2;
  double *new_var = work1d.buffer2;
  for (j = 0; j < settings1d.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 1001; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settings1d.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 1001; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settings1d.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 1001; i++) {
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
double calc_ineq_resid_squared(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG(work1d.buffer, work1d.x);
  /* Add -s + h. */
  for (i = 0; i < 320; i++)
    work1d.buffer[i] += -work1d.s[i] + work1d.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 320; i++)
    norm2_squared += work1d.buffer[i]*work1d.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA(work1d.buffer, work1d.x);
  /* Add +b. */
  for (i = 0; i < 120; i++)
    work1d.buffer[i] += work1d.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 120; i++)
    norm2_squared += work1d.buffer[i]*work1d.buffer[i];
  return norm2_squared;
}
void better_start(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  work1d.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 320; i++)
    work1d.s_inv_z[i] = 1;
  fill_KKT();
  ldl_factor();
  fillrhs_start();
  /* Borrow work1d.lhs_aff for the solution. */
  ldl_solve(work1d.rhs, work1d.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = work1d.lhs_aff;
  s = work1d.lhs_aff + 241;
  z = work1d.lhs_aff + 561;
  y = work1d.lhs_aff + 881;
  /* Just set x and y as is. */
  for (i = 0; i < 241; i++)
    work1d.x[i] = x[i];
  for (i = 0; i < 120; i++)
    work1d.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 320; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 320; i++)
      work1d.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 320; i++)
      work1d.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 320; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 320; i++)
      work1d.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 320; i++)
      work1d.z[i] = z[i] + alpha;
  }
}
void fillrhs_start(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work1d.rhs;
  r2 = work1d.rhs + 241;
  r3 = work1d.rhs + 561;
  r4 = work1d.rhs + 881;
  for (i = 0; i < 241; i++)
    r1[i] = -work1d.q[i];
  for (i = 0; i < 320; i++)
    r2[i] = 0;
  for (i = 0; i < 320; i++)
    r3[i] = work1d.h[i];
  for (i = 0; i < 120; i++)
    r4[i] = work1d.b[i];
}
long solve(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  work1d.converged = 0;
  setup_pointers();
  pre_ops();
#ifndef ZERO_LIBRARY_MODE
  if (settings1d.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq();
  fillh();
  fillb();
  if (settings1d.better_start)
    better_start();
  else
    set_start();
  for (iter = 0; iter < settings1d.max_iters; iter++) {
    for (i = 0; i < 320; i++) {
      work1d.s_inv[i] = 1.0 / work1d.s[i];
      work1d.s_inv_z[i] = work1d.s_inv[i]*work1d.z[i];
    }
    work1d.block_33[0] = 0;
    fill_KKT();
    ldl_factor();
    /* Affine scaling directions. */
    fillrhs_aff();
    ldl_solve(work1d.rhs, work1d.lhs_aff);
    refine(work1d.rhs, work1d.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc();
    ldl_solve(work1d.rhs, work1d.lhs_cc);
    refine(work1d.rhs, work1d.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 1001; i++)
      work1d.lhs_aff[i] += work1d.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = work1d.lhs_aff;
    ds = work1d.lhs_aff + 241;
    dz = work1d.lhs_aff + 561;
    dy = work1d.lhs_aff + 881;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 320; i++)
      if (ds[i] < minval*work1d.s[i])
        minval = ds[i]/work1d.s[i];
    for (i = 0; i < 320; i++)
      if (dz[i] < minval*work1d.z[i])
        minval = dz[i]/work1d.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 241; i++)
      work1d.x[i] += alpha*dx[i];
    for (i = 0; i < 320; i++)
      work1d.s[i] += alpha*ds[i];
    for (i = 0; i < 320; i++)
      work1d.z[i] += alpha*dz[i];
    for (i = 0; i < 120; i++)
      work1d.y[i] += alpha*dy[i];
    work1d.gap = eval_gap();
    work1d.eq_resid_squared = calc_eq_resid_squared();
    work1d.ineq_resid_squared = calc_ineq_resid_squared();
#ifndef ZERO_LIBRARY_MODE
    if (settings1d.verbose) {
      work1d.optval = eval_objv();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, work1d.optval, work1d.gap, sqrt(work1d.eq_resid_squared),
          sqrt(work1d.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (work1d.gap < settings1d.eps)
        && (work1d.eq_resid_squared <= settings1d.resid_tol*settings1d.resid_tol)
        && (work1d.ineq_resid_squared <= settings1d.resid_tol*settings1d.resid_tol)
       ) {
      work1d.converged = 1;
      work1d.optval = eval_objv();
      return iter+1;
    }
  }
  return iter;
}
