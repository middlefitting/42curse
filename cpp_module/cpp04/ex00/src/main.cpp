#include "CoutUtil.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		CoutUtil::infoCout("/// Animal Tests ///");
		CoutUtil::infoCout("/** Animal Construct Tests **/");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Type Tests **/");
		CoutUtil::regularCout(meta->getType());
		CoutUtil::regularCout(j->getType());
		CoutUtil::regularCout(i->getType());
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Sound Tests **/");
		meta->makeSound();
		j->makeSound();
		i->makeSound();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Destruct Tests **/");
		delete meta;
		delete j;
		delete i;
		CoutUtil::regularCout("");
	}
	{
		CoutUtil::infoCout("/// WrongAnimal Tests ///");
		CoutUtil::infoCout("/** WrongAnimal Construct Tests **/");
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** WrongAnimal Type Tests **/");
		CoutUtil::warningCout(i->getType());
		CoutUtil::warningCout(i->getType());
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** WrongAnimal Sound Tests **/");
		meta->makeSound();
		i->makeSound();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** WrongAnimal Destruct Tests **/");
		delete meta;
		delete i;
		CoutUtil::regularCout("");
	}
	return 0;
}
