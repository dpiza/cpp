#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

int checkEmptyInputs(std::string contactData[5]) {
	for (int i = 0; i < 5; i++) {
		if (contactData[i].empty())
			return (1);
	}
	return (0);
}

void addContact(PhoneBook *pb) {
	std::string contactData[5];

	std::cout << "Adding a new contact" << std::endl;
	std::cout << "First name: ";
	std::cin >> contactData[0];
	std::cout << "Last name: ";
	std::cin >> contactData[1];
	std::cout << "Nickname: ";
	std::cin >> contactData[2];
	std::cout << "Phone number: ";
	std::cin >> contactData[3];
	std::cout << "Dirty little secret: ";
	std::cin >> contactData[4];
	if (checkEmptyInputs(contactData))
		std::cout << "All contact's data is required." << std::endl;
	else
		pb->newContact(contactData[0], contactData[1], contactData[2],
					   contactData[3], contactData[4]);
}

void searchContact(PhoneBook *pb) {
	char buffer[10];
	std::stringstream index_stream;
	int index;

	std::cout << "Search contact" << std::endl;
	pb->printList();
	std::cout << "Contact's index: ";
	std::cin >> buffer;
	index_stream << buffer;
	index_stream >> index;
	std::cout << index;
	pb->searchContact(index);
}

int getAction(PhoneBook *pb, std::string input) {
	if (input.compare("EXIT") == 0)
		return (1);
	else if (input.compare("ADD") == 0)
		addContact(pb);
	else if (input.compare("SEARCH") == 0)
		searchContact(pb);
	else
		std::cout << "Invalid Input :(" << std::endl;
	return (0);
}

int main() {
	PhoneBook phonebook;
	char buff[7];

	std::cout << "========== Welcome to the AWESOME PhoneBook! =========="
			  << std::endl;
	std::cout << "The available actions are:" << std::endl << std::endl;
	std::cout << "ADD \tIncludes a new contact to your AWESOME PhoneBook"
			  << std::endl;
	std::cout << "SEARCH \tSearch for a contact from your AWESOME PhoneBook"
			  << std::endl;
	std::cout << "EXIT \tBurn the most AWESOME PhoneBook ever made" << std::endl
			  << std::endl;

	while (1) {
		std::cout << "/> ";
		std::cin >> buff;
		if (!*buff)
			break;
		if (getAction(&phonebook, std::string(buff)))
			break;
	}
	std::cout << "Bye!" << std::endl;

	return 0;
}