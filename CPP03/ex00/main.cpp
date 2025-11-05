#include "ClapTrap.hpp"

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
}
