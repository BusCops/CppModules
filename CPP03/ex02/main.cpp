#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("abdellah");

	a.attack("simo");
	a = b;
	a.attack("simo");
	a.takeDamage(50);
	a.takeDamage(70);
	a.beRepaired(100);
	a.highFivesGuys();
}
