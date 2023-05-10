#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>

#define N_CONTACTS 8

class PhoneBook {

  private:
	Contact _contact[N_CONTACTS];
	static int _nContacts;

  public:
	PhoneBook(void);
	~PhoneBook(void);

	void newContact(std::string, std::string, std::string, std::string,
					std::string);
	void printList(void);
	void searchContact(int);
};

#endif