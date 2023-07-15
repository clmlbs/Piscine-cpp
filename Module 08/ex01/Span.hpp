#pragma once

#include <iostream> 
#include "Exception.hpp"
#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		Span& operator=(const Span& rhs);
		void	addNumber(int nb);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
		void	printSpan();

	private:
		Span();
		const unsigned int		_N;
		std::vector<int>		_span;
		
};