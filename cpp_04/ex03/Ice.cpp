#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
}

Ice::~Ice(void) {
}

Ice::Ice(Ice & src) {
	*this = src;
}

Ice & Ice::operator=(Ice & src)  {
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}