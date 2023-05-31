#include "Bureaucrat.hpp"
#include "CoutUtil.hpp"

Bureaucrat::Bureaucrat()
: name("DefaultBureaucrat")
{
	setGrade(75);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
{
	this->grade = grade;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
: name(bureaucrat.name)
{
	setGrade(bureaucrat.grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	setGrade(bureaucrat.grade);
	return *this;
}

void Bureaucrat::gradeCheck(int grade) const
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::setGrade(int grade)
{
	gradeCheck(grade);
	this->grade = grade;
}

void Bureaucrat::incrementingGrade()
{
	gradeCheck(grade - 1);
	this->grade -= 1;
}

void Bureaucrat::decrementingGrade()
{
	gradeCheck(grade + 1);
	this->grade += 1;
}


const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade must not higher than 1";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade must not lower than 150";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat *bureaucrat)
{
	os << bureaucrat->getName();
	os << ", bureaucrat grade ";
	os << bureaucrat->getGrade();
	os << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &form) const
{
	std::string msg;

	try
	{
		form.beSigned(*this);
		msg = this->name + " signed " + form.getName();
		CoutUtil::regularCout(msg);
	}
	catch(const std::exception& e)
	{
		msg = this->name + " couldn’t sign " + form.getName() + " because " + e.what();
		CoutUtil::errorCout(msg);
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	std::string msg;

	try
	{
		form.execute(*this);
		msg = this->name + " execute " + form.getName();
		CoutUtil::regularCout(msg);
	}
	catch(const std::exception& e)
	{
		msg = this->name + " execute failed " + form.getName() + " because " + e.what();
		CoutUtil::errorCout(msg);
	}
}
