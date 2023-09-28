#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    {
      CoutUtil::infoCout("/** Intern Tests **/");

      Intern intern;

      CoutUtil::infoCout("Create Success");
      AForm *presidentialPardonForm =
          intern.makeForm("presidential pardon", "target1");
      AForm *robotomyRequestForm =
          intern.makeForm("robotomy request", "target2");
      AForm *shrubberyCreationForm =
          intern.makeForm("shrubbery creation", "target3");
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
      if (form) {
        CoutUtil::warningCout("Why exists?!");
        delete form;
      }
    }
  }
  return (0);
}
