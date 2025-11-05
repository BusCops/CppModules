#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("abdellah");

	a.attack("simo");
	a = b;
	a.attack("simo");
}
