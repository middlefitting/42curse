#include "Form.hpp"

Form::Form()
: name("DefaultForm"), grade_to_sign(150), grade_to_execute(150)
{
	is_signed = false;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	gradeCheck();
	is_signed = false;
}

Form::~Form() {}

Form::Form(const Form &form)
: name(form.name), grade_to_sign(form.grade_to_sign), grade_to_execute(form.grade_to_execute)
{
	this->is_signed = form.is_signed;
}

Form& Form::operator=(Form const &form)
{
	if (grade_to_sign >= form.grade_to_sign)
		this->is_signed = form.getIsSigned();
	return *this;
}

void Form::gradeCheck() const
{
	if (grade_to_sign > 150)
		throw Form::GradeTooLowException();
	if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150)
		throw Form::GradeTooLowException();
	if (grade_to_execute < 1)
		throw Form::GradeTooHighException();
}

const std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->is_signed;
}

int Form::getGradeToSign() const
{
	return this->grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

std::ostream &operator<<(std::ostream &os, Form *form)
{
	os << form->getName();
	os << ", form is signed: ";
	os << form->getIsSigned();
	os << ", form grade to sign: ";
	os << form->getGradeToSign();
	os << ", form grade to execute: ";
	os << form->getGradeToExecute();
	os << std::endl;
	return os;
}
