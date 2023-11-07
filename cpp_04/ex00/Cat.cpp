#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void) {
	std::cout << "Cat instance destroyed." << std::endl;
}

Cat::Cat(Cat & src) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat & src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "*meow*" << std::endl;
}