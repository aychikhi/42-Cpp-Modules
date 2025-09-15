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

Fixed cross_produt_2d(const Point p1, const Point p2, const Point p3)
{
	return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}
