#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include <ctime>
// #include <cstdlib>
#include "CoutUtil.hpp"


Base * generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		default:
			return new C;
			break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		CoutUtil::regularCout("it is an instance of class A");
	else if (dynamic_cast<B*>(p) != NULL)
		CoutUtil::regularCout("it is an instance of class B");
	else if (dynamic_cast<C*>(p) != NULL)
		CoutUtil::regularCout("it is an instance of class C");
	else
		CoutUtil::warningCout("it is not an instance of any class");
}

void	identify(Base& p)
{

	try
	{
		(void)dynamic_cast<A&>(p);
		CoutUtil::regularCout("it is an instance of class A");
		return ;
	}
	catch (std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		CoutUtil::regularCout("it is an instance of class B");
		return ;
	}
	catch (std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		CoutUtil::regularCout("it is an instance of class C");
		return ;
	}
	catch (std::bad_cast& e) {}

	CoutUtil::warningCout("it is not an instance of any class");
}
