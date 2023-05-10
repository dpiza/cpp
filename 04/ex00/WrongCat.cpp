#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "[WCAT] Default constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	std::cout << "[WCAT] Copy constructor" << std::endl;
	(void)src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() { std::cout << "[WCAT] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, WrongCat const &i) {
	o << "[WCAT] Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound(void) const {
	std::cout << "[WCAT] oinc" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */