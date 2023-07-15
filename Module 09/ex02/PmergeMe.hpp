#pragma once

#include <iostream>
#include <iomanip>
#include <vector> 
#include <algorithm>
#include <list>
#include <utility>
#include <stdio.h>
#include <time.h>
#include <set>

class PmergeMe
{
	public:
		PmergeMe(std::vector<int> &tab, std::vector<int> &vect);
		PmergeMe(std::vector<int> &tab, std::list<int> &list);
		PmergeMe(std::vector<int> &tab, std::set<int> &set);
		~PmergeMe() {}
		PmergeMe(const PmergeMe& src);

		PmergeMe& 	operator=(const PmergeMe& rhs);
		void		printList();
		void		printVector();
		void		printSet();
		bool		isOdd;

	private:
		PmergeMe();
		std::vector<int>					_orderedVector;
		std::list<int>						_orderedList;
		std::set<int>						_orderedSet;
		std::vector<std::pair<int, int> > 	_pairVector;
		std::list<std::pair <int, int> > 	_pairList;
		std::set<std::pair <int, int> > 	_pairSet;
		int									_odd;
};