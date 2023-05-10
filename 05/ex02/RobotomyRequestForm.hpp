#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {

  public:
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	void beExecuted(void) const;

	std::string getTarget(void) const;

  private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H  \
		*/