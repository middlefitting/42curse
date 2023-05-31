#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"

int main()
{
	{
		CoutUtil::infoCout("/** Exception Tests **/\n");
		///////////////////////////////
		CoutUtil::infoCout("High Exception");
		try
		{
			Form form_grade_to_high("MathForm", 0, 75);
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		try
		{
			Form execute_grade_to_high("MathForm", 75, -1);
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		///////////////////////////////
		CoutUtil::infoCout("Low Exception");
		try
		{
			Form form_grade_to_high("MathForm", 151, 75);
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		try
		{
			Form execute_grade_to_high("MathForm", 75, 20000);
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		///////////////////////////////
		CoutUtil::infoCout("/** Signed Tests **/");
		Form form("MathForm", 30, 75);
		Bureaucrat not_allow("Peter", 31);
		not_allow.signForm(form);
		Bureaucrat allow("Peter", 30);
		allow.signForm(form);
	}
	return (0);
}
