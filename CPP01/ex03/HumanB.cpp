#include "HumanB.hpp"

void	HumanB :: attack()
{
	if (weapon)
		std :: cout << name << " attacks with their " << weapon->getType() << std :: endl;
}

void	HumanB :: setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

HumanB :: HumanB(std :: string n)
:weapon(NULL), name(n)
{}
