//
// Created by greg on 12/2/18.
//

#ifndef PROJECT_CROSS_RATIO_H
#define PROJECT_CROSS_RATIO_H

#include <cassert>

namespace perspective_math {

double solveCrossRatio(double A, double B, double C, double D) {
    double numerator = (A - C) * (B - D);
    double denominator = (A - D) * (B - C);
    return numerator / denominator;
}

double solveCrossRatioForD(double A, double B, double C, double L) {
    double numerator = (L * A * B) - (L * A * C) - (A * B) + (C * B);
    double denominator = (L * B) - (L * C) + C - A;
    assert(denominator != 0);
    return numerator / denominator;
}

}
#endif //PROJECT_CROSS_RATIO_H
