#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void) {
	std::cout << "Dog instance destroyed." << std::endl;
}

Dog::Dog(Dog & src) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog & src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*woof*" << std::endl;
}