#include "Floar.hpp"

AMateria* Floar::materias[100];

int Floar::idx = 0;

Floar::Floar() {}

Floar::~Floar() {}

Floar::Floar(Floar const &floar) {
	*this = floar;
}

Floar& Floar::operator=(Floar const &floar) {
	(void) floar;
	return *this;
}

void Floar::gameStart() {
	std::memset(Floar::materias, 0, sizeof(Floar::materias));
}

void Floar::dropFloar(AMateria* materia) {
	if (idx < 100) {
		materias[idx] = materia;
		idx++;
	}
	else {
		delete materias[0];
		for (int i = 1; i < 100; i++)
			materias[i - 1] = materias[i];
		materias[99] = materia;
	}
}

void Floar::finish() {
	for (int i = 0; i < idx; i ++) {
		delete materias[i];
		materias[i] = 0;
	}
	idx = 0;
}

