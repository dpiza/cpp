#include "Megaphone.hpp"

int main(int argc, char **argv) {
	std::string amplified;
	int i = 1;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		while (i < argc) {
			amplified = megaphone(argv[i]);
			std::cout << amplified;
			i++;
		}
		std::cout << std::endl;
	}

	return (0);
}