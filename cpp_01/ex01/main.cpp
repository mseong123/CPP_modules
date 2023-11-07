#include "Zombie.hpp"

int	main(void) {
	int i = 0;
	int N = 5;

	Zombie *zH = zombieHorde( N, "zomzom" );
	while (i < N)
	{
		zH[i++].announce();
	}
	delete [] zH;
	return (0);
}