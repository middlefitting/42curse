#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
	AMateria* materias[4];

	public:
	virtual ~MateriaSource();
	MateriaSource();
	MateriaSource(MateriaSource const &materia_source);
	MateriaSource& operator=(MateriaSource const &materia_source);

	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type);
};
