#ifndef CVX_WRAPPER_TRACKER
#define CVX_WRAPPER_TRACKER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

namespace mrs_trackers
{

namespace cvx_wrapper
{

/* author: Daniel Hert */

class CvxWrapper {

public:
  CvxWrapper(bool verbose, int max_iters, std::vector<double> tempQ, double dt, double dt2, int dim);

  void   setInitialState(Eigen::MatrixXd &x);
  bool   setVelQ(double Q_vel);
  bool   setQ(std::vector<double> Qnew);
  void   loadReference(Eigen::MatrixXd &reference);
  void   setLimits(double max_speed, double min_speed, double max_acc, double min_acc, double max_jerk, double min_jerk, double max_snap, double min_snap);
  int    solveCvx();
  void   getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();

private:
  static const int    horizon_len = 40;
  std::vector<double> myQ;
  int                 dim;
};

}  // namespace cvx_wrapper

}  // namespace mrs_trackers

#endif
