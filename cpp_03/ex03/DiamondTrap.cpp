#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap constructor called." <<std::endl;
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 30;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " destroyed." <<std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap & src) : ClapTrap(src) {
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap & src) {
	if (this != &src)
	{
		this->_name = src.getname();
		this->_hitpoints = src.gethitpoints();
		this->_energypoints = src.getenergypoints();
		this->_attackdamage = src.getattackdamage();
	}
	std::cout << "Copy assignment operator called." <<std::endl;
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << "My name is " << this->_name << " and my Claptrap name is " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getname(void) const {
	return this->_name;
}