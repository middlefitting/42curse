#include "Cure.hpp"

Cure::Cure() {
	type = "cure";
}

Cure::~Cure() {}

Cure::Cure(Cure const &cure) {
	*this = cure;
}

Cure& Cure::operator=(Cure const &cure) {
	this->type = cure.type;
	return *this;
}

void Cure::use(ICharacter& target) {
	std::string msg = "* heals " + target.getName() + "'s wounds *";
	CoutUtil::regularCout(msg);
}

Cure* Cure::clone() const {
	Cure *cure = new Cure();
	return cure;
}
