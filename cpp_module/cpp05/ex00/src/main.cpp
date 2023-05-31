#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"

int main()
{
	{
		CoutUtil::infoCout("/** Exception Tests **/\n");
		CoutUtil::infoCout("High Exception");
		try
		{
			Bureaucrat bureaucrat("David", 0);
			std::cout << &bureaucrat;
		}
		catch(const std::exception& e)
		{

			CoutUtil::errorCout(e.what());
		}

		try
		{
			Bureaucrat bureaucrat("Brian", 10);
			while (true)
			{
				std::cout << &bureaucrat;
				bureaucrat.incrementingGrade();
			}
		}
		catch(const std::exception& e)
		{

			CoutUtil::errorCout(e.what());
		}

		CoutUtil::infoCout("\nLow Exception");
		try
		{
			Bureaucrat bureaucrat("David", 151);
			std::cout << &bureaucrat;
		}
		catch(const std::exception& e)
		{

			CoutUtil::errorCout(e.what());
		}
		try
		{
			Bureaucrat bureaucrat("David", 140);
			while (true)
			{
				std::cout << &bureaucrat;
				bureaucrat.decrementingGrade();
			}
		}
		catch(const std::exception& e)
		{

			CoutUtil::errorCout(e.what());
		}
	}
	return (0);
}
