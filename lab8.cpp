/*
 * This code takes the amount of the stock sale from the user
 * and calculates the sales commission based on the sales volume.
 * Then, it prints the total commission.
 */

#include <iostream>
#include <iomanip>

int main()
{
    // Define the variables.
    const int PRECISION{2};          // Stores the value of precision.
    const double BASE_COMISSION{35}; // Stores the value of base commission, in dollars.
    double salesComission{};         // Stores the value of sales commission.
    double stockSale{};              // Stores the stock sale amount, taken from the user.

    // Take the amount of the stock sale from the user.
    std::cout << "Please enter the amount of the stock sale: $ ";
    std::cin >> stockSale;

    // If stock sale less or equal to zero,
    // It prints the "Error" message.
    if (stockSale <= 0)
    {
        std::cout << "\nError, invalid sales amount entered.";
    }

    // If stock sale is greater than zero and less or equal to 500,
    // It calculates the commission and prints it.
    else if (stockSale > 0 && stockSale <= 500)
    {
        salesComission = BASE_COMISSION;
        std::cout << "\nThe commission is $" << std::fixed << std::setprecision(PRECISION) << salesComission;
    }

    // If stock sale is greater than 500 and less or equal to 1500,
    // It calculates the commission and prints it.'
    else if (stockSale > 500 && stockSale <= 1500)
    {
        salesComission = BASE_COMISSION + (stockSale - 500) * 2 / 100;
        std::cout << "\nThe commission is $" << std::fixed << std::setprecision(PRECISION) << salesComission;
    }

    // If stock sale is greater than 1500 and less or equal to 10000,
    // It calculates the commission and prints it.
    else if (stockSale > 1500 && stockSale <= 10000)
    {
        salesComission = (BASE_COMISSION + 10) + (stockSale - 1500) * 1 / 100;
        std::cout << "\nThe commission is $" << std::fixed << std::setprecision(PRECISION) << salesComission;
    }

    // If stock sale is greater than 10000 and less or equal to 100000,
    // It calculates the commission and prints it.
    else if (stockSale > 10000 && stockSale <= 100000)
    {
        salesComission = (BASE_COMISSION + 95) + (stockSale - 10000) * 0.75 / 100;
        std::cout << "\nThe commission is $" << std::fixed << std::setprecision(PRECISION) << salesComission;
    }

    // If stock sale is greater than 100000
    // It prints the constant sale commission.
    else
    {
        salesComission = 1000;
        std::cout << "\nThe commission is $" << std::fixed << std::setprecision(PRECISION) << salesComission;
    }

    return 0;
}