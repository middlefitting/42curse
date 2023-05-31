#include "CoutUtil.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	{
		CoutUtil::infoCout("/// Animal Tests ///");
		CoutUtil::infoCout("/** Animal Construct Tests **/");
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Type Tests **/");
		CoutUtil::regularCout(j->getType());
		CoutUtil::regularCout(i->getType());
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Sound Tests **/");
		j->makeSound();
		i->makeSound();
		CoutUtil::regularCout("");

		CoutUtil::infoCout("/** Animal Destruct Tests **/");
		delete j;
		delete i;
		CoutUtil::regularCout("");
	}
		{
		CoutUtil::infoCout("/// Animal Loop Tests ///");
		CoutUtil::infoCout("/** Animal Construct Tests **/");
		const AAnimal* animals[10];
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
