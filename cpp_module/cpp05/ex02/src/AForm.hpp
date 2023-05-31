#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

		virtual void gradeCheck() const;

	protected:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException:  public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException:  public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	public:
		AForm(const AForm &aForm);
		virtual AForm &operator=(const AForm &aForm);
		virtual ~AForm();

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm *aForm);
