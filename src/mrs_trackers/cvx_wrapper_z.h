#ifndef CVX_WRAPPERZ
#define CVX_WRAPPERZ

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

/* author: Daniel Hert */

class CvxWrapperZ {

public:
  CvxWrapperZ(bool verbose, int max_iters, std::vector<double> tempR, std::vector<double> tempQ, double dt, double dt2, double asc_jerk, double des_jerk);

  void setInitialState(Eigen::MatrixXd &x);
  void loadReference(Eigen::MatrixXd &reference);
  void setLimits(double speed_max, double speed_min, double acc_max, double acc_min);
  int solveCvx();
  void getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
private:
};

#endif
