#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point(void);
		~Point(void);
		Point(float const x, float const y);
		Point(Fixed x, Fixed y);
		Point(Point const & src);
		Fixed get_x(void) const;
		Fixed get_y(void) const;
		Point & operator=(Point & src);

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif