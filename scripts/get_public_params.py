#!/usr/bin/python3

import rospkg
import os

class ParamsGetter:

    def __init__(self):

        package_name = "mrs_uav_trackers"

        rospack = rospkg.RosPack()

        package_path = rospack.get_path(package_name)

        file_paths = []

        for path, subdirs, files in os.walk(package_path + "/config/public/"):
            for name in files:
                if name.endswith(".yaml") or name.endswith(".yml"):
                  file_paths.append(os.path.join(path, name))

        for file_path in file_paths:

            if os.path.getsize(file_path) == 0:
                continue

            with open(file_path, 'r') as file:
                try:
                    print(file.read())
                except:
                    print("There was a problem while opening the file '{}'".format(file_path))
                    break

if __name__ == '__main__':
    params_getter = ParamsGetter()
