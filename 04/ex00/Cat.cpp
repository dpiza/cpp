#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal() {
	std::cout << "[CAT] Default constructor" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "[CAT] Copy constructor" << std::endl;
	(void)src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() { std::cout << "[CAT] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs) {
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

/* ************************************************************************** */