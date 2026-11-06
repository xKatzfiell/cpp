/*
 * This program asks the user to enter a sales amount.
 * It provides preset tip percentages and custom tip options.
 * It checks the sales amount, menu choice, and custom tip values.
 * If the entries are valid, it displays the sales amount,
 * tip amount, and total amount due.
 */

#include <iostream>
#include <iomanip>

using namespace std;    // I do not prefer to use namespace,
                        // However if I do not use in this case it is giving an error.

// Declare the functions defined after main.
char getMenuItem(double salesAmount);
double calcTipAmt(double salesAmount, double percentageOfTip);
double calcTotalSale(double salesAmount, double amountOfTip);
bool checkValid(double salesAmount, double percentageOfTip, double amountOfTip);

int main()
{

    // Define the variables used for the sale and tip.
    double salesAmount{};        // Stores the amount before the tip.
    double percentageOfTip{};    // Stores the tip percentage.
    double amountOfTip{};        // Stores the tip amount.
    char choice{};               // Stores the menu choice.
    bool validChoice{true};      // Tracks whether it is valid.
    
    // Ask the user for the .
    std::cout << "Enter the amount of the sale: ";
    std::cin >> salesAmount;

    // Display the menu only if the initial values are valid.
    if (checkValid(salesAmount, percentageOfTip, amountOfTip))
        {
            choice = getMenuItem(salesAmount);

            if (choice == 'T' || choice == 't')
            {
                 // Set the tip percentage to 10 percent.
                percentageOfTip = 10.0;
            }
            else if (choice == 'F' || choice == 'f')
            {
                // Set the tip percentage to 15 percent.
                percentageOfTip = 15.0;
            }
            else if (choice == 'W' || choice == 'w')
            {
                // Set the tip percentage to 20 percent.
                percentageOfTip = 20.0;
            }

            // Ask the user for a custom tip percentage.
            else if (choice == 'P' || choice == 'p')
            {
                std::cout << "Enter a custom percentage: ";
                std::cin >> percentageOfTip;
            }
            
            // Ask the user for a custom tip amount.
            else if (choice == 'A' || choice == 'a')
            {
                std::cout << "Enter a custom amount: ";
                std::cin >> amountOfTip;
            }

            // Display an error message for an invalid menu choice.
            else
            {
                std::cout << "\nError, invalid menu choice entered.\n";
                validChoice = false;
            }

            // Continue if the menu choice and numeric values are valid.
            if (validChoice &&
                checkValid(salesAmount, percentageOfTip, amountOfTip))
            {
                // Calculate the tip unless the user entered a tip amount.
                if (choice != 'A' && choice != 'a')
                {
                    amountOfTip = calcTipAmt(salesAmount, percentageOfTip);
                }

                // Display the sales amount, tip amount, and total due.
                std::cout << "\nSales Amount: $" << salesAmount
                        << "\nTip Amount: $" << amountOfTip
                        << "\nTotal Due: $"
                        << calcTotalSale(salesAmount, amountOfTip)
                        << '\n';
            }
        }

    return 0;
}

/*
 * Calculates the tip using the sales amount and tip percentage.
 * Parameters: salesAmount (double) is the amount before the tip.
 *             percentageOfTip (double) is the tip percentage.
 * Returns: the calculated tip amount (double).
 */
double calcTipAmt(double salesAmount, double percentageOfTip)
{
    // Convert the percentage to a decimal and multiply by the sale.
    return salesAmount * percentageOfTip / 100.0;
}

/*
 * Displays the tip menu and reads the user's choice.
 * Parameter: salesAmount (double) is used to calculate preset tips.
 * Input: the user's menu choice (char).
 * Output: the menu, preset tip amounts, and an input prompt.
 * Returns: the entered menu choice (char).
 */
char getMenuItem(double salesAmount)
{
    char choice{};

    // Display the tip options and format amounts to two decimal places.
    std::cout << "\n\t\t\tTip Calculator\n"
            <<  std::fixed << std::setprecision(2) 
            << "\n\tT - 10 percent tip of $" << calcTipAmt(salesAmount, 10.0)
            << "\n\tF - 15 percent tip of $" << calcTipAmt(salesAmount, 15.0)
            << "\n\tW - 20 percent tip of $" << calcTipAmt(salesAmount, 20.0)
            << "\n\tP - Custom tip percentage "
            << "\n\tA - Custom tip amount "
            << "\nEnter your menu choice [T, F, W, P, A]: ";

    // Take the user's menu choice.
    std::cin >> choice;

    return choice;
}

/*
 * Calculates the total amount due, including the tip.
 * Parameters: salesAmount (double) is the amount before the tip.
 *             amountOfTip (double) is the tip amount.
 * Returns: the sum of the sales amount and tip (double).
 */
double calcTotalSale(double salesAmount, double amountOfTip)
{
    // Add the tip to the original sales amount.
    return salesAmount + amountOfTip;
}

/*
 * Checks whether the sales amount and tip values are allowed.
 * Parameters: salesAmount (double) must be positive.
 *             percentageOfTip (double) must be non-negative.
 *             amountOfTip (double) must be non-negative.
 * Output: an error message for the first invalid value, if any.
 * Returns: true (bool) if all values are valid; otherwise, false.
 */
bool checkValid(double salesAmount, double percentageOfTip, double amountOfTip)
{
    bool isValid{true};  // Stores whether the numeric values are valid.

    // Reject sales amounts that are zero or negative.
    if (salesAmount <= 0)
    {
        std::cout << "\nError, invalid sales amount entered.\n";
        isValid = false;
    }

    // Reject negative tip percentages.
    else if (percentageOfTip < 0)
    {
        std::cout << "\nError, invalid percentage entered.";
        std::cout << "\nValid percentages are non-negative.\n";
        isValid = false;
    }

    // Reject negative tip amounts.
    else if (amountOfTip < 0)
    {
        std::cout << "\nError, invalid tip amount entered.";
        std::cout << "\nValid amounts are non-negative.\n";
        isValid = false;
    }

    return isValid;
}