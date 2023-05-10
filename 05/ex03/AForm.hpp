#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
  protected:
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  public:
	AForm(std::string, int const, int const);
	AForm(AForm const &src);
	virtual ~AForm();

	AForm &operator=(AForm const &rhs);

	void execute(Bureaucrat const &executor) const;

	virtual void beExecuted(void) const;
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

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* ************************************************************ FORM_H  \
		*/