#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
}

Cure::~Cure(void) {
}

Cure::Cure(Cure & src) {
	*this = src;
}

Cure & Cure::operator=(Cure & src)  {
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}