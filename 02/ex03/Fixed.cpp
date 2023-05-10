#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(int const intValue) {
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intValue << this->_fBits;
}

Fixed::Fixed(float const floatValue) {
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floatValue * (1 << this->_fBits));
}

Fixed::Fixed(const Fixed &src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

bool Fixed::operator>(Fixed const &rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(Fixed const &rhs) const {
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(Fixed const &rhs) {
	Fixed cpy(*this);

	cpy.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (cpy);
}

Fixed Fixed::operator-(Fixed const &rhs) {
	Fixed cpy(*this);

	cpy.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (cpy);
}

Fixed Fixed::operator*(Fixed const &rhs) {
	Fixed cpy(*this);

	cpy.setRawBits(this->getRawBits() * rhs.getRawBits() / (1 << this->_fBits));
	return (cpy);
}

Fixed Fixed::operator/(Fixed const &rhs) {
	Fixed cpy(*this);

	cpy.setRawBits(this->getRawBits() * (1 << this->_fBits) / rhs.getRawBits());
	return (cpy);
}

Fixed &Fixed::operator++(void) {
	this->setRawBits(this->_rawBits + 1);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed cpy(*this);
	this->setRawBits(this->_rawBits + 1);
	return (cpy);
}

Fixed &Fixed::operator--(void) {
	this->setRawBits(this->_rawBits - 1);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed cpy(*this);
	this->setRawBits(this->_rawBits - 1);
	return (cpy);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::toInt(void) const { return (this->_rawBits >> this->_fBits); }

float Fixed::toFloat(void) const {
	return this->_rawBits / (float)(1 << this->_fBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b) {
		return a;
	}
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b) {
		return a;
	}
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b) {
		return a;
	}
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b) {
		return a;
	}
	return b;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

/* ************************************************************************** */