#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>

class Point {

  public:
	Point();
	Point(float const, float const);
	Point(Point const &src);
	~Point();

	Point &operator=(Point const &rhs);

	Fixed &getX(void) const;
	Fixed &getY(void) const;
	void setX(int);
	void setY(float);

  private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream &operator<<(std::ostream &o, Point const &i);

#endif /* *********************************************************** POINT_H  \
		*/