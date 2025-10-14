#include "Zombie.hpp"

Zombie :: ~Zombie()
{
	std :: cout << "Zombie Killed !" << std :: endl;
}

void	Zombie :: SetZombieName(std :: string Name)
{
	name = Name;
}

void	Zombie :: announce(void)
{
	std :: cout << name << ": BraiiiiiiinnnzzzZ..." << std :: endl;
}