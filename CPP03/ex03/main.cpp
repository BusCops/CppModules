#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("abdellah");

	a.attack("simo");
	a = b;
	a.attack("simo");
	a.takeDamage(50);
	a.takeDamage(70);
	a.beRepaired(100);
	DiamondTrap c;
	b.whoAmI();
	b.attack("ramdani");
	b = c;
	b.whoAmI();
	c.guardGate();
}
