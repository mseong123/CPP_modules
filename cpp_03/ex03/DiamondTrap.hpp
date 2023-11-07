#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap & src);
		~DiamondTrap(void);
		DiamondTrap & operator=(DiamondTrap & src);
		void	attack(const std::string& target);
		void	whoAmI(void) const;
		std::string getname(void) const;
};

#endif