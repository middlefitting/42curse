#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::string msg = type + ":WrongCat default constructor called";
	CoutUtil::warningCout(msg);
}

WrongCat::~WrongCat() {
	std::string msg = type + ":WrongCat destructor called";
	CoutUtil::warningCout(msg);

}

WrongCat::WrongCat(WrongCat const &wrong_cat) {
	std::string msg = type + ":WrongCat copy constructor called";
	CoutUtil::warningCout(msg);

	*this = wrong_cat;
}

WrongCat& WrongCat::operator=(WrongCat const &wrong_cat) {
	std::string msg = type + ":WrongCat copy assignment operator called";
	CoutUtil::warningCout(msg);
	type = wrong_cat.type;
	return *this;
}

void WrongCat::makeSound() {
	std::string msg = type + ":WrongCat says wrong naewon";
	CoutUtil::warningCout(msg);
}
