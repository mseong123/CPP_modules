#include "Fixed.hpp"

int const Fixed::_fract = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "getRawBits member function called" << std::endl;
	this->_value = raw;
}
