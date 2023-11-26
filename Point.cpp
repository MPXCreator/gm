//
// Created by Reyes on 2023/11/13.
//

#include "Point.h"
#include <iostream>

std::string logTimept() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    std::string time = "[" + std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" +
                       std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" +
                       std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + "]";
    return time;
}

namespace gm {
    Point::Point(double x, double y) : x(x), y(y) {
        std::clog << "[FUNCTION] " << logTimept() << " " << "Point constructor called." << std::endl;
    }

    Point::Point(const Point &point)  : x(point.x), y(point.y) {
        std::clog << "[FUNCTION] " << logTimept() << " " << "Point copy constructor called." << std::endl;
    }

    Point::~Point() {
        std::clog << "[FUNCTION] " << logTimept() << " " << "Point destructor called." << std::endl;
    }
} // gm