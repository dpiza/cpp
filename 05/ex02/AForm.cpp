#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(std::string name, int const reqSign, int const reqExecute)
	: _name(name), _signed(false), _reqSign(validateGrade(reqSign)),
	  _reqExecute(validateGrade(reqExecute)) {}

AForm::AForm(const AForm &src)
	: _name(src._name), _signed(false), _reqSign(src._reqSign),
	  _reqExecute(src._reqExecute) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i) {
	o << (i.getSigned() ? "SIGNED " : "NOT SIGNED ") << i.getName()
	  << " form, grade to sign: " << i.getReqSign()
	  << ", grade to execute: " << i.getReqExecute();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int AForm::validateGrade(int const grade) {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
	return grade;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getReqSign()) {
		this->_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::beExecuted(void) const {}

void AForm::execute(Bureaucrat const &executor) const {
	if (this->getReqExecute() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (!this->getSigned()) {
		throw AForm::FormNotSigned();
	}
	std::cout << executor.getName() << " executed " << this->getName()
			  << std::endl;
	this->beExecuted();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is higher than allowed");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is lower than allowed");
}

const char *AForm::FormNotSigned::what() const throw() {
	return ("Form is not yet signed");
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const AForm::getName(void) const { return this->_name; }
bool AForm::getSigned(void) const { return this->_signed; }
int AForm::getReqSign(void) const { return this->_reqSign; }
int AForm::getReqExecute(void) const { return this->_reqExecute; }

/* ************************************************************************** */