#include <iostream>

double square(double lenght);
double cube(double lenght);

int main()
{

	/* return = Return a value back to the spot where you called the encompassing function.
	 */

	double lenght{5.0};
	double area{square(lenght)};
	double volume{cube(lenght)};

	std::cout << "Area " << area << " cm^2\n";
	std::cout << "Volume " << volume << " cm^3\n";

	return 0;
}
double square(double lenght)
{

	double result = lenght * lenght;
	return result;
}
double cube(double lenght)
{

	double result = lenght * lenght * lenght;
	return result;
}