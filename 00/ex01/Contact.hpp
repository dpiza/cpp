#ifndef CONTACT_H
#define CONTACT_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#define MAX_CHAR 10

class Contact {
  private:
	int _index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _secret;

	static int _nContacts;
	static std::string _truncate(std::string);

  public:
	Contact(void);
	~Contact(void);

	void createContact(int, std::string, std::string, std::string, std::string,
					   std::string);

	void printContactList(void) const;
	void printContactDetails(void) const;

	std::string getContactName(void) const;
};

#endif