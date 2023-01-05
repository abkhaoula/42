#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const float a, const float b) : x(a), y(b) {}
Point::Point(Point& p) : x(p.x), y(p.y){}
Point& Point::operator=(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    return (*this);
}
Point::~Point() {}