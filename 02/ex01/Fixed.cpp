#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(int const intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intValue << this->_fBits;
}

Fixed::Fixed(float const floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floatValue * (1 << this->_fBits));
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const {
	return this->_rawBits / (float)(1 << this->_fBits);
}

int Fixed::toInt(void) const { return (this->_rawBits >> this->_fBits); }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

/* ************************************************************************** */