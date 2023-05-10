#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form *form;
	std::cout << "form = new Form(\"153-A\", 153, 1);" << std::endl;
	try {
		form = new Form("153-A", 153, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"-1-A\", -1, 1);" << std::endl;
	try {
		form = new Form("-1-A", -1, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"0-A\", 0, 1);" << std::endl;
	try {
		form = new Form("0-A", 0, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"153-B\", 1, 153);" << std::endl;
	try {
		form = new Form("153-B", 1, 153);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"-1-B\", 1, -1);" << std::endl;
	try {
		form = new Form("-1-A", -1, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"0-B\", 1, 0);" << std::endl;
	try {
		form = new Form("0-A", 0, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "form = new Form(\"143-A\", 143, 1);" << std::endl;
	try {
		form = new Form("143-A", 143, 1);
		std::cout << *form << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *john = 0;
	std::cout << "Bureaucrat *john;" << std::endl;
	std::cout << "john = new Bureaucrat(\"John\", 150);" << std::endl;
	try {
		john = new Bureaucrat("John", 150);
		std::cout << *john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << john << std::endl;
	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl << std::endl;
	delete john;

	std::cout << "john = new Bureaucrat(\"John\", 10);" << std::endl;
	try {
		john = new Bureaucrat("John", 10);
		std::cout << *john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << john << std::endl;
	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl << std::endl;
	delete john;

	std::cout << "john = new Bureaucrat(\"John\", 143);" << std::endl;
	try {
		john = new Bureaucrat("John", 143);
		std::cout << *john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << john << std::endl;
	std::cout << "john->signForm(*form);" << std::endl;
	john->signForm(*form);
	std::cout << *form << std::endl;
	delete john;
	delete form;
}