cmake_minimum_required(VERSION 3.5)
project(mrs_uav_trackers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-Wall)
add_definitions(-Wextra)

if(COVERAGE)
  message(WARNING "building with --coverage, the performance might be limited")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif()

set(CATKIN_DEPENDENCIES
  cmake_modules
  roscpp
  rospy
  geometry_msgs
  tf
  std_msgs
  mrs_lib
  mrs_msgs
  mrs_uav_managers
  dynamic_reconfigure
  mrs_uav_testing
  )

find_package(catkin REQUIRED COMPONENTS
  ${CATKIN_DEPENDENCIES}
  )

generate_dynamic_reconfigure_options(
  cfg/mpc_tracker.cfg
  cfg/flip_tracker.cfg
  )

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

file(REMOVE_RECURSE src/mpc_tracker/acados_mpc/c_generated_code/)
execute_process(COMMAND python src/mpc_tracker/acados_mpc/main_build.py 
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
file(GLOB_RECURSE DOT_O_FILES src/mpc_tracker/acados_mpc/c_generated_code/*.o)
file (REMOVE
    ${DOT_O_FILES}
)
file(GLOB_RECURSE DOT_SO_FILES src/mpc_tracker/acados_mpc/c_generated_code/*.so)
file (REMOVE
  ${DOT_SO_FILES}
)


set(LIBRARIES
  MrsUavTrackers_MpcTracker
  MrsUavTrackers_LineTracker
  MrsUavTrackers_LandoffTracker
  MrsUavTrackers_JoyTracker
  MrsUavTrackers_SpeedTracker
  MrsUavTrackers_FlipTracker
  MrsUavTrackers_MidairActivationTracker
  )

catkin_package(
  INCLUDE_DIRS include
  INCLUDE_DIRS src/mpc_tracker/acados_mpc/include
  CATKIN_DEPENDS ${CATKIN_DEPENDENCIES}
  LIBRARIES ${LIBRARIES}
  DEPENDS Eigen
  )
set(ACADOS_INCLUDE_DIR $ENV{ACADOS_SOURCE_DIR}/include)
set(ACADOS_LIB_DIR $ENV{ACADOS_SOURCE_DIR}/lib)

FILE(GLOB model_src src/mpc_tracker/acados_mpc/c_generated_code/quadrotor_ode_model/*.c)
FILE(GLOB ocp_src src/mpc_tracker/acados_mpc/c_generated_code/quadrotor_ode_cost/*.c)
find_library(ACADOS ${ACADOS_LIB_DIR}/libacados.so)



## --------------------------------------------------------------
## |                            Build                           |
## --------------------------------------------------------------

include_directories(
  include
        ${ACADOS_INCLUDE_DIR}
  src/mpc_tracker/acados_mpc/include
  src/propulsion_module/include
  ${ACADOS_INCLUDE_DIR}/blasfeo/include
  ${ACADOS_INCLUDE_DIR}/hpipm/include

  ${catkin_INCLUDE_DIRS}
  ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake


  ${EIGEN_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
  )

# wrapper
add_library(ModelObj ${model_src})
add_dependencies(ModelObj ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ModelObj
  ${catkin_LIBRARIES}
)

add_library(OcpObj ${ocp_src})
add_dependencies(OcpObj ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(OcpObj
  ${catkin_LIBRARIES}
)

add_library(AcadosSim src/mpc_tracker/acados_mpc/c_generated_code/acados_sim_solver_quadrotor_ode.c)
add_dependencies(AcadosSim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(AcadosSim
  ${catkin_LIBRARIES}
)


add_library(TargetExample src/mpc_tracker/acados_mpc/c_generated_code/main_quadrotor_ode.c src/mpc_tracker/acados_mpc/c_generated_code/acados_solver_quadrotor_ode.c)
add_dependencies(TargetExample ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(TargetExample
OcpObj
ModelObj
  ${catkin_LIBRARIES}
)
add_library(TargetExampleSim src/mpc_tracker/acados_mpc/c_generated_code/main_sim_quadrotor_ode.c)
add_dependencies(TargetExampleSim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(TargetExampleSim
  ${catkin_LIBRARIES}
)

# Mpc Solver Library

# Store in CMAKE_DEB_HOST_ARCH var the current build architecture
execute_process(COMMAND
  dpkg-architecture
  -qDEB_HOST_ARCH
  OUTPUT_VARIABLE
  CMAKE_DEB_HOST_ARCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )

# deduce the library path based on the system architecture
if(${CMAKE_DEB_HOST_ARCH} MATCHES "armhf")
  MESSAGE(FATAL_ERROR "Mising MpcTrackerSolver.so for armhf")
elseif(${CMAKE_DEB_HOST_ARCH} MATCHES "i386")
  MESSAGE(FATAL_ERROR "Mising MpcTrackerSolver.so for i386")
elseif(${CMAKE_DEB_HOST_ARCH} MATCHES "x64")
  set(MPC_CONTROLLER_SOLVER_BIN ${PROJECT_SOURCE_DIR}/lib/MpcTrackerSolver/x64/libMpcTrackerSolver.so)
elseif(${CMAKE_DEB_HOST_ARCH} MATCHES "amd64")
  set(MPC_CONTROLLER_SOLVER_BIN ${PROJECT_SOURCE_DIR}/lib/MpcTrackerSolver/x64/libMpcTrackerSolver.so)
elseif(${CMAKE_DEB_HOST_ARCH} MATCHES "arm64")
  set(MPC_CONTROLLER_SOLVER_BIN ${PROJECT_SOURCE_DIR}/lib/MpcTrackerSolver/arm64/libMpcTrackerSolver.so)
else()
  MESSAGE(FATAL_ERROR ${CMAKE_DEB_HOST_ARCH})
  MESSAGE(FATAL_ERROR "MpcTrackerSolver.so has not been selected, check CMakeLists.txt.")
endif()

# MPC Tracker

add_library(MrsUavTrackers_MpcTracker
  src/mpc_tracker/mpc_tracker.cpp
  src/mpc_tracker/acados_mpc/src/acados_wrapper.cpp

  )

add_dependencies(MrsUavTrackers_MpcTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_MpcTracker
  ${catkin_LIBRARIES}
  ${MPC_CONTROLLER_SOLVER_BIN}
   ${ACADOS_LIB_DIR}/libacados.so
 yaml-cpp 
 ModelObj
 OcpObj
 AcadosSim
 TargetExample
 TargetExampleSim

  )

# Line Tracker

add_library(MrsUavTrackers_LineTracker
  src/line_tracker/line_tracker.cpp
  )

add_dependencies(MrsUavTrackers_LineTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_LineTracker
  ${catkin_LIBRARIES}
  )

# Landoff Tracker

add_library(MrsUavTrackers_LandoffTracker
  src/landoff_tracker/landoff_tracker.cpp
  )

add_dependencies(MrsUavTrackers_LandoffTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_LandoffTracker
  ${catkin_LIBRARIES}
  )

# Joy Tracker

add_library(MrsUavTrackers_JoyTracker
  src/joy_tracker/joy_tracker.cpp
  )

add_dependencies(MrsUavTrackers_JoyTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_JoyTracker
  ${catkin_LIBRARIES}
  )

# Speed tracker

add_library(MrsUavTrackers_SpeedTracker
  src/speed_tracker/speed_tracker.cpp
  )

add_dependencies(MrsUavTrackers_SpeedTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_SpeedTracker
  ${catkin_LIBRARIES}
  )

# Flip tracker

add_library(MrsUavTrackers_FlipTracker
  src/flip_tracker/flip_tracker.cpp
  )

add_dependencies(MrsUavTrackers_FlipTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_FlipTracker
  ${catkin_LIBRARIES}
  )

# Midair activation tracker

add_library(MrsUavTrackers_MidairActivationTracker
  src/midair_activation_tracker/midair_activation_tracker.cpp
  )

add_dependencies(MrsUavTrackers_MidairActivationTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavTrackers_MidairActivationTracker
  ${catkin_LIBRARIES}
  )

## --------------------------------------------------------------
## |                           Testing                          |
## --------------------------------------------------------------

if(CATKIN_ENABLE_TESTING AND MRS_ENABLE_TESTING)

  message(WARNING "Testing enabled.")

  add_subdirectory(test)

endif()

## --------------------------------------------------------------
## |                           Install                          |
## --------------------------------------------------------------

install(TARGETS ${LIBRARIES}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
  )

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

install(FILES ${MPC_CONTROLLER_SOLVER_BIN}
  DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  )

install(DIRECTORY scripts/
  USE_SOURCE_PERMISSIONS
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY scripts
  USE_SOURCE_PERMISSIONS
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

install(FILES plugins.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
