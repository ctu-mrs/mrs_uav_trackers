^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package mrs_uav_trackers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1.0.4 (2023-01-20)
------------------
* updated readme, updated ci
* fixed collision avoidance flags
* Contributors: Dan Hert, Tomas Baca

1.0.3 (2022-05-09)
------------------
* refactored against publisher handler
* fixed avoidance descend for slower mpc rate
* refactored agains the new transformer
* + install in cmakelists
* add configs: simulation/naki
* add ScopeTimer and its logger to all trackers
* Contributors: Pavel Petracek, Tomas Baca

1.0.2 (2021-10-04)
------------------
* added trajectory input id
* removed broken hover timer run check
* fixed race cond. stuck bug in landing
* landoff: added velocity nullifier when stopping and hovering
* fixed wiggle
* removed the in-the-air check for landing
* added brus configs
* added midair activation
* added brus simulation configs
* added destructor implementation to trackers
* adding -id to diag message
* added dofec uav config
* updated mrs_status info from mpc_tracker
* updated debug prints
* MpcTracker: updated fullstate prediction
* added t18 configs
* added check for heading update (commented)
* braking and reference filtering not applied when traj. tracking
* updated debug prints, fixed deadlock
* MpcTracker: update debug prints
* added debugging prints for state update
* Contributors: Dan Hert, Tomas Baca

1.0.1 (2021-05-16)
------------------
* version -> 1.0.1
* MpcTracker: updated prints
* updated ros::shutdown
* linted the trackers, minor bug fixes
* removed the CsvTracker
* fixed looping with super-short trajectories
* MpcTracker: added debugging rinfo for looping
* MpcTracker: returning null when outputs are not finite
* added velocity reference, MpcTracker can do velocity cmd now
* reworking initial acceleration
* fixed constraint initialization bug
* landoff uses constraints for takeoff and landing
* MPC: not doing collision avoidance without RKT or GPS estimator
* fixed double -> bool variables
* made the flip tracker more "admittant"
* added full-state prediction publisher
* Contributors: Tomas Baca

1.0.0 (2021-03-18)
------------------
* Major release
* Noetic-compatible
* MpcTracker: ultimate trajectory following with interpolation and proper time handling
* MpcTracker: resolved running with < 1 RTF
* MpcTracker: new min execution rate of 10 Hz
* Major refactoring and ovehaul
* c++ refactoring
* other trackers: refactoring
* Contributors: Dan Hert, Matej Petrlik, Matouš Vrba, Robert Penicka, Tomas Baca

0.0.5 (2020-02-26)
------------------
* increased the possible takeoff height to 10 m
* Contributors: Tomas Baca

0.0.4 (2020-02-18)
------------------
* fixed yet another min altitude bug
* sanitized avoidance srv
* updated odometry reset in mpc
* limited rwarnings of bad avoidance tfs
* updated heading activation inital condition
* fixed odometry switch bug with speed/acc scaling
* added version check
* avoidance trajectory published in utm_origin
* increased t650 takeoff speed and acceleration
* fixed constraint setting bug
* Commented out priority swapping in collision avoidance
* added rampup takeoff saturation
* fixed safety area check in loadTrajectory()
* fixed zero trajectory-length due to bumper
* fixed traj enumeration bug and looping bug
* fixed odom frame switching in Landoff and Line trackers
* fixed flying bellow zero in Z
* fixed trajectory plotting, updated min_alt
* added trackerResetStatic() method
* fixed safety area "out of area" bug
* min height for avoidance got from common_handlers
* fixed marker array warning
* fixed safety area checks, fixed des traj transforms
* updated diagnostics, fixed avoidance uav list
* avoidance trajectories, stamp = time of receiving it
* refactored trajectory loading, made it time-aware
* Added trajectory timestamp checking and interpolation of delayed trajectories
* changed the constraints message
* added check for mpc tracker callbacks if it's initialized
* trajectory topics set to latching
* added automatic velocity penalization, removed no_overshoots completely
* removed no_overshoots service, param and made it true by default
  * it is true by default now, except for trajectory tracking
* added heading angle interpolation
* fixed heading tracking in trajectory
* fixed last noloop trajectory point
* lowered the lowest safe height in collision avoidance
* added trajectory interpolation
* fixed wrong loading of common handlers
* added init checks to trajectory callbacks
* fixed land/eland goal-reached bug
* added checking of heading error during tracking
* fixed arena trajectory check, added marker
* generalized the transforms
* updated transformer calls
* updated to new get_mutexed()
* updated tracker interface, added bumper to mpc
* fixed the acceleration rotation in mpc odom switch
* converting references using tfs
* improved tf transformer
* added tf to trajectory setter
* removed z acceleration from activation
* added speed tracker, updated trackers interface
* removed start id from tracker trajectory
* added accelerations to mpc tracker activation
* setting accelerations during odometry reset
* namespaced local_origin
* removed PES from csv tracker
* Contributors: Andriy, Dan Hert, Matej Petrlik, Tomas Baca, Vojtech Spurny, kratkvit

0.0.3 (2019-10-25)
------------------
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
* fixed use_heading during flying to trajectory start
* added avoidance status to diagnostics
* fixed tracking flag in diagnostics after initial hover
* added tilt mode to MatlabTracker
* joystic channels moved to config file
* moved mpc solver outside of mpc tracker
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
