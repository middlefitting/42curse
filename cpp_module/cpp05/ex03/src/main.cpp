#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		{
			CoutUtil::infoCout("/** Intern Tests **/");

			Intern intern;

			CoutUtil::infoCout("Create Success");
			AForm *presidentialPardonForm = intern.makeForm("PresidentialPardonForm", "target1");
			AForm *robotomyRequestForm = intern.makeForm("RobotomyRequestForm", "target2");
			AForm *shrubberyCreationForm = intern.makeForm("ShrubberyCreationForm", "target3");
			presidentialPardonForm->beSigned(Bureaucrat("bureaucrat1", 1));
			presidentialPardonForm->execute(Bureaucrat("bureaucrat1", 1));
			robotomyRequestForm->beSigned(Bureaucrat("bureaucrat1", 1));
			robotomyRequestForm->execute(Bureaucrat("bureaucrat1", 1));
			shrubberyCreationForm->beSigned(Bureaucrat("bureaucrat1", 1));
			shrubberyCreationForm->execute(Bureaucrat("bureaucrat1", 1));
			delete presidentialPardonForm;
			delete robotomyRequestForm;
			delete shrubberyCreationForm;

			CoutUtil::infoCout("Create Failed");
			AForm *form = intern.makeForm("NotExistingForm", "target4");
			if (form)
			{
				CoutUtil::warningCout("Why exists?!");
				delete form;
			}
		}
	}
	return (0);
}
