//
// Created by Reyes on 2023/11/13.
//

#include "Rectangle.h"
#include "AreaTooLargeException.h"
#include <iostream>

namespace gm {
    Rectangle::Rectangle(Point leftTop, Point rightBottom) : leftTop(leftTop), rightBottom(rightBottom), size(area()) {
        std::clog << "Rectangle constructor called." << std::endl;
        if (size > 100)
            throw AreaTooLargeException();
    }

    Rectangle::Rectangle(const Rectangle &rectangle) : leftTop(rectangle.leftTop), rightBottom(rectangle.rightBottom), size(rectangle.size) {
        std::clog << "Rectangle copy constructor called." << std::endl;
    }

    Rectangle::~Rectangle() {
        std::clog << "Rectangle destructor called." << std::endl;
    }

    double Rectangle::area() {
        std::clog << "Rectangle area called." << std::endl;
        return fabs((rightBottom.getX() - leftTop.getX()) * (leftTop.getY() - rightBottom.getY()));
    }

    std::string Rectangle::info() const {
        return std::string("Type: ") + std::string("Rectangle") + "\n"
               + "LeftTop: (" + std::to_string(leftTop.getX()) + ", " + std::to_string(leftTop.getY()) + ")\n"
               + "RightBottom: (" + std::to_string(rightBottom.getX()) + ", " + std::to_string(rightBottom.getY()) + ")\n"
               + "Area: " + std::to_string(size);
    }

    Rectangle::Rectangle() : leftTop(Point(0, 0)), rightBottom(Point(0, 0)), size(area()) {
        std::clog << "Rectangle constructor called." << std::endl;
    }
} // gm