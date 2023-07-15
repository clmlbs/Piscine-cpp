#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::ifstream* data);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange() {}
        BitcoinExchange& operator=(const BitcoinExchange& rhs);

        void printValues(std::ifstream& values);
		void removeChar(std::string& str, char c);

    private:
        BitcoinExchange();
        std::map<int, float> _database;
};