#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    // ▼ Arguments checks
    if (ac != 2) {
        std::cerr << "Error: right format is \".btc <database>\"" << std::endl;
        return 1;
    }
    std::ifstream data("./data.csv");
	if (!data) {
		std::cerr << "Impossible to open the data.csv file" << std::endl;
		return 1; 
    }
	// ▼ Database creation
    BitcoinExchange* Bitcoin = new BitcoinExchange(&data);
	std::string file(av[1]); 
	std::ifstream values("./" + file);
	if (!values) {
		std::cerr << "Impossible to open the file to evaluate" << std::endl;
	}
	Bitcoin->printValues(values);
    delete Bitcoin;  

    return 0;
}