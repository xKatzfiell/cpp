/* A program that gets two whole numbers from the user and finds and displays the following:
   the difference between the first and second numbers entered, the quotient produced when
   the first number entered is divided by the second, and finally the
   remainder produced when the first number entered is divided by the second.
*/

#include <iostream>

int main()
{

    int firstNumber{};
    int secondNumber{};

    std::cout << "Please enter a whole number: ";
    std::cin >> firstNumber;

    std::cout << "Please enter another whole number: ";
    std::cin >> secondNumber;

    std::cout << "\nThe difference is: " << firstNumber - secondNumber << std::endl;
    std::cout << "The quotient is: " << firstNumber / secondNumber << std::endl;
    std::cout << "The remainder of the division is: " << firstNumber % secondNumber << std::endl;

    return 0;
}