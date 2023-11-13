cmake_minimum_required(VERSION 3.26)
project(gm)

set(CMAKE_CXX_STANDARD 17)

add_executable(gm main.cpp
        Point.cpp
        Point.h
        Plane.cpp
        Plane.h
        Circle.cpp
        Circle.h
        Rectangle.cpp
        Rectangle.h
        AreaTooLargeException.h
        Linkedlist.h)
