#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack() const;
		void	setWeapon(Weapon &weapon);
};

#endif