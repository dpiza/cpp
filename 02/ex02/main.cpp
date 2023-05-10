#include "Fixed.hpp"
#include <iostream>

int main(void) {
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	{

		std::cout << std::endl << "Comparison operators:" << std::endl;
		Fixed a(20);
		Fixed b(20);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
		std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl
				  << std::endl;

		a.setRawBits(10);
		b.setRawBits(20);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
		std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl
				  << std::endl;

		std::cout << "Arithmetic operators:" << std::endl;
		a.setRawBits(10);
		b.setRawBits(20);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a + b: " << (a + b) << std::endl;
		std::cout << "a - b: " << (a - b) << std::endl;
		std::cout << "a * b: " << (a * b) << std::endl;
		std::cout << "a / b: " << (a / b) << std::endl << std::endl;

		std::cout << "Increment/decrement operators:" << std::endl;
		std::cout << "a: " << a << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "a++: " << (a++) << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "a: " << a << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "++a: " << (++a) << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "a: " << a << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "a--: " << (a--) << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "a: " << a << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl;
		std::cout << "--a: " << (--a) << " (rawBits:" << a.getRawBits() << ")"
				  << std::endl
				  << std::endl;

		std::cout << "Max/min overload:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "min a, b: " << Fixed::min(a, b) << std::endl;
		std::cout << "max a, b: " << Fixed::max(a, b) << std::endl;
		Fixed const ca = 10;
		Fixed const cb = 20;
		std::cout << "const min 10, 20: " << Fixed::min(ca, cb) << std::endl;
		std::cout << "const max 10, 20: " << Fixed::max(ca, cb) << std::endl;
	}

	return (0);
}