#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::string msg = type + ": Cat default constructor called";
	brain = new Brain("Cat's smart brain");
	CoutUtil::regularCout(msg);
}

Cat::~Cat() {
	std::string msg = type + ": Cat destructor called";
	CoutUtil::regularCout(msg);
	delete brain;
}

Cat::Cat(Cat const &cat) {
	std::string msg = type + ": Cat copy constructor called";
	CoutUtil::regularCout(msg);
	*this = cat;
}

Cat& Cat::operator=(Cat const &cat) {
	std::string msg = type + ": Cat copy assignment operator called";
	CoutUtil::regularCout(msg);
	type = cat.type;
	brain = cat.brain;
	return *this;
}

void Cat::makeSound() const {
	std::string msg = type + ": Cat says naewon";
	CoutUtil::regularCout(msg);
	brain->braingStorming();
}
