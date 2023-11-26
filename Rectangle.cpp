//
// Created by Reyes on 2023/11/13.
//

#include "Rectangle.h"
#include "AreaTooLargeException.h"
#include <iostream>
#include <ctime>

std::string logTimer() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    std::string time = "[" + std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" +
                       std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" +
                       std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + "]";
    return time;
}

namespace gm {
    Rectangle::Rectangle(const Point& leftTop, const Point& rightBottom) : leftTop(leftTop), rightBottom(rightBottom), size(area()) {
        std::clog << "[FUNCTION] " << logTimer() << " " << "Rectangle constructor called." << std::endl;
        if (size > 100)
            throw AreaTooLargeException();
    }

    Rectangle::Rectangle(const Rectangle &rectangle) : leftTop(rectangle.leftTop), rightBottom(rectangle.rightBottom), size(rectangle.size) {
        std::clog << "[FUNCTION] " << logTimer() << " " << "Rectangle copy constructor called." << std::endl;
    }

    Rectangle::~Rectangle() {
        std::clog << "[FUNCTION] " << logTimer() << " " << "Rectangle destructor called." << std::endl;
    }

    double Rectangle::area() {
        std::clog << "[FUNCTION] " << logTimer() << " " << "Rectangle area called." << std::endl;
        return fabs((rightBottom.getX() - leftTop.getX()) * (leftTop.getY() - rightBottom.getY()));
    }

    std::string Rectangle::info() const {
        return std::string("Type: ") + std::string("Rectangle") + "\n"
               + "LeftTop: (" + std::to_string(leftTop.getX()) + ", " + std::to_string(leftTop.getY()) + ")\n"
               + "RightBottom: (" + std::to_string(rightBottom.getX()) + ", " + std::to_string(rightBottom.getY()) + ")\n"
               + "Area: " + std::to_string(size);
    }

    Rectangle::Rectangle() : leftTop(Point(0, 0)), rightBottom(Point(0, 0)), size(area()) {
        std::clog << "[FUNCTION] " << logTimer() << " " << "Rectangle constructor called." << std::endl;
    }
} // gm