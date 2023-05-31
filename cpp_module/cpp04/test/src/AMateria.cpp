#include "AMateria.hpp"

AMateria::AMateria() {
	type = "AMateria";
	std::string msg = type + ": AMateria default constructor called";
	std::cout << msg << std::endl;
}

AMateria::~AMateria() {
	std::string msg = type + ": AMateria destructor called";
	std::cout << msg << std::endl;
}
