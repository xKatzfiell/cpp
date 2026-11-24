#include <iostream>
#include <string>

int main()
{

	/* fill() = Fills a range of elements with a specified value
				fill(begin, end,  value)
	*/

	const int SIZE = 100;
	std::string foods[SIZE];

	fill(foods, foods + (SIZE / 4), "Lahmmacun");
	fill(foods + (SIZE / 4), foods + (SIZE / 4) * 2, "Pide");
	fill(foods + (SIZE / 4) * 2, foods + (SIZE / 4) * 3, "Etli ekmek");
	fill(foods + (SIZE / 4) * 3, foods + (SIZE / 4) * 4, "Doner");

	for (std::string food : foods)
	{
		std::cout << food << "\n";
	}

	return 0;
}
