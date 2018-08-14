#ifndef COMMONS_H
#define COMMONS_H

#include <ros/ros.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653

namespace mrs_trackers_commons
{

double validateYawSetpoint(const double yaw_in) {

  double yaw_out = yaw_in;

  if (!std::isfinite(yaw_out)) {

    yaw_out = 0;
    ROS_ERROR("[validateYawSetpoint]: Desired YAW is not finite number!");
  }

  if (fabs(yaw_out) > 1000) {

    ROS_WARN("[validateYawSetpoint]: Desired YAW is > 1000");
  }
  // if desired yaw_out is grater then 2*PI mod it
  if (fabs(yaw_out) > 2 * PI) {
    yaw_out = fmod(yaw_out, 2 * PI);
  }

  // move it to its place
  if (yaw_out > PI) {
    yaw_out -= 2 * PI;
  } else if (yaw_out < -PI) {
    yaw_out += 2 * PI;
  }

  return yaw_out;
}

double sign(const double in) {

  return (in > 0) ? 1.0 : -1.0;
}

double dist2(const double x1, const double x2, const double y1, const double y2) {

  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double dist3(const double x1, const double x2, const double y1, const double y2, const double z1, const double z2) {

  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

double size3(const double x, const double y, const double z) {

  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
}

#endif
