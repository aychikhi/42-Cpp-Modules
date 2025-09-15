#include "Point.hpp"

int main(void)
{
    Point a(0, 3);
    Point b(-2, -2);
    Point c(2, 0);
    Point p(0, 0.001);
    Point test;
    std::cout << (bsp(a,b,c,p) ? "inside" : "outside") << std::endl;
}