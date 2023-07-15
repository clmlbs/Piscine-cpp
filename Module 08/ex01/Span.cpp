#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& src) : _N(src._N)
{
	*this = src;
}

Span::~Span() {}

Span& Span::operator=(const Span& rhs)
{
	this->_span = rhs._span;
	return *this;
}

void	Span::addNumber(int nb)
{
	if (this->_span.size() == this->_N)
		throw(ExcepVectorFull());
	else
		this->_span.push_back(nb);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + this->_span.size() > this->_N)
		throw(ExcepNotEnoughSpace());
	std::vector<int>::iterator it = begin;
	for (; it != end ; it++)
		addNumber(*it);
}

int		Span::shortestSpan()
{
	if (this->_span.size() == 0)
		throw(ExcepEmptyVector());
	if (this->_span.size() == 1)
		throw(ExcepSingleNb());
	
	int shortest = INT_MAX;
	std::vector<int> dup = this->_span;
	std::vector<int>::iterator it = dup.begin();

	std::sort(it, dup.end());
	for (++it ; it != dup.end() ; ++it)
	{
		if (abs(*it - *(it - 1)) < shortest)
			shortest = abs(*it - *(it - 1));
	}
	return shortest;	
}

int		Span::longestSpan()
{
	if (this->_span.size() == 0)
		throw(ExcepEmptyVector());
	if (this->_span.size() == 1)
		throw(ExcepSingleNb());

	std::vector<int> dup = this->_span;
	std::sort(dup.begin(), dup.end());
	return (abs(*(dup.end() - 1) - *dup.begin()));
}

void Span::printSpan()
{
	std::vector<int>::iterator it = this->_span.begin();
	int i = 0;
	for (it + 1 ; it != this->_span.end() ; it++)
		std::cout << i++ << "] " << *it << std::endl;

}