#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <string>

template <typename T> class Array {

  public:
	Array<T>() : _size(0) { this->_arr = new T[0]; }
	Array<T>(unsigned int n) : _size(n) { this->_arr = new T[n]; };
	Array<T>(Array<T> const &src) : _size(src._size) {
		this->_arr = new T[this->_size];
		*this = src;
	};

	~Array<T>() { delete[] this->_arr; };

	Array<T> &operator=(Array const &rhs) {
		if (this->_size != rhs._size) {
			this->_size = rhs._size;
			delete[] this->_arr;
			this->_arr = new T[this->_size];
		}
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_arr[i] = rhs._arr[i];
		}
		return (*this);
	};

	T &operator[](unsigned int const &index) const {
		if (index < 0 || index >= this->_size) {
			throw std::invalid_argument("invalid range");
		}
		return _arr[index];
	};

	unsigned int size() const { return this->_size; };

  private:
	T *_arr;
	unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &i) {
	o << "[ ";
	for (unsigned int j = 0; j < i.size(); j++) {
		o << i[j] << " ";
	}
	o << "]";
	return o;
};

#endif /* ***************************************************** ARRAY_TPP */