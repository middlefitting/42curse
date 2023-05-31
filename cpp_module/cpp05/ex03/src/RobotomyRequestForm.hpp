#pragma once

#include "AForm.hpp"
#include "CoutUtil.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		RobotomyRequestForm();
		void robotMsg() const;
		void drillingMsg() const;
		void successOrFailedMsg() const;

	public:
		RobotomyRequestForm(std::string name, std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &robotomyRequestForm);

		void execute(Bureaucrat const & executor) const;
};

