#pragma once

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN(std::string expr);
		~RPN(){}
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);

	private:
		RPN();
		std::stack<int> _stack;

};