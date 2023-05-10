#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice") {
	// std::cout << "[ICE] Default constructor" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
	// std::cout << "[ICE] Copy constructor" << std::endl;
}

Ice *Ice::clone() const { return new Ice(*this); }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &Ice::operator=(Ice const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Ice const &i) {
	o << "Type = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */