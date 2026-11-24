#include <iostream>

void printInfo(const std::string name, const int age);

int main()
{

	/* cons parameter = Parameter that is effectively read-only
						code is more secure & conveys intent
						useful for references and pointers.
	*/

	std::string name{"Can"};
	int age{18};

	printInfo(name, age);

	return 0;
}

void printInfo(const std::string name, const int age)
{
	/*	name = " ";		It won't work.
		age = " ";
	*/

	std::cout << name << "\n";
	std::cout << age << "\n";
}
