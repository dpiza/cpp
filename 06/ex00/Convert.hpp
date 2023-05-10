#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Convert {

  public:
	Convert();
	Convert(const std::string &);
	Convert(Convert const &src);
	~Convert();

	Convert &operator=(Convert const &rhs);

	double getValue(void) const;

	int identify(const std::string &);
	void convert(void);

	std::string toChar(void);
	std::string toInt(void);
	std::string toFloat(void);
	std::string toDouble(void);

  private:
	const std::string _str;
	double _raw;

	char _c;
	int _i;
	float _f;
	double _d;

	int _type;
};

std::ostream &operator<<(std::ostream &o, Convert const &i);

#define _INVALID 0
#define _CHAR 1
#define _INT 2
#define _FLOAT 3
#define _DOUBLE 4

#endif /* ********************************************************* CONVERT_H  \
		*/