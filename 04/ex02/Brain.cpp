#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() { std::cout << "[BRAIN] Default constructor" << std::endl; }

Brain::Brain(const Brain &src) {
	std::cout << "[BRAIN] Copy" << std::endl;
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() { std::cout << "[BRAIN] Destructor" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "[BRAIN] Copy assignment" << std::endl;
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Brain const &i) {
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string *Brain::getIdeas(void) const {
	return (std::string *)&this->_ideas;
}

/* ************************************************************************** */