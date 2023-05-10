#include "Base.hpp"
#include <ctime>
#include <iostream>

Base *generate(void) {
	int clock = std::clock();
	Base *randClass;
	switch (clock % 3) {
	case 0:
		randClass = new A();
		break;
	case 1:
		randClass = new B();
		break;
	case 2:
		randClass = new C();
		break;
	}
	return (randClass);
}

void identify(Base *p) {
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a) {
		std::cout << "A" << std::endl;
	} else if (b) {
		std::cout << "B" << std::endl;
	} else if (c) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch (std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch (std::exception &e) {
	}
}

int main(void) {
	std::cout << "A Class: " << std::endl;
	Base *aClass = new A();
	identify(aClass);
	identify(*aClass);
	std::cout << std::endl;

	std::cout << "B Class: " << std::endl;
	Base *bClass = new B();
	identify(bClass);
	identify(*bClass);
	std::cout << std::endl;

	std::cout << "C Class: " << std::endl;
	Base *cClass = new C();
	identify(cClass);
	identify(*cClass);
	std::cout << std::endl;

	std::cout << "Random Class: " << std::endl;
	Base *randClass = generate();
	identify(randClass);
	identify(*randClass);

	delete (aClass);
	delete (bClass);
	delete (cClass);
	delete (randClass);
	return (0);
}