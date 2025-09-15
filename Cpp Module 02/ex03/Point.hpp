#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float new_x, const float new_y);
		Point(const Point &other);
		Point &operator=(const Point &new_point);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};

Fixed triangleArea(Point const p1, Point const p2, Point const p3);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif