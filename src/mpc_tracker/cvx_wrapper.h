#ifndef CVX_WRAPPER
#define CVX_WRAPPER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapper {

public:
  CvxWrapper(bool verbose, int max_iters, std::vector<double> tempR, std::vector<double> tempQ, double dt, double dt2, int dim);

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(double max_speed, double min_speed, double max_acc, double min_acc, double max_jerk, double min_jerk);
  int  solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
  int    dim;

private:
};

#endif
