//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_POINT_H
#define GM_POINT_H

namespace gm {

    class Point {
    private:
        double x;
        double y;
    public:
        Point(double x, double y);
        Point(const Point& point);
        ~Point();

        double getX() const {
            return x;
        }

        void setX(double x) {
            Point::x = x;
        }

        double getY() const {
            return y;
        }

        void setY(double y) {
            Point::y = y;
        }
    };

} // gm

#endif //GM_POINT_H
