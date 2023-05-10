#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal() {
	std::cout << "[CAT] Default constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "[CAT] Copy constructor" << std::endl;
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	delete this->_brain;
	std::cout << "[CAT] Destructor" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "[CAT] Copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Cat const &i) {
	o << "[CAT] Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const { std::cout << "[CAT] meow" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain Cat::getBrain(void) { return *this->_brain; }

/* ************************************************************************** */