#pragma once

#include "AMateria.hpp"

class Cure: public AMateria {
	public:
	Cure();
	virtual ~Cure();
	Cure(Cure const &cure);
	virtual Cure& operator=(Cure const &cure);
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};
