#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("default robot", 25, 5)
{
	target = "default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target)
: AForm(name, 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
: AForm(presidentialPardonForm)
{
	target = presidentialPardonForm.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	AForm::operator=(presidentialPardonForm);
	target = presidentialPardonForm.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	CoutUtil::regularCout(target + " has been pardoned by Zafod Beeblebrox");
}
