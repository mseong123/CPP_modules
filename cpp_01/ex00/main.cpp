#include "Zombie.hpp"

int	main(void) {
	Zombie *z = newZombie("newZombie");
	z->announce();
	randomChump("randomChumpZombie");
	delete z;
	
}