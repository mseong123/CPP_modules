#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie *zH = new Zombie[N];

	while (i < N)
		zH[i++].set_name(name);
	return (zH);
}