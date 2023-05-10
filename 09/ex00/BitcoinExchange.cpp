#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() { loadDb("data.csv"); }

BitcoinExchange::BitcoinExchange(std::string fileName) { loadDb(fileName); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i) {
	o << "BitcoinExchange database size: " << i.dbSize();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::loadDb(std::string fileName) {
	std::string line, word, temp;
	std::string data[2];
	std::ifstream inputFile(fileName.c_str());
	if (!inputFile) {
		std::cout << "Error: couldn't open file: " << fileName << std::endl;
		return;
	}
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		std::stringstream s(line);
		for (int i = 0; i < 2; i++) {
			getline(s, word, ',');
			trim(word);
			data[i] = word;
		}

		this->_db.insert(
			std::pair<std::string, float>(data[0], std::atof(data[1].c_str())));
	}
}

void BitcoinExchange::printDb() {
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator ite;

	it = this->_db.begin();
	ite = this->_db.end();
	while (it != ite) {
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}

float BitcoinExchange::findDbValue(std::string date, std::string &dbDate) {
	std::string localDate = date;
	std::map<std::string, float>::iterator it = this->_db.end();

	while (it == this->_db.end()) {
		it = this->_db.find(localDate);
		dbDate = localDate;
		decrementDate(localDate);
	}
	return it->second;
}

void BitcoinExchange::calculate(std::string fileName) {
	if (dbSize() == 0) {
		std::cout << "Error: empty database" << std::endl;
		return;
	}
	std::ifstream inputFile(fileName.c_str());
	if (!inputFile) {
		std::cout << "Error: couldn't open file: " << fileName << std::endl;
		return;
	}

	std::string line, word, temp;
	std::string data[3];
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		std::stringstream s(line);
		if (line.find("|") == std::string::npos ||
			line.find("|") == line.size() - 1) {
			std::cout << "Parse error.\n";
			continue;
		}
		for (int i = 0; i < 2; i++) {
			getline(s, word, '|');
			data[i] = trim(word);
		}

		if (validateEntries(data, extractDate(this->_db.begin()->first))) {
			float dbValue = this->findDbValue(data[0], data[2]);
			std::cout << data[0];
			if (data[0] != data[2]) {
				std::cout << " (" << data[2] << ")";
			}
			std::cout << " => " << data[1] << " = ";
			std::cout << std::fixed << std::setprecision(2)
					  << (dbValue * std::atof(data[1].c_str())) << std::endl;
		}
	}
}

size_t BitcoinExchange::dbSize() const { return this->_db.size(); }

/*
** --------------------------------- UTILS ---------------------------------
*/

bool isValidDate(std::string str, time_t dbBegin) {
	std::istringstream is(str);
	char delimiter;
	int d, m, y;
	if (is >> y >> delimiter >> m >> delimiter >> d) {
		time_t epochDate = extractDate(str);

		const struct tm *normDate = localtime(&epochDate);

		if (!(normDate->tm_mday == d && normDate->tm_mon == m - 1 &&
			  normDate->tm_year == y - 1900)) {
			std::cout << "Error: bad input: " << str << std::endl;
			return false;
		} else if (epochDate < dbBegin) {
			std::cout << "Error: bad date range: " << str << std::endl;
			return false;
		} else {
			return true;
		}
	}
	std::cout << "Error: bad date format." << std::endl;
	return false;
}

bool isValidValue(std::string str) {
	float value = std::atof(str.c_str());
	if (value > 1000) {
		std::cout << "Error: too large number." << std::endl;
		return false;
	} else if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	} else if (value == 0 && str[0] != 0) {
		std::cout << "Error: invalid value." << std::endl;
		return false;
	}
	return true;
}

bool validateEntries(std::string data[2], time_t dbBegin) {
	if (!isValidDate(data[0], dbBegin)) {
		return false;
	}
	if (!isValidValue(data[1])) {
		return false;
	}
	return true;
}

void decrementDate(std::string &strDate) {
	std::ostringstream os;

	time_t epochDate = extractDate(strDate);
	epochDate -= 60 * 60 * 24;
	const struct tm *norm = localtime(&epochDate);

	os << norm->tm_year + 1900 << '-';
	os << std::setfill('0') << std::setw(2) << norm->tm_mon + 1 << '-';
	os << std::setfill('0') << std::setw(2) << norm->tm_mday;

	strDate = os.str();
}

time_t extractDate(std::string strDate) {
	std::istringstream is(strDate);
	time_t epochDate = 0;
	char delimiter;
	int d, m, y;
	if (is >> y >> delimiter >> m >> delimiter >> d) {
		struct tm t = {};
		t.tm_mday = d;
		t.tm_mon = m - 1;
		t.tm_year = y - 1900;
		t.tm_isdst = -1;

		epochDate = mktime(&t);
	}
	return epochDate;
}

std::string &trim(std::string &word) {
	std::size_t len =
		(word.find_last_not_of(' ') - word.find_first_not_of(' '));
	if (len > 0) {
		std::string temp(word.substr(word.find_first_not_of(' '), len + 1));
		word = temp;
	}
	return word;
}

/* ************************************************************************** */