#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap & src);
		FragTrap & operator=(FragTrap & src);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif