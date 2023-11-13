//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_PLANE_H
#define GM_PLANE_H

#include <string>
#include <iostream>
namespace gm {

    class Plane {
    private:
        double size;
    public:
        Plane();
        Plane(const Plane& plane);
        ~Plane();
        virtual double getSize() const { return size; }
        virtual double area();
        virtual std::string info() const;
    };

    bool operator<(const Plane& lhs, const Plane& rhs);
    bool operator>(const Plane& lhs, const Plane& rhs);

    std::ostream& operator<<(std::ostream& os, const Plane& plane);
} // gm

#endif //GM_PLANE_H
