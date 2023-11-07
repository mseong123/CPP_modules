#include "FragTrap.hpp"

int	main(void) {
	FragTrap fragtrap;
	FragTrap a("A");
	FragTrap copyA(a);
	FragTrap assignA("AssignA");
	assignA = a;

	std::cout << fragtrap.getname() << std::endl;
	std::cout << fragtrap.gethitpoints() << " hitpoints" << std::endl;
	std::cout << fragtrap.getenergypoints() << " energy points" << std::endl;
	std::cout << fragtrap.getattackdamage() << " attack damage" << std::endl;

	std::cout << a.getname() << std::endl;
	std::cout << a.gethitpoints() << " hitpoints" << std::endl;
	std::cout << a.getenergypoints() << " energy points" << std::endl;
	std::cout << a.getattackdamage() << " attack damage" << std::endl;

	std::cout << copyA.getname() << std::endl;
	std::cout << copyA.gethitpoints() << " hitpoints" << std::endl;
	std::cout << copyA.getenergypoints() << " energy points" << std::endl;
	std::cout << copyA.getattackdamage() << " attack damage" << std::endl;

	std::cout << assignA.getname() << std::endl;
	std::cout << assignA.gethitpoints() << " hitpoints" << std::endl;
	std::cout << assignA.getenergypoints() << " energy points" << std::endl;
	std::cout << assignA.getattackdamage() << " attack damage" << std::endl;

	a.attack("fragtrap2");
	std::cout << "FragTrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;
	a.takeDamage(5);
	std::cout << "FragTrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." << std::endl;
	a.beRepaired(5);
	std::cout << "FragTrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." <<std::endl;
	std::cout << "FragTrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;
	a.highFivesGuys();
	
	return (0);
}