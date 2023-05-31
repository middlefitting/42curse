#include "Character.hpp"

Character::Character(): name("Default") {
	std::memset(materias, 0, sizeof(materias));
}

Character::Character(std::string name): name(name) {
	std::memset(materias, 0, sizeof(materias));
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (materias[i]) {
			delete materias[i];
			materias[i] = 0;
		}
	}
}

Character::Character(Character const &character) {
	*this = character;
}

Character& Character::operator=(Character const &character) {
	for (int i = 0; i < 4; i++)
	{
		if (materias[i]) {
			delete materias[i];
			materias[i] = 0;
		}
		if (character.materias[i])
			materias[i] = character.materias[i]->clone();
	}
	return *this;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!materias[i]) {
			materias[i] = m;
			return ;
		}
	}
	Floar::dropFloar(m);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 4)
		return ;
	if (materias[idx])
	{
		Floar::dropFloar(materias[idx]);
		materias[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		return ;
	if (materias[idx]) {
		materias[idx]->use(target);
		delete materias[idx];
		materias[idx] = 0;
	}
}

std::string const & Character::getName() const {
	return name;
}
