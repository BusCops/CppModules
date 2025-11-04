#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:name("BusCops"), HP(10), EP(10), AD(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
:name(name), HP(10), EP(10), AD(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
}
	
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		HP = other.HP;
		EP = other.EP;
		AD = other.AD;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HP > 0)
	{
		if (EP > 0)
		{
			std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AD << " point of damage!" << std::endl;
			EP--;
			std::cout << "ClapTrap " << name << " energy remaining -> " << EP << std::endl;
		}
		else
			std::cout << "Insufficient attack points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HP > 0)
	{
		std::cout << "ClapTrap " << name << " took damage of the amount " << amount << std::endl;
		HP -= amount;
		if (HP > 0)
			std::cout << "ClapTrap " << name << " HP points remaining -> " << HP << std::endl;
		else
		{
			std::cout << "ClapTrap " << name << " Died" << std::endl;
			HP = 0;
		}
	}
	else
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EP > 0 && HP > 0)
	{
		std::cout << "ClapTrap " << name << " regains " << amount << " of hit points" << std::endl;
		EP--;
		HP += amount;
		std::cout << "ClapTrap " << name << " EP points remaining -> " << EP << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
}