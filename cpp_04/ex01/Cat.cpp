#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat(void) {
	std::cout << "Cat instance destroyed." << std::endl;
	delete this->brain;
}

Cat::Cat(Cat & src) : brain(NULL) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat & src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &src)
	{
		if (this->brain != NULL)
			delete brain;
		this->brain = new Brain(*(src.get_brain()));
		this->_type = src.getType();
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "*meow*" << std::endl;
}

Brain *Cat::get_brain(void) {
	return this->brain;
}