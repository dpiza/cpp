#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string name, int const reqSign, int const reqExecute)
	: _name(name), _signed(false), _reqSign(validateGrade(reqSign)),
	  _reqExecute(validateGrade(reqExecute)) {}

Form::Form(const Form &src)
	: _name(src._name), _signed(false), _reqSign(src._reqSign),
	  _reqExecute(src._reqExecute) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i) {
	o << (i.getSigned() ? "SIGNED " : "NOT SIGNED ") << i.getName()
	  << " form, grade to sign: " << i.getReqSign()
	  << ", grade to execute: " << i.getReqExecute();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Form::validateGrade(int const grade) {
	if (grade < 1) {
		throw Form::GradeTooHighException();
	} else if (grade > 150) {
		throw Form::GradeTooLowException();
	}
	return grade;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getReqSign()) {
		this->_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is higher than allowed");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is lower than allowed");
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Form::getName(void) const { return this->_name; }
bool Form::getSigned(void) const { return this->_signed; }
int Form::getReqSign(void) const { return this->_reqSign; }
int Form::getReqExecute(void) const { return this->_reqExecute; }

/* ************************************************************************** */