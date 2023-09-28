#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("default shrubbery", 145, 137) {
  target = "default target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
  this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &shrubberyCreationForm)
    : AForm(shrubberyCreationForm) {
  target = shrubberyCreationForm.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &shrubberyCreationForm) {
  AForm::operator=(shrubberyCreationForm);
  target = shrubberyCreationForm.target;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  drawTree();
}

void ShrubberyCreationForm::drawTree() const {
  std::ofstream ofs;
  openFile(ofs);
  drawLeaf(ofs);
  drawTrunk(ofs);
  ofs.close();
}

void ShrubberyCreationForm::openFile(std::ofstream &ofs) const {
  ofs.open((target + "_shrubbery").c_str());
  if (ofs.fail()) throw std::ios_base::failure("Error opening file");
}

void ShrubberyCreationForm::drawLeaf(std::ofstream &ofs) const {
  for (int i = 0; i < 20; i++) {
    for (int j = 20 - i; j > 0; j--) ofs << " ";
    for (int k = 0; k < (i + 1) * 2 - 1; k++) ofs << "*";
    ofs << std::endl;
  }
}

void ShrubberyCreationForm::drawTrunk(std::ofstream &ofs) const {
  for (int i = 0; i < 2; i++) {
    for (int j = 20; j > 0; j--) ofs << " ";
    ofs << "|";
    ofs << std::endl;
  }
}

const char *ShrubberyCreationForm::FileOpenFailedException::what() const
    throw() {
  return "file open failed";
}
