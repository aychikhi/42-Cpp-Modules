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

Fixed cross_produt_2d(const Point p1, const Point p2, const Point p3);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif