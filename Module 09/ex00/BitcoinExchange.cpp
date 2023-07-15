#include "BitcoinExchange.hpp"

int	checkInput(std::string line, int &date, float &value);
void printUniqueValue(int date, float value, float result);

BitcoinExchange::BitcoinExchange(std::ifstream* data) : _database()
{
    std::map<int, float>    database;
    std::string             line;
	std::string::size_type	commaPosition;

    std::string             dateStr;
    int                     dateInt;
    std::string             valueStr;
    float                   valueFloat;
    
    while (std::getline(*data, line))
    {
		commaPosition = line.find(',');
		dateStr = line.substr(0, commaPosition);
		removeChar(dateStr, '-');
		try {
		dateInt = std::stoi(dateStr);
		}
		catch (std::exception &e){
			dateStr.clear();
			continue;
		}
		valueStr = line.substr(commaPosition + 1, line.size());
		try {
		valueFloat = std::stof(valueStr);
		}
		catch (std::exception &e){
			valueStr.clear();
			continue;
		}
		database.insert(std::make_pair(dateInt, valueFloat));
		dateStr.clear();
        valueStr.clear();
    }
    this->_database = database;
}

void BitcoinExchange::removeChar(std::string& str, char c)
{
	std::string newStr;

	for (int i = 0 ; str[i]; i++)
	{
		if (str[i] != c)
			newStr += str[i];
	}
	str = newStr;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    this->_database = rhs._database;
	return *this;
}

void BitcoinExchange::printValues(std::ifstream& values)
{
	std::string line;
	while (std::getline(values, line))
	{
		int		date;
		float	value;
		if (line == "date | value")
			continue;
		if (!checkInput(line, date, value))
			continue;
		std::map<int, float>::iterator it = this->_database.begin();
		std::map<int, float>::iterator ite = this->_database.end();
		for (; it != ite ; it++)
		{
			if (date == it->first)
			{
				printUniqueValue(date, value, it->second * value);
				break;
			}
			else if (date < it->first)
			{
				if (it == this->_database.begin())
				{
					printUniqueValue(date, value, it->second * value);
					break;
				}
				else
				{
					printUniqueValue(date, value, (--it)->second * value);
					it++;
					break;
				}
			}
		}
		
	}
}

int	checkInput(std::string line, int &date, float &value)
{
	std::string str;
	long		nb;
	int			day;

	if (line.size() < 14) {
		std::cerr << "Error: not enough characters: " << line << std::endl;
		return 0;
	}
	else if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		std::cerr << "Error: bad syntax: " << line << " Syntax should be <YYYY-MM-DD | <value> >" << std::endl;
		return 0;
	}
	str = line.substr(0, 4);
	try {
		nb = stol(str);
		if (nb < 2008 || nb > 2023)
		{
			std::cerr << "Error: year should be between 2008 and 2023" << std::endl;
			return 0;
		}
		date = nb * 10000;
		str.clear();
		str = line.substr(5, 2);
		nb = stol(str);
		if (nb < 1 || nb > 12)
		{
			std::cerr << "Error: month should be between 01 and 12" << std::endl;
			return 0;
		}
		date += nb * 100;
		str.clear();
		str = line.substr(8, 2);
		day = stoi(str);
		if (day < 1 || day > 31)
		{
			std::cerr << "Error: day can be between 01 and 31" << std::endl;
			return 0;
		}
		if (nb == 2 && day > 29)
		{
			std::cerr << "Error: in february days can be between 01 and 29" << std::endl;
			return 0;
		}
		if (nb == 4 || nb == 6 || nb == 9 || nb == 11)
		{
			if (day > 30)
			{
				std::cerr << "Error: in april, june, september and november days can be between 01 and 30" << std::endl;
				return 0;
			}	
		}
		date += day;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: bad syntax: " << line << " Syntax should be <YYYY-MM-DD | <value> >" << std::endl;
		return 0;
	}
	str = line.substr(13, line.size() - 13);
	try 
	{
		nb = stol(str);
		if (nb < 0 || nb > 1000)
			throw std::exception();
		value = stof(str);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: unvalid value: " << str << ", value should be a number between 0 and 1000" << std::endl;
		return 0;
	}
	return 1;
}

void printUniqueValue(int date, float value, float result)
{
	std::string monthZero = "";
	std::string dayZero = "";

	int year = date / 10000;
	int month = (date - year * 10000) / 100;
	if (month < 10)
		monthZero = "0";
	int day = date - year * 10000 - month * 100;
	if (day < 10)
		dayZero = "0";	
	std::cout << year << "-" << monthZero << month << "-" << dayZero << day << " => " << value << " = " << result << std::endl;
}