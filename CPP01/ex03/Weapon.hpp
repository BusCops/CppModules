#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private :
		std :: string type;
	public :
		const	std :: string& getType() const;
		void	setType(std :: string weapontype);
		Weapon(std :: string Weapontype);
};

#endif