#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap & src);
		ScavTrap & operator=(ScavTrap & src);
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
