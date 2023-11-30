#!/bin/bash

PACKAGE_NAME=mrs_uav_trackers

while [ ! -e ".catkin_tools" ]; do
  cd ..
  if [[ `pwd` == "/" ]]; then
    # we reached the root and didn't find the build/COLCON_IGNORE file - that's a fail!
    echo "$0: could not find the root of the current workspace".
    return 1
  fi
done

cd build

lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info "*/test/*" --output-file coverage.info.removed
lcov --extract coverage.info.removed "*/${PACKAGE_NAME}/*" --output-file coverage.info.cleaned
genhtml -o coverage_html coverage.info.cleaned | tee /tmp/genhtml.log

COVERAGE_PCT=`cat /tmp/genhtml.log | tail -n 1 | awk '{print $2}'`

echo "Coverage: $COVERAGE_PCT"

xdg-open coverage_html/index.html
