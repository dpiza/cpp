#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("Robotomy", 72, 45), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {
	o << (i.getSigned() ? "SIGNED " : "NOT SIGNED ") << i.getName()
	  << " form, grade to sign: " << i.getReqSign()
	  << ", grade to execute: " << i.getReqExecute();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::beExecuted() const {
	int time = std::time(NULL);
	std::cout << "Bzzzz Z Pzzzzz Zzzzzzz" << std::endl;
	if (time % 2) {
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	} else {
		std::cout << this->getTarget() << "'s robotization failed."
				  << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RobotomyRequestForm::getTarget(void) const { return this->_target; }

/* ************************************************************************** */