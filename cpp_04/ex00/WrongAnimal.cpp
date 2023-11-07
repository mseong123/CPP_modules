#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal instance destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal & src) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal & src) {
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const {
	return this->_type;
}

void	WrongAnimal::makeSound(void)	const{
	std::cout << "*random WrongAnimal sound*" << std::endl;
}
