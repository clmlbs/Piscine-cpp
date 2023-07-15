#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template<typename T>
bool easyfind(T cont, int n)
{
	typename T::const_iterator it;

	it = find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		return false;
	return true;
}
