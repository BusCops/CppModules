#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *zombies;
	if (N < 1)
		return NULL;
	Zombie *zombies = new Zombie[N];
	while (i < N)
	{
		zombies[i] = Zombie(name);
		i++;
	}
	return zombies;
}