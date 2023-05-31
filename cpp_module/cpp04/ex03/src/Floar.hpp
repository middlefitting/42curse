#pragma once

#include <iostream>
#include "AMateria.hpp"

class Floar {
	private:
	static AMateria* materias[100];
	static int idx;
	Floar();
	virtual ~Floar();
	Floar(Floar const &floar);
	Floar& operator=(Floar const &floar);

	public:
	static void gameStart();
	static void dropFloar(AMateria* materia);
	static void finish();
};
