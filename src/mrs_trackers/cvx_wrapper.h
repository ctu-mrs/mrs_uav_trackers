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
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInputX();
  double getFirstControlInputY();
private:
};

#endif
