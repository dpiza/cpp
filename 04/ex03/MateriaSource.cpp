#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() : IMateriaSource(), _poolIndex(0) {
	// std::cout << "[MATERIA_SOURCE] Default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource() {
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
	}
	for (int i = 0; i < this->_poolIndex; i++) {
		if (this->_pool[i] != NULL) {
			delete this->_pool[i];
		}
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = materia;
			return;
		}
	}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	AMateria *newMateria;

	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL &&
			type.compare(this->_inventory[i]->getType()) == 0) {
			newMateria = this->_inventory[i]->clone();
			this->_pool[_poolIndex++] = newMateria;
			return newMateria;
		}
	}
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */