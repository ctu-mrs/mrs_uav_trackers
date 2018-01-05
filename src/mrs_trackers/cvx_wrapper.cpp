/* author: Daniel Hert */

extern "C" {
#include "cvxgen/solver.h"
}
#include <eigen3/Eigen/Eigen>
#include "cvx_wrapper.h"

using namespace Eigen;

Vars      vars;
Params    params;
Workspace work;
Settings  settings;
int       n = 9;

CvxWrapper::CvxWrapper() {
  ROS_INFO("Cvx wrapper initiated");
  set_defaults();
  setup_indexing();
  settings.verbose   = 0;
  settings.max_iters = 25;

  params.Q[0] = 5000;
  params.Q[1] = 0;
  params.Q[2] = 0;
  params.Q[3] = 0;
  params.Q[4] = 0;
  params.Q[5] = 0;
  params.Q[6] = 0;
  params.Q[7] = 0;
  params.Q[8] = 0;


  params.R[0]  = 500;
  params.A[0]  = 1;
  params.A[1]  = 1;
  params.A[2]  = 1;
  params.A[3]  = 0.2;
  params.A[4]  = 0.2;
  params.Af[0] = 1;
  params.Af[1] = 1;
  params.Af[2] = 1;
  params.Af[3] = 0.01;
  params.Af[4] = 0.01;
  params.B[0]  = 0.2;
  params.Bf[0] = 0.01;
}
void CvxWrapper::setInitialState(MatrixXd &x, int k) {
  params.x_0[0] = x(0 + 3 * k, 0);
  params.x_0[1] = x(1 + 3 * k, 0);
  params.x_0[2] = x(2 + 3 * k, 0);
}
void CvxWrapper::loadReference(MatrixXd &reference, int k) {
  params.x_ss_1[0]  = reference(0 * n + (k * 3), 0);
  params.x_ss_2[0]  = reference(1 * n + (k * 3), 0);
  params.x_ss_3[0]  = reference(2 * n + (k * 3), 0);
  params.x_ss_4[0]  = reference(3 * n + (k * 3), 0);
  params.x_ss_5[0]  = reference(4 * n + (k * 3), 0);
  params.x_ss_6[0]  = reference(5 * n + (k * 3), 0);
  params.x_ss_7[0]  = reference(6 * n + (k * 3), 0);
  params.x_ss_8[0]  = reference(7 * n + (k * 3), 0);
  params.x_ss_9[0]  = reference(8 * n + (k * 3), 0);
  params.x_ss_10[0] = reference(9 * n + (k * 3), 0);
  params.x_ss_11[0] = reference(10 * n + (k * 3), 0);
  params.x_ss_12[0] = reference(11 * n + (k * 3), 0);
  params.x_ss_13[0] = reference(12 * n + (k * 3), 0);
  params.x_ss_14[0] = reference(13 * n + (k * 3), 0);
  params.x_ss_15[0] = reference(14 * n + (k * 3), 0);
  params.x_ss_16[0] = reference(15 * n + (k * 3), 0);
  params.x_ss_17[0] = reference(16 * n + (k * 3), 0);
  params.x_ss_18[0] = reference(17 * n + (k * 3), 0);
  params.x_ss_19[0] = reference(18 * n + (k * 3), 0);
  params.x_ss_20[0] = reference(19 * n + (k * 3), 0);
  params.x_ss_21[0] = reference(20 * n + (k * 3), 0);
  params.x_ss_22[0] = reference(21 * n + (k * 3), 0);
  params.x_ss_23[0] = reference(22 * n + (k * 3), 0);
  params.x_ss_24[0] = reference(23 * n + (k * 3), 0);
  params.x_ss_25[0] = reference(24 * n + (k * 3), 0);
  params.x_ss_26[0] = reference(25 * n + (k * 3), 0);
  params.x_ss_27[0] = reference(26 * n + (k * 3), 0);
  params.x_ss_28[0] = reference(27 * n + (k * 3), 0);
  params.x_ss_29[0] = reference(28 * n + (k * 3), 0);
  params.x_ss_30[0] = reference(29 * n + (k * 3), 0);
  params.x_ss_31[0] = reference(30 * n + (k * 3), 0);
  params.x_ss_32[0] = reference(31 * n + (k * 3), 0);
  params.x_ss_33[0] = reference(32 * n + (k * 3), 0);
  params.x_ss_34[0] = reference(33 * n + (k * 3), 0);
  params.x_ss_35[0] = reference(34 * n + (k * 3), 0);
  params.x_ss_36[0] = reference(35 * n + (k * 3), 0);
  params.x_ss_37[0] = reference(36 * n + (k * 3), 0);
  params.x_ss_38[0] = reference(37 * n + (k * 3), 0);
  params.x_ss_39[0] = reference(38 * n + (k * 3), 0);
  params.x_ss_40[0] = reference(39 * n + (k * 3), 0);
}
int CvxWrapper::solveCvx() {
  return solve();
}
void CvxWrapper::getStates(MatrixXd &future_traj, int k) {
  future_traj(0 + k * 3 + (0 * 9))  = *(vars.x_1);
  future_traj(1 + k * 3 + (0 * 9))  = *(vars.x_1 + 1);
  future_traj(2 + k * 3 + (0 * 9))  = *(vars.x_1 + 2);
  future_traj(0 + k * 3 + (1 * 9))  = *(vars.x_2);
  future_traj(1 + k * 3 + (1 * 9))  = *(vars.x_2 + 1);
  future_traj(2 + k * 3 + (1 * 9))  = *(vars.x_2 + 2);
  future_traj(0 + k * 3 + (2 * 9))  = *(vars.x_3);
  future_traj(1 + k * 3 + (2 * 9))  = *(vars.x_3 + 1);
  future_traj(2 + k * 3 + (2 * 9))  = *(vars.x_3 + 2);
  future_traj(0 + k * 3 + (3 * 9))  = *(vars.x_4);
  future_traj(1 + k * 3 + (3 * 9))  = *(vars.x_4 + 1);
  future_traj(2 + k * 3 + (3 * 9))  = *(vars.x_4 + 2);
  future_traj(0 + k * 3 + (4 * 9))  = *(vars.x_5);
  future_traj(1 + k * 3 + (4 * 9))  = *(vars.x_5 + 1);
  future_traj(2 + k * 3 + (4 * 9))  = *(vars.x_5 + 2);
  future_traj(0 + k * 3 + (5 * 9))  = *(vars.x_6);
  future_traj(1 + k * 3 + (5 * 9))  = *(vars.x_6 + 1);
  future_traj(2 + k * 3 + (5 * 9))  = *(vars.x_6 + 2);
  future_traj(0 + k * 3 + (6 * 9))  = *(vars.x_7);
  future_traj(1 + k * 3 + (6 * 9))  = *(vars.x_7 + 1);
  future_traj(2 + k * 3 + (6 * 9))  = *(vars.x_7 + 2);
  future_traj(0 + k * 3 + (7 * 9))  = *(vars.x_8);
  future_traj(1 + k * 3 + (7 * 9))  = *(vars.x_8 + 1);
  future_traj(2 + k * 3 + (7 * 9))  = *(vars.x_8 + 2);
  future_traj(0 + k * 3 + (8 * 9))  = *(vars.x_9);
  future_traj(1 + k * 3 + (8 * 9))  = *(vars.x_9 + 1);
  future_traj(2 + k * 3 + (8 * 9))  = *(vars.x_9 + 2);
  future_traj(0 + k * 3 + (9 * 9))  = *(vars.x_10);
  future_traj(1 + k * 3 + (9 * 9))  = *(vars.x_10 + 1);
  future_traj(2 + k * 3 + (9 * 9))  = *(vars.x_10 + 2);
  future_traj(0 + k * 3 + (10 * 9)) = *(vars.x_11);
  future_traj(1 + k * 3 + (10 * 9)) = *(vars.x_11 + 1);
  future_traj(2 + k * 3 + (10 * 9)) = *(vars.x_11 + 2);
  future_traj(0 + k * 3 + (11 * 9)) = *(vars.x_12);
  future_traj(1 + k * 3 + (11 * 9)) = *(vars.x_12 + 1);
  future_traj(2 + k * 3 + (11 * 9)) = *(vars.x_12 + 2);
  future_traj(0 + k * 3 + (12 * 9)) = *(vars.x_13);
  future_traj(1 + k * 3 + (12 * 9)) = *(vars.x_13 + 1);
  future_traj(2 + k * 3 + (12 * 9)) = *(vars.x_13 + 2);
  future_traj(0 + k * 3 + (13 * 9)) = *(vars.x_14);
  future_traj(1 + k * 3 + (13 * 9)) = *(vars.x_14 + 1);
  future_traj(2 + k * 3 + (13 * 9)) = *(vars.x_14 + 2);
  future_traj(0 + k * 3 + (14 * 9)) = *(vars.x_15);
  future_traj(1 + k * 3 + (14 * 9)) = *(vars.x_15 + 1);
  future_traj(2 + k * 3 + (14 * 9)) = *(vars.x_15 + 2);
  future_traj(0 + k * 3 + (15 * 9)) = *(vars.x_16);
  future_traj(1 + k * 3 + (15 * 9)) = *(vars.x_16 + 1);
  future_traj(2 + k * 3 + (15 * 9)) = *(vars.x_16 + 2);
  future_traj(0 + k * 3 + (16 * 9)) = *(vars.x_17);
  future_traj(1 + k * 3 + (16 * 9)) = *(vars.x_17 + 1);
  future_traj(2 + k * 3 + (16 * 9)) = *(vars.x_17 + 2);
  future_traj(0 + k * 3 + (17 * 9)) = *(vars.x_18);
  future_traj(1 + k * 3 + (17 * 9)) = *(vars.x_18 + 1);
  future_traj(2 + k * 3 + (17 * 9)) = *(vars.x_18 + 2);
  future_traj(0 + k * 3 + (18 * 9)) = *(vars.x_19);
  future_traj(1 + k * 3 + (18 * 9)) = *(vars.x_19 + 1);
  future_traj(2 + k * 3 + (18 * 9)) = *(vars.x_19 + 2);
  future_traj(0 + k * 3 + (19 * 9)) = *(vars.x_20);
  future_traj(1 + k * 3 + (19 * 9)) = *(vars.x_20 + 1);
  future_traj(2 + k * 3 + (19 * 9)) = *(vars.x_20 + 2);
  future_traj(0 + k * 3 + (20 * 9)) = *(vars.x_21);
  future_traj(1 + k * 3 + (20 * 9)) = *(vars.x_21 + 1);
  future_traj(2 + k * 3 + (20 * 9)) = *(vars.x_21 + 2);
  future_traj(0 + k * 3 + (21 * 9)) = *(vars.x_22);
  future_traj(1 + k * 3 + (21 * 9)) = *(vars.x_22 + 1);
  future_traj(2 + k * 3 + (21 * 9)) = *(vars.x_22 + 2);
  future_traj(0 + k * 3 + (22 * 9)) = *(vars.x_23);
  future_traj(1 + k * 3 + (22 * 9)) = *(vars.x_23 + 1);
  future_traj(2 + k * 3 + (22 * 9)) = *(vars.x_23 + 2);
  future_traj(0 + k * 3 + (23 * 9)) = *(vars.x_24);
  future_traj(1 + k * 3 + (23 * 9)) = *(vars.x_24 + 1);
  future_traj(2 + k * 3 + (23 * 9)) = *(vars.x_24 + 2);
  future_traj(0 + k * 3 + (24 * 9)) = *(vars.x_25);
  future_traj(1 + k * 3 + (24 * 9)) = *(vars.x_25 + 1);
  future_traj(2 + k * 3 + (24 * 9)) = *(vars.x_25 + 2);
  future_traj(0 + k * 3 + (25 * 9)) = *(vars.x_26);
  future_traj(1 + k * 3 + (25 * 9)) = *(vars.x_26 + 1);
  future_traj(2 + k * 3 + (25 * 9)) = *(vars.x_26 + 2);
  future_traj(0 + k * 3 + (26 * 9)) = *(vars.x_27);
  future_traj(1 + k * 3 + (26 * 9)) = *(vars.x_27 + 1);
  future_traj(2 + k * 3 + (26 * 9)) = *(vars.x_27 + 2);
  future_traj(0 + k * 3 + (27 * 9)) = *(vars.x_28);
  future_traj(1 + k * 3 + (27 * 9)) = *(vars.x_28 + 1);
  future_traj(2 + k * 3 + (27 * 9)) = *(vars.x_28 + 2);
  future_traj(0 + k * 3 + (28 * 9)) = *(vars.x_29);
  future_traj(1 + k * 3 + (28 * 9)) = *(vars.x_29 + 1);
  future_traj(2 + k * 3 + (28 * 9)) = *(vars.x_29 + 2);
  future_traj(0 + k * 3 + (29 * 9)) = *(vars.x_30);
  future_traj(1 + k * 3 + (29 * 9)) = *(vars.x_30 + 1);
  future_traj(2 + k * 3 + (29 * 9)) = *(vars.x_30 + 2);
  future_traj(0 + k * 3 + (30 * 9)) = *(vars.x_31);
  future_traj(1 + k * 3 + (30 * 9)) = *(vars.x_31 + 1);
  future_traj(2 + k * 3 + (30 * 9)) = *(vars.x_31 + 2);
  future_traj(0 + k * 3 + (31 * 9)) = *(vars.x_32);
  future_traj(1 + k * 3 + (31 * 9)) = *(vars.x_32 + 1);
  future_traj(2 + k * 3 + (31 * 9)) = *(vars.x_32 + 2);
  future_traj(0 + k * 3 + (32 * 9)) = *(vars.x_33);
  future_traj(1 + k * 3 + (32 * 9)) = *(vars.x_33 + 1);
  future_traj(2 + k * 3 + (32 * 9)) = *(vars.x_33 + 2);
  future_traj(0 + k * 3 + (33 * 9)) = *(vars.x_34);
  future_traj(1 + k * 3 + (33 * 9)) = *(vars.x_34 + 1);
  future_traj(2 + k * 3 + (33 * 9)) = *(vars.x_34 + 2);
  future_traj(0 + k * 3 + (34 * 9)) = *(vars.x_35);
  future_traj(1 + k * 3 + (34 * 9)) = *(vars.x_35 + 1);
  future_traj(2 + k * 3 + (34 * 9)) = *(vars.x_35 + 2);
  future_traj(0 + k * 3 + (35 * 9)) = *(vars.x_36);
  future_traj(1 + k * 3 + (35 * 9)) = *(vars.x_36 + 1);
  future_traj(2 + k * 3 + (35 * 9)) = *(vars.x_36 + 2);
  future_traj(0 + k * 3 + (36 * 9)) = *(vars.x_37);
  future_traj(1 + k * 3 + (36 * 9)) = *(vars.x_37 + 1);
  future_traj(2 + k * 3 + (36 * 9)) = *(vars.x_37 + 2);
  future_traj(0 + k * 3 + (37 * 9)) = *(vars.x_38);
  future_traj(1 + k * 3 + (37 * 9)) = *(vars.x_38 + 1);
  future_traj(2 + k * 3 + (37 * 9)) = *(vars.x_38 + 2);
  future_traj(0 + k * 3 + (38 * 9)) = *(vars.x_39);
  future_traj(1 + k * 3 + (38 * 9)) = *(vars.x_39 + 1);
  future_traj(2 + k * 3 + (38 * 9)) = *(vars.x_39 + 2);
  future_traj(0 + k * 3 + (39 * 9)) = *(vars.x_40);
  future_traj(1 + k * 3 + (39 * 9)) = *(vars.x_40 + 1);
  future_traj(2 + k * 3 + (39 * 9)) = *(vars.x_40 + 2);
}
double CvxWrapper::getFirstControlInput() {
  return *(vars.u_0);
}
