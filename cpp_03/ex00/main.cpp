#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap claptrap;
	ClapTrap a("A");
	ClapTrap copyA(a);
	ClapTrap assignA("AssignA");
	assignA = a;

	std::cout << claptrap.getname() << std::endl;
	std::cout << claptrap.gethitpoints() << " hitpoints" << std::endl;
	std::cout << claptrap.getenergypoints() << " energy points" << std::endl;
	std::cout << claptrap.getattackdamage() << " attack damage" << std::endl;
	
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

	a.attack("Claptrap2");
	std::cout << "Claptrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;
	a.takeDamage(5);
	std::cout << "Claptrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." << std::endl;
	a.beRepaired(5);
	std::cout << "Claptrap " << a.getname() << " has " << a.gethitpoints() << " hitpoints left." <<std::endl;
	std::cout << "Claptrap " << a.getname() << " has " << a.getenergypoints() << " energy points left." << std::endl;

	return (0);
}