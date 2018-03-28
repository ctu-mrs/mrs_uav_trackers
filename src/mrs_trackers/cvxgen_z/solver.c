/* Produced by CVXGEN, 2018-03-26 17:47:45 -0400.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap_z(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 240; i++)
    gap += workZ.z[i]*workZ.s[i];
  return gap;
}
void set_defaults_z(void) {
  settingsZ.resid_tol = 1e-6;
  settingsZ.eps = 1e-4;
  settingsZ.max_iters = 25;
  settingsZ.refine_steps = 1;
  settingsZ.s_init = 1;
  settingsZ.z_init = 1;
  settingsZ.debug = 0;
  settingsZ.verbose = 1;
  settingsZ.verbose_refinement = 0;
  settingsZ.better_start = 1;
  settingsZ.kkt_reg = 1e-7;
}
void setup_pointers_z(void) {
  workZ.y = workZ.x + 160;
  workZ.s = workZ.x + 280;
  workZ.z = workZ.x + 520;
  varsZ.u_0 = workZ.x + 0;
  varsZ.u_1 = workZ.x + 1;
  varsZ.u_2 = workZ.x + 2;
  varsZ.u_3 = workZ.x + 3;
  varsZ.u_4 = workZ.x + 4;
  varsZ.u_5 = workZ.x + 5;
  varsZ.u_6 = workZ.x + 6;
  varsZ.u_7 = workZ.x + 7;
  varsZ.u_8 = workZ.x + 8;
  varsZ.u_9 = workZ.x + 9;
  varsZ.u_10 = workZ.x + 10;
  varsZ.u_11 = workZ.x + 11;
  varsZ.u_12 = workZ.x + 12;
  varsZ.u_13 = workZ.x + 13;
  varsZ.u_14 = workZ.x + 14;
  varsZ.u_15 = workZ.x + 15;
  varsZ.u_16 = workZ.x + 16;
  varsZ.u_17 = workZ.x + 17;
  varsZ.u_18 = workZ.x + 18;
  varsZ.u_19 = workZ.x + 19;
  varsZ.u_20 = workZ.x + 20;
  varsZ.u_21 = workZ.x + 21;
  varsZ.u_22 = workZ.x + 22;
  varsZ.u_23 = workZ.x + 23;
  varsZ.u_24 = workZ.x + 24;
  varsZ.u_25 = workZ.x + 25;
  varsZ.u_26 = workZ.x + 26;
  varsZ.u_27 = workZ.x + 27;
  varsZ.u_28 = workZ.x + 28;
  varsZ.u_29 = workZ.x + 29;
  varsZ.u_30 = workZ.x + 30;
  varsZ.u_31 = workZ.x + 31;
  varsZ.u_32 = workZ.x + 32;
  varsZ.u_33 = workZ.x + 33;
  varsZ.u_34 = workZ.x + 34;
  varsZ.u_35 = workZ.x + 35;
  varsZ.u_36 = workZ.x + 36;
  varsZ.u_37 = workZ.x + 37;
  varsZ.u_38 = workZ.x + 38;
  varsZ.u_39 = workZ.x + 39;
  varsZ.x_1 = workZ.x + 40;
  varsZ.x_2 = workZ.x + 43;
  varsZ.x_3 = workZ.x + 46;
  varsZ.x_4 = workZ.x + 49;
  varsZ.x_5 = workZ.x + 52;
  varsZ.x_6 = workZ.x + 55;
  varsZ.x_7 = workZ.x + 58;
  varsZ.x_8 = workZ.x + 61;
  varsZ.x_9 = workZ.x + 64;
  varsZ.x_10 = workZ.x + 67;
  varsZ.x_11 = workZ.x + 70;
  varsZ.x_12 = workZ.x + 73;
  varsZ.x_13 = workZ.x + 76;
  varsZ.x_14 = workZ.x + 79;
  varsZ.x_15 = workZ.x + 82;
  varsZ.x_16 = workZ.x + 85;
  varsZ.x_17 = workZ.x + 88;
  varsZ.x_18 = workZ.x + 91;
  varsZ.x_19 = workZ.x + 94;
  varsZ.x_20 = workZ.x + 97;
  varsZ.x_21 = workZ.x + 100;
  varsZ.x_22 = workZ.x + 103;
  varsZ.x_23 = workZ.x + 106;
  varsZ.x_24 = workZ.x + 109;
  varsZ.x_25 = workZ.x + 112;
  varsZ.x_26 = workZ.x + 115;
  varsZ.x_27 = workZ.x + 118;
  varsZ.x_28 = workZ.x + 121;
  varsZ.x_29 = workZ.x + 124;
  varsZ.x_30 = workZ.x + 127;
  varsZ.x_31 = workZ.x + 130;
  varsZ.x_32 = workZ.x + 133;
  varsZ.x_33 = workZ.x + 136;
  varsZ.x_34 = workZ.x + 139;
  varsZ.x_35 = workZ.x + 142;
  varsZ.x_36 = workZ.x + 145;
  varsZ.x_37 = workZ.x + 148;
  varsZ.x_38 = workZ.x + 151;
  varsZ.x_39 = workZ.x + 154;
  varsZ.x_40 = workZ.x + 157;
}
void setup_indexed_paramsZ_z(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  paramsZ.x_ss[1] = paramsZ.x_ss_1;
  paramsZ.x_ss[2] = paramsZ.x_ss_2;
  paramsZ.x_ss[3] = paramsZ.x_ss_3;
  paramsZ.x_ss[4] = paramsZ.x_ss_4;
  paramsZ.x_ss[5] = paramsZ.x_ss_5;
  paramsZ.x_ss[6] = paramsZ.x_ss_6;
  paramsZ.x_ss[7] = paramsZ.x_ss_7;
  paramsZ.x_ss[8] = paramsZ.x_ss_8;
  paramsZ.x_ss[9] = paramsZ.x_ss_9;
  paramsZ.x_ss[10] = paramsZ.x_ss_10;
  paramsZ.x_ss[11] = paramsZ.x_ss_11;
  paramsZ.x_ss[12] = paramsZ.x_ss_12;
  paramsZ.x_ss[13] = paramsZ.x_ss_13;
  paramsZ.x_ss[14] = paramsZ.x_ss_14;
  paramsZ.x_ss[15] = paramsZ.x_ss_15;
  paramsZ.x_ss[16] = paramsZ.x_ss_16;
  paramsZ.x_ss[17] = paramsZ.x_ss_17;
  paramsZ.x_ss[18] = paramsZ.x_ss_18;
  paramsZ.x_ss[19] = paramsZ.x_ss_19;
  paramsZ.x_ss[20] = paramsZ.x_ss_20;
  paramsZ.x_ss[21] = paramsZ.x_ss_21;
  paramsZ.x_ss[22] = paramsZ.x_ss_22;
  paramsZ.x_ss[23] = paramsZ.x_ss_23;
  paramsZ.x_ss[24] = paramsZ.x_ss_24;
  paramsZ.x_ss[25] = paramsZ.x_ss_25;
  paramsZ.x_ss[26] = paramsZ.x_ss_26;
  paramsZ.x_ss[27] = paramsZ.x_ss_27;
  paramsZ.x_ss[28] = paramsZ.x_ss_28;
  paramsZ.x_ss[29] = paramsZ.x_ss_29;
  paramsZ.x_ss[30] = paramsZ.x_ss_30;
  paramsZ.x_ss[31] = paramsZ.x_ss_31;
  paramsZ.x_ss[32] = paramsZ.x_ss_32;
  paramsZ.x_ss[33] = paramsZ.x_ss_33;
  paramsZ.x_ss[34] = paramsZ.x_ss_34;
  paramsZ.x_ss[35] = paramsZ.x_ss_35;
  paramsZ.x_ss[36] = paramsZ.x_ss_36;
  paramsZ.x_ss[37] = paramsZ.x_ss_37;
  paramsZ.x_ss[38] = paramsZ.x_ss_38;
  paramsZ.x_ss[39] = paramsZ.x_ss_39;
  paramsZ.x_ss[40] = paramsZ.x_ss_40;
  paramsZ.x[0] = paramsZ.x_0;
}
void setup_indexed_optvarsZ_z(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  varsZ.x[1] = varsZ.x_1;
  varsZ.x[2] = varsZ.x_2;
  varsZ.x[3] = varsZ.x_3;
  varsZ.x[4] = varsZ.x_4;
  varsZ.x[5] = varsZ.x_5;
  varsZ.x[6] = varsZ.x_6;
  varsZ.x[7] = varsZ.x_7;
  varsZ.x[8] = varsZ.x_8;
  varsZ.x[9] = varsZ.x_9;
  varsZ.x[10] = varsZ.x_10;
  varsZ.x[11] = varsZ.x_11;
  varsZ.x[12] = varsZ.x_12;
  varsZ.x[13] = varsZ.x_13;
  varsZ.x[14] = varsZ.x_14;
  varsZ.x[15] = varsZ.x_15;
  varsZ.x[16] = varsZ.x_16;
  varsZ.x[17] = varsZ.x_17;
  varsZ.x[18] = varsZ.x_18;
  varsZ.x[19] = varsZ.x_19;
  varsZ.x[20] = varsZ.x_20;
  varsZ.x[21] = varsZ.x_21;
  varsZ.x[22] = varsZ.x_22;
  varsZ.x[23] = varsZ.x_23;
  varsZ.x[24] = varsZ.x_24;
  varsZ.x[25] = varsZ.x_25;
  varsZ.x[26] = varsZ.x_26;
  varsZ.x[27] = varsZ.x_27;
  varsZ.x[28] = varsZ.x_28;
  varsZ.x[29] = varsZ.x_29;
  varsZ.x[30] = varsZ.x_30;
  varsZ.x[31] = varsZ.x_31;
  varsZ.x[32] = varsZ.x_32;
  varsZ.x[33] = varsZ.x_33;
  varsZ.x[34] = varsZ.x_34;
  varsZ.x[35] = varsZ.x_35;
  varsZ.x[36] = varsZ.x_36;
  varsZ.x[37] = varsZ.x_37;
  varsZ.x[38] = varsZ.x_38;
  varsZ.x[39] = varsZ.x_39;
  varsZ.x[40] = varsZ.x_40;
  varsZ.u[1] = varsZ.u_1;
  varsZ.u[2] = varsZ.u_2;
  varsZ.u[3] = varsZ.u_3;
  varsZ.u[4] = varsZ.u_4;
  varsZ.u[5] = varsZ.u_5;
  varsZ.u[6] = varsZ.u_6;
  varsZ.u[7] = varsZ.u_7;
  varsZ.u[8] = varsZ.u_8;
  varsZ.u[9] = varsZ.u_9;
  varsZ.u[10] = varsZ.u_10;
  varsZ.u[11] = varsZ.u_11;
  varsZ.u[12] = varsZ.u_12;
  varsZ.u[13] = varsZ.u_13;
  varsZ.u[14] = varsZ.u_14;
  varsZ.u[15] = varsZ.u_15;
  varsZ.u[16] = varsZ.u_16;
  varsZ.u[17] = varsZ.u_17;
  varsZ.u[18] = varsZ.u_18;
  varsZ.u[19] = varsZ.u_19;
  varsZ.u[20] = varsZ.u_20;
  varsZ.u[21] = varsZ.u_21;
  varsZ.u[22] = varsZ.u_22;
  varsZ.u[23] = varsZ.u_23;
  varsZ.u[24] = varsZ.u_24;
  varsZ.u[25] = varsZ.u_25;
  varsZ.u[26] = varsZ.u_26;
  varsZ.u[27] = varsZ.u_27;
  varsZ.u[28] = varsZ.u_28;
  varsZ.u[29] = varsZ.u_29;
  varsZ.u[30] = varsZ.u_30;
  varsZ.u[31] = varsZ.u_31;
  varsZ.u[32] = varsZ.u_32;
  varsZ.u[33] = varsZ.u_33;
  varsZ.u[34] = varsZ.u_34;
  varsZ.u[35] = varsZ.u_35;
  varsZ.u[36] = varsZ.u_36;
  varsZ.u[37] = varsZ.u_37;
  varsZ.u[38] = varsZ.u_38;
  varsZ.u[39] = varsZ.u_39;
  varsZ.u[0] = varsZ.u_0;
}
void setup_indexing_z(void) {
  setup_pointers_z();
  setup_indexed_paramsZ_z();
  setup_indexed_optvarsZ_z();
}
void set_start_z(void) {
  int i;
  for (i = 0; i < 160; i++)
    workZ.x[i] = 0;
  for (i = 0; i < 120; i++)
    workZ.y[i] = 0;
  for (i = 0; i < 240; i++)
    workZ.s[i] = (workZ.h[i] > 0) ? workZ.h[i] : settingsZ.s_init;
  for (i = 0; i < 240; i++)
    workZ.z[i] = settingsZ.z_init;
}
double eval_objv_z(void) {
  int i;
  double objv;
  /* Borrow space in workZ.rhs. */
  multbyP_z(workZ.rhs, workZ.x);
  objv = 0;
  for (i = 0; i < 160; i++)
    objv += workZ.x[i]*workZ.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 160; i++)
    objv += workZ.q[i]*workZ.x[i];
  objv += workZ.quad_600568381440[0]+workZ.quad_898851794944[0]+workZ.quad_88433618944[0]+workZ.quad_240204779520[0]+workZ.quad_635618762752[0]+workZ.quad_732753989632[0]+workZ.quad_427523055616[0]+workZ.quad_976046530560[0]+workZ.quad_688550678528[0]+workZ.quad_304816418816[0]+workZ.quad_819339411456[0]+workZ.quad_101800079360[0]+workZ.quad_976903761920[0]+workZ.quad_141299838976[0]+workZ.quad_343404097536[0]+workZ.quad_815806124032[0]+workZ.quad_997002137600[0]+workZ.quad_141630619648[0]+workZ.quad_835263414272[0]+workZ.quad_962643562496[0]+workZ.quad_928463360000[0]+workZ.quad_380101586944[0]+workZ.quad_150659375104[0]+workZ.quad_392524365824[0]+workZ.quad_653656117248[0]+workZ.quad_70101270528[0]+workZ.quad_514920816640[0]+workZ.quad_674593345536[0]+workZ.quad_563078742016[0]+workZ.quad_758829424640[0]+workZ.quad_779426672640[0]+workZ.quad_59167404032[0]+workZ.quad_532283006976[0]+workZ.quad_792751730688[0]+workZ.quad_677500567552[0]+workZ.quad_848330452992[0]+workZ.quad_31841603584[0]+workZ.quad_193524883456[0]+workZ.quad_637564002304[0]+workZ.quad_646561718272[0];
  return objv;
}
void fillrhs_aff_z(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workZ.rhs;
  r2 = workZ.rhs + 160;
  r3 = workZ.rhs + 400;
  r4 = workZ.rhs + 640;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT_z(r1, workZ.y);
  multbymGT_z(workZ.buffer, workZ.z);
  for (i = 0; i < 160; i++)
    r1[i] += workZ.buffer[i];
  multbyP_z(workZ.buffer, workZ.x);
  for (i = 0; i < 160; i++)
    r1[i] -= workZ.buffer[i] + workZ.q[i];
  /* r2 = -z. */
  for (i = 0; i < 240; i++)
    r2[i] = -workZ.z[i];
  /* r3 = -Gx - s + h. */
  multbymG_z(r3, workZ.x);
  for (i = 0; i < 240; i++)
    r3[i] += -workZ.s[i] + workZ.h[i];
  /* r4 = -Ax + b. */
  multbymA_z(r4, workZ.x);
  for (i = 0; i < 120; i++)
    r4[i] += workZ.b[i];
}
void fillrhs_cc_z(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = workZ.rhs + 160;
  ds_aff = workZ.lhs_aff + 160;
  dz_aff = workZ.lhs_aff + 400;
  mu = 0;
  for (i = 0; i < 240; i++)
    mu += workZ.s[i]*workZ.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 240; i++)
    if (ds_aff[i] < minval*workZ.s[i])
      minval = ds_aff[i]/workZ.s[i];
  for (i = 0; i < 240; i++)
    if (dz_aff[i] < minval*workZ.z[i])
      minval = dz_aff[i]/workZ.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 240; i++)
    sigma += (workZ.s[i] + alpha*ds_aff[i])*
      (workZ.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.004166666666666667;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 160; i++)
    workZ.rhs[i] = 0;
  for (i = 400; i < 760; i++)
    workZ.rhs[i] = 0;
  for (i = 0; i < 240; i++)
    r2[i] = workZ.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine_z(double *target, double *var) {
  int i, j;
  double *residual = workZ.buffer;
  double norm2;
  double *new_var = workZ.buffer2;
  for (j = 0; j < settingsZ.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply_z(residual, var);
    for (i = 0; i < 760; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settingsZ.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve_z(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 760; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settingsZ.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply_z(residual, var);
    for (i = 0; i < 760; i++) {
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
double calc_ineq_resid_squared_z(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG_z(workZ.buffer, workZ.x);
  /* Add -s + h. */
  for (i = 0; i < 240; i++)
    workZ.buffer[i] += -workZ.s[i] + workZ.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 240; i++)
    norm2_squared += workZ.buffer[i]*workZ.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared_z(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA_z(workZ.buffer, workZ.x);
  /* Add +b. */
  for (i = 0; i < 120; i++)
    workZ.buffer[i] += workZ.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 120; i++)
    norm2_squared += workZ.buffer[i]*workZ.buffer[i];
  return norm2_squared;
}
void better_start_z(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  workZ.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 240; i++)
    workZ.s_inv_z[i] = 1;
  fill_KKT_z();
  ldl_factor_z();
  fillrhs_start_z();
  /* Borrow workZ.lhs_aff for the solution. */
  ldl_solve_z(workZ.rhs, workZ.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = workZ.lhs_aff;
  s = workZ.lhs_aff + 160;
  z = workZ.lhs_aff + 400;
  y = workZ.lhs_aff + 640;
  /* Just set x and y as is. */
  for (i = 0; i < 160; i++)
    workZ.x[i] = x[i];
  for (i = 0; i < 120; i++)
    workZ.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 240; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 240; i++)
      workZ.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 240; i++)
      workZ.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 240; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 240; i++)
      workZ.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 240; i++)
      workZ.z[i] = z[i] + alpha;
  }
}
void fillrhs_start_z(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workZ.rhs;
  r2 = workZ.rhs + 160;
  r3 = workZ.rhs + 400;
  r4 = workZ.rhs + 640;
  for (i = 0; i < 160; i++)
    r1[i] = -workZ.q[i];
  for (i = 0; i < 240; i++)
    r2[i] = 0;
  for (i = 0; i < 240; i++)
    r3[i] = workZ.h[i];
  for (i = 0; i < 120; i++)
    r4[i] = workZ.b[i];
}
long solve_z(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  workZ.converged = 0;
  setup_pointers_z();
  pre_ops_z();
#ifndef ZERO_LIBRARY_MODE
  if (settingsZ.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq_z();
  fillh_z();
  fillb_z();
  if (settingsZ.better_start)
    better_start_z();
  else
    set_start_z();
  for (iter = 0; iter < settingsZ.max_iters; iter++) {
    for (i = 0; i < 240; i++) {
      workZ.s_inv[i] = 1.0 / workZ.s[i];
      workZ.s_inv_z[i] = workZ.s_inv[i]*workZ.z[i];
    }
    workZ.block_33[0] = 0;
    fill_KKT_z();
    ldl_factor_z();
    /* Affine scaling directions. */
    fillrhs_aff_z();
    ldl_solve_z(workZ.rhs, workZ.lhs_aff);
    refine_z(workZ.rhs, workZ.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc_z();
    ldl_solve_z(workZ.rhs, workZ.lhs_cc);
    refine_z(workZ.rhs, workZ.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 760; i++)
      workZ.lhs_aff[i] += workZ.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = workZ.lhs_aff;
    ds = workZ.lhs_aff + 160;
    dz = workZ.lhs_aff + 400;
    dy = workZ.lhs_aff + 640;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 240; i++)
      if (ds[i] < minval*workZ.s[i])
        minval = ds[i]/workZ.s[i];
    for (i = 0; i < 240; i++)
      if (dz[i] < minval*workZ.z[i])
        minval = dz[i]/workZ.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 160; i++)
      workZ.x[i] += alpha*dx[i];
    for (i = 0; i < 240; i++)
      workZ.s[i] += alpha*ds[i];
    for (i = 0; i < 240; i++)
      workZ.z[i] += alpha*dz[i];
    for (i = 0; i < 120; i++)
      workZ.y[i] += alpha*dy[i];
    workZ.gap = eval_gap_z();
    workZ.eq_resid_squared = calc_eq_resid_squared_z();
    workZ.ineq_resid_squared = calc_ineq_resid_squared_z();
#ifndef ZERO_LIBRARY_MODE
    if (settingsZ.verbose) {
      workZ.optval = eval_objv_z();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, workZ.optval, workZ.gap, sqrt(workZ.eq_resid_squared),
          sqrt(workZ.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (workZ.gap < settingsZ.eps)
        && (workZ.eq_resid_squared <= settingsZ.resid_tol*settingsZ.resid_tol)
        && (workZ.ineq_resid_squared <= settingsZ.resid_tol*settingsZ.resid_tol)
       ) {
      workZ.converged = 1;
      workZ.optval = eval_objv_z();
      return iter+1;
    }
  }
  return iter;
}
