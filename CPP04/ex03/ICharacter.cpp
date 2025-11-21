#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"

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
		
		name = other.name;
	}
	return *this;
}

Character::~Character()
{}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	for(i = 0;inventory[i] != NULL && i < 4;i++)
	{}
	if (i < 4)
	{
		inventory[i] = m;
		std::cout << name << "equip a AMateria " << inventory[i]->getType() << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx > 4 || idx < 0 || inventory[idx] == NULL)
		return ;
	else
	{
		std::cout << name << "unequiped a AMateria " << inventory[idx]->getType() << std::endl; 
		inventory[idx] = NULL;
	}
}
	
void Character::use(int idx, ICharacter& target)
{
	if (idx > 4 || idx < 0 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}