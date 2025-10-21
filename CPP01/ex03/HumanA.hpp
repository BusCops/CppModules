#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	Weapon &weapon;
	std::string name;

public:
	void attack();
	HumanA(std::string name, Weapon &first_weapon);
};

#endif