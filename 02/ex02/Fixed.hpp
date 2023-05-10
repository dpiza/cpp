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
	Fixed(Fixed const &);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);

	Fixed &operator=(Fixed const &);

	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(Fixed const &rhs);
	Fixed operator/(Fixed const &rhs);

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &, Fixed &);
	static Fixed const &min(Fixed const &, Fixed const &);
	static Fixed &max(Fixed &, Fixed &);
	static Fixed const &max(Fixed const &, Fixed const &);

  private:
	int _rawBits;
	static const int _fBits = 8;

	int getValue(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* ************************************************** FIXED_H  */