#include <catch_ros/catch.hpp>
#include <custom_msgs/Box.h>
#include "../src/box_tracker.h"

TEST_CASE("test_box_tracker", "navigation") {
    BoxTracker tracker;

    custom_msgs::Box box1;
    box1.id = "1";
    box1.bottom = 0.1f;
    box1.top = 0.2f;
    box1.left = -0.3f;
    box1.right = -0.2f;

    custom_msgs::Box box2;
    box2.id = "2";
    box2.bottom = -0.4f;
    box2.top = -0.2f;
    box2.left = -0.3f;
    box2.right = 0.0f;

    custom_msgs::Box box3;
    box3.id = "3";
    box3.bottom = 0.1f;
    box3.top = 0.35f;
    box3.left = 0.1;
    box3.right = 0.15;

    tracker.updateBox({box1, box2, box3});
    REQUIRE(tracker.trackedBox().id == "3");

    tracker.updateBox({box1, box2});
    REQUIRE(tracker.trackedBox().id == "2");

    const float delta = 0.25f;
    box1.right += delta;
    box1.left += delta;
    box2.right += delta;
    box2.left += delta;
    box3.right += delta;
    box3.left += delta;

    tracker.updateBox({box1, box2, box3});
    REQUIRE(tracker.trackedBox().id == "2"); // is still box2 even though it is worse cuz its id was tracked

    box2.id = "changedID";

    tracker.updateBox({box1, box2, box3});
    REQUIRE(tracker.trackedBox().id == "1"); // but with changed it picks the centered one
}
