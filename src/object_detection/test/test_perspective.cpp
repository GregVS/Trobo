//
// Created by greg on 12/1/18.
//

#include <catch_ros/catch.hpp>
#include <iostream>

#include "perspective/perspective_constants.h"
#include "perspective/perspective.h"

const double screen::vanishing = 0.406;
const double screen::firstMarker = -0.172;
const double screen::secondMarker = -0.003;
const double screen::cmToFrameRatio = 1.0 / 0.366;
const double world::firstMarker = 2;
const double world::secondMarker = 3;

// for comparing
const double marginError = 0.05;

// test to make sure that old stored data is deleted after the buffer reaches max size of (5)
TEST_CASE("test_screen_to_world", "perspective") {
    auto output =  perspective::screenToWorld(0.103, 0.239);
    CHECK(output.first == Approx(1).margin(marginError));
    CHECK(output.second == Approx(8).margin(marginError));
}

TEST_CASE("test_world_to_screen", "perspective") {
    auto output2 = perspective::worldToScreen(1, 8);
    CHECK(output2.first == Approx(0.103).margin(marginError));
    CHECK(output2.second == Approx(0.239).margin(marginError));

    //2018
}

TEST_CASE("screen_to_world_and_back", "perspective") {
    // convert the screen to world
    auto output =  perspective::screenToWorld(0.103, 0.239);
    CHECK(output.first == Approx(1).margin(marginError));
    CHECK(output.second == Approx(8).margin(marginError));

    output.first -= 1; // move 1 foot
    // back to screen coordinates
    auto output2 = perspective::worldToScreen(output.first, output.second);
    CHECK(output2.first == Approx(0.0).margin(marginError));
    CHECK(output2.second == Approx(0.239).margin(marginError));}