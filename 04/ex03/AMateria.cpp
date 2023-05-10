#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("void") {
	// std::cout << "[A_MATERIA] Default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	// std::cout << "[A_MATERIA] Type constructor" << std::endl;
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
	// std::cout << "[A_MATERIA] Copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &AMateria::operator=(AMateria const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, AMateria const &i) {
	o << "Value = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &AMateria::getType(void) const { return this->_type; }

/* ************************************************************************** */