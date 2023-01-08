#include "Fixed.hpp"
#include "Point.hpp"
#include "Fixed.h"

bool bsp(Point a, Point b, Point c, Point point)
{
    Fixed half((float) 1./2);
    Fixed area(half *(((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((c.getX() - a.getX()) * (b.getY() - a.getY()))));
    Fixed area1(half * ((b.getX() - point.getX()) * (c.getY() - point.getY()) - (b.getY() - point.getY()) * (c.getX() - point.getX())));
    Fixed area2(half * ((c.getX() - point.getX()) * (a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getX())));
    Fixed area3(half * ((a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX())));
    if (area1 < Fixed(0))
        area1 = Fixed(0) - area1;
    if (area2 < Fixed(0))
        area2 = Fixed(0) - area2;
    if (area3 < Fixed(0))
        area3 = Fixed(0) - area3;


    return ((area1 + area2 + area3) == area);
}