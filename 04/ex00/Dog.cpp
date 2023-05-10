#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal() {
	std::cout << "[DOG] Default constructor" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal() {
	std::cout << "[DOG] Copy constructor" << std::endl;
	(void)src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() { std::cout << "[DOG] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Dog const &i) {
	o << "[DOG] Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const { std::cout << "[DOG] Bark Bark" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */