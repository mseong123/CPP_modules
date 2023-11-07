#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name), _weapon(NULL) {

}

HumanB::~HumanB (void) {

}

void	HumanB::attack(void) const {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}