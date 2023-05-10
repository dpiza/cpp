#include "Array.tpp"
#include <iostream>

int main() {
	std::cout << " - Empty array" << std::endl;
	Array<int> emptyArr;
	std::cout << "Size: " << emptyArr.size() << std::endl;
	try {
		std::cout << emptyArr[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Read[0] error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << " - Int array[2]" << std::endl;
	Array<int> iArr(2);
	std::cout << "Size: " << iArr.size() << std::endl;
	std::cout << "Set values:" << std::endl;
	iArr[0] = 4;
	iArr[1] = 2;
	std::cout << iArr << std::endl << std::endl;

	std::cout << " - Char array[3]" << std::endl;
	Array<char> cArr(3);
	std::cout << "Size: " << cArr.size() << std::endl;
	std::cout << "Set values:" << std::endl;
	cArr[0] = 'r';
	cArr[1] = 'o';
	cArr[2] = 'i';
	std::cout << cArr << std::endl << std::endl;

	std::cout << " - Copy constructor Char array[3]" << std::endl;
	Array<char> ccArr(cArr);
	std::cout << "Size: " << ccArr.size() << std::endl;
	std::cout << ccArr << std::endl;
	std::cout << "Change OG values:" << std::endl;
	cArr[0] = 'x';
	cArr[1] = 'a';
	cArr[2] = 'u';
	std::cout << cArr << std::endl;
	std::cout << "Didnt affect new array:" << std::endl;
	std::cout << ccArr << std::endl << std::endl;

	std::cout << " - Copy operator Char array[3]" << std::endl;
	Array<char> coArr(8);
	std::cout << "Size before copy: " << coArr.size() << std::endl;
	coArr = cArr;
	std::cout << "Size after copy: " << coArr.size() << std::endl;
	std::cout << coArr << std::endl;
	std::cout << "Change OG values:" << std::endl;
	cArr[0] = 'r';
	cArr[1] = 'o';
	cArr[2] = 'i';
	std::cout << cArr << std::endl;
	std::cout << "Didnt affect new array:" << std::endl;
	std::cout << coArr << std::endl << std::endl;

	std::cout << "Trying to read indexes (-1, 1, 10):" << std::endl;
	try {
		std::cout << cArr[-1] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Read[-1] error: " << e.what() << std::endl;
	}
	try {
		std::cout << cArr[1] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Read[1] error: " << e.what() << std::endl;
	}
	try {
		std::cout << cArr[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Read[10] error: " << e.what() << std::endl;
	}

	return (0);
}