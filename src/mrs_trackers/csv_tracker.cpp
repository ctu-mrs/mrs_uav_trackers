#include <ros/ros.h>
#include <trackers_manager/Tracker.h>
#include <quadrotor_msgs/TrackerStatus.h>
#include <std_srvs/Trigger.h>
#include <tf/transform_datatypes.h>
#include <eigen3/Eigen/Eigen>
#include <nav_msgs/Odometry.h>
#include <thread>
#include <mutex>
#include <cmath>
#include <math.h>
#include <std_srvs/SetBool.h>
#include <iostream>
#include <fstream>
#include <mav_manager/Vec4.h>
#include <trackers_manager/Transition.h>
#include "tf/LinearMath/Transform.h"
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <gazebo_ros_link_attacher/Attach.h>

using namespace Eigen;

class CsvTracker : public trackers_manager::Tracker {
  public:

    CsvTracker(void);

    void Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh);
    bool Activate(const quadrotor_msgs::PositionCommand::ConstPtr &cmd);
    void Deactivate(void);

    const quadrotor_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
    const quadrotor_msgs::TrackerStatus::Ptr status();

    bool start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

    void odometryCallback(const nav_msgs::OdometryConstPtr &msg);

  private:

    ros::NodeHandle nh_;

    nav_msgs::Odometry odom;
    ros::Time odomLastTime;

    std::thread main_thread;

    quadrotor_msgs::PositionCommand position_cmd;
    quadrotor_msgs::PositionCommand last_position_cmd;

    std::mutex mutex_position_cmd, mutex_odom;

    // subscriber
    ros::Subscriber subscriber_odom;

    // service servers
    ros::ServiceServer service_start;

    // service clients
    ros::ServiceClient service_switch_tracker;
    ros::ServiceClient service_goto;
    ros::ServiceClient service_drop;

    // publishers
    ros::Publisher publisher_odom_pitch_;
    ros::Publisher publisher_desired_pitch_;
    ros::Publisher publisher_desired_zd_;
    ros::Publisher publisher_desired_xd_;

    ros::Publisher pub_weight;
    
    ros::Publisher publisher_desired_thrust_;

    std::thread mpc_thread;

    bool odom_set = false;
    bool active = false;
    bool got_odom = false;

    // for tracking
    bool tracking = false;
    int tracking_idx = 0;
    MatrixXd trajectory;
    int trajectory_len = 0;

    // for debugging
    double last_odom_pitch = 0;

    // params
    std::string filename_;

    // methods
    void mainThread(void);
};

CsvTracker::CsvTracker(void) :
  odom_set(false),
  active(false)
{
}

bool CsvTracker::start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

}

double dist(double ax, double ay, double az, double bx, double by, double bz) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2) + pow(az - bz, 2));
}

