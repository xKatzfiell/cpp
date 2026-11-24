#include <iostream>

int main()
{

	std::string students[]{"Tarik", "Yigit", "Ali", "Muharrem", "Can", "Toygu"};

	for (int i{0}; i < sizeof(students) / sizeof(std::string); i++)
	{
		std::cout << students[i] << "\n";
	}

	char grades[]{'A', 'B', 'C', 'D', 'E', 'F'};

	for (int i{0}; i < sizeof(grades) / sizeof(char); i++)
	{
		std::cout << grades[i] << "\n";
	}

	return 0;
}