#include "Megaphone.hpp"

std::string megaphone(std::string str) {
	std::string amplified;
	int i = -1;

	amplified = str.substr();

	while (str[++i])
		amplified[i] = toupper(str[i]);

	return amplified;
}
