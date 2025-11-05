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

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}
