#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>
#include <string>

template <typename T> class MutantStack : public std::stack<T> {

  public:
	MutantStack<T>() : std::stack<T>(){};
	MutantStack<T>(MutantStack const &src) : std::stack<T>(src){};
	~MutantStack<T>(){};

	MutantStack<T> &operator=(MutantStack const &rhs) {
		std::stack<T>::operator=(rhs);
		return *this;
	};

	bool empty(void) { return std::stack<T>::empty(); }
	std::size_t size(void) const { return std::stack<T>::size(); }
	T &top(void) { return std::stack<T>::top(); }
	void push(T item) { std::stack<T>::push(item); }
	void pop(void) { std::stack<T>::pop(); }
	void swap(MutantStack &item) {
		MutantStack tmp(*this);
		*this = item;
		item = tmp;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };

  private:
};

template <typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> &i) {
	o << "MutantStack: [ ";
	for (size_t j = 0; j < i.size(); j++) {
		o << *(&i.top() - (i.size() - 1) + j) << " ";
	}
	o << "]";
	return o;
};

#endif /* ********************************************* MUTANTSTACK_H */
