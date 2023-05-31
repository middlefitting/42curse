#include "Ice.hpp"

Ice::Ice() {
	type = "ice";
}

Ice::~Ice() {}

Ice::Ice(Ice const &ice) {
	*this = ice;
}

Ice& Ice::operator=(Ice const &ice) {
	this->type = ice.type;
	return *this;
}

void Ice::use(ICharacter& target) {
	std::string msg = "* shoots an ice bolt at " + target.getName() + " *";
	CoutUtil::regularCout(msg);
}

Ice* Ice::clone() const {
	Ice *ice = new Ice();
	return ice;
}
