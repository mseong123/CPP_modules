#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "Default WrongCat constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat instance destroyed." << std::endl;
}

WrongCat::WrongCat(WrongCat & src) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat & src) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "wrongcat *meow*" << std::endl;
}