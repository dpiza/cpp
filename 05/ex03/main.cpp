#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Intern someRandomInter;
	AForm *form;

	std::cout << "someRandomInter.makeForm(\"robotomy request\", \"Bender\");"
			  << std::endl;
	try {
		form = someRandomInter.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		delete form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout
		<< "someRandomInter.makeForm(\"ShrubberyCreationForm\", \"Home\");"
		<< std::endl;
	try {
		form = someRandomInter.makeForm("ShrubberyCreationForm", "Home");
		std::cout << *form << std::endl << std::endl;
		delete form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "someRandomInter.makeForm(\"RobotomyRequestForm\", \"Ford "
				 "Prefect\");"
			  << std::endl;
	try {
		form = someRandomInter.makeForm("RobotomyRequestForm", "Ford Prefect");
		std::cout << *form << std::endl << std::endl;
		delete form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "someRandomInter.makeForm(\"PresidentialPardonForm\", "
				 "\"Arthur Dent\");"
			  << std::endl;
	try {
		form =
			someRandomInter.makeForm("PresidentialPardonForm", "Arthur Dent");
		std::cout << *form << std::endl << std::endl;
		delete form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}