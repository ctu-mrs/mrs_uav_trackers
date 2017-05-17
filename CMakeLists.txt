cmake_minimum_required(VERSION 2.8.3)
project(mbzirc_trackers)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  geometry_msgs
  tf
  trackers_manager
  std_msgs
  message_generation
  mav_manager
  dynamic_reconfigure
  roscpp
  rospy
  mbzirc_estimation
  mrs_msgs
  )
find_package(Eigen REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(${EIGEN_INCLUDE_DIR} ${catkin_INCLUDE_DIRS})

generate_dynamic_reconfigure_options(
  config/gains_drs.cfg
)

#add_message_files(FILES
#  )

#add_service_files(FILES
#  Vec1.srv
#  Gains.srv
#  TrackerTrajectorySrv.srv
#)

#generate_messages(DEPENDENCIES
#  std_msgs
#  geometry_msgs
#)

catkin_package(INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS message_runtime geometry_msgs tf trackers_manager mbzirc_estimation
  DEPENDS Eigen thread)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake
  )

add_library(mpc_tracker src/${PROJECT_NAME}/mpc_tracker.cpp)
add_dependencies(mpc_tracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${PROJECT_NAME}_gencfg
  )
target_link_libraries(mpc_tracker ${catkin_LIBRARIES})

#############
## Install ##
#############

install(TARGETS
  mpc_tracker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
  )

install(FILES mbzirc_trackers.xml DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
