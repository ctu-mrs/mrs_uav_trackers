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

/* dim is used to offset the result in the output vecor, according to which dimension (x,y,z) is being calculated */
/* x - 0 */
/* y - 1 */
/* z - 2 */
/* yaw - 0 */

CvxWrapper::CvxWrapper(bool verbose, int max_iters, std::vector<double> tempQ, std::vector<double> tempR, double dt, double dt2, int dimension) {

  set_defaults();
  setup_indexing();
  setup_indexed_params();
  dim = dimension * 3;
  if (dim > 6 || dim < 0) {
    ROS_ERROR("CvxWrapper - parameter dim should be 0, 1 or 2 !!! setting to 0");
    dim = 0;
  }

  if ((verbose != 1 && verbose != 0) || !std::isfinite(verbose)) {
    ROS_ERROR("CvxWrapper - verbose has to be 0 or 1!!! Safe value of 0 set instead");
    verbose = 0;
  }
  settings.verbose = verbose;

  if ((max_iters < 1 || max_iters > 100) || !std::isfinite(max_iters)) {
    ROS_ERROR("CvxWrapper - max_iters wrong value!!! Safe value of 20 set instead");
    max_iters = 20;
  }
  settings.max_iters = max_iters;

  if (tempQ.size() == 3) {
    for (int i = 0; i < 3; i++) {
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
    params.Q[2] = 0;
  }

  if (tempR.size() == 1) {
    for (int i = 0; i < 1; i++) {
      if (tempR[i] >= 0 && std::isfinite(tempR[i])) {
        params.R[i]  = tempR[i];
        params.R2[i] = tempR[i] / 20;
      } else {
        ROS_ERROR_STREAM("CvxWrapper - R matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        params.R[i]  = 500;
        params.R2[i] = 500 / 20;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper - R matrix wrong size " << tempR.size() << " !!! Safe values set instead");
    params.R[0]  = 500;
    params.R2[0] = 500 / 20;
  }

  if (dt <= 0 || !std::isfinite(dt)) {
    ROS_ERROR_STREAM("CvxWrapper - dt parameter wrong " << dt << " !!! Safe value of 0.01 set instead");
    dt = 0.01;
  }

  if (dt2 <= 0 || !std::isfinite(dt2)) {
    ROS_ERROR_STREAM("CvxWrapper - dt2 parameter wrong " << dt2 << " !!! Safe value of 0.2 set instead");
    dt2 = 0.2;
  }

  params.A[0] = 1;
  params.A[1] = 1;
  params.A[2] = 1;
  params.A[3] = dt2;
  params.A[4] = dt2;
  params.A[5] = 0.5 * dt2 * dt2;

  params.B[0] = dt2;

  params.Af[0] = 1;
  params.Af[1] = 1;
  params.Af[2] = 1;
  params.Af[3] = dt;
  params.Af[4] = dt;
  params.Af[5] = 0.5 * dt * dt;

  params.Bf[0] = dt;

  ROS_INFO("Cvx wrapper initiated");
}
void CvxWrapper::setLimits(double max_speed, double min_speed, double max_acc, double min_acc, double max_jerk, double min_jerk) {
  params.x_max_2[0] = max_speed;
  params.x_min_2[0] = min_speed;
  params.x_max_3[0] = max_acc;
  params.x_min_3[0] = min_acc;
  params.u_max[0]   = max_jerk;
  params.u_min[0]   = min_jerk;
}

void CvxWrapper::setInitialState(MatrixXd& x) {
  params.x_0[0] = x(0, 0);
  params.x_0[1] = x(1, 0);
  params.x_0[2] = x(2, 0);
}
void CvxWrapper::loadReference(MatrixXd& reference) {
  for (int i = 0; i < horizon_len; i++) {
    *params.x_ss[i + 1] = reference(i, 0);
  }
}
int CvxWrapper::solveCvx() {
  return solve();
}
void CvxWrapper::getStates(MatrixXd& future_traj) {

  /* ROS_INFO_STREAM("[cvxgen]: " << *(vars.x_20) << " " << *(vars.x_30) << " " << *(vars.x_37) << " " << *(vars.x_38) << " " << *(vars.x_39) << " "); */
  /* ROS_INFO_STREAM("[cvxgen]:par " << params.x_ss_20[0] << " " << params.x_ss_30[0] << " " << params.x_ss_38[0] << " " << params.x_ss_39[0] << " " */
  /*                                 << params.x_ss_40[0] << " "); */

  for (int i = 0; i < horizon_len; i++) {
    future_traj(0 + dim + (i * 9)) = *(vars.x[i + 1]);
    future_traj(1 + dim + (i * 9)) = *(vars.x[i + 1] + 1);
    future_traj(2 + dim + (i * 9)) = *(vars.x[i + 1] + 2);
  }
}
double CvxWrapper::getFirstControlInput() {
  return *(vars.u_0);
}
