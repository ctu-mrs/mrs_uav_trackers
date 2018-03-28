/* Produced by CVXGEN, 2018-02-17 15:26:42 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap_yaw(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 160; i++)
    gap += workYaw.z[i]*workYaw.s[i];
  return gap;
}
void set_defaults_yaw(void) {
  settingsYaw.resid_tol = 1e-6;
  settingsYaw.eps = 1e-4;
  settingsYaw.max_iters = 25;
  settingsYaw.refine_steps = 1;
  settingsYaw.s_init = 1;
  settingsYaw.z_init = 1;
  settingsYaw.debug = 0;
  settingsYaw.verbose = 1;
  settingsYaw.verbose_refinement = 0;
  settingsYaw.better_start = 1;
  settingsYaw.kkt_reg = 1e-7;
}
void setup_pointers_yaw(void) {
  workYaw.y = workYaw.x + 161;
  workYaw.s = workYaw.x + 281;
  workYaw.z = workYaw.x + 441;
  varsYaw.u_0 = workYaw.x + 0;
  varsYaw.u_1 = workYaw.x + 1;
  varsYaw.u_2 = workYaw.x + 2;
  varsYaw.u_3 = workYaw.x + 3;
  varsYaw.u_4 = workYaw.x + 4;
  varsYaw.u_5 = workYaw.x + 5;
  varsYaw.u_6 = workYaw.x + 6;
  varsYaw.u_7 = workYaw.x + 7;
  varsYaw.u_8 = workYaw.x + 8;
  varsYaw.u_9 = workYaw.x + 9;
  varsYaw.u_10 = workYaw.x + 10;
  varsYaw.u_11 = workYaw.x + 11;
  varsYaw.u_12 = workYaw.x + 12;
  varsYaw.u_13 = workYaw.x + 13;
  varsYaw.u_14 = workYaw.x + 14;
  varsYaw.u_15 = workYaw.x + 15;
  varsYaw.u_16 = workYaw.x + 16;
  varsYaw.u_17 = workYaw.x + 17;
  varsYaw.u_18 = workYaw.x + 18;
  varsYaw.u_19 = workYaw.x + 19;
  varsYaw.u_20 = workYaw.x + 20;
  varsYaw.u_21 = workYaw.x + 21;
  varsYaw.u_22 = workYaw.x + 22;
  varsYaw.u_23 = workYaw.x + 23;
  varsYaw.u_24 = workYaw.x + 24;
  varsYaw.u_25 = workYaw.x + 25;
  varsYaw.u_26 = workYaw.x + 26;
  varsYaw.u_27 = workYaw.x + 27;
  varsYaw.u_28 = workYaw.x + 28;
  varsYaw.u_29 = workYaw.x + 29;
  varsYaw.u_30 = workYaw.x + 30;
  varsYaw.u_31 = workYaw.x + 31;
  varsYaw.u_32 = workYaw.x + 32;
  varsYaw.u_33 = workYaw.x + 33;
  varsYaw.u_34 = workYaw.x + 34;
  varsYaw.u_35 = workYaw.x + 35;
  varsYaw.u_36 = workYaw.x + 36;
  varsYaw.u_37 = workYaw.x + 37;
  varsYaw.u_38 = workYaw.x + 38;
  varsYaw.u_39 = workYaw.x + 39;
  varsYaw.u_40 = workYaw.x + 40;
  varsYaw.x_1 = workYaw.x + 41;
  varsYaw.x_2 = workYaw.x + 44;
  varsYaw.x_3 = workYaw.x + 47;
  varsYaw.x_4 = workYaw.x + 50;
  varsYaw.x_5 = workYaw.x + 53;
  varsYaw.x_6 = workYaw.x + 56;
  varsYaw.x_7 = workYaw.x + 59;
  varsYaw.x_8 = workYaw.x + 62;
  varsYaw.x_9 = workYaw.x + 65;
  varsYaw.x_10 = workYaw.x + 68;
  varsYaw.x_11 = workYaw.x + 71;
  varsYaw.x_12 = workYaw.x + 74;
  varsYaw.x_13 = workYaw.x + 77;
  varsYaw.x_14 = workYaw.x + 80;
  varsYaw.x_15 = workYaw.x + 83;
  varsYaw.x_16 = workYaw.x + 86;
  varsYaw.x_17 = workYaw.x + 89;
  varsYaw.x_18 = workYaw.x + 92;
  varsYaw.x_19 = workYaw.x + 95;
  varsYaw.x_20 = workYaw.x + 98;
  varsYaw.x_21 = workYaw.x + 101;
  varsYaw.x_22 = workYaw.x + 104;
  varsYaw.x_23 = workYaw.x + 107;
  varsYaw.x_24 = workYaw.x + 110;
  varsYaw.x_25 = workYaw.x + 113;
  varsYaw.x_26 = workYaw.x + 116;
  varsYaw.x_27 = workYaw.x + 119;
  varsYaw.x_28 = workYaw.x + 122;
  varsYaw.x_29 = workYaw.x + 125;
  varsYaw.x_30 = workYaw.x + 128;
  varsYaw.x_31 = workYaw.x + 131;
  varsYaw.x_32 = workYaw.x + 134;
  varsYaw.x_33 = workYaw.x + 137;
  varsYaw.x_34 = workYaw.x + 140;
  varsYaw.x_35 = workYaw.x + 143;
  varsYaw.x_36 = workYaw.x + 146;
  varsYaw.x_37 = workYaw.x + 149;
  varsYaw.x_38 = workYaw.x + 152;
  varsYaw.x_39 = workYaw.x + 155;
  varsYaw.x_40 = workYaw.x + 158;
}
void setup_indexed_paramsYaw_yaw(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  paramsYaw.x_ss[1] = paramsYaw.x_ss_1;
  paramsYaw.x_ss[2] = paramsYaw.x_ss_2;
  paramsYaw.x_ss[3] = paramsYaw.x_ss_3;
  paramsYaw.x_ss[4] = paramsYaw.x_ss_4;
  paramsYaw.x_ss[5] = paramsYaw.x_ss_5;
  paramsYaw.x_ss[6] = paramsYaw.x_ss_6;
  paramsYaw.x_ss[7] = paramsYaw.x_ss_7;
  paramsYaw.x_ss[8] = paramsYaw.x_ss_8;
  paramsYaw.x_ss[9] = paramsYaw.x_ss_9;
  paramsYaw.x_ss[10] = paramsYaw.x_ss_10;
  paramsYaw.x_ss[11] = paramsYaw.x_ss_11;
  paramsYaw.x_ss[12] = paramsYaw.x_ss_12;
  paramsYaw.x_ss[13] = paramsYaw.x_ss_13;
  paramsYaw.x_ss[14] = paramsYaw.x_ss_14;
  paramsYaw.x_ss[15] = paramsYaw.x_ss_15;
  paramsYaw.x_ss[16] = paramsYaw.x_ss_16;
  paramsYaw.x_ss[17] = paramsYaw.x_ss_17;
  paramsYaw.x_ss[18] = paramsYaw.x_ss_18;
  paramsYaw.x_ss[19] = paramsYaw.x_ss_19;
  paramsYaw.x_ss[20] = paramsYaw.x_ss_20;
  paramsYaw.x_ss[21] = paramsYaw.x_ss_21;
  paramsYaw.x_ss[22] = paramsYaw.x_ss_22;
  paramsYaw.x_ss[23] = paramsYaw.x_ss_23;
  paramsYaw.x_ss[24] = paramsYaw.x_ss_24;
  paramsYaw.x_ss[25] = paramsYaw.x_ss_25;
  paramsYaw.x_ss[26] = paramsYaw.x_ss_26;
  paramsYaw.x_ss[27] = paramsYaw.x_ss_27;
  paramsYaw.x_ss[28] = paramsYaw.x_ss_28;
  paramsYaw.x_ss[29] = paramsYaw.x_ss_29;
  paramsYaw.x_ss[30] = paramsYaw.x_ss_30;
  paramsYaw.x_ss[31] = paramsYaw.x_ss_31;
  paramsYaw.x_ss[32] = paramsYaw.x_ss_32;
  paramsYaw.x_ss[33] = paramsYaw.x_ss_33;
  paramsYaw.x_ss[34] = paramsYaw.x_ss_34;
  paramsYaw.x_ss[35] = paramsYaw.x_ss_35;
  paramsYaw.x_ss[36] = paramsYaw.x_ss_36;
  paramsYaw.x_ss[37] = paramsYaw.x_ss_37;
  paramsYaw.x_ss[38] = paramsYaw.x_ss_38;
  paramsYaw.x_ss[39] = paramsYaw.x_ss_39;
  paramsYaw.x_ss[40] = paramsYaw.x_ss_40;
  paramsYaw.x[0] = paramsYaw.x_0;
}
void setup_indexed_optvarsYaw_yaw(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  varsYaw.x[1] = varsYaw.x_1;
  varsYaw.x[2] = varsYaw.x_2;
  varsYaw.x[3] = varsYaw.x_3;
  varsYaw.x[4] = varsYaw.x_4;
  varsYaw.x[5] = varsYaw.x_5;
  varsYaw.x[6] = varsYaw.x_6;
  varsYaw.x[7] = varsYaw.x_7;
  varsYaw.x[8] = varsYaw.x_8;
  varsYaw.x[9] = varsYaw.x_9;
  varsYaw.x[10] = varsYaw.x_10;
  varsYaw.x[11] = varsYaw.x_11;
  varsYaw.x[12] = varsYaw.x_12;
  varsYaw.x[13] = varsYaw.x_13;
  varsYaw.x[14] = varsYaw.x_14;
  varsYaw.x[15] = varsYaw.x_15;
  varsYaw.x[16] = varsYaw.x_16;
  varsYaw.x[17] = varsYaw.x_17;
  varsYaw.x[18] = varsYaw.x_18;
  varsYaw.x[19] = varsYaw.x_19;
  varsYaw.x[20] = varsYaw.x_20;
  varsYaw.x[21] = varsYaw.x_21;
  varsYaw.x[22] = varsYaw.x_22;
  varsYaw.x[23] = varsYaw.x_23;
  varsYaw.x[24] = varsYaw.x_24;
  varsYaw.x[25] = varsYaw.x_25;
  varsYaw.x[26] = varsYaw.x_26;
  varsYaw.x[27] = varsYaw.x_27;
  varsYaw.x[28] = varsYaw.x_28;
  varsYaw.x[29] = varsYaw.x_29;
  varsYaw.x[30] = varsYaw.x_30;
  varsYaw.x[31] = varsYaw.x_31;
  varsYaw.x[32] = varsYaw.x_32;
  varsYaw.x[33] = varsYaw.x_33;
  varsYaw.x[34] = varsYaw.x_34;
  varsYaw.x[35] = varsYaw.x_35;
  varsYaw.x[36] = varsYaw.x_36;
  varsYaw.x[37] = varsYaw.x_37;
  varsYaw.x[38] = varsYaw.x_38;
  varsYaw.x[39] = varsYaw.x_39;
  varsYaw.x[40] = varsYaw.x_40;
  varsYaw.u[1] = varsYaw.u_1;
  varsYaw.u[2] = varsYaw.u_2;
  varsYaw.u[3] = varsYaw.u_3;
  varsYaw.u[4] = varsYaw.u_4;
  varsYaw.u[5] = varsYaw.u_5;
  varsYaw.u[6] = varsYaw.u_6;
  varsYaw.u[7] = varsYaw.u_7;
  varsYaw.u[8] = varsYaw.u_8;
  varsYaw.u[9] = varsYaw.u_9;
  varsYaw.u[10] = varsYaw.u_10;
  varsYaw.u[11] = varsYaw.u_11;
  varsYaw.u[12] = varsYaw.u_12;
  varsYaw.u[13] = varsYaw.u_13;
  varsYaw.u[14] = varsYaw.u_14;
  varsYaw.u[15] = varsYaw.u_15;
  varsYaw.u[16] = varsYaw.u_16;
  varsYaw.u[17] = varsYaw.u_17;
  varsYaw.u[18] = varsYaw.u_18;
  varsYaw.u[19] = varsYaw.u_19;
  varsYaw.u[20] = varsYaw.u_20;
  varsYaw.u[21] = varsYaw.u_21;
  varsYaw.u[22] = varsYaw.u_22;
  varsYaw.u[23] = varsYaw.u_23;
  varsYaw.u[24] = varsYaw.u_24;
  varsYaw.u[25] = varsYaw.u_25;
  varsYaw.u[26] = varsYaw.u_26;
  varsYaw.u[27] = varsYaw.u_27;
  varsYaw.u[28] = varsYaw.u_28;
  varsYaw.u[29] = varsYaw.u_29;
  varsYaw.u[30] = varsYaw.u_30;
  varsYaw.u[31] = varsYaw.u_31;
  varsYaw.u[32] = varsYaw.u_32;
  varsYaw.u[33] = varsYaw.u_33;
  varsYaw.u[34] = varsYaw.u_34;
  varsYaw.u[35] = varsYaw.u_35;
  varsYaw.u[36] = varsYaw.u_36;
  varsYaw.u[37] = varsYaw.u_37;
  varsYaw.u[38] = varsYaw.u_38;
  varsYaw.u[39] = varsYaw.u_39;
  varsYaw.u[40] = varsYaw.u_40;
  varsYaw.u[0] = varsYaw.u_0;
}
void setup_indexing_yaw(void) {
  setup_pointers_yaw();
  setup_indexed_paramsYaw_yaw();
  setup_indexed_optvarsYaw_yaw();
}
void set_start_yaw(void) {
  int i;
  for (i = 0; i < 161; i++)
    workYaw.x[i] = 0;
  for (i = 0; i < 120; i++)
    workYaw.y[i] = 0;
  for (i = 0; i < 160; i++)
    workYaw.s[i] = (workYaw.h[i] > 0) ? workYaw.h[i] : settingsYaw.s_init;
  for (i = 0; i < 160; i++)
    workYaw.z[i] = settingsYaw.z_init;
}
double eval_objv_yaw(void) {
  int i;
  double objv;
  /* Borrow space in workYaw.rhs. */
  multbyP_yaw(workYaw.rhs, workYaw.x);
  objv = 0;
  for (i = 0; i < 161; i++)
    objv += workYaw.x[i]*workYaw.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 161; i++)
    objv += workYaw.q[i]*workYaw.x[i];
  objv += workYaw.quad_600568381440[0]+workYaw.quad_898851794944[0]+workYaw.quad_88433618944[0]+workYaw.quad_240204779520[0]+workYaw.quad_635618762752[0]+workYaw.quad_732753989632[0]+workYaw.quad_427523055616[0]+workYaw.quad_976046530560[0]+workYaw.quad_688550678528[0]+workYaw.quad_304816418816[0]+workYaw.quad_819339411456[0]+workYaw.quad_101800079360[0]+workYaw.quad_976903761920[0]+workYaw.quad_141299838976[0]+workYaw.quad_343404097536[0]+workYaw.quad_815806124032[0]+workYaw.quad_997002137600[0]+workYaw.quad_141630619648[0]+workYaw.quad_835263414272[0]+workYaw.quad_962643562496[0]+workYaw.quad_928463360000[0]+workYaw.quad_380101586944[0]+workYaw.quad_150659375104[0]+workYaw.quad_392524365824[0]+workYaw.quad_653656117248[0]+workYaw.quad_70101270528[0]+workYaw.quad_514920816640[0]+workYaw.quad_674593345536[0]+workYaw.quad_563078742016[0]+workYaw.quad_758829424640[0]+workYaw.quad_779426672640[0]+workYaw.quad_59167404032[0]+workYaw.quad_532283006976[0]+workYaw.quad_792751730688[0]+workYaw.quad_677500567552[0]+workYaw.quad_848330452992[0]+workYaw.quad_31841603584[0]+workYaw.quad_193524883456[0]+workYaw.quad_637564002304[0]+workYaw.quad_646561718272[0];
  return objv;
}
void fillrhs_aff_yaw(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workYaw.rhs;
  r2 = workYaw.rhs + 161;
  r3 = workYaw.rhs + 321;
  r4 = workYaw.rhs + 481;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT_yaw(r1, workYaw.y);
  multbymGT_yaw(workYaw.buffer, workYaw.z);
  for (i = 0; i < 161; i++)
    r1[i] += workYaw.buffer[i];
  multbyP_yaw(workYaw.buffer, workYaw.x);
  for (i = 0; i < 161; i++)
    r1[i] -= workYaw.buffer[i] + workYaw.q[i];
  /* r2 = -z. */
  for (i = 0; i < 160; i++)
    r2[i] = -workYaw.z[i];
  /* r3 = -Gx - s + h. */
  multbymG_yaw(r3, workYaw.x);
  for (i = 0; i < 160; i++)
    r3[i] += -workYaw.s[i] + workYaw.h[i];
  /* r4 = -Ax + b. */
  multbymA_yaw(r4, workYaw.x);
  for (i = 0; i < 120; i++)
    r4[i] += workYaw.b[i];
}
void fillrhs_cc_yaw(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = workYaw.rhs + 161;
  ds_aff = workYaw.lhs_aff + 161;
  dz_aff = workYaw.lhs_aff + 321;
  mu = 0;
  for (i = 0; i < 160; i++)
    mu += workYaw.s[i]*workYaw.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 160; i++)
    if (ds_aff[i] < minval*workYaw.s[i])
      minval = ds_aff[i]/workYaw.s[i];
  for (i = 0; i < 160; i++)
    if (dz_aff[i] < minval*workYaw.z[i])
      minval = dz_aff[i]/workYaw.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 160; i++)
    sigma += (workYaw.s[i] + alpha*ds_aff[i])*
      (workYaw.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.00625;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 161; i++)
    workYaw.rhs[i] = 0;
  for (i = 321; i < 601; i++)
    workYaw.rhs[i] = 0;
  for (i = 0; i < 160; i++)
    r2[i] = workYaw.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine_yaw(double *target, double *var) {
  int i, j;
  double *residual = workYaw.buffer;
  double norm2;
  double *new_var = workYaw.buffer2;
  for (j = 0; j < settingsYaw.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply_yaw(residual, var);
    for (i = 0; i < 601; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settingsYaw.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve_yaw(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 601; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settingsYaw.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply_yaw(residual, var);
    for (i = 0; i < 601; i++) {
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
double calc_ineq_resid_squared_yaw(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG_yaw(workYaw.buffer, workYaw.x);
  /* Add -s + h. */
  for (i = 0; i < 160; i++)
    workYaw.buffer[i] += -workYaw.s[i] + workYaw.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 160; i++)
    norm2_squared += workYaw.buffer[i]*workYaw.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared_yaw(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA_yaw(workYaw.buffer, workYaw.x);
  /* Add +b. */
  for (i = 0; i < 120; i++)
    workYaw.buffer[i] += workYaw.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 120; i++)
    norm2_squared += workYaw.buffer[i]*workYaw.buffer[i];
  return norm2_squared;
}
void better_start_yaw(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  workYaw.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 160; i++)
    workYaw.s_inv_z[i] = 1;
  fill_KKT_yaw();
  ldl_factor_yaw();
  fillrhs_start_yaw();
  /* Borrow workYaw.lhs_aff for the solution. */
  ldl_solve_yaw(workYaw.rhs, workYaw.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = workYaw.lhs_aff;
  s = workYaw.lhs_aff + 161;
  z = workYaw.lhs_aff + 321;
  y = workYaw.lhs_aff + 481;
  /* Just set x and y as is. */
  for (i = 0; i < 161; i++)
    workYaw.x[i] = x[i];
  for (i = 0; i < 120; i++)
    workYaw.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 160; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 160; i++)
      workYaw.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 160; i++)
      workYaw.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 160; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 160; i++)
      workYaw.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 160; i++)
      workYaw.z[i] = z[i] + alpha;
  }
}
void fillrhs_start_yaw(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = workYaw.rhs;
  r2 = workYaw.rhs + 161;
  r3 = workYaw.rhs + 321;
  r4 = workYaw.rhs + 481;
  for (i = 0; i < 161; i++)
    r1[i] = -workYaw.q[i];
  for (i = 0; i < 160; i++)
    r2[i] = 0;
  for (i = 0; i < 160; i++)
    r3[i] = workYaw.h[i];
  for (i = 0; i < 120; i++)
    r4[i] = workYaw.b[i];
}
long solve_yaw(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  workYaw.converged = 0;
  setup_pointers_yaw();
  pre_ops_yaw();
#ifndef ZERO_LIBRARY_MODE
  if (settingsYaw.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq_yaw();
  fillh_yaw();
  fillb_yaw();
  if (settingsYaw.better_start)
    better_start_yaw();
  else
    set_start_yaw();
  for (iter = 0; iter < settingsYaw.max_iters; iter++) {
    for (i = 0; i < 160; i++) {
      workYaw.s_inv[i] = 1.0 / workYaw.s[i];
      workYaw.s_inv_z[i] = workYaw.s_inv[i]*workYaw.z[i];
    }
    workYaw.block_33[0] = 0;
    fill_KKT_yaw();
    ldl_factor_yaw();
    /* Affine scaling directions. */
    fillrhs_aff_yaw();
    ldl_solve_yaw(workYaw.rhs, workYaw.lhs_aff);
    refine_yaw(workYaw.rhs, workYaw.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc_yaw();
    ldl_solve_yaw(workYaw.rhs, workYaw.lhs_cc);
    refine_yaw(workYaw.rhs, workYaw.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 601; i++)
      workYaw.lhs_aff[i] += workYaw.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = workYaw.lhs_aff;
    ds = workYaw.lhs_aff + 161;
    dz = workYaw.lhs_aff + 321;
    dy = workYaw.lhs_aff + 481;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 160; i++)
      if (ds[i] < minval*workYaw.s[i])
        minval = ds[i]/workYaw.s[i];
    for (i = 0; i < 160; i++)
      if (dz[i] < minval*workYaw.z[i])
        minval = dz[i]/workYaw.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 161; i++)
      workYaw.x[i] += alpha*dx[i];
    for (i = 0; i < 160; i++)
      workYaw.s[i] += alpha*ds[i];
    for (i = 0; i < 160; i++)
      workYaw.z[i] += alpha*dz[i];
    for (i = 0; i < 120; i++)
      workYaw.y[i] += alpha*dy[i];
    workYaw.gap = eval_gap_yaw();
    workYaw.eq_resid_squared = calc_eq_resid_squared_yaw();
    workYaw.ineq_resid_squared = calc_ineq_resid_squared_yaw();
#ifndef ZERO_LIBRARY_MODE
    if (settingsYaw.verbose) {
      workYaw.optval = eval_objv_yaw();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, workYaw.optval, workYaw.gap, sqrt(workYaw.eq_resid_squared),
          sqrt(workYaw.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (workYaw.gap < settingsYaw.eps)
        && (workYaw.eq_resid_squared <= settingsYaw.resid_tol*settingsYaw.resid_tol)
        && (workYaw.ineq_resid_squared <= settingsYaw.resid_tol*settingsYaw.resid_tol)
       ) {
      workYaw.converged = 1;
      workYaw.optval = eval_objv_yaw();
      return iter+1;
    }
  }
  return iter;
}
