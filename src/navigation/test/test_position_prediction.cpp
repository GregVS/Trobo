//
// Created by greg on 12/31/18.
//

#include <catch_ros/catch.hpp>
#include <custom_msgs/Action.h>
#include "../src/prediction/PositionPrediction.h"
#include <boost/make_shared.hpp>

#include <iostream>

TEST_CASE("test_position_prediction", "navigation") {
    custom_msgs::Action action;
    action.id = 1;
    action.params = { 1, 0.5 };

    auto ptr = boost::make_shared<custom_msgs::Action const>(action);
    auto output = prediction::predictMovement(ptr, 1);

    std::cout << output.dx << ", " << output.dy << ", " <<  output.rotation << std::endl;
}