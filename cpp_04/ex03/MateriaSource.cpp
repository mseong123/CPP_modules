#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	int i = 0;

	while (i < 4)
		this->_materia[i++] = NULL;
}

MateriaSource::~MateriaSource(void) {
	int i = 0;
	while (i < 4)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource & src) {
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource & src) {
	int i = 0;
	int j = 0;
	AMateria **src_materia = src.get_materia();
	
	if (this != &src)
	{
		while (i < 4)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			i++;
		}
		while(j < 4)
		{
			if (src_materia[j])
				delete src_materia[j];
			j++;
		}
	}
	return *this;
}

AMateria** MateriaSource::get_materia() {
	return this->_materia;
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;
	int equipped = 0;
	while (i < 4)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			std::cout << "Materia of type " << m->getType() << " learned." << std::endl;
			equipped = 1;
			break;
		}
		i++;
	}
	if (!equipped)
		std::cout << "4 Materia currently stored. Can't learn anymore Materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	int i = 0;
	while (i < 4)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
		i++;
	}
	std::cout << "Materia type does not exists." << std::endl;
	return (0);
}