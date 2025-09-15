#include "Point.hpp"

Point::Point() : x(0) , y(0) {};

Point::Point(const float new_x, const float new_y) : x(new_x) , y(new_y) {};

Point::Point(const Point &other) : x(other.x) , y(other.y) {};

Point &Point::operator=(const Point &new_point)
{
	(void)new_point;
    return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}

Fixed triangleArea(Point const p1, Point const p2, Point const p3)
{
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();
    Fixed area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (area < Fixed(0))
        area = Fixed(0) - area;
    return area / Fixed(2);
}
