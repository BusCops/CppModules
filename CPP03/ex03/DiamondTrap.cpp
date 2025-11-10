#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("BusCops_clap_name")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    HP = 100;
    EP = 50;
    AD = 30;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    this->name = name;
    HP = 100;
    EP = 50;
    AD = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    name = other.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
        ClapTrap::operator = (other);
        name = other.name;
    }
	return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << " ClapTrap name: " << ClapTrap::name << std::endl;
}