#include "ScavTrap.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("abdellah");

	a.attack("simo");
	a = b;
	a.attack("simo");
	a.guardGate();
}
