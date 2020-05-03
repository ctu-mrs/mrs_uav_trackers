cmake_minimum_required(VERSION 2.8.3)
project(mrs_uav_trackers)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  geometry_msgs
  tf
  std_msgs
  roscpp
  rospy
  mrs_lib
  mrs_msgs
  mrs_uav_managers
  dynamic_reconfigure
  )

generate_dynamic_reconfigure_options(
  cfg/mpc_tracker.cfg
  )

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color -O0 -g")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES MpcTrackerCvxgen
  CATKIN_DEPENDS geometry_msgs tf mrs_lib mrs_uav_managers mrs_msgs
  DEPENDS Eigen
  )

###########
## Build ##
###########

include_directories(
  include
  ${EIGEN_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
  ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake
  )

# CVXgen wrapper for MPC tracker

add_library(MpcTrackerCvxgen src/cvx_wrapper/cvx_wrapper.cpp
  src/cvx_wrapper/cvxgen/ldl.c
  src/cvx_wrapper/cvxgen/matrix_support.c
  src/cvx_wrapper/cvxgen/solver.c
  src/cvx_wrapper/cvxgen/util.c
  )

# MPC Tracker

add_library(MpcTracker src/mpc_tracker/mpc_tracker.cpp)

add_dependencies(MpcTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MpcTracker
  ${catkin_LIBRARIES}
  MpcTrackerCvxgen
  )

# CSV Tracker

add_library(CsvTracker
  src/csv_tracker/csv_tracker.cpp
  )
add_dependencies(CsvTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(CsvTracker
  ${catkin_LIBRARIES}
  )

# Line Tracker

add_library(LineTracker
  src/line_tracker/line_tracker.cpp
  )
add_dependencies(LineTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(LineTracker
  ${catkin_LIBRARIES}
  )

# Landoff Tracker

add_library(LandoffTracker
  src/landoff_tracker/landoff_tracker.cpp
  )
add_dependencies(LandoffTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(LandoffTracker
  ${catkin_LIBRARIES}
  )

# Joy Tracker

add_library(JoyTracker
  src/joy_tracker/joy_tracker.cpp
  )
add_dependencies(JoyTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(JoyTracker
  ${catkin_LIBRARIES}
  )

# Matlab tracker

add_library(MatlabTracker
  src/matlab_tracker/matlab_tracker.cpp
  )
add_dependencies(MatlabTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(MatlabTracker
  ${catkin_LIBRARIES}
  )

# Speed tracker

add_library(SpeedTracker
  src/speed_tracker/speed_tracker.cpp
  )
add_dependencies(SpeedTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(SpeedTracker
  ${catkin_LIBRARIES}
  )

#############
## Install ##
#############

install(TARGETS
  MpcTracker
  CsvTracker
  LineTracker
  LandoffTracker
  JoyTracker
  MatlabTracker
  MpcTrackerCvxgen
  SpeedTracker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  )

install(FILES
  plugins.xml
  DESTINATION
  ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
