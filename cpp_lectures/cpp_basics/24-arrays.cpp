#include <iostream>

int main()
{

	/* array = A data structure that can hold multiple values
				values are accesed by an index number
				"kind of like a variable that holds multiple values"
	*/

	std::string cars[] = {"Porsche", "BMW", "Mercedes"};

	std::cout << cars[0] << "\n";
	std::cout << cars[1] << "\n";
	std::cout << cars[2] << "\n";

	std::cout << "********************\n";

	std::string names[3];

	names[0] = "Tarik";
	names[1] = "Yigit";
	names[2] = "Ali";

	std::cout << names[0] << "\n";
	std::cout << names[1] << "\n";
	std::cout << names[2] << "\n";

	return 0;
}