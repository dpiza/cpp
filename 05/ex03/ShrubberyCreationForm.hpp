#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {

  public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	void beExecuted(void) const;

	std::string getTarget(void) const;

  private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H  \
		*/