#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	Weapon *weapon;
	std::string name;

public:
	void attack();
	void setWeapon(Weapon &newWeapon);
	HumanB(std::string name);
};

#endif