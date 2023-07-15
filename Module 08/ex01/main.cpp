#include "Span.hpp"

int main(void)
{
	try
	{
		std::cout << "===== Example of subject =====" << std::endl;
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
		
		
		std::cout << "\n===== Example of subject - modified =====" << std::endl;
		Span sp2 = Span(7);
		sp2.addNumber(6);
		sp2.addNumber(3);
		sp2.addNumber(20);
		sp2.addNumber(9);
		sp2.addNumber(11);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		sp2.addNumber(-35980);
		sp2.addNumber(-35979);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << "\n===== Error vector's full =====" << std::endl;
		sp2.addNumber(-35980);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span sp3 = Span(5);
		std::cout << "\n===== Error vector empty =====" << std::endl;
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span sp4 = Span(5);
		sp4.addNumber(2023);
		std::cout << "\n===== Error only one value =====" << std::endl;
		std::cout << sp4.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int> vect(10000);
		for (int i = 0 ; i < 10000 ; i++)
			vect[i] = i;

		Span sp5 = Span(10000);
		sp5.addRange(vect.begin(), vect.end());
		sp5.printSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}