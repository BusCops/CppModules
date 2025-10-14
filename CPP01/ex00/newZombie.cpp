#include "Zombie.hpp"

Zombie* newZombie(std :: string name)
{
	Zombie *z;

	z = new Zombie;
	z->SetZombieName(name);
	return z;
}