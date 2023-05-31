#include "AMateria.hpp"

AMateria::AMateria() {
	type = "default";
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::AMateria(AMateria const &a_materia) {
	*this = a_materia;
}

AMateria& AMateria::operator=(AMateria const &a_materia) {
	this->type = a_materia.type;
	return *this;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::string msg = "default use function" + target.getName();
	CoutUtil::regularCout(msg);
}
