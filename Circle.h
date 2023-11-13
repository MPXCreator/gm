//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_CIRCLE_H
#define GM_CIRCLE_H

#include "Plane.h"
#include "Point.h"

namespace gm {

    class Circle : public Plane {
    private:
        double radius;
        Point center;
        double size;
    public:
        Circle();
        Circle(Point center, double radius);
        Circle(const Circle& circle);
        ~Circle();
        double getRadius() const { return radius; }
        Point getCenter() const { return center; }
        double getSize() const override { return size; }
        double area() override;
        std::string info() const override;
    };

} // gm

#endif //GM_CIRCLE_H
