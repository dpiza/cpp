#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  public:
	Form(std::string, int const, int const);
	Form(Form const &src);
	~Form();

	Form &operator=(Form const &rhs);

	void beSigned(Bureaucrat const &bureaucrat);
	int validateGrade(int const);

	std::string const getName(void) const;
	bool getSigned(void) const;
	int getReqSign(void) const;
	int getReqExecute(void) const;

  private:
	std::string const _name;
	bool _signed;
	int const _reqSign;
	int const _reqExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H  \
		*/