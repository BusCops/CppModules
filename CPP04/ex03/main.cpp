#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"

int main ()
{
	AMateria *cure = new Cure();
	AMateria *ice = new Ice();
	ICharacter *jake = new Character("jake");

	jake->equip(cure);
	jake->equip(cure);
	jake->equip(ice);
	jake->equip(cure);
	jake->equip(ice);
	jake->unequip(12);
	jake->unequip(3);
	jake->equip(ice);
	jake->use(10, *jake);

	return 0;
}