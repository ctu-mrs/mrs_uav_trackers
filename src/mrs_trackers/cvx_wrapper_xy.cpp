/* author: Daniel Hert */
extern "C" {
#include "cvxgen_xy/solver.h"
}
#include "cvx_wrapper_xy.h"

Vars      vars;
Params    params;
Workspace work;
Settings  settings;

CvxWrapperXY::CvxWrapperXY() {
  ROS_INFO("Cvx wrapper XY initiated");
  Params params;
  params.x_aprx_max_1[0] = 0.01;
  ROS_INFO("Cvx wrapperXY params set");
}
