//
// Created by Reyes on 2023/11/13.
//

#include "Point.h"
#include <iostream>

namespace gm {
    Point::Point(double x, double y) : x(x), y(y) {
        std::clog << "Point constructor called." << std::endl;
    }

    Point::Point(const Point &point)  : x(point.x), y(point.y) {
        std::clog << "Point copy constructor called." << std::endl;
    }

    Point::~Point() {
        std::clog << "Point destructor called." << std::endl;
    }
} // gm