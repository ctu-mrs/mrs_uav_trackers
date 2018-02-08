#ifndef CVX_WRAPPER1D
#define CVX_WRAPPER1D

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapper1d {

public:
  CvxWrapper1d();

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(double speed_max, double speed_min, double acc_max, double acc_min);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
private:
};

#endif
