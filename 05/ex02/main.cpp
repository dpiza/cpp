#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat *john = 0;
	std::cout << "Bureaucrat *john;" << std::endl;
	std::cout << "john = new Bureaucrat(\"John\", 25);" << std::endl;
	try {
		john = new Bureaucrat("John", 25);
		std::cout << *john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << john << std::endl << std::endl;

	AForm *form;
	std::cout << "form = new ShrubberyCreationForm(\"Home\");" << std::endl;
	try {
		form = new ShrubberyCreationForm("Home");
		std::cout << *form << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl;
	std::cout << "john->executeForm(*form);" << std::endl;
	john->executeForm(*form);
	std::cout << std::endl;
	delete form;

	std::cout << "form = new RobotomyRequestForm(\"Ford Prefect\");"
			  << std::endl;
	form = new RobotomyRequestForm("Ford Prefect");
	std::cout << *form << std::endl;
	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl;
	std::cout << "john->executeForm(*form);" << std::endl;
	john->executeForm(*form);
	std::cout << std::endl;
	delete form;

	std::cout << "form = new PresidentialPardonForm(\"Arthur Dent\");"
			  << std::endl;
	form = new PresidentialPardonForm("Arthur Dent");
	std::cout << *form << std::endl;
	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl;
	std::cout << "john->executeForm(*form);" << std::endl;
	john->executeForm(*form);
	delete form;
	delete john;
}