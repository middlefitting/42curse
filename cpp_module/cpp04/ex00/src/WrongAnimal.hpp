#pragma once

#include <iostream>
#include "CoutUtil.hpp"

class WrongAnimal {
	protected:
	std::string type;

	public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal const &wrong_animal);
	WrongAnimal& operator=(WrongAnimal const &wrong_animal);
	void makeSound() const;
	std::string getType() const;
};
