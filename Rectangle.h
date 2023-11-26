//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_RECTANGLE_H
#define GM_RECTANGLE_H

#include "Plane.h"
#include "Point.h"

namespace gm {

    class Rectangle : public Plane {
    private:
        Point leftTop;
        Point rightBottom;
        double size;
    public:
        Rectangle();
        Rectangle(const Point& leftTop, const Point& rightBottom);
        Rectangle(const Rectangle& rectangle);
        ~Rectangle();
        Point getLeftTop() const { return leftTop; }
        Point getRightBottom() const { return rightBottom; }
        double getSize() const override { return size; }
        double area() override;
        std::string info() const override;
    };

} // gm

#endif //GM_RECTANGLE_H