// called once at the very beginning
void CsvTracker::Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh) {
  ros::NodeHandle priv_nh(nh, "csv_tracker");

  nh.param("filename", filename_, std::string());

  if (filename_.empty()) {
    ROS_ERROR("The file name has not been filled!"); 
    ros::shutdown();
    return;
  }

  // posX posY vx vy ax ay theta thrust release
  trajectory = MatrixXd::Zero(5000, 9);

  std::ifstream in(filename_.c_str(), std::ifstream::in);

  if (!in) {

    ROS_ERROR("Cannot open %s", filename_.c_str());
    ros::shutdown();
    return;

  } else {

    ROS_INFO("Loading from file: %s", filename_.c_str());
    std::string line;

    while (getline(in, line)) {

      std::istringstream s(line);

      s >> trajectory(trajectory_len, 0);
      s >> trajectory(trajectory_len, 1);
      s >> trajectory(trajectory_len, 2);
      s >> trajectory(trajectory_len, 3);
      s >> trajectory(trajectory_len, 4);
      s >> trajectory(trajectory_len, 5);
      s >> trajectory(trajectory_len, 6);
      s >> trajectory(trajectory_len, 7);
      s >> trajectory(trajectory_len, 8);

      ROS_INFO("%2.2f %2.2f", trajectory(trajectory_len, 0), trajectory(trajectory_len, 1));

      trajectory_len++;
    }

    in.close();

    ROS_INFO("Trajectory loaded, len = %d", trajectory_len);
  }

  service_goto = priv_nh.serviceClient<mav_manager::Vec4>("goto_out");
  service_switch_tracker = priv_nh.serviceClient<trackers_manager::Transition>("transition_out");
  service_switch_tracker = priv_nh.serviceClient<trackers_manager::Transition>("transition_out");

  service_drop = priv_nh.serviceClient<gazebo_ros_link_attacher::Attach>("drop");
  pub_weight = priv_nh.advertise<std_msgs::Float32>("set_mass", 1);

  subscriber_odom = priv_nh.subscribe("/uav1/mrs_odometry/new_odom", 1, &CsvTracker::odometryCallback, this, ros::TransportHints().tcpNoDelay());
  
  publisher_odom_pitch_ = priv_nh.advertise<std_msgs::Float64>("odom_pitch", 1, false);
  publisher_desired_pitch_ = priv_nh.advertise<std_msgs::Float64>("desired_pitch", 1, false);
  publisher_desired_zd_ = priv_nh.advertise<std_msgs::Float64>("desired_zd", 1, false);
  publisher_desired_xd_ = priv_nh.advertise<std_msgs::Float64>("desired_xd", 1, false);

  publisher_desired_thrust_ = priv_nh.advertise<std_msgs::Float64>("desired_thrust", 1, false);

  main_thread = std::thread(&CsvTracker::mainThread, this);
}

void CsvTracker::odometryCallback(const nav_msgs::OdometryConstPtr &msg) {

  got_odom = true;

  // tady tim to neni
  mutex_odom.lock();
  {
    odom = *msg;
  }
  mutex_odom.unlock();
}

bool CsvTracker::Activate(const quadrotor_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odom) {

    ROS_ERROR("Cannot activate CSV tracker, dont have odometry");
    return false;
  }

  last_position_cmd = *cmd;

  tracking_idx = 0;

  position_cmd = *cmd;

  // if we are too far from the initial point
  double distance = dist(odom.pose.pose.position.x, odom.pose.pose.position.y, odom.pose.pose.position.z, trajectory(0, 0), odom.pose.pose.position.y, trajectory(0, 1));

  ROS_INFO("Distance: %2.2f", distance);

  if (distance > 100.0) {

    /* mav_manager::Vec4 goto_ser; */
    /* goto_ser.request.goal[0] = trajectory(0, 0); */
    /* goto_ser.request.goal[1] = odom.pose.pose.position.y; */
    /* goto_ser.request.goal[2] = trajectory(0, 1); */
    /* goto_ser.request.goal[3] = last_position_cmd.yaw; */

    /* service_goto.call(goto_ser); */

    /* ROS_INFO("Called goto on MPC tracker, active me again when we are there"); */

    ROS_ERROR("Cannon activate, to far from the initial point!");

    active = false;

  } else {

    ROS_INFO("CSV tracker activated");
    active = true;
    tracking = true;
  }

  return active;
}

void CsvTracker::Deactivate(void) {

  active = false;
  odom_set = false;

  ROS_INFO("CSV tracker deactivated");
}

// if the tracker is active, this mehod is called on every odometry update, even if the tracker is not active
const quadrotor_msgs::PositionCommand::ConstPtr CsvTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // very important, return null pointer when the tracker is not active, but we can still do some stuff
  if(!active)
    return quadrotor_msgs::PositionCommand::Ptr();

  // calculate the current angle
  double odom_roll, odom_pitch, odom_yaw;
  geometry_msgs::Quaternion odom_quat = msg->pose.pose.orientation;
  tf::Quaternion qt(odom_quat.x, odom_quat.y, odom_quat.z, odom_quat.w);
  tf::Matrix3x3(qt).getRPY(odom_roll, odom_pitch, odom_yaw);

  last_odom_pitch = odom_pitch;

  quadrotor_msgs::PositionCommand::ConstPtr out;

  mutex_position_cmd.lock();
  {
    out = quadrotor_msgs::PositionCommand::ConstPtr(new quadrotor_msgs::PositionCommand(position_cmd));
  }
  mutex_position_cmd.unlock();

  return out;
}

