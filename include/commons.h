#ifndef COMMONS_H
#define COMMONS_H

#define PI 3.141592653

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

#endif
