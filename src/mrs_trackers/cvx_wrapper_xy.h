#ifndef CVX_WRAPPER_XY
#define CVX_WRAPPER_XY

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapperXY {

public:
  CvxWrapperXY();

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInputX();
  double getFirstControlInputY();
private:
};

#endif
