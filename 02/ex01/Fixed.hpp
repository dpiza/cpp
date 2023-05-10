#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed {

  public:
	Fixed();
	Fixed(int const);
	Fixed(float const);
	Fixed(Fixed const &src);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);

	Fixed &operator=(Fixed const &rhs);

	float toFloat(void) const;
	int toInt(void) const;

  private:
	int _rawBits;
	static const int _fBits = 8;

	int getValue(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* ************************************************** FIXED_H  */