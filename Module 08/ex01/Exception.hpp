#pragma once

#include <iostream>

class ExcepEmptyVector : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: vector empty");
		}
};

class ExcepSingleNb : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: only one number in vector, impossible to find distance");
		}
};

class ExcepVectorFull : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: the vector is full, you cannot add new number");
		}
};



class ExcepNotEnoughSpace : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: there is not enough space to add the range of iterators");
		}
};