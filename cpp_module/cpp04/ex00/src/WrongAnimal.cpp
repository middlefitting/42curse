#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "WrongAnimal";
	std::string msg = type + ": WrongAnimal default constructor called";
	CoutUtil::warningCout(msg);
}

WrongAnimal::~WrongAnimal() {
	std::string msg = type + ": WrongAnimal destructor called";
	CoutUtil::warningCout(msg);

}

WrongAnimal::WrongAnimal(WrongAnimal const &wrong_animal) {
	std::string msg = type + ": WrongAnimal copy constructor called";
	CoutUtil::warningCout(msg);

	*this = wrong_animal;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &wrong_animal) {
	std::string msg = type + ": WrongAnimal copy assignment operator called";
	CoutUtil::warningCout(msg);
	type = wrong_animal.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::string msg = type + ": WrongAnimal says hello WrongAnimal world";
	CoutUtil::warningCout(msg);
}

std::string WrongAnimal::getType() const {
	return type;
}
