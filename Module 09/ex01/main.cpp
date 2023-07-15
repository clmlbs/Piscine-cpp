#include "RPN.hpp"

bool areCharAuthorized(std::string expr, std::string charset)
{
	int	digits = 0;
	int operators = 0;

	for (int i = 0 ; expr[i] ; i++)
	{
		if (charset.find(expr[i]) == std::string::npos)
		{
			std::cerr << "Error: characters authorized are \"0123456789+-* \"" << std::endl;
			return false;
		}
		if (i % 2 != 0 && expr[i] != ' ')
		{
			std::cerr << "Error: bad syntax" << std::endl;
			return false;
		}
		if (isdigit(expr[i]))
			digits++;
		else if (expr[i] != ' ')
			operators++;
		if (operators >= digits)
		{
			std::cerr << "Error: bad syntax" << std::endl;
			return false;
		}

	}
	if (operators + 1 == digits)
		return true;
	std::cerr << "Error: bad syntax" << std::endl;
	return false;
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: correct syntax: \"./RPN \"expression\" \"" << std::endl;
		return 1;
	}
	std::string expr(av[1]);
	std::string charset = "0123456789+-*/ ";
	if (!areCharAuthorized(expr, charset))
		return 1;
	RPN solve(expr);
	return 0;
}