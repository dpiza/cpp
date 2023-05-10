#include "Span.hpp"
#include <iostream>
#include <list>

int main() {
	{
		std::cout << "- First test: longest and shortest" << std::endl;

		std::cout << "Success:" << std::endl;
		Span sp(6);
		sp.addNumber(22);
		sp.addNumber(13);
		sp.addNumber(3);
		sp.addNumber(27);
		sp.addNumber(8);
		sp.addNumber(1);
		std::cout << sp << std::endl;
		std::cout << "Longest Span: ";
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Shortest Span: ";
		try {
			std::cout << sp.shortestSpan() << std::endl << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << "Failure: Span size 0" << std::endl;
		Span sp1(0);
		std::cout << sp1 << std::endl;
		std::cout << "Longest Span: ";
		try {
			std::cout << sp1.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Shortest Span: ";
		try {
			std::cout << sp1.shortestSpan() << std::endl << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl << std::endl;
		}

		std::cout << "Failure: Span size 1" << std::endl;
		Span sp2(1);
		sp2.addNumber(1);
		std::cout << sp2 << std::endl;
		std::cout << "Longest Span: ";
		try {
			std::cout << sp2.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Shortest Span: ";
		try {
			std::cout << sp2.shortestSpan() << std::endl << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl << std::endl;
		}
	}
	{
		std::cout << "- Second test: range copy" << std::endl;

		std::cout << "From int array:" << std::endl;
		Span sp(5);
		int iArr[5] = {1, 2, 3, 4, 5};
		try {
			sp.addManyNumbers(iArr, iArr + 5);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << sp << std::endl << std::endl;

		std::cout << "From std::list<int>:" << std::endl;
		Span sp1(5);
		std::list<int> list;
		list.assign(5, 10);
		sp1.addManyNumbers(list.begin(), list.end());
		std::cout << sp1 << std::endl << std::endl;

		std::cout << "From std::vector<int>:" << std::endl;
		Span sp2(5);
		std::vector<int> vector;
		vector.assign(5, 20);
		sp2.addManyNumbers(vector.begin(), vector.end());
		std::cout << sp2 << std::endl << std::endl;
	}
	{
		std::cout << "- Third test: exceptions" << std::endl;

		std::cout << "Calling addNumber 3 times in a Span size 2:" << std::endl;
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try {
			sp.addNumber(3);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << sp << std::endl << std::endl;

		std::cout << "Calling addManyNumbers for 3 numbers in a Span size 2:"
				  << std::endl;
		Span sp1(2);
		int iArr[3] = {1, 2, 3};
		try {
			sp1.addManyNumbers(iArr, iArr + 3);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << sp1 << std::endl << std::endl;
	}
	{
		std::cout << "- Fourth test: huge array of numbers" << std::endl;

		std::cout << "Calling addManyNumbers for 10000 numbers:" << std::endl;
		Span sp(10000);
		std::vector<int> vector;
		vector.assign(10000, 99);
		try {
			sp.addManyNumbers(vector.begin(), vector.end());
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << sp << std::endl << std::endl;

		std::cout << "Calling addManyNumbers for 50000 numbers:" << std::endl;
		Span sp1(50000);
		std::vector<int> vector1;
		vector1.assign(50000, 99);
		try {
			sp1.addManyNumbers(vector1.begin(), vector1.end());
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << sp1 << std::endl << std::endl;
	}
}