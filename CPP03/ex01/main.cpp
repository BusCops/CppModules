#include "ScavTrap.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("abdellah");

	a.attack("simo");
	a = b;
	a.attack("simo");
	a.takeDamage(50);
	a.takeDamage(70);
	a.beRepaired(100);
	a.guardGate();
}
