#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1 = cross_produt_2d(a, b, point);
	Fixed c2 = cross_produt_2d(b, c, point);
	Fixed c3 = cross_produt_2d(c, a, point);
	bool all_positive = (c1 > 0) && (c2 > 0) && (c3 > 0);
	bool all_negative = (c1 < 0) && (c2 < 0) && (c3 < 0);
	return all_negative || all_positive;
}