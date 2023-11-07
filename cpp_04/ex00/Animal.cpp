#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal instance destroyed." << std::endl;
}

Animal::Animal(Animal & src) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

Animal & Animal::operator=(Animal & src) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

std::string	Animal::getType(void) const {
	return this->_type;
}

void	Animal::makeSound(void)	const{
	std::cout << "*random animal sound*" << std::endl;
}
