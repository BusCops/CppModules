#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    HP = 100;
    EP = 50;
    AD = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
    HP = 100;
    EP = 50;
    AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
        ClapTrap::operator = (other);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (HP > 0)
	{
		if (EP > 0)
		{
			std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AD << " point of damage!" << std::endl;
			EP--;
			std::cout << "ScavTrap " << name << " energy remaining -> " << EP << std::endl;
		}
		else
			std::cout << "Insufficient attack points" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " is already dead" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}
