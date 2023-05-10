#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {

  public:
	Data();
	Data(std::string, long);
	Data(Data const &src);
	~Data();

	Data &operator=(Data const &rhs);

	std::string getName(void) const;
	long getPhone(void) const;

  private:
	std::string _name;
	long _phone;
};

std::ostream &operator<<(std::ostream &o, Data const &i);

#endif /* ************************************************************ DATA_H  \
		*/