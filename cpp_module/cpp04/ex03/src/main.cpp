#include "AMateria.hpp"
#include "Character.hpp"
#include "CoutUtil.hpp"
#include "Cure.hpp"
#include "Floar.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
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

	{
		Floar::gameStart();
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		for (int i = 0; i < 8; i ++) {
			AMateria* tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		me->use(0, *bob);
		me->use(0, *bob);
		me->use(4, *bob);
		me->use(5, *bob);
		for (int i = 0; i < 8; i ++) {
			AMateria* tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		Floar::finish();
		delete bob;
		delete me;
		delete src;
	}
}
