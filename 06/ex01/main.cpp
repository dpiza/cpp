#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data *pi) {
	uintptr_t address;
	address = reinterpret_cast<uintptr_t>(pi);
	return address;
}

Data *deserialize(uintptr_t raw) {
	Data *address;
	address = reinterpret_cast<Data *>(raw);
	return address;
}

int main(void) {
	Data data("Denny", 15999998888);
	Data *pData = &data;

	std::cout << "Data: " << data << std::endl;
	std::cout << "*pData: " << *pData << std::endl << std::endl;

	std::cout << "pData: " << pData << std::endl;
	std::cout << "serialize(pData): " << serialize(pData) << std::endl;
	std::cout << "deserialize(serialize(pData)): "
			  << deserialize(serialize(pData)) << std::endl
			  << std::endl;

	std::cout << std::boolalpha << "(pData == deserialize(serialize(pData))): "
			  << (pData == deserialize(serialize(pData))) << std::endl
			  << std::endl;
	std::cout << "*deserialize(serialize(pData)): "
			  << *deserialize(serialize(pData)) << std::endl;

	return (0);
}