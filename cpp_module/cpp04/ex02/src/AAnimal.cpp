#include "AAnimal.hpp"

AAnimal::AAnimal() {
	type = "AAnimal";
	std::string msg = type + ": AAnimal default constructor called";
	CoutUtil::regularCout(msg);
}

AAnimal::~AAnimal() {
	std::string msg = type + ": AAnimal destructor called";
	CoutUtil::regularCout(msg);

}

AAnimal::AAnimal(AAnimal const &a_animal) {
	std::string msg = type + ": AAnimal copy constructor called";
	CoutUtil::regularCout(msg);

	*this = a_animal;
}

AAnimal& AAnimal::operator=(AAnimal const &a_animal) {
	std::string msg = type + ": AAnimal copy assignment operator called";
	CoutUtil::regularCout(msg);
	type = a_animal.type;
	return *this;
}

std::string AAnimal::getType() const{
	return type;
}
