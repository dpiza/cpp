#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { return; }

PhoneBook::~PhoneBook(void) { return; }

void PhoneBook::newContact(std::string firstName, std::string lastName,
						   std::string nickName, std::string phoneNumber,
						   std::string secret) {
	if (_nContacts == N_CONTACTS)
		_nContacts = 0;
	_contact[_nContacts].createContact(_nContacts, firstName, lastName,
									   nickName, phoneNumber, secret);
	PhoneBook::_nContacts += 1;
}

void PhoneBook::printList(void) {
	std::cout << std::setw(10) << "INDEX"
			  << "|";
	std::cout << std::setw(10) << "FIRST NAME"
			  << "|";
	std::cout << std::setw(10) << "LAST NAME"
			  << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	for (int i = 0; i < N_CONTACTS; i++)
		_contact[i].printContactList();
}

void PhoneBook::searchContact(int index) {
	Contact *pContact;

	if (index >= N_CONTACTS || index < 0) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	pContact = &_contact[index];
	if (!pContact->getContactName().empty())
		pContact->printContactDetails();
}

int PhoneBook::_nContacts = 0;
