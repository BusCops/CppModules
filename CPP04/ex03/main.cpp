#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"
#include <stdio.h>

void	mainTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	otherTest()
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	ICharacter *player = new Character("player1");
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(cure);
	src->learnMateria(ice);
	AMateria *tmp1 = src->createMateria("cure");
	AMateria *tmp2 = src->createMateria("ice");
	AMateria *tmp3 = src->createMateria("cure");
	AMateria *tmp4 = src->createMateria("ice");
	player->equip(tmp1);
	player->equip(tmp2);
	player->equip(tmp3);
	player->equip(tmp4);

	player->unequip(0);

	player->use(0, *player);
	player->use(1, *player);
	player->use(2, *player);
	player->use(3, *player);

	delete tmp1;
	delete ice;
	delete cure;
	delete src;
	delete player;
}

int main()
{
	//mainTest();
	otherTest();
}
