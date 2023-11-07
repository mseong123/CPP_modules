#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void) : ClapTrap("Default ScavTrap") {
	std::cout << "Default ScavTrap constructor called." <<std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called." <<std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
}

ScavTrap::~ScavTrap (void) {
	std::cout << "ScavTrap " << this->getname() << " destroyed." <<std::endl;
}

ScavTrap::ScavTrap(ScavTrap & src) : ClapTrap(src) {
}

ScavTrap & ScavTrap::operator=(ScavTrap & src) {
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

void	ScavTrap::attack(const std::string& target) {
	 if (this->_energypoints <= 0 || this->_hitpoints <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " has no energy to attack!" << std::endl;
        return ;
    }
	std::cout << "ScavTrap " << this->getname() << " attacks " << target << " ,causing " << this->getattackdamage() << " points of damage!" << std::endl;
	this->_energypoints--;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getname() << " is in GateKeeper mode." <<std::endl;
}


