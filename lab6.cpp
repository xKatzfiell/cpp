/*
 *  This code gets the sale price from the user, and calculates tip rates.
 *  Then prints sales amount, tip amount and total amount in order.
 */

#include <iostream>
#include <iomanip>

int main()
{
    // Define the variables.
    double salePrice{};  // Stores the value of sale price.
    double tip{};        // Stores the value of tip.
    const int PREC{2};   // Stores the value of setprecision.
    const int WIDTH{15}; // Stores the value of setw.

    // Get input from the user.
    std::cout << "Enter the amount of the sale in $: ";
    std::cin >> salePrice;

    // Use functions to set decimal before printed it.
    std::cout << std::fixed << std::setprecision(PREC);

    // Calculate the tip rate by using sale price, then print it.
    std::cout << "\n20% tip: " << "$" << (salePrice * 20) / 100 << std::endl;
    std::cout << "22% tip: " << "$" << (salePrice * 22) / 100 << std::endl;
    std::cout << "25% tip: " << "$" << (salePrice * 25) / 100 << std::endl;
    std::cout << std::endl;

    // Get input from the user.
    std::cout << "Enter the amount of the tip in $: ";
    std::cin >> tip;

    // Skip to the next line.
    std::cout << std::endl;

    // Use io manipulators to set decimal before print it.
    std::cout << std::fixed << std::setprecision(PREC);

    // Print sales amount, tip amount and total amount in order.
    std::cout << std::left << std::setw(WIDTH)
              << "Sales Amount:" << "$" << salePrice << std::endl;
    std::cout << std::left << std::setw(WIDTH)
              << "Tip Amount:" << "$" << tip << std::endl;
    std::cout << std::left << std::setw(WIDTH)
              << "Total:" << "$" << salePrice + tip << std::endl;

    return 0;
}