#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << "PDF tests" << std::endl;
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	std::cout << std::endl << "Brain validation" << std::endl;
	{
		Animal *animal[10];
		for (int i = 0; i < 10; i++) {
			if (i < 10 / 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
		}
		for (int i = 0; i < 10; i++) {
			delete animal[i];
		}
	}
	std::cout << std::endl << "Copy reference validation" << std::endl;
	{
		Animal *cat = new Cat();
		std::cout << *cat << std::endl;
		std::cout << std::endl;

		Animal catCopy = *cat;
		delete cat;
		std::cout << std::endl;
		std::cout << catCopy << std::endl;
	}
	return 0;
}