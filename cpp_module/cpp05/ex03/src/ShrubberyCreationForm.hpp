#pragma once

#include <fstream>

#include "AForm.hpp"
#include "CoutUtil.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target;
  ShrubberyCreationForm();
  void drawTree() const;
  void openFile(std::ofstream &ofs) const;
  void drawLeaf(std::ofstream &ofs) const;
  void drawTrunk(std::ofstream &ofs) const;

  class FileOpenFailedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

 public:
  ShrubberyCreationForm(std::string target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
  ShrubberyCreationForm &operator=(
      const ShrubberyCreationForm &shrubberyCreationForm);

  void execute(Bureaucrat const &executor) const;
};
