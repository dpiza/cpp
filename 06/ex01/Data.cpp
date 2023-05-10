#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data() {}

Data::Data(std::string name, long phone) : _name(name), _phone(phone) {}

Data::Data(const Data &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &Data::operator=(Data const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_phone = rhs.getPhone();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Data const &i) {
	o << "Name: " << i.getName() << "\t"
	  << "Phone: " << i.getPhone();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Data::getName(void) const { return this->_name; }

long Data::getPhone(void) const { return this->_phone; }

/* ************************************************************************** */