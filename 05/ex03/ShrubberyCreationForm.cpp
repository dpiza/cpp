#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("Shrubbery", 145, 137), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {
	o << (i.getSigned() ? "SIGNED " : "NOT SIGNED ") << i.getName()
	  << " form, grade to sign: " << i.getReqSign()
	  << ", grade to execute: " << i.getReqExecute();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::beExecuted() const {
	std::ofstream outputFile;
	std::string fileName = this->getTarget();
	fileName.append("_shrubbery");
	outputFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	outputFile << "               ,@@@@@@@," << std::endl;
	outputFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outputFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outputFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outputFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outputFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outputFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outputFile << "       |o|        | |         | |" << std::endl;
	outputFile << "       |.|        | |         | |" << std::endl;
	outputFile << "  \\_\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

/* ************************************************************************** */