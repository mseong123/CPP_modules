#include "FragTrap.hpp"

FragTrap::FragTrap (void) : ClapTrap("Default FragTrap") {
	std::cout << "Default FragTrap constructor called." <<std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called." <<std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
}

FragTrap::~FragTrap (void) {
	std::cout << "FragTrap " << this->getname() << " destroyed." <<std::endl;
}

FragTrap::FragTrap(FragTrap & src) : ClapTrap(src){
}

FragTrap & FragTrap::operator=(FragTrap & src) {
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

void	FragTrap::attack(const std::string& target) {
	if (this->_energypoints <= 0 || this->_hitpoints <= 0)
    {
        std::cout << "FragTrap " << this->_name << " has no energy to attack!" << std::endl;
        return ;
    }
	std::cout << "FragTrap " << this->getname() << " attacks " << target << " ,causing " << this->getattackdamage() << " points of damage!" << std::endl;
	this->_energypoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " give you a high five." << std::endl;
}