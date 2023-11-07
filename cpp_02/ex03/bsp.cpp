#include "Point.hpp"

float find_area(Point const a, Point const b, Point const c) {
	float result;

	result = (
	(c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat())) + 
	(a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat())) +
	(b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat()))
	) / 2;
	if (result < 0)
		return -1 * result;
	else
		return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float area = find_area(a, b, c);
	float a1 = find_area(point, b, c);
	float a2 = find_area(a, point, c);
	float a3 = find_area(a, b, point);

	if (a1 == 0 || a2 == 0 || a3 == 0) {
       return false;
   }
	return (area == a1 + a2 + a3);
}
