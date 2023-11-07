#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y (Fixed(0)){
}

Point::~Point(void) {

}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {

}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y){

}

Point & Point::operator=(Point & src) {
	//std::cout << "Assignment of const variables impossible, values will stay the same as in the default constructor." << std::endl;
	return (*this);
}

Point::Point(Point const & src) : _x(src.get_x()), _y(src.get_y()) {

}

Fixed Point::get_x(void) const{
	return this->_x;
}

Fixed Point::get_y(void) const{
	return this->_y;
}