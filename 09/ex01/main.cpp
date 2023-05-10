#include "RPN.hpp"

int main(int c, char **v) {
	if (c < 2) {
		std::cout << "Usage:\t./RPN \"N N op\"\n";
		std::cout << "\tN\t0-9\n\top\t+ - * /\n";
		return 1;
	}
	try {
		std::cout << RPN::execute(v[1]) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}