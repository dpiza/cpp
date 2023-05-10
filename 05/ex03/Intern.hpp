#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
	class InvalidFormName : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string, std::string);

  private:
};

std::ostream &operator<<(std::ostream &o, Intern const &i);

#endif /* ********************************************************** INTERN_H  \
		*/