#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure") {
	// std::cout << "[CURE] Default constructor" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
	// std::cout << "[CURE] Copy constructor" << std::endl;
}

Cure *Cure::clone() const { return new Cure(*this); }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &Cure::operator=(Cure const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Cure const &i) {
	o << "Type = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */