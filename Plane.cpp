//
// Created by Reyes on 2023/11/13.
//

#include "Plane.h"
#include <iostream>

namespace gm {
    Plane::Plane() : size(area()) {
        std::clog << "Plane constructor called." << std::endl;
    }

    Plane::Plane(const Plane &plane) : size(plane.size) {
        std::clog << "Plane copy constructor called." << std::endl;
    }

    Plane::~Plane() {
        std::clog << "Plane destructor called." << std::endl;
    }

    double Plane::area() {
        std::clog << "Plane area called." << std::endl;
        return 0;
    }

    std::string Plane::info() const {
        return std::string("Type: ") + std::string("Plane") + "\n" + "Area: " + std::to_string(size);
    }

    bool operator<(const Plane &lhs, const Plane &rhs) {
        return lhs.getSize() < rhs.getSize();
    }

    bool operator>(const Plane& lhs, const Plane& rhs) {
        return lhs.getSize() > rhs.getSize();
    }

    std::ostream &operator<<(std::ostream &os, const Plane &plane) {
        os << plane.info();
        return os;
    }
} // gm