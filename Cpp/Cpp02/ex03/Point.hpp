#ifndef __POINT_H__
#define __POINT_H__
#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float a, const float b);
        Point(Point& p);//const Point& p?
        Point& operator=(const Point &p);
        ~Point();
};

#endif /* __POINT_H__ */