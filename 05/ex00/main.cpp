#include "Bureaucrat.hpp"

int main() {
	std::cout << "Bureaucrat *John = new Bureaucrat(\"John\", 10);"
			  << std::endl;
	try {
		Bureaucrat *John = new Bureaucrat("John", 10);
		std::cout << *John << std::endl << std::endl;
		delete John;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat *John = new Bureaucrat(\"John\", 100);"
			  << std::endl;
	try {
		Bureaucrat *John = new Bureaucrat("John", 100);
		std::cout << *John << std::endl << std::endl;
		delete John;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Bureaucrat *John = new Bureaucrat(\"John\", 1000);"
			  << std::endl;
	try {
		Bureaucrat *John = new Bureaucrat("John", 1000);
		std::cout << *John << std::endl << std::endl;
		delete John;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Bureaucrat *John = new Bureaucrat(\"John\", -1);"
			  << std::endl;
	try {
		Bureaucrat *John = new Bureaucrat("John", -1);
		std::cout << *John << std::endl << std::endl;
		delete John;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Bureaucrat *John = new Bureaucrat(\"John\", 0);" << std::endl;
	try {
		Bureaucrat *John = new Bureaucrat("John", 0);
		std::cout << *John << std::endl << std::endl;
		delete John;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	Bureaucrat *John = 0;
	std::cout << "Bureaucrat *John;" << std::endl;
	std::cout << "John = new Bureaucrat(\"John\", 0);" << std::endl;
	try {
		John = new Bureaucrat("John", 0);
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << John << std::endl << std::endl;

	std::cout << "John = new Bureaucrat(\"John\", 150);" << std::endl;
	try {
		John = new Bureaucrat("John", 150);
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John address: " << John << std::endl;
	std::cout << "John->decrementGrade();" << std::endl;
	try {
		John->decrementGrade();
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	delete John;

	std::cout << "John = new Bureaucrat(\"John\", 1);" << std::endl;
	try {
		John = new Bureaucrat("John", 1);
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "John address: " << John << std::endl;
	std::cout << "John->incrementGrade();" << std::endl;
	try {
		John->incrementGrade();
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	delete John;

	std::cout << "John = new Bureaucrat(\"John\", 10);" << std::endl;
	try {
		John = new Bureaucrat("John", 10);
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "John address: " << John << std::endl;
	std::cout << "John->incrementGrade();" << std::endl;
	try {
		John->incrementGrade();
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "John->decrementGrade();" << std::endl;
	try {
		John->decrementGrade();
		std::cout << *John << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete John;
}