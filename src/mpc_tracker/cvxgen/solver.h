/* Produced by CVXGEN, 2018-08-14 08:45:54 -0400.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.h. */
/* Description: Header file with relevant definitions. */
#ifndef SOLVER_H
#define SOLVER_H
/* Uncomment the next line to remove all library dependencies. */
/*#define ZERO_LIBRARY_MODE */
#ifdef MATLAB_MEX_FILE
/* Matlab functions. MATLAB_MEX_FILE will be defined by the mex compiler. */
/* If you are not using the mex compiler, this functionality will not intrude, */
/* as it will be completely disabled at compile-time. */
#include "mex.h"
#else
#ifndef ZERO_LIBRARY_MODE
#include <stdio.h>
#endif
#endif
/* Space must be allocated somewhere (testsolver.c, csolve.c or your own */
/* program) for the global variables vars, params, work and settings. */
/* At the bottom of this file, they are externed. */
#ifndef ZERO_LIBRARY_MODE
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)
#endif
typedef struct Params_t {
  double x_ss_1[3];
  double Q[3];
  double x_ss_2[3];
  double x_ss_3[3];
  double x_ss_4[3];
  double x_ss_5[3];
  double x_ss_6[3];
  double x_ss_7[3];
  double x_ss_8[3];
  double x_ss_9[3];
  double x_ss_10[3];
  double x_ss_11[3];
  double x_ss_12[3];
  double x_ss_13[3];
  double x_ss_14[3];
  double x_ss_15[3];
  double x_ss_16[3];
  double x_ss_17[3];
  double x_ss_18[3];
  double x_ss_19[3];
  double x_ss_20[3];
  double x_ss_21[3];
  double x_ss_22[3];
  double x_ss_23[3];
  double x_ss_24[3];
  double x_ss_25[3];
  double x_ss_26[3];
  double x_ss_27[3];
  double x_ss_28[3];
  double x_ss_29[3];
  double x_ss_30[3];
  double x_ss_31[3];
  double x_ss_32[3];
  double x_ss_33[3];
  double x_ss_34[3];
  double x_ss_35[3];
  double x_ss_36[3];
  double x_ss_37[3];
  double x_ss_38[3];
  double x_ss_39[3];
  double x_ss_40[3];
  double R[1];
  double R2[1];
  double Af[6];
  double x_0[3];
  double Bf[1];
  double A[6];
  double B[1];
  double x_max_2_1[1];
  double x_max_2_2[1];
  double x_max_2_3[1];
  double x_max_2_4[1];
  double x_max_2_5[1];
  double x_max_2_6[1];
  double x_max_2_7[1];
  double x_max_2_8[1];
  double x_max_2_9[1];
  double x_max_2_10[1];
  double x_max_2_11[1];
  double x_max_2_12[1];
  double x_max_2_13[1];
  double x_max_2_14[1];
  double x_max_2_15[1];
  double x_max_2_16[1];
  double x_max_2_17[1];
  double x_max_2_18[1];
  double x_max_2_19[1];
  double x_max_2_20[1];
  double x_max_2_21[1];
  double x_max_2_22[1];
  double x_max_2_23[1];
  double x_max_2_24[1];
  double x_max_2_25[1];
  double x_max_2_26[1];
  double x_max_2_27[1];
  double x_max_2_28[1];
  double x_max_2_29[1];
  double x_max_2_30[1];
  double x_max_2_31[1];
  double x_max_2_32[1];
  double x_max_2_33[1];
  double x_max_2_34[1];
  double x_max_2_35[1];
  double x_max_2_36[1];
  double x_max_2_37[1];
  double x_max_2_38[1];
  double x_max_2_39[1];
  double x_max_2_40[1];
  double x_min_2_1[1];
  double x_min_2_2[1];
  double x_min_2_3[1];
  double x_min_2_4[1];
  double x_min_2_5[1];
  double x_min_2_6[1];
  double x_min_2_7[1];
  double x_min_2_8[1];
  double x_min_2_9[1];
  double x_min_2_10[1];
  double x_min_2_11[1];
  double x_min_2_12[1];
  double x_min_2_13[1];
  double x_min_2_14[1];
  double x_min_2_15[1];
  double x_min_2_16[1];
  double x_min_2_17[1];
  double x_min_2_18[1];
  double x_min_2_19[1];
  double x_min_2_20[1];
  double x_min_2_21[1];
  double x_min_2_22[1];
  double x_min_2_23[1];
  double x_min_2_24[1];
  double x_min_2_25[1];
  double x_min_2_26[1];
  double x_min_2_27[1];
  double x_min_2_28[1];
  double x_min_2_29[1];
  double x_min_2_30[1];
  double x_min_2_31[1];
  double x_min_2_32[1];
  double x_min_2_33[1];
  double x_min_2_34[1];
  double x_min_2_35[1];
  double x_min_2_36[1];
  double x_min_2_37[1];
  double x_min_2_38[1];
  double x_min_2_39[1];
  double x_min_2_40[1];
  double x_max_3_1[1];
  double x_max_3_2[1];
  double x_max_3_3[1];
  double x_max_3_4[1];
  double x_max_3_5[1];
  double x_max_3_6[1];
  double x_max_3_7[1];
  double x_max_3_8[1];
  double x_max_3_9[1];
  double x_max_3_10[1];
  double x_max_3_11[1];
  double x_max_3_12[1];
  double x_max_3_13[1];
  double x_max_3_14[1];
  double x_max_3_15[1];
  double x_max_3_16[1];
  double x_max_3_17[1];
  double x_max_3_18[1];
  double x_max_3_19[1];
  double x_max_3_20[1];
  double x_max_3_21[1];
  double x_max_3_22[1];
  double x_max_3_23[1];
  double x_max_3_24[1];
  double x_max_3_25[1];
  double x_max_3_26[1];
  double x_max_3_27[1];
  double x_max_3_28[1];
  double x_max_3_29[1];
  double x_max_3_30[1];
  double x_max_3_31[1];
  double x_max_3_32[1];
  double x_max_3_33[1];
  double x_max_3_34[1];
  double x_max_3_35[1];
  double x_max_3_36[1];
  double x_max_3_37[1];
  double x_max_3_38[1];
  double x_max_3_39[1];
  double x_max_3_40[1];
  double x_min_3_1[1];
  double x_min_3_2[1];
  double x_min_3_3[1];
  double x_min_3_4[1];
  double x_min_3_5[1];
  double x_min_3_6[1];
  double x_min_3_7[1];
  double x_min_3_8[1];
  double x_min_3_9[1];
  double x_min_3_10[1];
  double x_min_3_11[1];
  double x_min_3_12[1];
  double x_min_3_13[1];
  double x_min_3_14[1];
  double x_min_3_15[1];
  double x_min_3_16[1];
  double x_min_3_17[1];
  double x_min_3_18[1];
  double x_min_3_19[1];
  double x_min_3_20[1];
  double x_min_3_21[1];
  double x_min_3_22[1];
  double x_min_3_23[1];
  double x_min_3_24[1];
  double x_min_3_25[1];
  double x_min_3_26[1];
  double x_min_3_27[1];
  double x_min_3_28[1];
  double x_min_3_29[1];
  double x_min_3_30[1];
  double x_min_3_31[1];
  double x_min_3_32[1];
  double x_min_3_33[1];
  double x_min_3_34[1];
  double x_min_3_35[1];
  double x_min_3_36[1];
  double x_min_3_37[1];
  double x_min_3_38[1];
  double x_min_3_39[1];
  double x_min_3_40[1];
  double u_max_0[1];
  double u_max_1[1];
  double u_max_2[1];
  double u_max_3[1];
  double u_max_4[1];
  double u_max_5[1];
  double u_max_6[1];
  double u_max_7[1];
  double u_max_8[1];
  double u_max_9[1];
  double u_max_10[1];
  double u_max_11[1];
  double u_max_12[1];
  double u_max_13[1];
  double u_max_14[1];
  double u_max_15[1];
  double u_max_16[1];
  double u_max_17[1];
  double u_max_18[1];
  double u_max_19[1];
  double u_max_20[1];
  double u_max_21[1];
  double u_max_22[1];
  double u_max_23[1];
  double u_max_24[1];
  double u_max_25[1];
  double u_max_26[1];
  double u_max_27[1];
  double u_max_28[1];
  double u_max_29[1];
  double u_max_30[1];
  double u_max_31[1];
  double u_max_32[1];
  double u_max_33[1];
  double u_max_34[1];
  double u_max_35[1];
  double u_max_36[1];
  double u_max_37[1];
  double u_max_38[1];
  double u_max_39[1];
  double u_min_0[1];
  double u_min_1[1];
  double u_min_2[1];
  double u_min_3[1];
  double u_min_4[1];
  double u_min_5[1];
  double u_min_6[1];
  double u_min_7[1];
  double u_min_8[1];
  double u_min_9[1];
  double u_min_10[1];
  double u_min_11[1];
  double u_min_12[1];
  double u_min_13[1];
  double u_min_14[1];
  double u_min_15[1];
  double u_min_16[1];
  double u_min_17[1];
  double u_min_18[1];
  double u_min_19[1];
  double u_min_20[1];
  double u_min_21[1];
  double u_min_22[1];
  double u_min_23[1];
  double u_min_24[1];
  double u_min_25[1];
  double u_min_26[1];
  double u_min_27[1];
  double u_min_28[1];
  double u_min_29[1];
  double u_min_30[1];
  double u_min_31[1];
  double u_min_32[1];
  double u_min_33[1];
  double u_min_34[1];
  double u_min_35[1];
  double u_min_36[1];
  double u_min_37[1];
  double u_min_38[1];
  double u_min_39[1];
  double *x_ss[41];
  double *x[1];
  double *x_max_2[41];
  double *x_min_2[41];
  double *x_max_3[41];
  double *x_min_3[41];
  double *u_max[40];
  double *u_min[40];
} Params;
typedef struct Vars_t {
  double *x_1; /* 3 rows. */
  double *x_2; /* 3 rows. */
  double *x_3; /* 3 rows. */
  double *x_4; /* 3 rows. */
  double *x_5; /* 3 rows. */
  double *x_6; /* 3 rows. */
  double *x_7; /* 3 rows. */
  double *x_8; /* 3 rows. */
  double *x_9; /* 3 rows. */
  double *x_10; /* 3 rows. */
  double *x_11; /* 3 rows. */
  double *x_12; /* 3 rows. */
  double *x_13; /* 3 rows. */
  double *x_14; /* 3 rows. */
  double *x_15; /* 3 rows. */
  double *x_16; /* 3 rows. */
  double *x_17; /* 3 rows. */
  double *x_18; /* 3 rows. */
  double *x_19; /* 3 rows. */
  double *x_20; /* 3 rows. */
  double *x_21; /* 3 rows. */
  double *x_22; /* 3 rows. */
  double *x_23; /* 3 rows. */
  double *x_24; /* 3 rows. */
  double *x_25; /* 3 rows. */
  double *x_26; /* 3 rows. */
  double *x_27; /* 3 rows. */
  double *x_28; /* 3 rows. */
  double *x_29; /* 3 rows. */
  double *x_30; /* 3 rows. */
  double *x_31; /* 3 rows. */
  double *x_32; /* 3 rows. */
  double *x_33; /* 3 rows. */
  double *x_34; /* 3 rows. */
  double *x_35; /* 3 rows. */
  double *x_36; /* 3 rows. */
  double *x_37; /* 3 rows. */
  double *x_38; /* 3 rows. */
  double *x_39; /* 3 rows. */
  double *x_40; /* 3 rows. */
  double *u_1; /* 1 rows. */
  double *u_2; /* 1 rows. */
  double *u_3; /* 1 rows. */
  double *u_4; /* 1 rows. */
  double *u_5; /* 1 rows. */
  double *u_6; /* 1 rows. */
  double *u_7; /* 1 rows. */
  double *u_8; /* 1 rows. */
  double *u_9; /* 1 rows. */
  double *u_10; /* 1 rows. */
  double *u_11; /* 1 rows. */
  double *u_12; /* 1 rows. */
  double *u_13; /* 1 rows. */
  double *u_14; /* 1 rows. */
  double *u_15; /* 1 rows. */
  double *u_16; /* 1 rows. */
  double *u_17; /* 1 rows. */
  double *u_18; /* 1 rows. */
  double *u_19; /* 1 rows. */
  double *u_20; /* 1 rows. */
  double *u_21; /* 1 rows. */
  double *u_22; /* 1 rows. */
  double *u_23; /* 1 rows. */
  double *u_24; /* 1 rows. */
  double *u_25; /* 1 rows. */
  double *u_26; /* 1 rows. */
  double *u_27; /* 1 rows. */
  double *u_28; /* 1 rows. */
  double *u_29; /* 1 rows. */
  double *u_30; /* 1 rows. */
  double *u_31; /* 1 rows. */
  double *u_32; /* 1 rows. */
  double *u_33; /* 1 rows. */
  double *u_34; /* 1 rows. */
  double *u_35; /* 1 rows. */
  double *u_36; /* 1 rows. */
  double *u_37; /* 1 rows. */
  double *u_38; /* 1 rows. */
  double *u_39; /* 1 rows. */
  double *u_0; /* 1 rows. */
  double *x[41];
  double *u[40];
} Vars;
typedef struct Workspace_t {
  double h[240];
  double s_inv[240];
  double s_inv_z[240];
  double b[120];
  double q[160];
  double rhs[760];
  double x[760];
  double *s;
  double *z;
  double *y;
  double lhs_aff[760];
  double lhs_cc[760];
  double buffer[760];
  double buffer2[760];
  double KKT[1514];
  double L[1140];
  double d[760];
  double v[760];
  double d_inv[760];
  double gap;
  double optval;
  double ineq_resid_squared;
  double eq_resid_squared;
  double block_33[1];
  /* Pre-op symbols. */
  double quad_600568381440[1];
  double quad_898851794944[1];
  double quad_88433618944[1];
  double quad_240204779520[1];
  double quad_635618762752[1];
  double quad_732753989632[1];
  double quad_427523055616[1];
  double quad_976046530560[1];
  double quad_688550678528[1];
  double quad_304816418816[1];
  double quad_819339411456[1];
  double quad_101800079360[1];
  double quad_976903761920[1];
  double quad_141299838976[1];
  double quad_343404097536[1];
  double quad_815806124032[1];
  double quad_997002137600[1];
  double quad_141630619648[1];
  double quad_835263414272[1];
  double quad_962643562496[1];
  double quad_928463360000[1];
  double quad_380101586944[1];
  double quad_150659375104[1];
  double quad_392524365824[1];
  double quad_653656117248[1];
  double quad_70101270528[1];
  double quad_514920816640[1];
  double quad_674593345536[1];
  double quad_563078742016[1];
  double quad_758829424640[1];
  double quad_779426672640[1];
  double quad_59167404032[1];
  double quad_532283006976[1];
  double quad_792751730688[1];
  double quad_677500567552[1];
  double quad_848330452992[1];
  double quad_31841603584[1];
  double quad_193524883456[1];
  double quad_637564002304[1];
  double quad_646561718272[1];
  int converged;
} Workspace;
typedef struct Settings_t {
  double resid_tol;
  double eps;
  int max_iters;
  int refine_steps;
  int better_start;
  /* Better start obviates the need for s_init and z_init. */
  double s_init;
  double z_init;
  int verbose;
  /* Show extra details of the iterative refinement steps. */
  int verbose_refinement;
  int debug;
  /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
  double kkt_reg;
} Settings;
extern Vars vars;
extern Params params;
extern Workspace work;
extern Settings settings;
/* Function definitions in ldl.c: */
void ldl_solve(double *target, double *var);
void ldl_factor(void);
double check_factorization(void);
void matrix_multiply(double *result, double *source);
double check_residual(double *target, double *multiplicand);
void fill_KKT(void);

