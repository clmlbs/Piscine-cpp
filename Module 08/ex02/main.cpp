#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "=== Example of subject ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "=== Nb on top of stack ===" << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "=== Size of stack ===" << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\n=== Stack bottom of stack ===" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "=== Stack top of stack ===\n" << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << std::endl;
	
		std::cout << "=== Example with list ===" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "=== Nb of last link of list ===" << std::endl;
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << "=== Size of stack ===" << std::endl;
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		std::cout << "\n=== First link of list ===" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "=== Last link of list ===" << std::endl;
		
		std::stack<int, std::list<int> > s(list);
		std::cout << "\n=== Adding element on stack type list of int ===" << std::endl;
		s.push(2023);
		std::cout << s.top() << std::endl;
		
		MutantStack<int, std::list<int> > Ms(list);
		
		MutantStack<int, std::list<int> >::iterator it2 = Ms.begin();
		MutantStack<int, std::list<int> >::iterator ite2 = Ms.end();
		std::cout << "\n=== Stack bottom of stack ===" << std::endl;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::cout << "=== Stack top of stack ===\n" << std::endl;

	return 0;
}
