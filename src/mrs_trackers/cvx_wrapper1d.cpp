/* author: Daniel Hert */

extern "C" {
#include "cvxgen1d/solver.h"
}
#include <eigen3/Eigen/Eigen>
#include "cvx_wrapper1d.h"

using namespace Eigen;

Vars1d      vars1d;
Params1d    params1d;
Workspace1d work1d;
Settings1d  settings1d;
int         n = 9;

CvxWrapper1d::CvxWrapper1d(bool verbose, int max_iters, std::vector<double> tempQ, std::vector<double> tempR, double dt, double dt2) {


  set_defaults1d();
  setup_indexing1d();

  if ((verbose != 1 && verbose != 0) || !std::isfinite(verbose)) {
    ROS_ERROR("CvxWrapper1d - verbose has to be 0 or 1!!! Safe value of 0 set instead");
    verbose = 0;
  }
  settings1d.verbose = verbose;

  if ((max_iters < 1 || max_iters > 100) || !std::isfinite(max_iters)) {
    ROS_ERROR("CvxWrapper1d - max_iters wrong value!!! Safe value of 25 set instead");
    max_iters = 25;
  }
  settings1d.max_iters = max_iters;

  if (tempQ.size() == 3) {
    for (int i = 0; i < 3; i++) {
      if (tempQ[i] >= 0 && std::isfinite(tempQ[i])) {
        params1d.Q[i] = tempQ[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper1d - Q matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        params1d.Q[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper1d - Q matrix wrong size " << tempQ.size() << " !!! Safe values set instead");
    params1d.Q[0] = 5000;
    params1d.Q[1] = 0;
    params1d.Q[2] = 0;
  }

  if (tempR.size() == 1) {
    for (int i = 0; i < 1; i++) {
      if (tempR[i] >= 0 && std::isfinite(tempR[i])) {
        params1d.R[i] = tempR[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper1d - R matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        params1d.R[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper1d - R matrix wrong size " << tempR.size() << " !!! Safe values set instead");
    params1d.R[0] = 500;
  }

  if (dt <= 0 || !std::isfinite(dt)) {
    ROS_ERROR_STREAM("CvxWrapper1d - dt parameter wrong " << dt << " !!! Safe value of 0.01 set instead");
    dt = 0.01;
  }

  if (dt2 <= 0 || !std::isfinite(dt2)) {
    ROS_ERROR_STREAM("CvxWrapper1d - dt2 parameter wrong " << dt2 << " !!! Safe value of 0.2 set instead");
    dt = 0.01;
  }


  params1d.A[0] = 1;
  params1d.A[1] = 1;
  params1d.A[2] = 1;
  params1d.A[3] = dt2;
  params1d.A[4] = dt2;

  params1d.Af[0] = 1;
  params1d.Af[1] = 1;
  params1d.Af[2] = 1;
  params1d.Af[3] = dt;
  params1d.Af[4] = dt;

  params1d.B[0]  = dt2;

  params1d.Bf[0] = dt;

  ROS_INFO("Cvx wrapper 1d initiated");
}
void CvxWrapper1d::setLimits(double speed_max, double speed_min, double acc_max, double acc_min) {
  params1d.x_max_2[0] = speed_max;
  params1d.x_max_3[0] = acc_max;
  params1d.x_min_2[0] = -speed_min;
  params1d.x_min_3[0] = -acc_min;
}

void CvxWrapper1d::setInitialState(MatrixXd &x) {
  params1d.x_0[0]    = x(6, 0);
  params1d.x_0[1]    = x(7, 0);
  params1d.x_0[2]    = x(8, 0);
}
void CvxWrapper1d::loadReference(MatrixXd &reference) {

  params1d.x_ss_1[0]  = reference(0 * n + 6, 0);
  params1d.x_ss_2[0]  = reference(1 * n + 6, 0);
  params1d.x_ss_3[0]  = reference(2 * n + 6, 0);
  params1d.x_ss_4[0]  = reference(3 * n + 6, 0);
  params1d.x_ss_5[0]  = reference(4 * n + 6, 0);
  params1d.x_ss_6[0]  = reference(5 * n + 6, 0);
  params1d.x_ss_7[0]  = reference(6 * n + 6, 0);
  params1d.x_ss_8[0]  = reference(7 * n + 6, 0);
  params1d.x_ss_9[0]  = reference(8 * n + 6, 0);
  params1d.x_ss_10[0] = reference(9 * n + 6, 0);
  params1d.x_ss_11[0] = reference(10 * n + 6, 0);
  params1d.x_ss_12[0] = reference(11 * n + 6, 0);
  params1d.x_ss_13[0] = reference(12 * n + 6, 0);
  params1d.x_ss_14[0] = reference(13 * n + 6, 0);
  params1d.x_ss_15[0] = reference(14 * n + 6, 0);
  params1d.x_ss_16[0] = reference(15 * n + 6, 0);
  params1d.x_ss_17[0] = reference(16 * n + 6, 0);
  params1d.x_ss_18[0] = reference(17 * n + 6, 0);
  params1d.x_ss_19[0] = reference(18 * n + 6, 0);
  params1d.x_ss_20[0] = reference(19 * n + 6, 0);
  params1d.x_ss_21[0] = reference(20 * n + 6, 0);
  params1d.x_ss_22[0] = reference(21 * n + 6, 0);
  params1d.x_ss_23[0] = reference(22 * n + 6, 0);
  params1d.x_ss_24[0] = reference(23 * n + 6, 0);
  params1d.x_ss_25[0] = reference(24 * n + 6, 0);
  params1d.x_ss_26[0] = reference(25 * n + 6, 0);
  params1d.x_ss_27[0] = reference(26 * n + 6, 0);
  params1d.x_ss_28[0] = reference(27 * n + 6, 0);
  params1d.x_ss_29[0] = reference(28 * n + 6, 0);
  params1d.x_ss_30[0] = reference(29 * n + 6, 0);
  params1d.x_ss_31[0] = reference(30 * n + 6, 0);
  params1d.x_ss_32[0] = reference(31 * n + 6, 0);
  params1d.x_ss_33[0] = reference(32 * n + 6, 0);
  params1d.x_ss_34[0] = reference(33 * n + 6, 0);
  params1d.x_ss_35[0] = reference(34 * n + 6, 0);
  params1d.x_ss_36[0] = reference(35 * n + 6, 0);
  params1d.x_ss_37[0] = reference(36 * n + 6, 0);
  params1d.x_ss_38[0] = reference(37 * n + 6, 0);
  params1d.x_ss_39[0] = reference(38 * n + 6, 0);
  params1d.x_ss_40[0] = reference(39 * n + 6, 0);
}
int CvxWrapper1d::solveCvx() {
  return solve1d();
}
void CvxWrapper1d::getStates(MatrixXd &future_traj) {
  future_traj(6 + (0 * 9))  = *(vars1d.x_1);
  future_traj(7 + (0 * 9))  = *(vars1d.x_1 + 1);
  future_traj(8 + (0 * 9))  = *(vars1d.x_1 + 2);
  future_traj(6 + (1 * 9))  = *(vars1d.x_2);
  future_traj(7 + (1 * 9))  = *(vars1d.x_2 + 1);
  future_traj(8 + (1 * 9))  = *(vars1d.x_2 + 2);
  future_traj(6 + (2 * 9))  = *(vars1d.x_3);
  future_traj(7 + (2 * 9))  = *(vars1d.x_3 + 1);
  future_traj(8 + (2 * 9))  = *(vars1d.x_3 + 2);
  future_traj(6 + (3 * 9))  = *(vars1d.x_4);
  future_traj(7 + (3 * 9))  = *(vars1d.x_4 + 1);
  future_traj(8 + (3 * 9))  = *(vars1d.x_4 + 2);
  future_traj(6 + (4 * 9))  = *(vars1d.x_5);
  future_traj(7 + (4 * 9))  = *(vars1d.x_5 + 1);
  future_traj(8 + (4 * 9))  = *(vars1d.x_5 + 2);
  future_traj(6 + (5 * 9))  = *(vars1d.x_6);
  future_traj(7 + (5 * 9))  = *(vars1d.x_6 + 1);
  future_traj(8 + (5 * 9))  = *(vars1d.x_6 + 2);
  future_traj(6 + (6 * 9))  = *(vars1d.x_7);
  future_traj(7 + (6 * 9))  = *(vars1d.x_7 + 1);
  future_traj(8 + (6 * 9))  = *(vars1d.x_7 + 2);
  future_traj(6 + (7 * 9))  = *(vars1d.x_8);
  future_traj(7 + (7 * 9))  = *(vars1d.x_8 + 1);
  future_traj(8 + (7 * 9))  = *(vars1d.x_8 + 2);
  future_traj(6 + (8 * 9))  = *(vars1d.x_9);
  future_traj(7 + (8 * 9))  = *(vars1d.x_9 + 1);
  future_traj(8 + (8 * 9))  = *(vars1d.x_9 + 2);
  future_traj(6 + (9 * 9))  = *(vars1d.x_10);
  future_traj(7 + (9 * 9))  = *(vars1d.x_10 + 1);
  future_traj(8 + (9 * 9))  = *(vars1d.x_10 + 2);
  future_traj(6 + (10 * 9)) = *(vars1d.x_11);
  future_traj(7 + (10 * 9)) = *(vars1d.x_11 + 1);
  future_traj(8 + (10 * 9)) = *(vars1d.x_11 + 2);
  future_traj(6 + (11 * 9)) = *(vars1d.x_12);
  future_traj(7 + (11 * 9)) = *(vars1d.x_12 + 1);
  future_traj(8 + (11 * 9)) = *(vars1d.x_12 + 2);
  future_traj(6 + (12 * 9)) = *(vars1d.x_13);
  future_traj(7 + (12 * 9)) = *(vars1d.x_13 + 1);
  future_traj(8 + (12 * 9)) = *(vars1d.x_13 + 2);
  future_traj(6 + (13 * 9)) = *(vars1d.x_14);
  future_traj(7 + (13 * 9)) = *(vars1d.x_14 + 1);
  future_traj(8 + (13 * 9)) = *(vars1d.x_14 + 2);
  future_traj(6 + (14 * 9)) = *(vars1d.x_15);
  future_traj(7 + (14 * 9)) = *(vars1d.x_15 + 1);
  future_traj(8 + (14 * 9)) = *(vars1d.x_15 + 2);
  future_traj(6 + (15 * 9)) = *(vars1d.x_16);
  future_traj(7 + (15 * 9)) = *(vars1d.x_16 + 1);
  future_traj(8 + (15 * 9)) = *(vars1d.x_16 + 2);
  future_traj(6 + (16 * 9)) = *(vars1d.x_17);
  future_traj(7 + (16 * 9)) = *(vars1d.x_17 + 1);
  future_traj(8 + (16 * 9)) = *(vars1d.x_17 + 2);
  future_traj(6 + (17 * 9)) = *(vars1d.x_18);
  future_traj(7 + (17 * 9)) = *(vars1d.x_18 + 1);
  future_traj(8 + (17 * 9)) = *(vars1d.x_18 + 2);
  future_traj(6 + (18 * 9)) = *(vars1d.x_19);
  future_traj(7 + (18 * 9)) = *(vars1d.x_19 + 1);
  future_traj(8 + (18 * 9)) = *(vars1d.x_19 + 2);
  future_traj(6 + (19 * 9)) = *(vars1d.x_20);
  future_traj(7 + (19 * 9)) = *(vars1d.x_20 + 1);
  future_traj(8 + (19 * 9)) = *(vars1d.x_20 + 2);
  future_traj(6 + (20 * 9)) = *(vars1d.x_21);
  future_traj(7 + (20 * 9)) = *(vars1d.x_21 + 1);
  future_traj(8 + (20 * 9)) = *(vars1d.x_21 + 2);
  future_traj(6 + (21 * 9)) = *(vars1d.x_22);
  future_traj(7 + (21 * 9)) = *(vars1d.x_22 + 1);
  future_traj(8 + (21 * 9)) = *(vars1d.x_22 + 2);
  future_traj(6 + (22 * 9)) = *(vars1d.x_23);
  future_traj(7 + (22 * 9)) = *(vars1d.x_23 + 1);
  future_traj(8 + (22 * 9)) = *(vars1d.x_23 + 2);
  future_traj(6 + (23 * 9)) = *(vars1d.x_24);
  future_traj(7 + (23 * 9)) = *(vars1d.x_24 + 1);
  future_traj(8 + (23 * 9)) = *(vars1d.x_24 + 2);
  future_traj(6 + (24 * 9)) = *(vars1d.x_25);
  future_traj(7 + (24 * 9)) = *(vars1d.x_25 + 1);
  future_traj(8 + (24 * 9)) = *(vars1d.x_25 + 2);
  future_traj(6 + (25 * 9)) = *(vars1d.x_26);
  future_traj(7 + (25 * 9)) = *(vars1d.x_26 + 1);
  future_traj(8 + (25 * 9)) = *(vars1d.x_26 + 2);
  future_traj(6 + (26 * 9)) = *(vars1d.x_27);
  future_traj(7 + (26 * 9)) = *(vars1d.x_27 + 1);
  future_traj(8 + (26 * 9)) = *(vars1d.x_27 + 2);
  future_traj(6 + (27 * 9)) = *(vars1d.x_28);
  future_traj(7 + (27 * 9)) = *(vars1d.x_28 + 1);
  future_traj(8 + (27 * 9)) = *(vars1d.x_28 + 2);
  future_traj(6 + (28 * 9)) = *(vars1d.x_29);
  future_traj(7 + (28 * 9)) = *(vars1d.x_29 + 1);
  future_traj(8 + (28 * 9)) = *(vars1d.x_29 + 2);
  future_traj(6 + (29 * 9)) = *(vars1d.x_30);
  future_traj(7 + (29 * 9)) = *(vars1d.x_30 + 1);
  future_traj(8 + (29 * 9)) = *(vars1d.x_30 + 2);
  future_traj(6 + (30 * 9)) = *(vars1d.x_31);
  future_traj(7 + (30 * 9)) = *(vars1d.x_31 + 1);
  future_traj(8 + (30 * 9)) = *(vars1d.x_31 + 2);
  future_traj(6 + (31 * 9)) = *(vars1d.x_32);
  future_traj(7 + (31 * 9)) = *(vars1d.x_32 + 1);
  future_traj(8 + (31 * 9)) = *(vars1d.x_32 + 2);
  future_traj(6 + (32 * 9)) = *(vars1d.x_33);
  future_traj(7 + (32 * 9)) = *(vars1d.x_33 + 1);
  future_traj(8 + (32 * 9)) = *(vars1d.x_33 + 2);
  future_traj(6 + (33 * 9)) = *(vars1d.x_34);
  future_traj(7 + (33 * 9)) = *(vars1d.x_34 + 1);
  future_traj(8 + (33 * 9)) = *(vars1d.x_34 + 2);
  future_traj(6 + (34 * 9)) = *(vars1d.x_35);
  future_traj(7 + (34 * 9)) = *(vars1d.x_35 + 1);
  future_traj(8 + (34 * 9)) = *(vars1d.x_35 + 2);
  future_traj(6 + (35 * 9)) = *(vars1d.x_36);
  future_traj(7 + (35 * 9)) = *(vars1d.x_36 + 1);
  future_traj(8 + (35 * 9)) = *(vars1d.x_36 + 2);
  future_traj(6 + (36 * 9)) = *(vars1d.x_37);
  future_traj(7 + (36 * 9)) = *(vars1d.x_37 + 1);
  future_traj(8 + (36 * 9)) = *(vars1d.x_37 + 2);
  future_traj(6 + (37 * 9)) = *(vars1d.x_38);
  future_traj(7 + (37 * 9)) = *(vars1d.x_38 + 1);
  future_traj(8 + (37 * 9)) = *(vars1d.x_38 + 2);
  future_traj(6 + (38 * 9)) = *(vars1d.x_39);
  future_traj(7 + (38 * 9)) = *(vars1d.x_39 + 1);
  future_traj(8 + (38 * 9)) = *(vars1d.x_39 + 2);
  future_traj(6 + (39 * 9)) = *(vars1d.x_40);
  future_traj(7 + (39 * 9)) = *(vars1d.x_40 + 1);
  future_traj(8 + (39 * 9)) = *(vars1d.x_40 + 2);
}
double CvxWrapper1d::getFirstControlInput() {
  return *(vars1d.u_0);
}
