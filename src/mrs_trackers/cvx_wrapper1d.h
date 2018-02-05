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
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
private:
};

#endif
