//
// Created by Reyes on 2023/11/13.
//

#include "Circle.h"
#include "AreaTooLargeException.h"
#include <iostream>

namespace gm {
    Circle::Circle(Point center, double radius) : center(center), radius(radius), size(area()) {
        std::clog << "Circle constructor called." << std::endl;
        if (size > 100)
            throw AreaTooLargeException();
    }

    Circle::Circle(const Circle &circle) : center(circle.center), radius(circle.radius), size(circle.size) {
        std::clog << "Circle copy constructor called." << std::endl;
    }

    Circle::~Circle() {
        std::clog << "Circle destructor called." << std::endl;
    }

    double Circle::area() {
        std::clog << "Circle area called." << std::endl;
        return 3.14 * radius * radius;
    }

    std::string Circle::info() const {
        return std::string("Type: ") + std::string("Circle") + "\n"
               + "Center: (" + std::to_string(center.getX()) + ", " + std::to_string(center.getY()) + ")\n"
               + "Radius: " + std::to_string(radius) + "\n"
               + "Area: " + std::to_string(size);
    }

    Circle::Circle() : center(Point(0, 0)), radius(0), size(area()) {
        std::clog << "Circle constructor called." << std::endl;
    }
} // gm