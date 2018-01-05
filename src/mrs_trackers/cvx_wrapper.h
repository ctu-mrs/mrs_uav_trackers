#ifndef CVX_WRAPPER
#define CVX_WRAPPER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapper {

public:
  CvxWrapper();

  void setInitialState(Eigen::MatrixXd &x, int k);
  void loadReference(Eigen::MatrixXd &reference, int k);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj, int k);
  double getFirstControlInput();
private:
};

#endif
