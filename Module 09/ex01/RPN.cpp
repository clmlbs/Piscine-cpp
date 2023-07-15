#include "RPN.hpp"

RPN::RPN(std::string expr)
{
	int nb1;
	int nb2;
	char operators[4] = {'+', '-', '*', '/'};
	
	for (int i = 0 ; expr[i] ; i++)
	{
		if (isdigit(expr[i]))
			_stack.push(expr[i] - '0');
		else if (expr[i] != ' ')
		{
			nb1 = _stack.top();
			_stack.pop();
			nb2 = _stack.top();
			_stack.pop();
			for (int j = 0 ; j < 4 ; j++)
			{
				if (expr[i] == operators[j])
				{
					switch (j)
					{
						case 0:
							_stack.push(nb2 + nb1);
							break;
						case 1:
							_stack.push(nb2 - nb1);
							break;
						case 2:
						{
							_stack.push(nb2 * nb1);
							break;
						}
						case 3:
						{
							if (nb1 == 0)
							{
								std::cerr << "Error: impossible to divise per zero" << std::endl;
								return ;
							}
							_stack.push(nb2 / nb1);
							break;
						}
						default:
							break;
					}
				}
			}
		}
	}
	std::cout << _stack.top() << std::endl;
}

RPN::RPN(const RPN& src) 
{
	*this = src;
}

RPN& RPN::operator=(const RPN& rhs)
{
	this->_stack = rhs._stack;
	return *this;
}