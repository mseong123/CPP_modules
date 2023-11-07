#include "Character.hpp"

Character::Character(std::string name) {
	int i = 0;

	this->_name = name;
	while (i < 4)
		this->_inventory[i++] = NULL;
}

Character::~Character(void) {
	int i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		i++;
	}
}

Character::Character(Character & src) {
	*this = src;
}

Character & Character::operator=(Character & src) {
	int i = 0;
	int j = 0;
	AMateria **src_inventory = src.get_inventory();
	
	if (this != &src)
	{
		while (i < 4)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			i++;
		}
		while(j < 4)
		{
			
			if (src_inventory[j])
				this->_inventory[j] = src_inventory[j]->clone();
			j++;
		}
		this->_name = src.getName();
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

AMateria** Character::get_inventory() {
	return this->_inventory;
}

void Character::equip(AMateria* m) {
	int i = 0;
	int equipped = 0;
	if (m == NULL)
		std::cout << "Can't equip materia type." << std::endl;
	else
	{
		while (i < 4)
		{
			if (this->_inventory[i] == NULL )
			{
				this->_inventory[i] = m;
				std::cout << "Materia equipped." << std::endl;
				equipped = 1;
				break;
			}
			i++;
		}
		if (!equipped)
			std::cout << "Inventory is full. Can't equip anymore Materias." << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		std::cout << "Non existing Materia. Can't unequip." << std::endl;
	else
	{
		this->_inventory[idx] = NULL;
		std::cout << "Materia unequipped." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		std::cout << "Non existing Materia. Can't use." << std::endl;
	else
		this->_inventory[idx]->use(target);
}