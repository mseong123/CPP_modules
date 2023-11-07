#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "Default AAnimal constructor called." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal instance destroyed." << std::endl;
}

AAnimal::AAnimal(AAnimal & src) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = src;
}

AAnimal & AAnimal::operator=(AAnimal & src) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

std::string	AAnimal::getType(void) const {
	return this->_type;
}

void	AAnimal::makeSound(void)	const{
	std::cout << "*random AAnimal sound*" << std::endl;
}
