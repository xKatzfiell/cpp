
/*
 *   This code calculates the change amount in dollars.
 *   Then it prints change dues as dollars, quarters, dimes, nickels and pennies.
 */

#include <iostream>
#include <cmath>

int main()
{

    // Define the variables.
    double dollars{}; // Stores the value of the dollars as a zero, but it will be replaced by user's input.
    int quarters{25}; // Stores the value of the quarters.
    int dimes{10};    // Stores the value of the dimes.
    int nickels{5};   // Stores the value of the nickelss.
    int pennies{1};   // Stores the value of the pennies.

    // Get the input from user.
    std::cout << "Enter the change amount to make in dollars: ";
    std::cin >> dollars;

    /*
     *  Makes calculations.
     *  Subtracted the integer value from double value, multiplied the result by 100 to get an integer number.
     *  Then used the std::round function because of floating inaccuracy, and converted the value to an integer.
     */
    int valueQuarters = static_cast<int>(std::round((dollars - static_cast<int>(dollars)) * 100)) / quarters;
    int valueDimes = (static_cast<int>(std::round((dollars - static_cast<int>(dollars)) * 100)) % quarters) / dimes;
    int valueNickels = ((static_cast<int>(std::round((dollars - static_cast<int>(dollars)) * 100)) % quarters) % dimes) / nickels;
    int valuePennies = (((static_cast<int>(std::round((dollars - static_cast<int>(dollars)) * 100)) % quarters) % dimes) % nickels) / pennies;

    // Print the calculated values.
    std::cout << "Change Due:\n";
    std::cout << "\t" << static_cast<int>(dollars) << " dollars\n";
    std::cout << "\t" << valueQuarters << " quarters\n";
    std::cout << "\t" << valueDimes << " dimes\n";
    std::cout << "\t" << valueNickels << " nickels\n";
    std::cout << "\t" << valuePennies << " pennies\n";

    return 0;
}