void CsvTracker::mainThread(void) {

  ROS_INFO("Main thread has started");

  ros::Rate r(100);

  int released = 0;

  while (ros::ok()) {

    while (!active && ros::ok()) {r.sleep();}

    ROS_INFO_THROTTLE(1, "Thread is spinning, idx=%d", tracking_idx);

    mutex_position_cmd.lock();
    {
      // set the message according to the file
      position_cmd.header.stamp = ros::Time::now();
      position_cmd.header.frame_id = "local_origin";
      
      position_cmd.position.x = trajectory(tracking_idx, 0);
      position_cmd.position.z = trajectory(tracking_idx, 1);

      position_cmd.velocity.x = trajectory(tracking_idx, 2);
      position_cmd.velocity.z = trajectory(tracking_idx, 3);

      position_cmd.acceleration.x = trajectory(tracking_idx, 4);
      position_cmd.acceleration.z = trajectory(tracking_idx, 5);

      position_cmd.position.y = 0;
      position_cmd.velocity.y = 0;
      position_cmd.acceleration.y = 0;
      
      position_cmd.yaw = last_position_cmd.yaw;
      position_cmd.yaw_dot = 0;
    }
    mutex_position_cmd.unlock();

    // debugging current pitch
    std_msgs::Float64 odom_pitch_msg;
    odom_pitch_msg.data = last_odom_pitch;

    // debugging desired pitch
    std_msgs::Float64 desired_pitch_msg;
    desired_pitch_msg.data = -trajectory(tracking_idx, 6);

    // debugging desired zd
    std_msgs::Float64 desired_zd_msg;
    desired_zd_msg.data = trajectory(tracking_idx, 3);

    // debugging desired xd
    std_msgs::Float64 desired_xd_msg;
    desired_xd_msg.data = trajectory(tracking_idx, 2);

    publisher_odom_pitch_.publish(odom_pitch_msg);
    publisher_desired_pitch_.publish(desired_pitch_msg);
    publisher_desired_zd_.publish(desired_zd_msg);
    publisher_desired_xd_.publish(desired_xd_msg);

    if (trajectory(tracking_idx, 8) == 1) {

      ROS_ERROR("RELEASING MASS");

      gazebo_ros_link_attacher::Attach drop_ser; 

      drop_ser.request.model_name_1 = "uav1";
      drop_ser.request.model_name_2 = "object1";
      drop_ser.request.link_name_1 = "base_link";
      drop_ser.request.link_name_2 = "link";

      service_drop.call(drop_ser);

      std_msgs::Float32 msg;
      msg.data = 2.5;
      pub_weight.publish(msg);

    }

    // debugging desired thrust
    std_msgs::Float64 desired_thrust_msg;
    desired_thrust_msg.data = trajectory(tracking_idx, 7)/34.3233;

    publisher_desired_thrust_.publish(desired_thrust_msg);

    if (tracking_idx < (trajectory_len-1)) {

      tracking_idx = tracking_idx + 1;

    } else {

      ROS_INFO_THROTTLE(1, "Trajectory has finished, replaying the last poing...");

    }

    r.sleep();
  }
}

const quadrotor_msgs::TrackerStatus::Ptr CsvTracker::status() {

  if(!active)
    return quadrotor_msgs::TrackerStatus::Ptr();

  quadrotor_msgs::TrackerStatus::Ptr msg(new quadrotor_msgs::TrackerStatus);
  msg->status = quadrotor_msgs::TrackerStatus::SUCCEEDED;
  return msg;
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(CsvTracker, trackers_manager::Tracker)
