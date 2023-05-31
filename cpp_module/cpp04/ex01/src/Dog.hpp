#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	private:
	Brain *brain;

	public:
	Dog();
	virtual ~Dog();
	Dog(Dog const &dog);
	Dog& operator=(Dog const &dog);
	virtual void makeSound() const;
};
