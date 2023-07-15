#include "PmergeMe.hpp"

bool checkValues(int ac, char**av, std::vector<int> *tab)
{
	long buf;
	try
	{
		if (ac < 3) {
			std::cerr << "Error: the sequence should contain at least 2 numbers" << std::endl;
			return 0;
		}
		for (int i = 1 ; i < ac ; i++)
		{
			for (int j = 0 ; av[i][j] ; j++) {
				if (!isdigit(av[i][j]))
					throw std::exception();
			}
			buf = std::stol(av[i]);
			if (buf > INT_MAX)
				throw std::exception();
			tab->push_back(std::stoi(av[i]));
		}
		// std::vector<int>::iterator it = tab->begin();
		// std::vector<int>::iterator it2;
		// for (; it != tab->end() ; it++)
		// {
		// 	it2 = it + 1;
		// 	for (; it2 != tab->end() ; it2++)
		// 	{
		// 		if (*it == *it2)
		// 			throw std::exception();
		// 	}
		// }
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: bad syntax" << std::endl;
		return 0;
	}
	return 1;
}

void printTab(std::vector<int> &tab)
{
	std::vector<int>::iterator it = tab.begin();
	for (; it != tab.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::vector<int> 	tab, tabList, tabSet;
	time_t startTime, endTime;
    double timeVector, timeList, timeSet;

	if (!checkValues(ac, av, &tab))
		return 1;
	std::cout << "⭐️ Before:			";
	printTab(tab);
	std::vector<int> vector;
	std::list<int> list;
	std::set<int> set;
	tabList = tab;
	tabSet = tab;

    startTime = clock();
	PmergeMe Vect(tab, vector);
	endTime = clock();
    timeVector = ((double)(endTime - startTime) / CLOCKS_PER_SEC) * 1e6;
	Vect.printVector();

	startTime = clock();
	PmergeMe List(tabList, list);
	endTime = clock();
	timeList = ((double)(endTime - startTime) / CLOCKS_PER_SEC) * 1e6;
	List.printList();

	startTime = clock();
	PmergeMe Set(tabSet, set);
	endTime = clock();
	timeSet = ((double)(endTime - startTime) / CLOCKS_PER_SEC) * 1e6;
	Set.printSet();

	std::cout << "⏰ Time to process a range of	" << ac - 1 << " elements with std::vector:	" << timeVector << " us" << std::endl;
	std::cout << "⏰ Time to process a range of	" << ac - 1 << " elements with std::list:	" << timeList << " us" << std::endl;
	std::cout << "⏰ Time to process a range of	" << ac - 1 << " elements with std::set:	" << timeSet << " us" << std::endl;
	
	return 0;
}