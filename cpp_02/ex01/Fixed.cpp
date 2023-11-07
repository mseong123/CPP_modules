#include "Fixed.hpp"

int const Fixed::_fract = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << Fixed::_fract) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << Fixed::_fract))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//returning *this allows chaining of assignment operations (e.g., a = b = c;) 

Fixed & Fixed::operator=(Fixed const & fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->getRawBits() / (1 << Fixed::_fract);
}

int Fixed::toInt( void ) const {
	return this->getRawBits() >> Fixed::_fract;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)
{
	return o << fixed.toFloat();
}
