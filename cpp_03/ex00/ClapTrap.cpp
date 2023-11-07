#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default Claptrap"), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "Default constructor called." <<std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "Constructor called." <<std::endl;
} 

ClapTrap::~ClapTrap(void) {
	std::cout << "Claptrap " << this->_name << " destroyed." <<std::endl;
}

ClapTrap::ClapTrap(ClapTrap & src) : _name(src.getname()), _hitpoints(src.gethitpoints()), _energypoints(src.getenergypoints()), _attackdamage(src.getattackdamage()){
	std::cout << "Copy constructor called." <<std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap & src) {
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

void	ClapTrap::attack(const std::string& target) {
	if (this->_energypoints <= 0 || this->_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy to attack!" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " ,causing " << this->_attackdamage << " points of damage!" << std::endl;
	this->_energypoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if ((unsigned int)this->_hitpoints <= amount)
    {
        this->_hitpoints = 0;
        std::cout << "ClapTrap " << this->_name << " has no hitpoints left!" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage." << std::endl;
	this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energypoints <= 0 || this->_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy or hitpoints to repair!" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << this->_name << " repairs itself, restoring " << amount << " hitpoints." << std::endl;
	this->_hitpoints += amount;
	this->_energypoints--;
}

std::string ClapTrap::getname(void) const {
	return this->_name;
}

int ClapTrap::gethitpoints(void) const {
	return this->_hitpoints;
}
int ClapTrap::getenergypoints(void) const {
	return this->_energypoints;
}

int ClapTrap::getattackdamage(void) const {
	return this->_attackdamage;
}