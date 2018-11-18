# CMake generated Testfile for 
# Source directory: /home/greg/trobo_cpp/src/vision_opencv/image_geometry/test
# Build directory: /home/greg/trobo_cpp/src/cmake-build-debug/vision_opencv/image_geometry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_image_geometry_nosetests_directed.py "/home/greg/trobo_cpp/src/cmake-build-debug/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/greg/trobo_cpp/src/cmake-build-debug/test_results/image_geometry/nosetests-directed.py.xml" "--return-code" "/home/greg/clion/bin/cmake/linux/bin/cmake -E make_directory /home/greg/trobo_cpp/src/cmake-build-debug/test_results/image_geometry" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/greg/trobo_cpp/src/vision_opencv/image_geometry/test/directed.py --with-xunit --xunit-file=/home/greg/trobo_cpp/src/cmake-build-debug/test_results/image_geometry/nosetests-directed.py.xml")
add_test(_ctest_image_geometry_gtest_image_geometry-utest "/home/greg/trobo_cpp/src/cmake-build-debug/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/greg/trobo_cpp/src/cmake-build-debug/test_results/image_geometry/gtest-image_geometry-utest.xml" "--return-code" "/home/greg/trobo_cpp/src/cmake-build-debug/devel/lib/image_geometry/image_geometry-utest --gtest_output=xml:/home/greg/trobo_cpp/src/cmake-build-debug/test_results/image_geometry/gtest-image_geometry-utest.xml")
