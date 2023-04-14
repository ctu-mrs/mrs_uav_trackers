#ifndef TRACKER_SOLVER_H
#define TRACKER_SOLVER_H

#include <stdio.h>
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)

namespace mrs_mpc_solvers
{

namespace mpc_tracker
{

class QPSolver {

  /* structs //{ */

  typedef struct Params_t
  {
    double  x_ss_1[4];
    double  Q[4];
    double  x_ss_2[4];
    double  x_ss_3[4];
    double  x_ss_4[4];
    double  x_ss_5[4];
    double  x_ss_6[4];
    double  x_ss_7[4];
    double  x_ss_8[4];
    double  x_ss_9[4];
    double  x_ss_10[4];
    double  x_ss_11[4];
    double  x_ss_12[4];
    double  x_ss_13[4];
    double  x_ss_14[4];
    double  x_ss_15[4];
    double  x_ss_16[4];
    double  x_ss_17[4];
    double  x_ss_18[4];
    double  x_ss_19[4];
    double  x_ss_20[4];
    double  x_ss_21[4];
    double  x_ss_22[4];
    double  x_ss_23[4];
    double  x_ss_24[4];
    double  x_ss_25[4];
    double  x_ss_26[4];
    double  x_ss_27[4];
    double  x_ss_28[4];
    double  x_ss_29[4];
    double  x_ss_30[4];
    double  x_ss_31[4];
    double  x_ss_32[4];
    double  x_ss_33[4];
    double  x_ss_34[4];
    double  x_ss_35[4];
    double  x_ss_36[4];
    double  x_ss_37[4];
    double  x_ss_38[4];
    double  x_ss_39[4];
    double  x_ss_40[4];
    double  Af[9];
    double  x_0[4];
    double  Bf[1];
    double  A[9];
    double  B[1];
    double  x_max_2[1];
    double  x_min_2[1];
    double  x_max_3[1];
    double  x_min_3[1];
    double  x_max_4[1];
    double  x_min_4[1];
    double  u_max[1];
    double  u_min[1];
    double *x_ss[41];
    double *x[1];
  } Params;

  typedef struct Vars_t
  {
    double *x_1;  /* 4 rows. */
    double *x_2;  /* 4 rows. */
    double *x_3;  /* 4 rows. */
    double *x_4;  /* 4 rows. */
    double *x_5;  /* 4 rows. */
    double *x_6;  /* 4 rows. */
    double *x_7;  /* 4 rows. */
    double *x_8;  /* 4 rows. */
    double *x_9;  /* 4 rows. */
    double *x_10; /* 4 rows. */
    double *x_11; /* 4 rows. */
    double *x_12; /* 4 rows. */
    double *x_13; /* 4 rows. */
    double *x_14; /* 4 rows. */
    double *x_15; /* 4 rows. */
    double *x_16; /* 4 rows. */
    double *x_17; /* 4 rows. */
    double *x_18; /* 4 rows. */
    double *x_19; /* 4 rows. */
    double *x_20; /* 4 rows. */
    double *x_21; /* 4 rows. */
    double *x_22; /* 4 rows. */
    double *x_23; /* 4 rows. */
    double *x_24; /* 4 rows. */
    double *x_25; /* 4 rows. */
    double *x_26; /* 4 rows. */
    double *x_27; /* 4 rows. */
    double *x_28; /* 4 rows. */
    double *x_29; /* 4 rows. */
    double *x_30; /* 4 rows. */
    double *x_31; /* 4 rows. */
    double *x_32; /* 4 rows. */
    double *x_33; /* 4 rows. */
    double *x_34; /* 4 rows. */
    double *x_35; /* 4 rows. */
    double *x_36; /* 4 rows. */
    double *x_37; /* 4 rows. */
    double *x_38; /* 4 rows. */
    double *x_39; /* 4 rows. */
    double *x_40; /* 4 rows. */
    double *u_0;  /* 1 rows. */
    double *u_1;  /* 1 rows. */
    double *u_2;  /* 1 rows. */
    double *u_3;  /* 1 rows. */
    double *u_4;  /* 1 rows. */
    double *u_5;  /* 1 rows. */
    double *u_6;  /* 1 rows. */
    double *u_7;  /* 1 rows. */
    double *u_8;  /* 1 rows. */
    double *u_9;  /* 1 rows. */
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
    double *x[41];
    double *u[40];
  } Vars;

  typedef struct Workspace_t
  {
    double  h[320];
    double  s_inv[320];
    double  s_inv_z[320];
    double  b[160];
    double  q[200];
    double  rhs[1000];
    double  x[1000];
    double *s;
    double *z;
    double *y;
    double  lhs_aff[1000];
    double  lhs_cc[1000];
    double  buffer[1000];
    double  buffer2[1000];
    double  KKT[1991];
    double  L[1720];
    double  d[1000];
    double  v[1000];
    double  d_inv[1000];
    double  gap;
    double  optval;
    double  ineq_resid_squared;
    double  eq_resid_squared;
    double  block_33[1];
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
    int    converged;
  } Workspace;

  typedef struct Settings_t
  {
    double resid_tol;
    double eps;
    int    max_iters;
    int    refine_steps;
    int    better_start;
    /* Better start obviates the need for s_init and z_init. */
    double s_init;
    double z_init;
    int    verbose;
    /* Show extra details of the iterative refinement steps. */
    int verbose_refinement;
    int debug;
    /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
    double kkt_reg;
  } Settings;

  //}

public:
  Vars      vars;
  Params    params;
  Workspace work;
  Settings  settings;

  /* Function definitions in ldl.c: */
  void   ldl_solve(double *target, double *var);
  void   ldl_factor(void);
  double check_factorization(void);
  void   matrix_multiply(double *result, double *source);
  double check_residual(double *target, double *multiplicand);
  void   fill_KKT(void);

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
  void   set_defaults(void);
  void   setup_pointers(void);
  void   setup_indexed_params(void);
  void   setup_indexed_optvars(void);
  void   setup_indexing(void);
  void   set_start(void);
  double eval_objv(void);
  void   fillrhs_aff(void);
  void   fillrhs_cc(void);
  void   refine(double *target, double *var);
  double calc_ineq_resid_squared(void);
  double calc_eq_resid_squared(void);
  void   better_start(void);
  void   fillrhs_start(void);
  long   solve(void);

  /* Function definitions in testsolver.c: */
  int  main(int argc, char **argv);
  void load_default_data(void);

  /* Function definitions in util.c: */
  void   tic(void);
  float  toc(void);
  float  tocq(void);
  void   printmatrix(char *name, double *A, int m, int n, int sparse);
  double unif(double lower, double upper);
  float  ran1(long *idum, int reset);
  float  randn_internal(long *idum, int reset);
  double randn(void);
  void   reset_rand(void);
};

}  // namespace mpc_tracker

}  // namespace mrs_mpc_solvers

#endif
