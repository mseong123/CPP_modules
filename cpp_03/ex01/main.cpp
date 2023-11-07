#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap scavtrap;
	ScavTrap a("A");
	ScavTrap copyA(a);
	ScavTrap assignA("AssignA");
	assignA = a;

	std::cout << scavtrap.getname() << std::endl;
	std::cout << scavtrap.gethitpoints() << " hitpoints" << std::endl;
	std::cout << scavtrap.getenergypoints() << " energy points" << std::endl;
	std::cout << scavtrap.getattackdamage() << " attack damage" << std::endl;

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

	a.attack("Scavtrap2");
	std::cout << "Scavtrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;
	a.takeDamage(5);
	std::cout << "Scavtrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." << std::endl;
	a.beRepaired(5);
	std::cout << "Scavtrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." <<std::endl;
	std::cout << "Scavtrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;
	a.guardGate();
	
	return (0);
}