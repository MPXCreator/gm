//
// Created by Reyes on 2023/11/13.
//

#include "Plane.h"
#include <iostream>
#include <ctime>

std::string logTimep() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    std::string time = "[" + std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" +
                       std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" +
                       std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + "]";
    return time;
}

namespace gm {
    Plane::Plane() : size(area()) {
        std::clog << "[FUNCTION] " << logTimep() << " " << "Plane constructor called." << std::endl;
    }

    Plane::Plane(const Plane &plane) : size(plane.size) {
        std::clog << "[FUNCTION] " << logTimep() << " " << "Plane copy constructor called." << std::endl;
    }

    Plane::~Plane() {
        std::clog << "[FUNCTION] " << logTimep() << " " << "Plane destructor called." << std::endl;
    }

    double Plane::area() {
        std::clog << "[FUNCTION] " << logTimep() << " " << "Plane area called." << std::endl;
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