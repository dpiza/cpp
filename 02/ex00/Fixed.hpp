#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

  public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);

	Fixed &operator=(Fixed const &rhs);

  private:
	int _rawBits;
	static const int fBits = 8;

	int getValue(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* ************************************************** FIXED_H  */