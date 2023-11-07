#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap diamond("diamond");

	std::cout << "My name is " << diamond.getname() << std::endl;
	std::cout << diamond.gethitpoints() << " hitpoints (FRAGTRAP's 100 hitpoints)" << std::endl;
	std::cout << diamond.getenergypoints() << " energy points (SCAVTRAP's 50 energy points)" << std::endl;
	std::cout << diamond.getattackdamage() << " attack damage (FRAGTRAP's 30 attack damage)" << std::endl;

	diamond.attack("diamond2");
	std::cout << "DiamondTrap inherits ScavTrap's attack" << std::endl;
	diamond.guardGate();
	std::cout << "DiamondTrap inherits ScavTrap's Gatekeeper ability" << std::endl;
	diamond.highFivesGuys();
	std::cout << "DiamondTrap inherits FragTrap's HighFive ability" << std::endl;
	diamond.whoAmI();
	std::cout << "DiamondTrap's own ability" << std::endl;
	
	return (0);
}