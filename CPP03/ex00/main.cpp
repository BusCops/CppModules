#include "ClapTrap.hpp"

unsigned int	sss(unsigned int c)
{
	unsigned int i = c;
	std::cout << i << std::endl;
	return i;
}

int main()
{
	ClapTrap a;

	a.attack("Wilson");
	a.takeDamage(5);
	a.attack("Wilson");
	a.beRepaired(10);
	a.takeDamage(1);
	a.takeDamage(20);
	a.attack("Wilson");
	a.beRepaired(10);
	int i = -50;
	std::cout << sss(i) << std::endl;
}
