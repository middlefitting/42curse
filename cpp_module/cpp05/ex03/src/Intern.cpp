#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) { (void)src; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

AForm* Intern::createPresident(const std::string target) {
  return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobot(const std::string target) {
  return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubbery(const std::string target) {
  return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string form_to_create,
                        const std::string target_for_form) {
  std::string forms[] = {"presidential pardon", "robotomy request",
                         "shrubbery creation"};
  AForm* (*creaters[])(const std::string target) = {
      &createPresident, &createRobot, &createShrubbery};
  for (int i = 0; i < 3; i++) {
    if (form_to_create == forms[i]) {
      CoutUtil::regularCout("Intern creates " + form_to_create);
      return (creaters[i](target_for_form));
    }
  }
  CoutUtil::errorCout("Intern can't create " + form_to_create +
                      "because it doesn't exist");
  return NULL;
}
