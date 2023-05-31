#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(WrongCat const &wrong_cat);
	WrongCat& operator=(WrongCat const &wrong_cat);
	void makeSound();
};
