#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(const RPN &src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs) {
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, RPN const &i) {
	(void)i;
	o << "RPN Class";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int RPN::calculate(char c) {
	int calc = 0;
	int a, b;
	b = RPN::_stack.top();
	RPN::_stack.pop();
	a = RPN::_stack.top();
	RPN::_stack.pop();
	switch (c) {
	case '+':
		calc = a + b;
		break;
	case '-':
		calc = a - b;
		break;
	case '*':
		calc = a * b;
		break;
	case '/':
		calc = a / b;
		break;
	default:
		throw std::invalid_argument("Error");
		break;
	}
	return calc;
}

bool RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

int RPN::execute(std::string expr) {
	std::stringstream s(expr);
	char c;
	while (s >> c) {
		if (std::isdigit(c)) {
			RPN::_stack.push(c - 48);
		} else if (RPN::isOperator(c)) {
			if (RPN::_stack.size() < 2) {
				throw std::invalid_argument(
					"Error: not enough data to calculate");
			}
			RPN::_stack.push(RPN::calculate(c));
		} else {
			throw std::invalid_argument("Error: invalid character");
		}
	}
	if (RPN::_stack.size() > 1) {
		throw std::invalid_argument("Error: missing an operator");
	}
	return RPN::_stack.top();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::stack<int> RPN::_stack;

/* ************************************************************************** */