/* author: Daniel Hert */

#include <eigen3/Eigen/Eigen>
#include <mrs_uav_trackers/cvx_wrapper.h>

using namespace Eigen;

namespace mrs_uav_trackers
{

namespace cvx_wrapper
{

extern "C" {
#include "cvxgen/solver.h"
}

Vars      vars;
Params    params;
Workspace work;
Settings  settings;

/* CvxWrapper() //{ */

/* dim is used to offset the result in the output vecor, according to which dimension (x,y,z) is being calculated */
/* x - 0 */
/* y - 1 */
/* z - 2 */
/* yaw - 0 */

CvxWrapper::CvxWrapper(bool verbose, int max_iters, std::vector<double> tempQ, double dt, double dt2, int dimension) {

  myQ = std::vector<double>(4);
  set_defaults();
  setup_indexing();
  setup_indexed_params();
  dim = dimension * 4;
  if (dim > 8 || dim < 0) {
    ROS_ERROR("CvxWrapper - parameter dim should be 0, 1 or 2 !!! setting to 0");
    dim = 0;
  }

  if (verbose) {
    settings.verbose = 1;
  } else {
    settings.verbose = 0;
  }

  if ((max_iters < 1 || max_iters > 100) || !std::isfinite(max_iters)) {
    ROS_ERROR("CvxWrapper - max_iters wrong value!!! Safe value of 20 set instead");
    max_iters = 20;
  }
  settings.max_iters = max_iters;

  if (tempQ.size() == 4) {
    for (int i = 0; i < 4; i++) {
      if (tempQ[i] >= 0 && std::isfinite(tempQ[i])) {
        myQ[i] = tempQ[i];
      } else {
        ROS_ERROR_STREAM("CvxWrapper - Q matrix has to be PSD - parameter " << i << " !!! Safe value of 500 set instead");
        myQ[i] = 500;
      }
    }
  } else {
    ROS_ERROR_STREAM("CvxWrapper - Q matrix wrong size " << tempQ.size() << " !!! Safe values set instead");
    myQ[0] = 5000;
    myQ[1] = 0;
    myQ[2] = 0;
    myQ[3] = 0;
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
  params.A[3] = 1;
  params.A[4] = dt2;
  params.A[5] = dt2;
  params.A[6] = dt2;
  params.A[7] = 0.5 * dt2 * dt2;
  params.A[8] = 0.5 * dt2 * dt2;

  params.B[0] = dt2;

  params.Af[0] = 1;
  params.Af[1] = 1;
  params.Af[2] = 1;
  params.Af[3] = 1;
  params.Af[4] = dt;
  params.Af[5] = dt;
  params.Af[6] = dt;
  params.Af[7] = 0.5 * dt * dt;
  params.Af[8] = 0.5 * dt * dt;

  params.Bf[0] = dt;

  ROS_INFO("Cvx wrapper initiated");
}

//}

/* setLimits() //{ */

void CvxWrapper::setLimits(double max_speed, double min_speed, double max_acc, double min_acc, double max_jerk, double min_jerk, double max_snap,
                           double min_snap) {
  params.x_max_2[0] = max_speed;
  params.x_min_2[0] = min_speed;
  params.x_max_3[0] = max_acc;
  params.x_min_3[0] = min_acc;
  params.x_max_4[0] = max_jerk;
  params.x_min_4[0] = min_jerk;
  params.u_max[0]   = max_snap;
  params.u_min[0]   = min_snap;
}

//}

/* setInitialState() //{ */

void CvxWrapper::setInitialState(MatrixXd& x) {
  params.x_0[0] = x(0, 0);
  params.x_0[1] = x(1, 0);
  params.x_0[2] = x(2, 0);
  params.x_0[3] = x(3, 0);
}

//}

/* setVelQ() //{ */

bool CvxWrapper::setVelQ(double Q_vel) {
  if (Q_vel < 0.0) {
    ROS_ERROR_STREAM("[MpcTracker]: CvxWrapper - Q vel has to be positive!! Q_vel" << Q_vel << " !!!");
    return false;
  } else {
    myQ[1] = Q_vel;
    return true;
  }
}

//}

/* setQ() //{ */

bool CvxWrapper::setQ(std::vector<double> Qnew) {
  bool result = true;
  if (Qnew.size() == 4) {
    for (int i = 0; i < 4; i++) {
      if (Qnew[i] >= 0 && std::isfinite(Qnew[i])) {
        myQ[i] = Qnew[i];
      } else {
        ROS_ERROR_STREAM("[MpcTracker]: CvxWrapper - Q matrix has to be PSD - parameter " << i << " !!!");
        result = false;
      }
    }
  } else {
    ROS_ERROR("[MpcTracker]: CvxWrapper - wrong dimension received when setting Q");
    result = false;
  }
  if (result) {
    ROS_INFO("[MpcTracker]: CvxWrapper - successfully set matrix Q");
  }
  return result;
}

//}

/* loadReference() //{ */

void CvxWrapper::loadReference(MatrixXd& reference) {
  for (int i = 0; i < horizon_len; i++) {
    *params.x_ss[i + 1] = reference(i, 0);
  }
}

//}

/* solveCvx //{ */

int CvxWrapper::solveCvx() {
  for (int i = 0; i < 4; i++) {
    params.Q[i] = myQ[i];
  }
  return solve();
}

//}

/* getStates() //{ */

void CvxWrapper::getStates(MatrixXd& future_traj) {
  for (int i = 0; i < horizon_len; i++) {
    future_traj(0 + dim + (i * 12)) = *(vars.x[i + 1]);
    future_traj(1 + dim + (i * 12)) = *(vars.x[i + 1] + 1);
    future_traj(2 + dim + (i * 12)) = *(vars.x[i + 1] + 2);
    future_traj(3 + dim + (i * 12)) = *(vars.x[i + 1] + 3);
  }
}

//}

/* getFirstControlInput() //{ */

double CvxWrapper::getFirstControlInput() {
  return *(vars.u_0);
}

//}

}  // namespace cvx_wrapper

}  // namespace mrs_uav_trackers
