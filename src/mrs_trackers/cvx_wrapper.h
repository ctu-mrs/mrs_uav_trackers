#ifndef CVX_WRAPPER
#define CVX_WRAPPER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapper {

public:
  CvxWrapper(bool verbose, int max_iters, std::vector<double> tempR, std::vector<double> tempQ, double dt, double dt2);

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(Eigen::VectorXd &max_speed, Eigen::VectorXd &max_acc);
  int  solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInputX();
  double getFirstControlInputY();

private:
};

#endif
