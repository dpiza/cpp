#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &Point::operator=(Point const &rhs) {
	this->setX(rhs.getX().getRawBits());
	this->setY(rhs.getY().getRawBits());

	return *this;
}

std::ostream &operator<<(std::ostream &o, Point const &i) {
	o << i.getX() << ", " << i.getY();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed &Point::getX(void) const { return (Fixed &)this->_x; }

Fixed &Point::getY(void) const { return (Fixed &)this->_y; }

void Point::setX(int n) { this->getX().setRawBits(n); }

void Point::setY(float n) { this->getY().setRawBits(n); }

/* ************************************************************************** */