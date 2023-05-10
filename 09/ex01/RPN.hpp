#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {

  public:
	RPN();
	RPN(RPN const &src);
	~RPN();

	RPN &operator=(RPN const &rhs);

	static bool isOperator(char);
	static int calculate(char);
	static int execute(std::string);

  private:
	static std::stack<int> _stack;
};

std::ostream &operator<<(std::ostream &o, RPN const &i);

#endif /* ********************************************************* RPN_H  */