#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		Bureaucrat();
		void gradeCheck(int grade) const;
		void setGrade(int grade);

	public:
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		virtual ~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		void incrementingGrade();
		void decrementingGrade();

		const std::string getName() const;
		int getGrade() const;
		void signForm(Form &form) const;

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat *bureaucrat);
