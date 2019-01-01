find_package(catch_ros REQUIRED)
include_directories(${catkin_INCLUDE_DIRS})

catch_add_test(box_tracker_test test_box_tracker.cpp ../src/box_tracker.cpp)
catch_add_test(position_prediction_test test_position_prediction.cpp)

target_include_directories(box_tracker_test PUBLIC ../src)

target_link_libraries(box_tracker_test ${catkin_LIBRARIES})
target_link_libraries(position_prediction_test ${catkin_LIBRARIES})