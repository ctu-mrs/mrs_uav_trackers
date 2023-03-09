#ifndef MPC_TRACKER_SOLVER
#define MPC_TRACKER_SOLVER

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>

namespace mrs_mpc_solvers
{

namespace mpc_tracker
{

class Solver {

public:
  Solver(std::string name, bool verbose, int max_iters, std::vector<double> tempQ, double dt, double dt2, int dim);

  void   setInitialState(Eigen::MatrixXd &x);
  bool   setVelQ(double Q_vel);
  bool   setQ(std::vector<double> Qnew);
  void   loadReference(Eigen::MatrixXd &reference);
  void   setLimits(double max_speed, double min_speed, double max_acc, double min_acc, double max_jerk, double min_jerk, double max_snap, double min_snap);
  int    solveMPC();
  void   getStates(Eigen::MatrixXd &future_traj);
  double getFirstControlInput();
  void   setDt(const double &dt);

private:
  static const int _horizon_len_ = 40;
  int              _dim_;
  std::string      _name_;

  std::vector<double> myQ_;
};

}  // namespace mpc_tracker

}  // namespace mrs_mpc_solvers

#endif
