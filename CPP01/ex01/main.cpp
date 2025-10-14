#include "Zombie.hpp"

int main()
{
	Zombie* zombies;
	int i = 0;
	int	n = 6;

	zombies = zombieHorde(n, "3alawi");
	while (i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return 0;
}
