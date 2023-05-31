#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

		Form();
		void gradeCheck() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	public:
		Form(const Form &form);
		Form &operator=(const Form &form);
		virtual ~Form();

		Form(std::string name, int grade_to_sign, int grade_to_execute);

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &os, Form *form);
