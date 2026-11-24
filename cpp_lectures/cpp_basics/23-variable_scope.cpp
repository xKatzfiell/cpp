#include <iostream>

void printNum();
int myNum{1};

int main()
{

	/* local variables = Declared inside a function or block {}.
		global variables = Declared outside of all functions.
	*/

	int myNum{2};

	printNum();
	std::cout << myNum << "\n";

	return 0;
}

void printNum()
{
	int myNum{3};
	std::cout << ::myNum << "\n";
}