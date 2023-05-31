#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	public:
	Dog();
	virtual ~Dog();
	Dog(Dog const &dog);
	Dog& operator=(Dog const &dog);
	virtual void makeSound() const;
};
