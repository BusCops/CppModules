#include "Zombie.hpp"

int main()
{
	Zombie* zombies;
	int i = 0;
	int	n = 6;

	zombies = zombieHorde(n, "3alawi");
	if (!zombies)
		return 1;
	while (i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return 0;
}
