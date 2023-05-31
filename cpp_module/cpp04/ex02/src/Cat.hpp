#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal{
	private:
	Brain *brain;

	public:
	Cat();
	virtual ~Cat();
	Cat(Cat const &cat);
	Cat& operator=(Cat const &cat);
	virtual void makeSound() const;
};
