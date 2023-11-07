#include "AMateria.hpp"

AMateria::AMateria(void) {
}

AMateria::~AMateria(void) {
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(AMateria & src) {
	*this = src;
}

AMateria & AMateria::operator=(AMateria & src)  {
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
}