#include "PmergeMe.hpp"

bool comparePair(const std::pair<int, int> &nb1, const std::pair<int, int> &nb2)
{
	return (nb1.first < nb2.first);
}

bool comparePairSecond(const std::pair<int, int> &nb1, const std::pair<int, int> &nb2)
{
	return (nb1.second < nb2.second);
}

PmergeMe::PmergeMe(std::vector<int> &tab, std::vector<int> &vect) : _orderedVector(vect)
{
	if (tab.size() % 2 != 0)
	{
		this->isOdd = true;
		this->_odd = tab.back();
	}
	else
		this->isOdd = false;
	// Creation du tableau de paires d'int
	for (unsigned long i = 0 ; i < (tab.size() / 2) * 2 ; i += 2)
	{
		std::pair<int, int> pair;
		pair.first = tab[i];
		pair.second = tab[i + 1];
		this->_pairVector.push_back(pair);
	}
	
	// Comparaison et tri de chaque paire
	std::vector< std::pair <int, int> >::iterator it = this->_pairVector.begin();
	for (; it != _pairVector.end() ; it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}

	// Tri des paires entre elles
	std::sort(_pairVector.begin(), _pairVector.end(), comparePair);
	
	// Remplissage de orderedVector avec les first
	it = this->_pairVector.begin();
	for (; it != _pairVector.end() ; it++)
		this->_orderedVector.push_back(it->first);
	
	//Remplissage de orderedVector avec les second
	int distance;
	std::sort(_pairVector.begin(), _pairVector.end(), comparePairSecond);
	std::vector<int>::iterator itInt = _orderedVector.begin();
	it = this->_pairVector.begin();
	for (; it != _pairVector.end() ; it++)
	{
		while (itInt != _orderedVector.end() && it->second > *itInt)
			itInt++;
		if (itInt != _orderedVector.end()) 
		{
			distance = std::distance(_orderedVector.begin(), itInt);
			_orderedVector.insert(_orderedVector.begin() + distance, it->second);
			itInt = _orderedVector.begin() + distance;
		}
		else
		{
			_orderedVector.push_back(it->second);
			itInt = _orderedVector.end();
		}
	}

	//Ajout du dernier element si impair 
	if (this->isOdd)
		_orderedVector.insert(std::upper_bound(_orderedVector.begin(), _orderedVector.end(), this->_odd), this->_odd);
}

PmergeMe::PmergeMe(std::vector<int> &tab, std::list<int> &list) : _orderedList(list)
{
 	if (tab.size() % 2 != 0)
	{
		this->isOdd = true;
		this->_odd = tab.back();
	}
	else
		this->isOdd = false;
	// // Creation du tableau de paires d'int
	for (unsigned long i = 0 ; i < (tab.size() / 2) * 2 ; i += 2)
	{
		std::pair<int, int> pair;
		pair.first = tab[i];
		pair.second = tab[i + 1];
		this->_pairList.push_back(pair);
	}

	// Comparaison et tri de chaque paire
	std::list< std::pair <int, int> >::iterator it = this->_pairList.begin();
	for (; it != _pairList.end() ; it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	
	// Tri des paires entre elles
	_pairList.sort(comparePair);
	
	// // Remplissage de orderedVector avec les first
	it = this->_pairList.begin();
	for (; it != _pairList.end() ; it++)
		this->_orderedList.push_back(it->first);
	
	// //Remplissage de orderedVector avec les second
	_pairList.sort(comparePairSecond);
	std::list<int>::iterator itInt = _orderedList.begin();
	it = this->_pairList.begin();
	for (; it != _pairList.end() ; it++)
	{
		while (itInt != _orderedList.end() && it->second > *itInt)
			itInt++;
		if (itInt != _orderedList.end()) 
			_orderedList.insert(itInt, it->second);
		else
		{
			_orderedList.push_back(it->second);
			itInt = _orderedList.end();
		}
	}
	//Ajout du dernier element si impair 
	if (this->isOdd)
	{
		itInt = std::upper_bound(_orderedList.begin(), _orderedList.end(), this->_odd);
    	_orderedList.insert(itInt, this->_odd);
	}
}

PmergeMe::PmergeMe(std::vector<int> &tab, std::set<int> &set) : _orderedSet(set)
{
	 	if (tab.size() % 2 != 0)
	{
		this->isOdd = true;
		this->_odd = tab.back();
	}
	else
		this->isOdd = false;
	// // Creation du tableau de paires d'int
	for (unsigned long i = 0 ; i < (tab.size() / 2) * 2 ; i += 2)
	{
		std::pair<int, int> pair;
		pair.first = tab[i];
		pair.second = tab[i + 1];
		this->_pairSet.insert(pair);
	}
	
	// Comparaison et tri de chaque paire
	std::set< std::pair <int, int> >::iterator it = this->_pairSet.begin();
	
	// // Remplissage de orderedVector avec les first
	it = this->_pairSet.begin();
	for (; it != _pairSet.end() ; it++)
		this->_orderedSet.insert(it->first);
	
	// //Remplissage de orderedVector avec les second
	it = this->_pairSet.begin();
	for (; it != _pairSet.end() ; it++)
	{
		this->_orderedSet.insert(it->second);
	}

	//Ajout du dernier element si impair 
	if (this->isOdd)
	{
    	_orderedSet.insert(this->_odd);
	}
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	this->_orderedList = rhs._orderedList;
	this->_orderedVector = rhs._orderedVector;
	this->_orderedSet = rhs._orderedSet;
	this->_pairVector = rhs._pairVector;
	this->_pairList = rhs._pairList;
	this->_pairSet = rhs._pairSet;
	this->isOdd = rhs.isOdd;
	return *this;
}

void PmergeMe::printVector()
{
	std::cout << "✅ After with std::vector:	";
	
	std::vector<int>::iterator it = this->_orderedVector.begin();
	for (; it != this->_orderedVector.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList()
{
	std::cout << "✅ After with std::list:	";
	
	std::list<int>::iterator it = this->_orderedList.begin();
	for (; it != this->_orderedList.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printSet()
{
	std::cout << "✅ After with std::set:		";
	
	std::set<int>::iterator it = this->_orderedSet.begin();
	for (; it != this->_orderedSet.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}