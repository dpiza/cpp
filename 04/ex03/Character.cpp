#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name) : ICharacter(), _name(name) {
	// std::cout << "[CHAR] String constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const ICharacter &src)
	: ICharacter(), _name(src.getName()) {
	// std::cout << "[CHAR] Copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = src.getMateria(i);
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &Character::operator=(ICharacter const &rhs) {
	// std::cout << "[CHAR] Asignment constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = rhs.getMateria(i);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Character const &i) {
	o << "Value = " << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool isValidIndex(int idx) {
	if (idx < 0 || idx > 3) {
		return false;
	}
	return true;
}

void Character::equip(AMateria *m) {
	if (m == NULL) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (isValidIndex(idx) && this->_inventory[idx] != NULL) {
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (isValidIndex(idx) && this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Character::getName(void) const { return this->_name; }

AMateria *Character::getMateria(int idx) const {
	if (isValidIndex(idx) && this->_inventory[idx] != NULL) {
		return this->_inventory[idx];
	}
	return NULL;
}

/* ************************************************************************** */