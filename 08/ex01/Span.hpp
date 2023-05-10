#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

class Span {

  public:
	Span();
	Span(unsigned int);
	Span(Span const &src);
	~Span();

	void addNumber(int);
	int shortestSpan();
	int longestSpan();

	void printList();

	Span &operator=(Span const &rhs);
	int operator[](std::size_t size) const;

	unsigned int getNMax(void) const;
	unsigned int getSize(void) const;

	template <typename T> void addManyNumbers(T x, T y) {
		if (this->_vector.size() + iterLen(x, y) <= this->getNMax()) {
			std::vector<int>::iterator it = this->_vector.begin();
			this->_vector.insert(it + this->_vector.size(), x, y);
		} else {
			throw std::length_error("Span is not big enough");
		}
	}

	template <typename T> std::size_t iterLen(T x, T y) {
		std::size_t size = 0;
		while (x++ != y) {
			size++;
		}
		return size;
	}

  private:
	std::vector<int> _vector;
	unsigned int _nMax;
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif /* **************************************************** SPAN_H */