#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		{
			CoutUtil::infoCout("/** ShrubberyCreationForm Tests **/");

			ShrubberyCreationForm shrubberyCreationForm("shrubber", "target1");
			Bureaucrat test0("bure", 146);
			Bureaucrat test1("bure", 145);
			Bureaucrat test2("bure", 137);

			CoutUtil::infoCout("Signed Failed Exception");
			test0.signForm(shrubberyCreationForm);

			CoutUtil::infoCout("Not Signed Exception");
			test1.executeForm(shrubberyCreationForm);

			CoutUtil::infoCout("Grade Low To Execute Exception");
			test1.signForm(shrubberyCreationForm);
			test1.executeForm(shrubberyCreationForm);

			CoutUtil::infoCout("Execute Success");
			test2.executeForm(shrubberyCreationForm);
		}
		{
			CoutUtil::infoCout("\n/** RobotomyRequestForm Tests **/");

			RobotomyRequestForm robotomyRequestForm("robot", "target2");
			Bureaucrat test0("david", 73);
			Bureaucrat test1("david", 72);
			Bureaucrat test2("david", 45);

			CoutUtil::infoCout("Signed Failed Exception");
			test0.signForm(robotomyRequestForm);

			CoutUtil::infoCout("Not Signed Exception");
			test1.executeForm(robotomyRequestForm);

			CoutUtil::infoCout("Grade Low To Execute Exception");
			test1.signForm(robotomyRequestForm);
			test1.executeForm(robotomyRequestForm);

			CoutUtil::infoCout("Execute Success");
			for (int i = 0; i < 15; i++)
				test2.executeForm(robotomyRequestForm);
		}
		{
			CoutUtil::infoCout("\n/** PresidentialPardonForm Tests **/");

			PresidentialPardonForm presidentialPardonForm("presidential", "target3");
			Bureaucrat test0("peter", 26);
			Bureaucrat test1("peter", 25);
			Bureaucrat test2("peter", 5);

			CoutUtil::infoCout("Signed Failed Exception");
			test0.signForm(presidentialPardonForm);

			CoutUtil::infoCout("Not Signed Exception");
			test1.executeForm(presidentialPardonForm);

			CoutUtil::infoCout("Grade Low To Execute Exception");
			test1.signForm(presidentialPardonForm);
			test1.executeForm(presidentialPardonForm);

			CoutUtil::infoCout("Execute Success");
			test2.executeForm(presidentialPardonForm);
		}
	}
	return (0);
}
