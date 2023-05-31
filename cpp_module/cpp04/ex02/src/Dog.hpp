#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
	private:
	Brain *brain;

	public:
	Dog();
	virtual ~Dog();
	Dog(Dog const &dog);
	Dog& operator=(Dog const &dog);
	virtual void makeSound() const;
};
