#include <iostream>

int main()
{

	// sizeof() = Determines the size in bytes of a: variable, data type, class, objects, etc.

	std::string name = "Katzfiell";
	char grade{'A'};
	double gpa{4.0};
	bool student{true};
	char grades[]{'A', 'B', 'C', 'D', 'E'};
	std::string students[]{"Tarik", "Yigit", "Ali"};

	std::cout << sizeof(students) / sizeof(std::string) << " Elements\n";

	return 0;
}