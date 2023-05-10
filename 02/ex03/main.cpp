#include "bsp.h"
#include <iostream>

int main() {
	{
		std::cout << "Test - false" << std::endl;
		Point a(0, 0);
		Point b(1, 0);
		Point c(0, 1);
		Point p(0.0f, 1.0f);

		std::cout << "A: (" << a << ") B: (" << b << ") C: (" << c << ")"
				  << std::endl;
		std::cout << "Point p: (" << p << ")" << std::endl;
		std::cout << "The point p " << (bsp(a, b, c, p) ? "IS " : "IS NOT ");
		std::cout << "inside the triangle defined by abc." << std::endl
				  << std::endl;
	}
	{
		std::cout << "Test - true" << std::endl;
		Point a(0, 0);
		Point b(1, 0);
		Point c(0, 1);
		Point p(0.0f, 0.9f);

		std::cout << "A: (" << a << ") B: (" << b << ") C: (" << c << ")"
				  << std::endl;
		std::cout << "Point p: (" << p << ")" << std::endl;
		std::cout << "The point p " << (bsp(a, b, c, p) ? "IS " : "IS NOT ");
		std::cout << "inside the triangle defined by abc." << std::endl
				  << std::endl;
	}
	{
		std::cout << "Test - true" << std::endl;
		Point a(0, 0);
		Point b(-1, 0);
		Point c(0, -1);
		Point p(0.0f, -0.9f);

		std::cout << "A: (" << a << ") B: (" << b << ") C: (" << c << ")"
				  << std::endl;
		std::cout << "Point p: (" << p << ")" << std::endl;
		std::cout << "The point p " << (bsp(a, b, c, p) ? "IS " : "IS NOT ");
		std::cout << "inside the triangle defined by abc." << std::endl
				  << std::endl;
	}
	{
		std::cout << "Test - false" << std::endl;
		Point a(10, 20);
		Point b(1, 0);
		Point c(10, 0);
		Point p(0.5f, 0.6f);

		std::cout << "A: (" << a << ") B: (" << b << ") C: (" << c << ")"
				  << std::endl;
		std::cout << "Point p: (" << p << ")" << std::endl;
		std::cout << "The point p " << (bsp(a, b, c, p) ? "IS " : "IS NOT ");
		std::cout << "inside the triangle defined by abc." << std::endl
				  << std::endl;
	}
	{
		std::cout << "Test - true" << std::endl;
		Point a(2, 1);
		Point b(-3, 5);
		Point c(4, 3);
		Point p(1, 3);

		std::cout << "A: (" << a << ") B: (" << b << ") C: (" << c << ")"
				  << std::endl;
		std::cout << "Point p: (" << p << ")" << std::endl;
		std::cout << "The point p " << (bsp(a, b, c, p) ? "IS " : "IS NOT ");
		std::cout << "inside the triangle defined by abc." << std::endl
				  << std::endl;
	}
}
