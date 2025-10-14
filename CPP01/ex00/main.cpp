#include "Zombie.hpp"

int main()
{
	Zombie *z = newZombie("simo");
	z->announce();
	delete z;
	randomChump("walo");
	return 0;
}