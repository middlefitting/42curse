#pragma once

#include "AMateria.hpp"

class Ice: public AMateria {
	public:
	Ice();
	virtual ~Ice();
	Ice(Ice const &ice);
	virtual Ice& operator=(Ice const &ice);
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};
