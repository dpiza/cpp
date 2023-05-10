#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal() {
	std::cout << "[DOG] Default constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "[DOG] Copy" << std::endl;
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	delete this->_brain;
	std::cout << "[DOG] Destructor" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "[DOG] Copy assignment" << std::endl;
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

Brain Dog::getBrain(void) { return *this->_brain; }

/* ************************************************************************** */