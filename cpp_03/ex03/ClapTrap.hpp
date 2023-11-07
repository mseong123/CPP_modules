#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int _hitpoints;
		int _energypoints;
		int _attackdamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap & src);
		ClapTrap & operator=(ClapTrap & src);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getname(void) const;
		int gethitpoints(void) const;
		int getenergypoints(void) const;
		int getattackdamage(void) const;

};

#endif