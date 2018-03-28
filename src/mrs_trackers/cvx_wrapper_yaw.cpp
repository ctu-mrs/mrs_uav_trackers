/* author: Daniel Hert */

extern "C" {
#include "cvxgen_yaw/solver.h"
}
#include <eigen3/Eigen/Eigen>
#include "cvx_wrapper_yaw.h"

using namespace Eigen;

VarsYaw      varsYaw;
ParamsYaw    paramsYaw;
WorkspaceYaw workYaw;
SettingsYaw  settingsYaw;

CvxWrapperYaw::CvxWrapperYaw(bool verbose, int max_iters, std::vector<double> tempQ, std::vector<double> tempR, double dt, double dt2) {


  set_defaults_yaw();
  setup_indexing_yaw();

  if ((verbose != 1 && verbose != 0) || !std::isfinite(verbose)) {
    ROS_ERROR("CvxWrapper_yaw - verbose has to be 0 or 1!!! Safe value of 0 set instead");
    verbose = 0;
  }
  settingsYaw.verbose = verbose;

  if ((max_iters < 1 || max_iters > 100) || !std::isfinite(max_iters)) {
    ROS_ERROR("CvxWrapper_yaw - max_iters wrong value!!! Safe value of 25 set instead");
    max_iters = 25;
  }
  settingsYaw.max_iters = max_iters;

  if (tempQ.size() == 3) {
    for (int i = 0; i < 3; i++) {
      if (tempQ[i] >= 0 && std::isfinite(tempQ[i])) {
        paramsYaw.Q[i] = tempQ[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper_yaw - Q matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        paramsYaw.Q[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper_yaw - Q matrix wrong size " << tempQ.size() << " !!! Safe values set instead");
    paramsYaw.Q[0] = 5000;
    paramsYaw.Q[1] = 0;
    paramsYaw.Q[2] = 0;
  }

  if (tempR.size() == 1) {
    for (int i = 0; i < 1; i++) {
      if (tempR[i] >= 0 && std::isfinite(tempR[i])) {
        paramsYaw.R[i] = tempR[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper_yaw - R matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        paramsYaw.R[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper_yaw - R matrix wrong size " << tempR.size() << " !!! Safe values set instead");
    paramsYaw.R[0] = 500;
  }

  if (dt <= 0 || !std::isfinite(dt)) {
    ROS_ERROR_STREAM("CvxWrapper_yaw - dt parameter wrong " << dt << " !!! Safe value of 0.01 set instead");
    dt = 0.01;
  }

  if (dt2 <= 0 || !std::isfinite(dt2)) {
    ROS_ERROR_STREAM("CvxWrapper_yaw - dt2 parameter wrong " << dt2 << " !!! Safe value of 0.2 set instead");
    dt = 0.01;
  }


  paramsYaw.A[0] = 1;
  paramsYaw.A[1] = 1;
  paramsYaw.A[2] = 1;
  paramsYaw.A[3] = dt2;
  paramsYaw.A[4] = dt2;

  paramsYaw.Af[0] = 1;
  paramsYaw.Af[1] = 1;
  paramsYaw.Af[2] = 1;
  paramsYaw.Af[3] = dt;
  paramsYaw.Af[4] = dt;

  paramsYaw.B[0]  = dt2;

  paramsYaw.Bf[0] = dt;

  ROS_INFO("Cvx wrapper _yaw initiated");
}
void CvxWrapperYaw::setLimits(double speed_max, double acc_max) {
  paramsYaw.x_max_2[0] = speed_max;
  paramsYaw.x_max_3[0] = acc_max;
}

void CvxWrapperYaw::setInitialState(MatrixXd &x) {
  paramsYaw.x_0[0]    = x(0, 0);
  paramsYaw.x_0[1]    = x(1, 0);
  paramsYaw.x_0[2]    = x(2, 0);
}
void CvxWrapperYaw::loadReference(MatrixXd &reference) {
  paramsYaw.x_ss_1[0]  = reference(0 * 3, 0);
  paramsYaw.x_ss_2[0]  = reference(1 * 3, 0);
  paramsYaw.x_ss_3[0]  = reference(2 * 3, 0);
  paramsYaw.x_ss_4[0]  = reference(3 * 3, 0);
  paramsYaw.x_ss_5[0]  = reference(4 * 3, 0);
  paramsYaw.x_ss_6[0]  = reference(5 * 3, 0);
  paramsYaw.x_ss_7[0]  = reference(6 * 3, 0);
  paramsYaw.x_ss_8[0]  = reference(7 * 3, 0);
  paramsYaw.x_ss_9[0]  = reference(8 * 3, 0);
  paramsYaw.x_ss_10[0] = reference(9 * 3, 0);
  paramsYaw.x_ss_11[0] = reference(10 * 3, 0);
  paramsYaw.x_ss_12[0] = reference(11 * 3, 0);
  paramsYaw.x_ss_13[0] = reference(12 * 3, 0);
  paramsYaw.x_ss_14[0] = reference(13 * 3, 0);
  paramsYaw.x_ss_15[0] = reference(14 * 3, 0);
  paramsYaw.x_ss_16[0] = reference(15 * 3, 0);
  paramsYaw.x_ss_17[0] = reference(16 * 3, 0);
  paramsYaw.x_ss_18[0] = reference(17 * 3, 0);
  paramsYaw.x_ss_19[0] = reference(18 * 3, 0);
  paramsYaw.x_ss_20[0] = reference(19 * 3, 0);
  paramsYaw.x_ss_21[0] = reference(20 * 3, 0);
  paramsYaw.x_ss_22[0] = reference(21 * 3, 0);
  paramsYaw.x_ss_23[0] = reference(22 * 3, 0);
  paramsYaw.x_ss_24[0] = reference(23 * 3, 0);
  paramsYaw.x_ss_25[0] = reference(24 * 3, 0);
  paramsYaw.x_ss_26[0] = reference(25 * 3, 0);
  paramsYaw.x_ss_27[0] = reference(26 * 3, 0);
  paramsYaw.x_ss_28[0] = reference(27 * 3, 0);
  paramsYaw.x_ss_29[0] = reference(28 * 3, 0);
  paramsYaw.x_ss_30[0] = reference(29 * 3, 0);
  paramsYaw.x_ss_31[0] = reference(30 * 3, 0);
  paramsYaw.x_ss_32[0] = reference(31 * 3, 0);
  paramsYaw.x_ss_33[0] = reference(32 * 3, 0);
  paramsYaw.x_ss_34[0] = reference(33 * 3, 0);
  paramsYaw.x_ss_35[0] = reference(34 * 3, 0);
  paramsYaw.x_ss_36[0] = reference(35 * 3, 0);
  paramsYaw.x_ss_37[0] = reference(36 * 3, 0);
  paramsYaw.x_ss_38[0] = reference(37 * 3, 0);
  paramsYaw.x_ss_39[0] = reference(38 * 3, 0);
  paramsYaw.x_ss_40[0] = reference(39 * 3, 0);
}
int CvxWrapperYaw::solveCvx() {
  return solve_yaw();
}
void CvxWrapperYaw::getStates(MatrixXd &future_traj) {
  future_traj(0 + (0 * 3))  = *(varsYaw.x_1);
  future_traj(1 + (0 * 3))  = *(varsYaw.x_1 + 1);
  future_traj(2 + (0 * 3))  = *(varsYaw.x_1 + 2);
  future_traj(0 + (1 * 3))  = *(varsYaw.x_2);
  future_traj(1 + (1 * 3))  = *(varsYaw.x_2 + 1);
  future_traj(2 + (1 * 3))  = *(varsYaw.x_2 + 2);
  future_traj(0 + (2 * 3))  = *(varsYaw.x_3);
  future_traj(1 + (2 * 3))  = *(varsYaw.x_3 + 1);
  future_traj(2 + (2 * 3))  = *(varsYaw.x_3 + 2);
  future_traj(0 + (3 * 3))  = *(varsYaw.x_4);
  future_traj(1 + (3 * 3))  = *(varsYaw.x_4 + 1);
  future_traj(2 + (3 * 3))  = *(varsYaw.x_4 + 2);
  future_traj(0 + (4 * 3))  = *(varsYaw.x_5);
  future_traj(1 + (4 * 3))  = *(varsYaw.x_5 + 1);
  future_traj(2 + (4 * 3))  = *(varsYaw.x_5 + 2);
  future_traj(0 + (5 * 3))  = *(varsYaw.x_6);
  future_traj(1 + (5 * 3))  = *(varsYaw.x_6 + 1);
  future_traj(2 + (5 * 3))  = *(varsYaw.x_6 + 2);
  future_traj(0 + (6 * 3))  = *(varsYaw.x_7);
  future_traj(1 + (6 * 3))  = *(varsYaw.x_7 + 1);
  future_traj(2 + (6 * 3))  = *(varsYaw.x_7 + 2);
  future_traj(0 + (7 * 3))  = *(varsYaw.x_8);
  future_traj(1 + (7 * 3))  = *(varsYaw.x_8 + 1);
  future_traj(2 + (7 * 3))  = *(varsYaw.x_8 + 2);
  future_traj(0 + (8 * 3))  = *(varsYaw.x_9);
  future_traj(1 + (8 * 3))  = *(varsYaw.x_9 + 1);
  future_traj(2 + (8 * 3))  = *(varsYaw.x_9 + 2);
  future_traj(0 + (9 * 3))  = *(varsYaw.x_10);
  future_traj(1 + (9 * 3))  = *(varsYaw.x_10 + 1);
  future_traj(2 + (9 * 3))  = *(varsYaw.x_10 + 2);
  future_traj(0 + (10 * 3)) = *(varsYaw.x_11);
  future_traj(1 + (10 * 3)) = *(varsYaw.x_11 + 1);
  future_traj(2 + (10 * 3)) = *(varsYaw.x_11 + 2);
  future_traj(0 + (11 * 3)) = *(varsYaw.x_12);
  future_traj(1 + (11 * 3)) = *(varsYaw.x_12 + 1);
  future_traj(2 + (11 * 3)) = *(varsYaw.x_12 + 2);
  future_traj(0 + (12 * 3)) = *(varsYaw.x_13);
  future_traj(1 + (12 * 3)) = *(varsYaw.x_13 + 1);
  future_traj(2 + (12 * 3)) = *(varsYaw.x_13 + 2);
  future_traj(0 + (13 * 3)) = *(varsYaw.x_14);
  future_traj(1 + (13 * 3)) = *(varsYaw.x_14 + 1);
  future_traj(2 + (13 * 3)) = *(varsYaw.x_14 + 2);
  future_traj(0 + (14 * 3)) = *(varsYaw.x_15);
  future_traj(1 + (14 * 3)) = *(varsYaw.x_15 + 1);
  future_traj(2 + (14 * 3)) = *(varsYaw.x_15 + 2);
  future_traj(0 + (15 * 3)) = *(varsYaw.x_16);
  future_traj(1 + (15 * 3)) = *(varsYaw.x_16 + 1);
  future_traj(2 + (15 * 3)) = *(varsYaw.x_16 + 2);
  future_traj(0 + (16 * 3)) = *(varsYaw.x_17);
  future_traj(1 + (16 * 3)) = *(varsYaw.x_17 + 1);
  future_traj(2 + (16 * 3)) = *(varsYaw.x_17 + 2);
  future_traj(0 + (17 * 3)) = *(varsYaw.x_18);
  future_traj(1 + (17 * 3)) = *(varsYaw.x_18 + 1);
  future_traj(2 + (17 * 3)) = *(varsYaw.x_18 + 2);
  future_traj(0 + (18 * 3)) = *(varsYaw.x_19);
  future_traj(1 + (18 * 3)) = *(varsYaw.x_19 + 1);
  future_traj(2 + (18 * 3)) = *(varsYaw.x_19 + 2);
  future_traj(0 + (19 * 3)) = *(varsYaw.x_20);
  future_traj(1 + (19 * 3)) = *(varsYaw.x_20 + 1);
  future_traj(2 + (19 * 3)) = *(varsYaw.x_20 + 2);
  future_traj(0 + (20 * 3)) = *(varsYaw.x_21);
  future_traj(1 + (20 * 3)) = *(varsYaw.x_21 + 1);
  future_traj(2 + (20 * 3)) = *(varsYaw.x_21 + 2);
  future_traj(0 + (21 * 3)) = *(varsYaw.x_22);
  future_traj(1 + (21 * 3)) = *(varsYaw.x_22 + 1);
  future_traj(2 + (21 * 3)) = *(varsYaw.x_22 + 2);
  future_traj(0 + (22 * 3)) = *(varsYaw.x_23);
  future_traj(1 + (22 * 3)) = *(varsYaw.x_23 + 1);
  future_traj(2 + (22 * 3)) = *(varsYaw.x_23 + 2);
  future_traj(0 + (23 * 3)) = *(varsYaw.x_24);
  future_traj(1 + (23 * 3)) = *(varsYaw.x_24 + 1);
  future_traj(2 + (23 * 3)) = *(varsYaw.x_24 + 2);
  future_traj(0 + (24 * 3)) = *(varsYaw.x_25);
  future_traj(1 + (24 * 3)) = *(varsYaw.x_25 + 1);
  future_traj(2 + (24 * 3)) = *(varsYaw.x_25 + 2);
  future_traj(0 + (25 * 3)) = *(varsYaw.x_26);
  future_traj(1 + (25 * 3)) = *(varsYaw.x_26 + 1);
  future_traj(2 + (25 * 3)) = *(varsYaw.x_26 + 2);
  future_traj(0 + (26 * 3)) = *(varsYaw.x_27);
  future_traj(1 + (26 * 3)) = *(varsYaw.x_27 + 1);
  future_traj(2 + (26 * 3)) = *(varsYaw.x_27 + 2);
  future_traj(0 + (27 * 3)) = *(varsYaw.x_28);
  future_traj(1 + (27 * 3)) = *(varsYaw.x_28 + 1);
  future_traj(2 + (27 * 3)) = *(varsYaw.x_28 + 2);
  future_traj(0 + (28 * 3)) = *(varsYaw.x_29);
  future_traj(1 + (28 * 3)) = *(varsYaw.x_29 + 1);
  future_traj(2 + (28 * 3)) = *(varsYaw.x_29 + 2);
  future_traj(0 + (29 * 3)) = *(varsYaw.x_30);
  future_traj(1 + (29 * 3)) = *(varsYaw.x_30 + 1);
  future_traj(2 + (29 * 3)) = *(varsYaw.x_30 + 2);
  future_traj(0 + (30 * 3)) = *(varsYaw.x_31);
  future_traj(1 + (30 * 3)) = *(varsYaw.x_31 + 1);
  future_traj(2 + (30 * 3)) = *(varsYaw.x_31 + 2);
  future_traj(0 + (31 * 3)) = *(varsYaw.x_32);
  future_traj(1 + (31 * 3)) = *(varsYaw.x_32 + 1);
  future_traj(2 + (31 * 3)) = *(varsYaw.x_32 + 2);
  future_traj(0 + (32 * 3)) = *(varsYaw.x_33);
  future_traj(1 + (32 * 3)) = *(varsYaw.x_33 + 1);
  future_traj(2 + (32 * 3)) = *(varsYaw.x_33 + 2);
  future_traj(0 + (33 * 3)) = *(varsYaw.x_34);
  future_traj(1 + (33 * 3)) = *(varsYaw.x_34 + 1);
  future_traj(2 + (33 * 3)) = *(varsYaw.x_34 + 2);
  future_traj(0 + (34 * 3)) = *(varsYaw.x_35);
  future_traj(1 + (34 * 3)) = *(varsYaw.x_35 + 1);
  future_traj(2 + (34 * 3)) = *(varsYaw.x_35 + 2);
  future_traj(0 + (35 * 3)) = *(varsYaw.x_36);
  future_traj(1 + (35 * 3)) = *(varsYaw.x_36 + 1);
  future_traj(2 + (35 * 3)) = *(varsYaw.x_36 + 2);
  future_traj(0 + (36 * 3)) = *(varsYaw.x_37);
  future_traj(1 + (36 * 3)) = *(varsYaw.x_37 + 1);
  future_traj(2 + (36 * 3)) = *(varsYaw.x_37 + 2);
  future_traj(0 + (37 * 3)) = *(varsYaw.x_38);
  future_traj(1 + (37 * 3)) = *(varsYaw.x_38 + 1);
  future_traj(2 + (37 * 3)) = *(varsYaw.x_38 + 2);
  future_traj(0 + (38 * 3)) = *(varsYaw.x_39);
  future_traj(1 + (38 * 3)) = *(varsYaw.x_39 + 1);
  future_traj(2 + (38 * 3)) = *(varsYaw.x_39 + 2);
  future_traj(0 + (39 * 3)) = *(varsYaw.x_40);
  future_traj(1 + (39 * 3)) = *(varsYaw.x_40 + 1);
  future_traj(2 + (39 * 3)) = *(varsYaw.x_40 + 2);
}
double CvxWrapperYaw::getFirstControlInput() {
  return *(varsYaw.u_0);
}
