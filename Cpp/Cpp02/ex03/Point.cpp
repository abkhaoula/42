#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const float a, const float b) : x(a), y(b) {}
Point::Point(const Point& p) : x(p.x), y(p.y){}
Point& Point::operator=(const Point &p) {
    (Fixed) this->x = p.getX();
    (Fixed) this->y = p.getY();
    return (*this);
}
Point::~Point() {}

Fixed Point::getX( void ) const {
    return this->x;
}

Fixed Point::getY( void ) const {
    return this->y;
}