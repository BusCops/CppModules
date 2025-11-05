#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    HP = 100;
    EP = 100;
    AD = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called!" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    HP = 100;
    EP = 100;
    AD = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
        ClapTrap::operator = (other);
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requesting a high-five if you are not high enough !" << std::endl;
}