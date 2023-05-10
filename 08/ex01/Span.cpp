#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() {}

Span::Span(unsigned int n) : _nMax(n) {}

Span::Span(const Span &src) : _nMax(src.getNMax()) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->_nMax = rhs.getNMax();
		this->_vector.clear();
		for (std::size_t i = 0; i < this->getSize(); i++) {
			this->_vector[i] = rhs[i];
		}
	}
	return *this;
}

int Span::operator[](std::size_t index) const { return this->_vector[index]; }

std::ostream &operator<<(std::ostream &o, Span const &i) {
	o << "Span: [ ";
	for (unsigned int j = 0; j < i.getSize(); j++) {
		o << i[j] << " ";
		if (j == 10) {
			o << "... ] length: " << i.getSize();
			return o;
		}
	}
	o << "] length: " << i.getSize();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Span::longestSpan() {
	if (this->_vector.size() < 2) {
		throw std::length_error("Span list does not have enough data");
	}

	std::vector<int>::iterator min =
		std::min_element(this->_vector.begin(), this->_vector.end());
	std::vector<int>::iterator max =
		std::max_element(this->_vector.begin(), this->_vector.end());

	return (*max - *min);
}

int Span::shortestSpan() {
	if (this->_vector.size() < 2) {
		throw std::length_error("Span list does not have enough data");
	}

	std::vector<int> result;
	std::sort(this->_vector.begin(), this->_vector.end());
	std::adjacent_difference(this->_vector.begin(), this->_vector.end(),
							 std::back_inserter(result));

	std::sort(result.begin() + 1, result.end());

	return *(result.begin() + 1);
}

void Span::addNumber(int n) {
	if (this->_vector.size() == this->_nMax) {
		throw std::length_error("Span list is full");
	}
	this->_vector.push_back(n);
}

void Span::printList() {
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = this->_vector.end();

	for (it = this->_vector.begin(); it != ite; it++) {
		std::cout << *it << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getNMax(void) const { return this->_nMax; }

unsigned int Span::getSize(void) const { return this->_vector.size(); }

/* ************************************************************************** */