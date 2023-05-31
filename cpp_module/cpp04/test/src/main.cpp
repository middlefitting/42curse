#include "AMateria.hpp"
#include "Floar.hpp"

int main(void) {
	Floar::gameStart();
	AMateria *materia;
	for (int i = 0; i < 150; i++) {
		materia = new AMateria();
		Floar::dropFloar(materia);
	}
	Floar::finish();
	return (0);
}
