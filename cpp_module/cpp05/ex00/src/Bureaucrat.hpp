#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		Bureaucrat();
		void gradeCheck(int grade) const;
		void setGrade(int grade);

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
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		virtual ~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		void incrementingGrade();
		void decrementingGrade();

		const std::string getName() const;
		int getGrade() const;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat *bureaucrat);
