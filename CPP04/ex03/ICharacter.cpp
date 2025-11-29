#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"
#include <stdio.h>

void	InistializeInventory(AMateria **inventory)
{
	for (int i = 0; i < 4;i++)
		inventory[i] = NULL;
}

Character::Character()
:name()
{
	InistializeInventory(inventory);
}

Character::Character(const std::string &name)
:name(name)
{
	InistializeInventory(inventory);
}

Character::Character(const Character &other)
{
	InistializeInventory(inventory);
	*this = other;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0;i < 4;i++)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = NULL;
		}

		for (int i = 0;i < 4;i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
		name = other.name;
	}
	return *this; 
}

Character::~Character()
{
	for( int i = 0;i < 4;i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}
std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	int i = 0;
	for(i = 0;i < 4;i++)
	{
		if (m == inventory[i])
			return ;
	}
	for(i = 0;i < 4 && inventory[i] != NULL;i++)
	{}
	if (i < 4)
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx > 4 || idx < 0 || inventory[idx] == NULL)
		return ;
	else
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 4 || idx < 0 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}