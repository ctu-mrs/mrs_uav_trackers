ros2 service call /uav1/control_manager/switch_tracker mrs_msgs/srv/String '{"value": "FlipTracker"}' 

echo "flippin"

ros2 service call /uav1/control_manager/flip_tracker/flip std_srvs/srv/Trigger '{}' 
