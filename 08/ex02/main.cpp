#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

template <typename T> void test_stack_methods(T &stack) {
	std::cout << "empty()? " << (stack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Push 10, 20, 30 and 40" << std::endl;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	std::cout << "empty()? " << (stack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "top() result: " << stack.top() << std::endl;
	std::cout << "pop()" << std::endl;
	stack.pop();
	std::cout << "New size: " << stack.size() << std::endl << std::endl;
}

template <typename T> void test_iter_methods(T it, T ite) {
	std::cout << "Print using iterator ++/-- operators:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	--it;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

int main() {
	MutantStack<int> ms;
	std::stack<int> st;
	std::list<int> lst;

	test_stack_methods(st);
	test_stack_methods(ms);

	lst.insert(lst.begin(), 3, 100);

	test_iter_methods(ms.begin(), ms.end());
	test_iter_methods(lst.begin(), lst.end());

	std::cout << "Copy using Copy Constructor: " << std::endl;
	MutantStack<int> ms2(ms);
	ms.pop();
	std::cout << ms2 << std::endl << std::endl;

	std::cout << "Copy using Copy Assign: " << std::endl;
	MutantStack<int> ms3;
	ms3 = ms2;
	ms2.pop();
	std::cout << ms3 << std::endl;

	return 0;
}