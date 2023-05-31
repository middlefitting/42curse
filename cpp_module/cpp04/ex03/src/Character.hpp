#pragma once

#include "ICharacter.hpp"
#include "Floar.hpp"

class Character: public ICharacter {
	private:
	AMateria* materias[4];
	std::string const name;

	public:
	virtual ~Character();
	Character();
	Character(std::string name);
	Character(Character const &character);
	Character& operator=(Character const &character);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};
