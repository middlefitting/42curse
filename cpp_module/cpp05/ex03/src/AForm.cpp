#include "AForm.hpp"

AForm::AForm()
: name("DefaultAForm"), grade_to_sign(150), grade_to_execute(150)
{
	is_signed = false;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	gradeCheck();
	is_signed = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm &aForm)
: name(aForm.name), grade_to_sign(aForm.grade_to_sign), grade_to_execute(aForm.grade_to_execute)
{
	this->is_signed = aForm.is_signed;
}

AForm& AForm::operator=(AForm const &aForm)
{
	if (grade_to_sign >= aForm.grade_to_sign)
		this->is_signed = aForm.getIsSigned();
	return *this;
}

void AForm::gradeCheck() const
{
	if (grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	if (grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	if (grade_to_execute < 1)
		throw AForm::GradeTooHighException();
}

const std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->is_signed;
}

int AForm::getGradeToSign() const
{
	return this->grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "form is not signed";
}

std::ostream &operator<<(std::ostream &os, AForm *Aform)
{
	os << Aform->getName();
	os << ", Aform is signed: ";
	os << Aform->getIsSigned();
	os << ", Aform grade to sign: ";
	os << Aform->getGradeToSign();
	os << ", Aform grade to execute: ";
	os << Aform->getGradeToExecute();
	os << std::endl;
	return os;
}
