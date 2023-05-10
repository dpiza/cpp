#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T> void swap(T &lhs, T &rhs) {
	T tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template <typename T> T min(T const &lhs, T const &rhs) {
	return ((lhs < rhs) ? lhs : rhs);
}

template <typename T> T max(T const &lhs, T const &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

#endif
