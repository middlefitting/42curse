#pragma once

#include <iostream>
#include "CoutUtil.hpp"

class Animal {
	protected:
	std::string type;

	public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &animal);
	Animal& operator=(Animal const &animal);
	virtual void makeSound() const;
	std::string getType() const;
};
