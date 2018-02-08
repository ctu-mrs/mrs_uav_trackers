#ifndef CVX_WRAPPER
#define CVX_WRAPPER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapper {

public:
  CvxWrapper();

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(double max_speed, double max_acc);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInputX();
  double getFirstControlInputY();
private:
};

#endif
