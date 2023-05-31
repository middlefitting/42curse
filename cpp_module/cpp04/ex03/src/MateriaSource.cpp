#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::memset(materias, 0, sizeof(materias));
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materias[i]) {
			delete materias[i];
			materias[i] = 0;
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &materia_source) {
	*this = materia_source;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &materia_source) {
	for (int i = 0; i < 4; i++) {
		if (materias[i]) {
			delete materias[i];
			materias[i] = 0;
		}
		if (materia_source.materias[i])
			materias[i] = materia_source.materias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!materias[i]) {
			materias[i] = m->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] && (materias[i]->getType() == type)) {
			return materias[i]->clone();
		}
	}
	return 0;
}
