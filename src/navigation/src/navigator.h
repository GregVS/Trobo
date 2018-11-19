//
// Created by greg on 11/18/18.
//

#ifndef PROJECT_NAVIGATOR_H
#define PROJECT_NAVIGATOR_H

#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>
#include <custom_msgs/Box.h>

class Navigator {

public:
    // PRECONDITION: THE PROVIDED BOXES SHOULD HAVE ID'S THAT ARE NOT EQUAL TO 0
    custom_msgs::Action navigate(const custom_msgs::ImagesAndBoxes& imgAndBoxes);

private:
    std::unique_ptr<custom_msgs::Box> trackedBox_;

    bool shouldDriveStraight(const custom_msgs::ImagesAndBoxes& imgAndBoxes);
    custom_msgs::Box nearestBox(std::vector<custom_msgs::Box> boxes);
    bool verifyTrackedBoxExists(std::vector<custom_msgs::Box> boxes);

};

#endif //PROJECT_NAVIGATOR_H
