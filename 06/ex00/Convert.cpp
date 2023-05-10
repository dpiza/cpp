#include "Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert() {}

Convert::Convert(const std::string &str)
	: _str(str), _raw(0), _c(0), _i(0), _f(0), _d(0), _type(0) {
	if (str.length() == 1 && std::isalpha(*str.begin())) {
		this->_raw = static_cast<double>(*str.begin());
		this->_c = static_cast<char>(this->_raw);
		this->_type = _CHAR;
	} else {
		this->_raw = std::strtod(str.c_str(), NULL);
		this->_type = identify(str);
	}
	this->convert();
}

Convert::Convert(const Convert &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &Convert::operator=(Convert const &rhs) {
	if (this != &rhs) {
		this->_raw = rhs.getValue();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Convert const &i) {
	o << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Convert::identify(const std::string &str) {
	bool decimal = (str.find('.', 0) != std::string::npos);
	bool floatSign = (str.at(str.length() - 1) == 'f');

	this->_i = static_cast<int>(this->_raw);
	this->_f = static_cast<float>(this->_raw);
	this->_d = static_cast<double>(this->_raw);
	if (this->_raw == 0 && str.compare("0")) {
		return (_INVALID);
	} else if (!decimal && !floatSign &&
			   static_cast<double>(this->_i) == this->_raw) {
		this->_type = _INT;
	} else if (decimal && floatSign && this->_f < FLT_MAX) {
		this->_type = _FLOAT;
	} else if (decimal && !floatSign && this->_d < DBL_MAX) {
		this->_type = _DOUBLE;
	}
	return (this->_type);
}

void Convert::convert() {
	switch (this->_type) {
	case _CHAR:
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
		break;
	case _INT:
		this->_c = static_cast<char>(this->_i);
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
		break;
	case _FLOAT:
		this->_c = static_cast<char>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_d = static_cast<double>(this->_f);
		break;
	case _DOUBLE:
		this->_c = static_cast<char>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_f = static_cast<float>(this->_d);
		break;
	default:
		break;
	}
}

std::string Convert::toChar() {
	std::stringstream sstream;
	char cConvert = this->_c;
	if (this->_raw > 127 || this->_raw < -126 || this->_type == 0) {
		sstream << "impossible";
	} else if (!std::isprint(this->_raw)) {
		sstream << "Non displayable";
	} else {
		sstream << "\'" << cConvert << "\'";
	}
	return sstream.str();
}

std::string Convert::toInt() {
	std::stringstream sstream;
	int iConvert = this->_i;
	if ((iConvert == -2147483648 && this->_str.compare("-2147483648")) ||
		this->_type == 0) {
		sstream << "impossible";
	} else {
		sstream << iConvert;
	}
	return sstream.str();
}

std::string Convert::toFloat() {
	std::stringstream sstream;
	float fConvert = this->_f;
	if (fConvert > static_cast<int>(fConvert) || this->_raw != this->_raw ||
		std::isinf(this->_raw)) {
		sstream << fConvert << "f";
	} else if (this->_type == 0) {
		sstream << "impossible";
	} else {
		sstream << fConvert << ".0f";
	}
	return sstream.str();
}

std::string Convert::toDouble() {
	std::stringstream sstream;
	double dConvert = this->_d;
	if (dConvert > static_cast<int>(dConvert) || this->_raw != this->_raw ||
		std::isinf(this->_raw)) {
		sstream << dConvert;
	} else if (this->_type == 0) {
		sstream << "impossible";
	} else if (dConvert == static_cast<int>(dConvert)) {
		sstream << dConvert << ".0";
	}
	return sstream.str();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

double Convert::getValue(void) const { return this->_raw; }

/* ************************************************************************** */