/* Function definitions in matrix_support.c: */
void multbymA(double *lhs, double *rhs);
void multbymAT(double *lhs, double *rhs);
void multbymG(double *lhs, double *rhs);
void multbymGT(double *lhs, double *rhs);
void multbyP(double *lhs, double *rhs);
void fillq(void);
void fillh(void);
void fillb(void);
void pre_ops(void);

/* Function definitions in solver.c: */
double eval_gap(void);
void set_defaults(void);
void setup_pointers(void);
void setup_indexed_params(void);
void setup_indexed_optvars(void);
void setup_indexing(void);
void set_start(void);
double eval_objv(void);
void fillrhs_aff(void);
void fillrhs_cc(void);
void refine(double *target, double *var);
double calc_ineq_resid_squared(void);
double calc_eq_resid_squared(void);
void better_start(void);
void fillrhs_start(void);
long solve(void);

/* Function definitions in testsolver.c: */
int main(int argc, char **argv);
void load_default_data(void);

/* Function definitions in util.c: */
void tic(void);
float toc(void);
float tocq(void);
void printmatrix(char *name, double *A, int m, int n, int sparse);
double unif(double lower, double upper);
float ran1(long*idum, int reset);
float randn_internal(long *idum, int reset);
double randn(void);
void reset_rand(void);

#endif
