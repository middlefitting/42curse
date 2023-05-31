#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "CoutUtil.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;
		AMateria();
		AMateria(AMateria const &a_materia);
	 	AMateria& operator=(AMateria const &AMateria);
	public:
	virtual ~AMateria();
	AMateria(std::string const & type);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
