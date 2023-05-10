#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Animal") {
	std::cout << "[ANML] Default constructor" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "[ANML] Copy constructor" << std::endl;
	this->setType(src.getType());
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "[ANML] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "[ANML] Copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Animal const &i) {
	o << "[ANML] Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const { std::cout << "[ANML] Burp" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const { return (this->_type); }

void Animal::setType(std::string type) { this->_type = type; }

/* ************************************************************************** */