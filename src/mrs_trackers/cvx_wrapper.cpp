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

CvxWrapper::CvxWrapper(bool verbose, int max_iters, std::vector<double> tempQ, std::vector<double> tempR, double dt, double dt2) {

  set_defaults();
  setup_indexing();

  if ((verbose != 1 && verbose != 0) || !std::isfinite(verbose)) {
    ROS_ERROR("CvxWrapper - verbose has to be 0 or 1!!! Safe value of 0 set instead");
    verbose = 0;
  }
  settings.verbose = verbose;

  if ((max_iters < 1 || max_iters > 100) || !std::isfinite(max_iters)) {
    ROS_ERROR("CvxWrapper - max_iters wrong value!!! Safe value of 25 set instead");
    max_iters = 15;
  }
  settings.max_iters = max_iters;
  settings.eps = 0.0001;
  settings.resid_tol = 0.001;
  
  if (tempQ.size() == 4) {
    for (int i = 0; i < 4; i++) {
      if (tempQ[i] >= 0 && std::isfinite(tempQ[i])) {
        params.Q[i] = tempQ[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper - Q matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        params.Q[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper - Q matrix wrong size " << tempQ.size() << " !!! Safe values set instead");
    params.Q[0] = 5000;
    params.Q[1] = 0;
    params.Q[2] = 5000;
    params.Q[3] = 0;
  }

  if (tempR.size() == 2) {
    for (int i = 0; i < 2; i++) {
      if (tempR[i] >= 0 && std::isfinite(tempR[i])) {
        params.R[i] = tempR[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper - R matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        params.R[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper - R matrix wrong size " << tempR.size() << " !!! Safe values set instead");
    params.R[0] = 500;
    params.R[1] = 500;
  }

  if (dt <= 0 || !std::isfinite(dt)) {
    ROS_ERROR_STREAM("CvxWrapper - dt parameter wrong " << dt << " !!! Safe value of 0.01 set instead");
    dt = 0.01;
  }

  if (dt2 <= 0 || !std::isfinite(dt2)) {
    ROS_ERROR_STREAM("CvxWrapper - dt2 parameter wrong " << dt2 << " !!! Safe value of 0.2 set instead");
    dt = 0.01;
  }

  params.A[0] = 1;
  params.A[1] = 1;
  params.A[2] = 1;
  params.A[3] = 1;
  params.A[4] = dt2;
  params.A[5] = dt2;

  params.Af[0] = 1;
  params.Af[1] = 1;
  params.Af[2] = 1;
  params.Af[3] = 1;
  params.Af[4] = dt;
  params.Af[5] = dt;

  params.B[0] = dt2;
  params.B[1] = dt2;

  params.Bf[0] = dt;
  params.Bf[1] = dt;

  ROS_INFO("Cvx wrapper XY initiated");
}
void CvxWrapper::setInitialState(MatrixXd& x) {
  params.x_0[0] = x(0, 0);
  params.x_0[1] = x(1, 0);
  params.x_0[2] = x(3, 0);
  params.x_0[3] = x(4, 0);
}
void CvxWrapper::setLimits(VectorXd& max_speed, VectorXd& max_acc) {
  params.x_max_2_1[0] = max_speed(0);
  params.x_max_2_2[0] = max_speed(1);
  params.x_max_2_3[0] = max_speed(2);
  params.x_max_2_4[0] = max_speed(3);
  params.x_max_2_5[0] = max_speed(4);
  params.x_max_2_6[0] = max_speed(5);
  params.x_max_2_7[0] = max_speed(6);
  params.x_max_2_8[0] = max_speed(7);
  params.x_max_2_9[0] = max_speed(8);
  params.x_max_2_10[0] = max_speed(9);
  params.x_max_2_11[0] = max_speed(10);
  params.x_max_2_12[0] = max_speed(11);
  params.x_max_2_13[0] = max_speed(12);
  params.x_max_2_14[0] = max_speed(13);
  params.x_max_2_15[0] = max_speed(14);
  params.x_max_2_16[0] = max_speed(15);
  params.x_max_2_17[0] = max_speed(16);
  params.x_max_2_18[0] = max_speed(17);
  params.x_max_2_19[0] = max_speed(18);
  params.x_max_2_20[0] = max_speed(19);
  params.x_max_2_21[0] = max_speed(20);
  params.x_max_2_22[0] = max_speed(21);
  params.x_max_2_23[0] = max_speed(22);
  params.x_max_2_24[0] = max_speed(23);
  params.x_max_2_25[0] = max_speed(24);
  params.x_max_2_26[0] = max_speed(25);
  params.x_max_2_27[0] = max_speed(26);
  params.x_max_2_28[0] = max_speed(27);
  params.x_max_2_29[0] = max_speed(28);
  params.x_max_2_30[0] = max_speed(29);
  params.x_max_2_31[0] = max_speed(30);
  params.x_max_2_32[0] = max_speed(31);
  params.x_max_2_33[0] = max_speed(32);
  params.x_max_2_34[0] = max_speed(33);
  params.x_max_2_35[0] = max_speed(34);
  params.x_max_2_36[0] = max_speed(35);
  params.x_max_2_37[0] = max_speed(36);
  params.x_max_2_38[0] = max_speed(37);
  params.x_max_2_39[0] = max_speed(38);
  params.x_max_2_40[0] = max_speed(39);
  
  params.x_max_3_0[0] = max_acc(0);
  params.x_max_3_1[0] = max_acc(1);
  params.x_max_3_2[0] = max_acc(2);
  params.x_max_3_3[0] = max_acc(3);
  params.x_max_3_4[0] = max_acc(4);
  params.x_max_3_5[0] = max_acc(5);
  params.x_max_3_6[0] = max_acc(6);
  params.x_max_3_7[0] = max_acc(7);
  params.x_max_3_8[0] = max_acc(8);
  params.x_max_3_9[0] = max_acc(9);
  params.x_max_3_10[0] = max_acc(10);
  params.x_max_3_11[0] = max_acc(11);
  params.x_max_3_12[0] = max_acc(12);
  params.x_max_3_13[0] = max_acc(13);
  params.x_max_3_14[0] = max_acc(14);
  params.x_max_3_15[0] = max_acc(15);
  params.x_max_3_16[0] = max_acc(16);
  params.x_max_3_17[0] = max_acc(17);
  params.x_max_3_18[0] = max_acc(18);
  params.x_max_3_19[0] = max_acc(19);
  params.x_max_3_20[0] = max_acc(20);
  params.x_max_3_21[0] = max_acc(21);
  params.x_max_3_22[0] = max_acc(22);
  params.x_max_3_23[0] = max_acc(23);
  params.x_max_3_24[0] = max_acc(24);
  params.x_max_3_25[0] = max_acc(25);
  params.x_max_3_26[0] = max_acc(26);
  params.x_max_3_27[0] = max_acc(27);
  params.x_max_3_28[0] = max_acc(28);
  params.x_max_3_29[0] = max_acc(29);
  params.x_max_3_30[0] = max_acc(30);
  params.x_max_3_31[0] = max_acc(31);
  params.x_max_3_32[0] = max_acc(32);
  params.x_max_3_33[0] = max_acc(33);
  params.x_max_3_34[0] = max_acc(34);
  params.x_max_3_35[0] = max_acc(35);
  params.x_max_3_36[0] = max_acc(36);
  params.x_max_3_37[0] = max_acc(37);
  params.x_max_3_38[0] = max_acc(38);
  params.x_max_3_39[0] = max_acc(39);
}
void CvxWrapper::loadReference(MatrixXd& reference) {
  params.x_ss_1[0]  = reference(0 * n + 0, 0);
  params.x_ss_1[2]  = reference(0 * n + 3, 0);
  params.x_ss_2[0]  = reference(1 * n + 0, 0);
  params.x_ss_2[2]  = reference(1 * n + 3, 0);
  params.x_ss_3[0]  = reference(2 * n + 0, 0);
  params.x_ss_3[2]  = reference(2 * n + 3, 0);
  params.x_ss_4[0]  = reference(3 * n + 0, 0);
  params.x_ss_4[2]  = reference(3 * n + 3, 0);
  params.x_ss_5[0]  = reference(4 * n + 0, 0);
  params.x_ss_5[2]  = reference(4 * n + 3, 0);
  params.x_ss_6[0]  = reference(5 * n + 0, 0);
  params.x_ss_6[2]  = reference(5 * n + 3, 0);
  params.x_ss_7[0]  = reference(6 * n + 0, 0);
  params.x_ss_7[2]  = reference(6 * n + 3, 0);
  params.x_ss_8[0]  = reference(7 * n + 0, 0);
  params.x_ss_8[2]  = reference(7 * n + 3, 0);
  params.x_ss_9[0]  = reference(8 * n + 0, 0);
  params.x_ss_9[2]  = reference(8 * n + 3, 0);
  params.x_ss_10[0] = reference(9 * n + 0, 0);
  params.x_ss_10[2] = reference(9 * n + 3, 0);
  params.x_ss_11[0] = reference(10 * n + 0, 0);
  params.x_ss_11[2] = reference(10 * n + 3, 0);
  params.x_ss_12[0] = reference(11 * n + 0, 0);
  params.x_ss_12[2] = reference(11 * n + 3, 0);
  params.x_ss_13[0] = reference(12 * n + 0, 0);
  params.x_ss_13[2] = reference(12 * n + 3, 0);
  params.x_ss_14[0] = reference(13 * n + 0, 0);
  params.x_ss_14[2] = reference(13 * n + 3, 0);
  params.x_ss_15[0] = reference(14 * n + 0, 0);
  params.x_ss_15[2] = reference(14 * n + 3, 0);
  params.x_ss_16[0] = reference(15 * n + 0, 0);
  params.x_ss_16[2] = reference(15 * n + 3, 0);
  params.x_ss_17[0] = reference(16 * n + 0, 0);
  params.x_ss_17[2] = reference(16 * n + 3, 0);
  params.x_ss_18[0] = reference(17 * n + 0, 0);
  params.x_ss_18[2] = reference(17 * n + 3, 0);
  params.x_ss_19[0] = reference(18 * n + 0, 0);
  params.x_ss_19[2] = reference(18 * n + 3, 0);
  params.x_ss_20[0] = reference(19 * n + 0, 0);
  params.x_ss_20[2] = reference(19 * n + 3, 0);
  params.x_ss_21[0] = reference(20 * n + 0, 0);
  params.x_ss_21[2] = reference(20 * n + 3, 0);
  params.x_ss_22[0] = reference(21 * n + 0, 0);
  params.x_ss_22[2] = reference(21 * n + 3, 0);
  params.x_ss_23[0] = reference(22 * n + 0, 0);
  params.x_ss_23[2] = reference(22 * n + 3, 0);
  params.x_ss_24[0] = reference(23 * n + 0, 0);
  params.x_ss_24[2] = reference(23 * n + 3, 0);
  params.x_ss_25[0] = reference(24 * n + 0, 0);
  params.x_ss_25[2] = reference(24 * n + 3, 0);
  params.x_ss_26[0] = reference(25 * n + 0, 0);
  params.x_ss_26[2] = reference(25 * n + 3, 0);
  params.x_ss_27[0] = reference(26 * n + 0, 0);
  params.x_ss_27[2] = reference(26 * n + 3, 0);
  params.x_ss_28[0] = reference(27 * n + 0, 0);
  params.x_ss_28[2] = reference(27 * n + 3, 0);
  params.x_ss_29[0] = reference(28 * n + 0, 0);
  params.x_ss_29[2] = reference(28 * n + 3, 0);
  params.x_ss_30[0] = reference(29 * n + 0, 0);
  params.x_ss_30[2] = reference(29 * n + 3, 0);
  params.x_ss_31[0] = reference(30 * n + 0, 0);
  params.x_ss_31[2] = reference(30 * n + 3, 0);
  params.x_ss_32[0] = reference(31 * n + 0, 0);
  params.x_ss_32[2] = reference(31 * n + 3, 0);
  params.x_ss_33[0] = reference(32 * n + 0, 0);
  params.x_ss_33[2] = reference(32 * n + 3, 0);
  params.x_ss_34[0] = reference(33 * n + 0, 0);
  params.x_ss_34[2] = reference(33 * n + 3, 0);
  params.x_ss_35[0] = reference(34 * n + 0, 0);
  params.x_ss_35[2] = reference(34 * n + 3, 0);
  params.x_ss_36[0] = reference(35 * n + 0, 0);
  params.x_ss_36[2] = reference(35 * n + 3, 0);
  params.x_ss_37[0] = reference(36 * n + 0, 0);
  params.x_ss_37[2] = reference(36 * n + 3, 0);
  params.x_ss_38[0] = reference(37 * n + 0, 0);
  params.x_ss_38[2] = reference(37 * n + 3, 0);
  params.x_ss_39[0] = reference(38 * n + 0, 0);
  params.x_ss_39[2] = reference(38 * n + 3, 0);
  params.x_ss_40[0] = reference(39 * n + 0, 0);
  params.x_ss_40[2] = reference(39 * n + 3, 0);
}
int CvxWrapper::solveCvx() {
  return solve();
}
void CvxWrapper::getStates(MatrixXd& future_traj) {
  /* ROS_INFO_STREAM_THROTTLE(0.1, "Us: " << *(vars.u_0) << " " << *(vars.u_1) << " " << *(vars.u_2)); */
  future_traj(0 + (0 * 9))  = *(vars.x_1);
  future_traj(1 + (0 * 9))  = *(vars.x_1 + 1);
  future_traj(2 + (0 * 9))  = *(vars.u_0);
  future_traj(3 + (0 * 9))  = *(vars.x_1 + 2);
  future_traj(4 + (0 * 9))  = *(vars.x_1 + 3);
  future_traj(5 + (0 * 9))  = *(vars.u_0 + 1);
  future_traj(0 + (1 * 9))  = *(vars.x_2);
  future_traj(1 + (1 * 9))  = *(vars.x_2 + 1);
  future_traj(2 + (1 * 9))  = *(vars.u_1);
  future_traj(3 + (1 * 9))  = *(vars.x_2 + 2);
  future_traj(4 + (1 * 9))  = *(vars.x_2 + 3);
  future_traj(5 + (1 * 9))  = *(vars.u_1 + 1);
  future_traj(0 + (2 * 9))  = *(vars.x_3);
  future_traj(1 + (2 * 9))  = *(vars.x_3 + 1);
  future_traj(2 + (2 * 9))  = *(vars.u_2);
  future_traj(3 + (2 * 9))  = *(vars.x_3 + 2);
  future_traj(4 + (2 * 9))  = *(vars.x_3 + 3);
  future_traj(5 + (2 * 9))  = *(vars.u_2 + 1);
  future_traj(0 + (3 * 9))  = *(vars.x_4);
  future_traj(1 + (3 * 9))  = *(vars.x_4 + 1);
  future_traj(2 + (3 * 9))  = *(vars.u_3);
  future_traj(3 + (3 * 9))  = *(vars.x_4 + 2);
  future_traj(4 + (3 * 9))  = *(vars.x_4 + 3);
  future_traj(5 + (3 * 9))  = *(vars.u_3 + 1);
  future_traj(0 + (4 * 9))  = *(vars.x_5);
  future_traj(1 + (4 * 9))  = *(vars.x_5 + 1);
  future_traj(2 + (4 * 9))  = *(vars.u_4);
  future_traj(3 + (4 * 9))  = *(vars.x_5 + 2);
  future_traj(4 + (4 * 9))  = *(vars.x_5 + 3);
  future_traj(5 + (4 * 9))  = *(vars.u_4 + 1);
  future_traj(0 + (5 * 9))  = *(vars.x_6);
  future_traj(1 + (5 * 9))  = *(vars.x_6 + 1);
  future_traj(2 + (5 * 9))  = *(vars.u_5);
  future_traj(3 + (5 * 9))  = *(vars.x_6 + 2);
  future_traj(4 + (5 * 9))  = *(vars.x_6 + 3);
  future_traj(5 + (5 * 9))  = *(vars.u_5 + 1);
  future_traj(0 + (6 * 9))  = *(vars.x_7);
  future_traj(1 + (6 * 9))  = *(vars.x_7 + 1);
  future_traj(2 + (6 * 9))  = *(vars.u_6);
  future_traj(3 + (6 * 9))  = *(vars.x_7 + 2);
  future_traj(4 + (6 * 9))  = *(vars.x_7 + 3);
  future_traj(5 + (6 * 9))  = *(vars.u_6 + 1);
  future_traj(0 + (7 * 9))  = *(vars.x_8);
  future_traj(1 + (7 * 9))  = *(vars.x_8 + 1);
  future_traj(2 + (7 * 9))  = *(vars.u_7);
  future_traj(3 + (7 * 9))  = *(vars.x_8 + 2);
  future_traj(4 + (7 * 9))  = *(vars.x_8 + 3);
  future_traj(5 + (7 * 9))  = *(vars.u_7 + 1);
  future_traj(0 + (8 * 9))  = *(vars.x_9);
  future_traj(1 + (8 * 9))  = *(vars.x_9 + 1);
  future_traj(2 + (8 * 9))  = *(vars.u_8);
  future_traj(3 + (8 * 9))  = *(vars.x_9 + 2);
  future_traj(4 + (8 * 9))  = *(vars.x_9 + 3);
  future_traj(5 + (8 * 9))  = *(vars.u_8 + 1);
  future_traj(0 + (9 * 9))  = *(vars.x_10);
  future_traj(1 + (9 * 9))  = *(vars.x_10 + 1);
  future_traj(2 + (9 * 9))  = *(vars.u_9);
  future_traj(3 + (9 * 9))  = *(vars.x_10 + 2);
  future_traj(4 + (9 * 9))  = *(vars.x_10 + 3);
  future_traj(5 + (9 * 9))  = *(vars.u_9 + 1);
  future_traj(0 + (10 * 9)) = *(vars.x_11);
  future_traj(1 + (10 * 9)) = *(vars.x_11 + 1);
  future_traj(2 + (10 * 9)) = *(vars.u_10);
  future_traj(3 + (10 * 9)) = *(vars.x_11 + 2);
  future_traj(4 + (10 * 9)) = *(vars.x_11 + 3);
  future_traj(5 + (10 * 9)) = *(vars.u_10 + 1);
  future_traj(0 + (11 * 9)) = *(vars.x_12);
  future_traj(1 + (11 * 9)) = *(vars.x_12 + 1);
  future_traj(2 + (11 * 9)) = *(vars.u_11);
  future_traj(3 + (11 * 9)) = *(vars.x_12 + 2);
  future_traj(4 + (11 * 9)) = *(vars.x_12 + 3);
  future_traj(5 + (11 * 9)) = *(vars.u_11 + 1);
  future_traj(0 + (12 * 9)) = *(vars.x_13);
  future_traj(1 + (12 * 9)) = *(vars.x_13 + 1);
  future_traj(2 + (12 * 9)) = *(vars.u_12);
  future_traj(3 + (12 * 9)) = *(vars.x_13 + 2);
  future_traj(4 + (12 * 9)) = *(vars.x_13 + 3);
  future_traj(5 + (12 * 9)) = *(vars.u_12 + 1);
  future_traj(0 + (13 * 9)) = *(vars.x_14);
  future_traj(1 + (13 * 9)) = *(vars.x_14 + 1);
  future_traj(2 + (13 * 9)) = *(vars.u_13);
  future_traj(3 + (13 * 9)) = *(vars.x_14 + 2);
  future_traj(4 + (13 * 9)) = *(vars.x_14 + 3);
  future_traj(5 + (13 * 9)) = *(vars.u_13 + 1);
  future_traj(0 + (14 * 9)) = *(vars.x_15);
  future_traj(1 + (14 * 9)) = *(vars.x_15 + 1);
  future_traj(2 + (14 * 9)) = *(vars.u_14);
  future_traj(3 + (14 * 9)) = *(vars.x_15 + 2);
  future_traj(4 + (14 * 9)) = *(vars.x_15 + 3);
  future_traj(5 + (14 * 9)) = *(vars.u_14 + 1);
  future_traj(0 + (15 * 9)) = *(vars.x_16);
  future_traj(1 + (15 * 9)) = *(vars.x_16 + 1);
  future_traj(2 + (15 * 9)) = *(vars.u_15);
  future_traj(3 + (15 * 9)) = *(vars.x_16 + 2);
  future_traj(4 + (15 * 9)) = *(vars.x_16 + 3);
  future_traj(5 + (15 * 9)) = *(vars.u_15 + 1);
  future_traj(0 + (16 * 9)) = *(vars.x_17);
  future_traj(1 + (16 * 9)) = *(vars.x_17 + 1);
  future_traj(2 + (16 * 9)) = *(vars.u_16);
  future_traj(3 + (16 * 9)) = *(vars.x_17 + 2);
  future_traj(4 + (16 * 9)) = *(vars.x_17 + 3);
  future_traj(5 + (16 * 9)) = *(vars.u_16 + 1);
  future_traj(0 + (17 * 9)) = *(vars.x_18);
  future_traj(1 + (17 * 9)) = *(vars.x_18 + 1);
  future_traj(2 + (17 * 9)) = *(vars.u_17);
  future_traj(3 + (17 * 9)) = *(vars.x_18 + 2);
  future_traj(4 + (17 * 9)) = *(vars.x_18 + 3);
  future_traj(5 + (17 * 9)) = *(vars.u_17 + 1);
  future_traj(0 + (18 * 9)) = *(vars.x_19);
  future_traj(1 + (18 * 9)) = *(vars.x_19 + 1);
  future_traj(2 + (18 * 9)) = *(vars.u_18);
  future_traj(3 + (18 * 9)) = *(vars.x_19 + 2);
  future_traj(4 + (18 * 9)) = *(vars.x_19 + 3);
  future_traj(5 + (18 * 9)) = *(vars.u_18 + 1);
  future_traj(0 + (19 * 9)) = *(vars.x_20);
  future_traj(1 + (19 * 9)) = *(vars.x_20 + 1);
  future_traj(2 + (19 * 9)) = *(vars.u_19);
  future_traj(3 + (19 * 9)) = *(vars.x_20 + 2);
  future_traj(4 + (19 * 9)) = *(vars.x_20 + 3);
  future_traj(5 + (19 * 9)) = *(vars.u_19 + 1);
  future_traj(0 + (20 * 9)) = *(vars.x_21);
  future_traj(1 + (20 * 9)) = *(vars.x_21 + 1);
  future_traj(2 + (20 * 9)) = *(vars.u_20);
  future_traj(3 + (20 * 9)) = *(vars.x_21 + 2);
  future_traj(4 + (20 * 9)) = *(vars.x_21 + 3);
  future_traj(5 + (20 * 9)) = *(vars.u_20 + 1);
  future_traj(0 + (21 * 9)) = *(vars.x_22);
  future_traj(1 + (21 * 9)) = *(vars.x_22 + 1);
  future_traj(2 + (21 * 9)) = *(vars.u_21);
  future_traj(3 + (21 * 9)) = *(vars.x_22 + 2);
  future_traj(4 + (21 * 9)) = *(vars.x_22 + 3);
  future_traj(5 + (21 * 9)) = *(vars.u_21 + 1);
  future_traj(0 + (22 * 9)) = *(vars.x_23);
  future_traj(1 + (22 * 9)) = *(vars.x_23 + 1);
  future_traj(2 + (22 * 9)) = *(vars.u_22);
  future_traj(3 + (22 * 9)) = *(vars.x_23 + 2);
  future_traj(4 + (22 * 9)) = *(vars.x_23 + 3);
  future_traj(5 + (22 * 9)) = *(vars.u_22 + 1);
  future_traj(0 + (23 * 9)) = *(vars.x_24);
  future_traj(1 + (23 * 9)) = *(vars.x_24 + 1);
  future_traj(2 + (23 * 9)) = *(vars.u_23);
  future_traj(3 + (23 * 9)) = *(vars.x_24 + 2);
  future_traj(4 + (23 * 9)) = *(vars.x_24 + 3);
  future_traj(5 + (23 * 9)) = *(vars.u_23 + 1);
  future_traj(0 + (24 * 9)) = *(vars.x_25);
  future_traj(1 + (24 * 9)) = *(vars.x_25 + 1);
  future_traj(2 + (24 * 9)) = *(vars.u_24);
  future_traj(3 + (24 * 9)) = *(vars.x_25 + 2);
  future_traj(4 + (24 * 9)) = *(vars.x_25 + 3);
  future_traj(5 + (24 * 9)) = *(vars.u_24 + 1);
  future_traj(0 + (25 * 9)) = *(vars.x_26);
  future_traj(1 + (25 * 9)) = *(vars.x_26 + 1);
  future_traj(2 + (25 * 9)) = *(vars.u_25);
  future_traj(3 + (25 * 9)) = *(vars.x_26 + 2);
  future_traj(4 + (25 * 9)) = *(vars.x_26 + 3);
  future_traj(5 + (25 * 9)) = *(vars.u_25 + 1);
  future_traj(0 + (26 * 9)) = *(vars.x_27);
  future_traj(1 + (26 * 9)) = *(vars.x_27 + 1);
  future_traj(2 + (26 * 9)) = *(vars.u_26);
  future_traj(3 + (26 * 9)) = *(vars.x_27 + 2);
  future_traj(4 + (26 * 9)) = *(vars.x_27 + 3);
  future_traj(5 + (26 * 9)) = *(vars.u_26 + 1);
  future_traj(0 + (27 * 9)) = *(vars.x_28);
  future_traj(1 + (27 * 9)) = *(vars.x_28 + 1);
  future_traj(2 + (27 * 9)) = *(vars.u_27);
  future_traj(3 + (27 * 9)) = *(vars.x_28 + 2);
  future_traj(4 + (27 * 9)) = *(vars.x_28 + 3);
  future_traj(5 + (27 * 9)) = *(vars.u_27 + 1);
  future_traj(0 + (28 * 9)) = *(vars.x_29);
  future_traj(1 + (28 * 9)) = *(vars.x_29 + 1);
  future_traj(2 + (28 * 9)) = *(vars.u_28);
  future_traj(3 + (28 * 9)) = *(vars.x_29 + 2);
  future_traj(4 + (28 * 9)) = *(vars.x_29 + 3);
  future_traj(5 + (28 * 9)) = *(vars.u_28 + 1);
  future_traj(0 + (29 * 9)) = *(vars.x_30);
  future_traj(1 + (29 * 9)) = *(vars.x_30 + 1);
  future_traj(2 + (29 * 9)) = *(vars.u_29);
  future_traj(3 + (29 * 9)) = *(vars.x_30 + 2);
  future_traj(4 + (29 * 9)) = *(vars.x_30 + 3);
  future_traj(5 + (29 * 9)) = *(vars.u_29 + 1);
  future_traj(0 + (30 * 9)) = *(vars.x_31);
  future_traj(1 + (30 * 9)) = *(vars.x_31 + 1);
  future_traj(2 + (30 * 9)) = *(vars.u_30);
  future_traj(3 + (30 * 9)) = *(vars.x_31 + 2);
  future_traj(4 + (30 * 9)) = *(vars.x_31 + 3);
  future_traj(5 + (30 * 9)) = *(vars.u_30 + 1);
  future_traj(0 + (31 * 9)) = *(vars.x_32);
  future_traj(1 + (31 * 9)) = *(vars.x_32 + 1);
  future_traj(2 + (31 * 9)) = *(vars.u_31);
  future_traj(3 + (31 * 9)) = *(vars.x_32 + 2);
  future_traj(4 + (31 * 9)) = *(vars.x_32 + 3);
  future_traj(5 + (31 * 9)) = *(vars.u_31 + 1);
  future_traj(0 + (32 * 9)) = *(vars.x_33);
  future_traj(1 + (32 * 9)) = *(vars.x_33 + 1);
  future_traj(2 + (32 * 9)) = *(vars.u_32);
  future_traj(3 + (32 * 9)) = *(vars.x_33 + 2);
  future_traj(4 + (32 * 9)) = *(vars.x_33 + 3);
  future_traj(5 + (32 * 9)) = *(vars.u_32 + 1);
  future_traj(0 + (33 * 9)) = *(vars.x_34);
  future_traj(1 + (33 * 9)) = *(vars.x_34 + 1);
  future_traj(2 + (33 * 9)) = *(vars.u_33);
  future_traj(3 + (33 * 9)) = *(vars.x_34 + 2);
  future_traj(4 + (33 * 9)) = *(vars.x_34 + 3);
  future_traj(5 + (33 * 9)) = *(vars.u_33 + 1);
  future_traj(0 + (34 * 9)) = *(vars.x_35);
  future_traj(1 + (34 * 9)) = *(vars.x_35 + 1);
  future_traj(2 + (34 * 9)) = *(vars.u_34);
  future_traj(3 + (34 * 9)) = *(vars.x_35 + 2);
  future_traj(4 + (34 * 9)) = *(vars.x_35 + 3);
  future_traj(5 + (34 * 9)) = *(vars.u_34 + 1);
  future_traj(0 + (35 * 9)) = *(vars.x_36);
  future_traj(1 + (35 * 9)) = *(vars.x_36 + 1);
  future_traj(2 + (35 * 9)) = *(vars.u_35);
  future_traj(3 + (35 * 9)) = *(vars.x_36 + 2);
  future_traj(4 + (35 * 9)) = *(vars.x_36 + 3);
  future_traj(5 + (35 * 9)) = *(vars.u_35 + 1);
  future_traj(0 + (36 * 9)) = *(vars.x_37);
  future_traj(1 + (36 * 9)) = *(vars.x_37 + 1);
  future_traj(2 + (36 * 9)) = *(vars.u_36);
  future_traj(3 + (36 * 9)) = *(vars.x_37 + 2);
  future_traj(4 + (36 * 9)) = *(vars.x_37 + 3);
  future_traj(5 + (36 * 9)) = *(vars.u_36 + 1);
  future_traj(0 + (37 * 9)) = *(vars.x_38);
  future_traj(1 + (37 * 9)) = *(vars.x_38 + 1);
  future_traj(2 + (37 * 9)) = *(vars.u_37);
  future_traj(3 + (37 * 9)) = *(vars.x_38 + 2);
  future_traj(4 + (37 * 9)) = *(vars.x_38 + 3);
  future_traj(5 + (37 * 9)) = *(vars.u_37 + 1);
  future_traj(0 + (38 * 9)) = *(vars.x_39);
  future_traj(1 + (38 * 9)) = *(vars.x_39 + 1);
  future_traj(2 + (38 * 9)) = *(vars.u_38);
  future_traj(3 + (38 * 9)) = *(vars.x_39 + 2);
  future_traj(4 + (38 * 9)) = *(vars.x_39 + 3);
  future_traj(5 + (38 * 9)) = *(vars.u_38 + 1);
  future_traj(0 + (39 * 9)) = *(vars.x_40);
  future_traj(1 + (39 * 9)) = *(vars.x_40 + 1);
  future_traj(2 + (39 * 9)) = *(vars.u_39);
  future_traj(3 + (39 * 9)) = *(vars.x_40 + 2);
  future_traj(4 + (39 * 9)) = *(vars.x_40 + 3);
  future_traj(5 + (39 * 9)) = *(vars.u_39 + 1);
}
double CvxWrapper::getFirstControlInputX() {
  return *(vars.u_0);
}
double CvxWrapper::getFirstControlInputY() {
  return *(vars.u_0 + 1);
}
