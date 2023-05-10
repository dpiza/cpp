#include "iter.hpp"
#include <iostream>

template <typename T> void print(T const &i) { std::cout << i << std::endl; }

int main(void) {
	int arrI[3] = {1, 2, 3};
	char arrC[3] = {'a', 'b', 'c'};

	iter(arrI, 3, print);
	iter(arrC, 3, print);
	return (0);
}