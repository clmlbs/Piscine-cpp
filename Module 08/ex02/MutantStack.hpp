#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const Container& cont);
		MutantStack(MutantStack<T, Container> const &src);
		MutantStack<T, Container> &operator=(MutantStack<T, Container> const &rhs);
		~MutantStack();

		typedef typename Container::iterator iterator;

		typename Container::iterator begin();
		iterator end();
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template < typename T, typename Container > 
MutantStack<T, Container>::MutantStack(const Container& cont) : std::stack<T, Container>(cont) {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	(void)rhs;
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

