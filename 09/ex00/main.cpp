#include "BitcoinExchange.hpp"
#include <iostream>

int main(int c, char **v) {
	if (c != 2) {
		std::cout << "Usage:\t\t./btc input.txt" << std::endl;
		return 1;
	}
	BitcoinExchange btc("data.csv");
	try {
		btc.calculate(v[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
		return 1;
	}
	return 0;
}