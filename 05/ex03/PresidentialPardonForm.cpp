#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: AForm("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &src)
	: AForm("PresidentialPardon", 25, 5), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
	o << (i.getSigned() ? "SIGNED " : "NOT SIGNED ") << i.getName()
	  << " form, grade to sign: " << i.getReqSign()
	  << ", grade to execute: " << i.getReqExecute();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::beExecuted() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}

/* ************************************************************************** */