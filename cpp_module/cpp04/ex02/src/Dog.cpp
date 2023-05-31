#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::string msg = type + ": Dog default constructor called";
	brain = new Brain("Dog's cute brain");
	CoutUtil::regularCout(msg);
}

Dog::~Dog() {
	std::string msg = type + ": Dog destructor called";
	CoutUtil::regularCout(msg);
	delete brain;
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
	brain = dog.brain;
	return *this;
}

void Dog::makeSound() const{
	std::string msg = type + ": Dog says bark";
	CoutUtil::regularCout(msg);

	brain->braingStorming();
}
