#include "Convert.hpp"

int main(int c, char *v[]) {
	if (c != 2) {
		std::cout << "Invalid argument" << std::endl;
		exit(1);
	}
	const std::string str(v[1]);
	Convert input(str);

	std::cout << "Char: \t\t" << input.toChar() << std::endl;
	std::cout << "Int: \t\t" << input.toInt() << std::endl;
	std::cout << "Float: \t\t" << input.toFloat() << std::endl;
	std::cout << "Double: \t" << input.toDouble() << std::endl;
	return (0);
}
