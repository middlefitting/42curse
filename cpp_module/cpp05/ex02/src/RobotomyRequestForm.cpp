#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default robot", 72, 45) {
  target = "default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
  this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(
    const RobotomyRequestForm &robotomyRequestForm)
    : AForm(robotomyRequestForm) {
  target = robotomyRequestForm.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &robotomyRequestForm) {
  AForm::operator=(robotomyRequestForm);
  target = robotomyRequestForm.target;
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  robotMsg();
}

void RobotomyRequestForm::robotMsg() const {
  drillingMsg();
  successOrFailedMsg();
}

void RobotomyRequestForm::drillingMsg() const {
  CoutUtil::regularCout("DRLLLLLLLLLLLLLLLLLL!!!!");
}

void RobotomyRequestForm::successOrFailedMsg() const {
  if (std::rand() % 2)
    CoutUtil::regularCout(target + " has been robotomized success");
  else
    CoutUtil::warningCout("Robotomization of " + target + " has failed!");
}
