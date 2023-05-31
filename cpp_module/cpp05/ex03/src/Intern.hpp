#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		static AForm *createPresident(const std::string target);
		static AForm *createRobot(const std::string target);
		static AForm *createShrubbery(const std::string target);

	public:
		Intern();
		Intern(const Intern &src);

		~Intern();

		Intern &operator=(const Intern &src);

		AForm	*makeForm(const std::string form_to_create, const std::string target_for_form);
};
