/*
 *  This code calculates the Hypotenus.
 *   And prints it with two digits after the decimal point.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{

    // Define the variables.
    double firstSide{};  // Stores the value of the first side of triangle.
    double secondSide{}; // Stores the value of the second side of triangle.
    double hypotenuse{}; // Stores the hypotenuse value.

    // Take the value of the first triangle side and calculate its square.
    std::cout << "Enter first triangle side: " << std::endl;
    std::cin >> firstSide;
    firstSide = (firstSide * firstSide);

    // Take the value of second triangle side and calculate its square.
    std::cout << "Enter second triangle side: " << std::endl;
    std::cin >> secondSide;
    secondSide *= secondSide;

    // Calculate the square root of values and find the Hypotenuse. Then print it.
    hypotenuse = sqrt(firstSide + secondSide);
    std::cout << std::fixed << std::setprecision(2) << "Hypotenuse: " << hypotenuse << std::endl;

    return 0;
}