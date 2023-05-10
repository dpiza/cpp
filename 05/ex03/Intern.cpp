#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i) {
	(void)i;
	o << "Intern";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string list[] = {"ShrubberyCreationForm", "RobotomyRequestForm",
						  "PresidentialPardonForm"};
	AForm *formPtr;
	int index;
	for (index = 0; index < 3; index++) {
		if (formName.compare(list[index]) == 0) {
			break;
		}
	}
	switch (index) {
	case 0:
		formPtr = new ShrubberyCreationForm(target);
		break;
	case 1:
		formPtr = new RobotomyRequestForm(target);
		break;
	case 2:
		formPtr = new PresidentialPardonForm(target);
		break;
	default:
		throw Intern::InvalidFormName();
	}
	std::cout << "Intern creates " << formName << std::endl;
	return formPtr;
}

const char *Intern::InvalidFormName::what() const throw() {
	return ("Form name is invalid");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */