#ifndef __POINT_H__
#define __POINT_H__
#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float a, const float b);
        Point(const Point& p);//const Point& p?
        Point& operator=(const Point &p);
        ~Point();
        Fixed getX( void ) const ;
        Fixed getY( void ) const ;
};

#endif /* __POINT_H__ */