#include <iostream>

int main()
{

    /*
        This code takes two numbers from the user,
        and makes calculations. Then prints the results.
    */

    // Define the variables. I used {} to initialize them to zero to prevent the garbage values.

    double dividend{};
    double divisor{};

    // Get the values from the user.

    std::cout << "Enter a whole number that is the dividend: ";
    std::cin >> dividend;
    std::cout << "Enter a whole number that is the divisor: ";
    std::cin >> divisor;

    // Display information about the calculation before calculating

    std::cout << "\nWe will divide " << dividend << " by " << divisor << "\n";

    // Makes calculations.

    int result_1 = dividend / divisor;
    double result_2 = dividend / divisor;

    // Prints the results to the screen.

    std::cout << "\nThe quotient of the integer division is: " << result_1 << std::endl;
    std::cout << "The quotient of the double division is: " << result_2 << std::endl;

    return 0;
}