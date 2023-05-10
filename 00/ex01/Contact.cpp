#include "Contact.hpp"

Contact::Contact(void) : _index(_nContacts) {
	_nContacts += 1;
	return;
}

Contact::~Contact(void) { return; }

void Contact::createContact(int index, std::string firstName,
							std::string lastName, std::string nickName,
							std::string phoneNumber, std::string secret) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_secret = secret;
	this->_index = index;
}

std::string Contact::_truncate(std::string string) {
	if (string.length() > MAX_CHAR)
		return string.substr(0, MAX_CHAR - 1) + '.';
	return string;
}

void Contact::printContactList(void) const {
	std::cout << std::setw(10) << this->_index;
	std::cout << "|";
	std::cout << std::setw(10) << this->_truncate(this->_firstName);
	std::cout << "|";
	std::cout << std::setw(10) << this->_truncate(this->_lastName);
	std::cout << "|";
	std::cout << std::setw(10) << this->_truncate(this->_nickName) << std::endl;
}

void Contact::printContactDetails(void) const {
	std::cout << "\t\t#" << this->_index << std::endl;
	std::cout << "First name:\t" << this->_firstName << std::endl;
	std::cout << "Last name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickName << std::endl;
	std::cout << "Phone number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Secret:\t\t" << this->_secret << std::endl;
}

std::string Contact::getContactName(void) const { return this->_firstName; }

int Contact::_nContacts = 0;