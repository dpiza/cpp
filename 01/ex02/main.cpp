#include <iostream>
#include <string>

int main(void) {
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "The memory address of the string variable:\t" << &stringVAR
			  << std::endl;
	std::cout << "The memory address held by stringPTR:\t\t" << stringPTR
			  << std::endl;
	std::cout << "The memory address held by string REF:\t\t" << &stringREF
			  << std::endl;

	std::cout << "The value of the string variable:\t\t" << stringVAR
			  << std::endl;
	std::cout << "The value pointed to by stringPTR:\t\t" << *stringPTR
			  << std::endl;
	std::cout << "The value pointed to by stringPTR:\t\t" << *&stringREF
			  << std::endl;
}