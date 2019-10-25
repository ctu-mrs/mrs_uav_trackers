^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package mrs_trackers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Forthcoming
-----------
* fixed disabling lateral gains in landoff
* updated mpc tracker circle saturation for trajectories
* updated collision avoidance diagnostics
* updated default wiggle parameters
* removed odometry reset from landoff tracker
* added other uav avoidance trajectories to diagnostics
* change uav_names loadint to mrs_general/uav_names.yml
* fixed the takeoff tracker switching bug
* added more hovering callback checks
* added hovering check for mpc tracker
* fixed disabled callbacks
* improved mpc_tracker diagnostics
* minor change in tracker status
* fixed hover trigger message
* fixed mutex deadlock bug in hover timer
* fixed hover timer
* + t650 and f450 configs
* MpcTracker code commenting and prints
* fixed the motion saturation during takeff in landoff_tracker
* updated configs for new "hierarchy" config system
* reworking launch files
* no_overshoots for MpcTracker
* mpc's status involves whether hovering is in progress
* updated getStatus()
* added landoff diagnostics, updated horizontal hover state transition
* generalized takeoff for non-zero initial z
* made JoyBumperTracker routines work only when it is active
* fixed bug with stopping trajectory following
* fixed wiggle service client
* added wiggle to mpc tracker
* added "is_active" checks to trajectory service callbacks
* fixed use_yaw during flying to trajectory start
* added avoidance status to diagnostics
* fixed tracking flag in diagnostics after initial hover
* added tilt mode to MatlabTracker
* joystic channels moved to config file
* moved cvx wrapper outside of mpc tracker
* Restore original joy tracker
* Add new joy bumper tracker
* added missing trackers to install in cmakelists
* fixed bugs in odom switch
* updated the mpc odometry switch to proper rotation
* fixed volocity rotation in mpc tracker
* update velocity transition in mpc tracker
* update odometry switch in mpc tracker
* Add repulsion distances as parameters in config file
* Add computation of regulation error and its difference
* Add implementation of bumper for vertical direction
* Add subscriber and callback for bumper
* Add params for joystick channels setting
* Add template for joy bumper tracker
* updated channel numbers from the logitech joystic
* Contributors: Andriy, Dan Hert, Tomas Baca, UAV41, UAV_44, Vit Kratky, Vojtech Spurny, afzal, uav42, uav61

0.0.2 (2019-07-01)
------------------
* added avoidance rinfo
* fixed collision avoidance for RTK
* allowed activating eland in low height, unified initial conditions for
  landoff tracker
* disabled odomeotry reset during takeoff
* fixed csv trackers deactivation deadlock
* increased elanding speed for naki
* collision avoidance triggers only in GPS odometry mode
* Contributors: NAKI, Tomas Baca, Tomáš Báča, uav3, uav4, uav5

0.0.1 (2019-05-20)
------------------
