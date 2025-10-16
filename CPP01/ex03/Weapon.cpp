#include "Weapon.hpp"

Weapon :: Weapon(std :: string Weapontype)
{
	type = Weapontype;
}

const std :: string&  Weapon :: getType() const
{
	return type;
}

void	Weapon :: setType(std :: string weapontype)
{
	type = weapontype;
}