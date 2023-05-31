#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::string msg = type + ": Dog default constructor called";
	CoutUtil::regularCout(msg);
}

Dog::~Dog() {
	std::string msg = type + ": Dog destructor called";
	CoutUtil::regularCout(msg);

}

Dog::Dog(Dog const &dog) {
	std::string msg = type + ": Dog copy constructor called";
	CoutUtil::regularCout(msg);

	*this = dog;
}

Dog& Dog::operator=(Dog const &dog) {
	std::string msg = type + ": Dog copy assignment operator called";
	CoutUtil::regularCout(msg);
	type = dog.type;
	return *this;
}

void Dog::makeSound() const{
	std::string msg = type + ": Dog says bark";
	CoutUtil::regularCout(msg);
}
