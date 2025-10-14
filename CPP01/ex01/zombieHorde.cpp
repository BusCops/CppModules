#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std :: string name)
{
	int		i = 0;
	Zombie	*zombies;
	
	zombies = new Zombie[N];
	while (i < N)
	{
		zombies[i].SetZombieName(name);
		i++;
	}
	return zombies;
}