#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();

	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade--;
	}
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade++;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is higher than allowed");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is lower than allowed");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Bureaucrat::getName(void) const { return this->_name; }

int Bureaucrat::getGrade(void) const { return this->_grade; }

/* ************************************************************************** */