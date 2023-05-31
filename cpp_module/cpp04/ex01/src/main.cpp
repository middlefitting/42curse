#include "CoutUtil.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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
		CoutUtil::infoCout("/// Animal Loop Tests ///");
		CoutUtil::infoCout("/** Animal Construct Tests **/");
		const Animal* animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		CoutUtil::regularCout("");


		CoutUtil::infoCout("/** Animal Type Tests **/");
		for (int i = 0; i < 10; i++)
			CoutUtil::regularCout(animals[i]->getType());
		CoutUtil::regularCout("");


		CoutUtil::infoCout("/** Animal Sound Tests **/");
		for (int i = 0; i < 10; i++)
		{
			animals[i]->makeSound();
			CoutUtil::regularCout("");
		}
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Destruct Tests **/");
		for (int i = 0; i < 10; i++)
		{
			delete animals[i];
			CoutUtil::regularCout("");
		}
		CoutUtil::regularCout("");
	}
	return 0;
}
