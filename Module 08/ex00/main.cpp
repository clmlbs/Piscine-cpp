#include "easyfind.hpp"

template<typename T>
void	show_result(T& cont, int n)
{
	if (easyfind(cont, n) == true)
		std::cout << "Value: " << n << " found" << std::endl;
	else
		std::cout << "Value: " << n << " not found" << std::endl;
} 

int main(void)
{
	int values[] = {20, 5, 2023, -11, 45};
	std::list<int> list(values, values + sizeof(values) / sizeof(int));
	std::vector<int> vector(values, values + sizeof(values) / sizeof(int));
	
	std::cout << "=== LIST ===" << std::endl;
	show_result(list, 2023);
	show_result(list, 2024);
	list.push_back(2024);
	std::cout << "Adding value 2024" << std::endl;
	show_result(list, 2024);
	std::cout << "=== VECTOR ===" << std::endl;
	show_result(vector, 2023);
	show_result(vector, 2024);

	return 0;
}