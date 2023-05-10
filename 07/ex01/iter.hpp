#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T *address, int len, void (*func)(const T &)) {
	for (int i = 0; i < len; i++) {
		func(address[i]);
	}
}

#endif