#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void) {
	std::cout << "Dog instance destroyed." << std::endl;
	delete this->brain;
}

Dog::Dog(Dog & src) : brain(NULL) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog & src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_type = src.getType();
		if (this->brain)
			delete brain;
		this->brain = new Brain(*(src.get_brain()));
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*woof*" << std::endl;
}

Brain *Dog::get_brain(void) {
	return this->brain;
}