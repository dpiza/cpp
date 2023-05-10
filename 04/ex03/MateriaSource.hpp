#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource {

  public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &rhs);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

  private:
	AMateria *_inventory[4];
	AMateria *_pool[10];
	int _poolIndex;
};

#endif /* *************************************************** MATERIASOURCE_H  \
		*/