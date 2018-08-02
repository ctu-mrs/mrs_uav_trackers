#ifndef CVX_WRAPPERXY
#define CVX_WRAPPERXY

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapperXY {

public:
  CvxWrapperXY(bool verbose, int max_iters, std::vector<double> tempR, std::vector<double> tempQ, double dt, double dt2, double hjerk);

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
