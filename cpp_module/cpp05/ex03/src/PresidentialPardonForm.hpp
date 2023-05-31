#pragma once

#include "AForm.hpp"
#include "CoutUtil.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string name, std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &presidentialPardonForm);

		void execute(Bureaucrat const & executor) const;
};

