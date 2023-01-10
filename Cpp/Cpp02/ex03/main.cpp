#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Fixed.h"
#include <cassert>

int main()
{
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);
    Point d(1./4, 1./4);
    Point e(1, 1);
    Point f(2, 2);

    //bsp(a, b, c, e);
    std::cout<<(bsp(a, b, c, d) == true);  // Point d is inside the triangle
    std::cout<<(bsp(a, b, c, e) == false); // Point e is on the edge of the triangle
    std::cout<<(bsp(a, b, c, f) == false); // Point f is outside the triangle

    return 0;
}