#ifndef CVX_WRAPPERYAW
#define CVX_WRAPPERYAW

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapperYaw {

public:
  CvxWrapperYaw(bool verbose, int max_iters, std::vector<double> tempR, std::vector<double> tempQ, double dt, double dt2);

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(double speed_max, double acc_max);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
private:
};

#endif
