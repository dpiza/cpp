#ifndef BTC_HPP
#define BTC_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {

  public:
	BitcoinExchange();
	BitcoinExchange(std::string);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();

	void printDb();
	void calculate(std::string fileName);

	size_t dbSize() const;

	BitcoinExchange &operator=(BitcoinExchange const &rhs);

  private:
	std::map<std::string, float> _db;

	void loadDb(std::string);
	float findDbValue(std::string, std::string &);
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

bool validateEntries(std::string[2], time_t);
void decrementDate(std::string &str);
time_t extractDate(std::string str);
std::string &trim(std::string &);

#endif /* ********************************************************* BTC_H  	*/