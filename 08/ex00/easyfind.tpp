#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T vector, int n) {
	typename T::iterator it;

	it = find(vector.begin(), vector.end(), n);
	if (it == vector.end()) {
		throw std::invalid_argument("Invalid argument");
	}
	return it;
}