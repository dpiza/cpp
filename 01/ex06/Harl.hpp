#ifndef HARL_H
#define HARL_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

class Harl;
typedef void (Harl::*funcPtr)(void);

class Harl {
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void misc(void);
	funcPtr _getMember(std::string);

  public:
	Harl(void);
	~Harl(void);

	void complain(std::string);
};

#endif