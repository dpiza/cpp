#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "[WANML] Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "[WANML] Copy constructor" << std::endl;
	(void)src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() { std::cout << "[WANML] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i) {
	o << "[WANML] Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound(void) const {
	std::cout << "[WANML] roi?" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType(void) const { return (this->_type); }

void WrongAnimal::setType(std::string type) { this->_type = type; }

/* ************************************************************************** */