#include "Animal.hpp"

Animal::Animal() {
	type = "Animal";
	std::string msg = type + ": Animal default constructor called";
	CoutUtil::regularCout(msg);
}

Animal::~Animal() {
	std::string msg = type + ": Animal destructor called";
	CoutUtil::regularCout(msg);

}

Animal::Animal(Animal const &animal) {
	std::string msg = type + ": Animal copy constructor called";
	CoutUtil::regularCout(msg);

	*this = animal;
}

Animal& Animal::operator=(Animal const &animal) {
	std::string msg = type + ": Animal copy assignment operator called";
	CoutUtil::regularCout(msg);
	type = animal.type;
	return *this;
}

void Animal::makeSound() const {
	std::string msg = type + ": Animal says hello animal world";
	CoutUtil::regularCout(msg);
}

std::string Animal::getType() const{
	return type;
}
