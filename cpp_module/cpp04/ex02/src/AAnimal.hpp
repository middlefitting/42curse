#pragma once

#include <iostream>
#include "CoutUtil.hpp"

class AAnimal {
	protected:
	std::string type;
	AAnimal();

	public:
	virtual ~AAnimal();
	AAnimal(AAnimal const &aanimal);
	AAnimal& operator=(AAnimal const &aanimal);
	virtual void makeSound() const = 0;
	std::string getType() const;
};
