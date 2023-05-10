#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {

  public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	void beExecuted(void) const;

	std::string getTarget(void) const;

  private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H  \
		*/