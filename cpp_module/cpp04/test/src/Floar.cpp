#include "Floar.hpp"

AMateria* Floar::materiases[100];
int Floar::idx = 0;

Floar::Floar() {}

void Floar::gameStart() {
	std::memset(Floar::materiases, 0, sizeof(Floar::materiases));
}

void Floar::dropFloar(AMateria* materias) {
	if (idx < 100) {
		materiases[idx] = materias;
		idx++;
	}
	else {
		delete materiases[0];
		for (int i = 1; i < 100; i++)
			materiases[i - 1] = materiases[i];
		materiases[99] = materias;
	}
}

void Floar::finish() {
	for (int i = 0; i < idx; i ++) {
		delete materiases[i];
	}
}

Floar::~Floar() {}
