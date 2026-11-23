/*
 * This program reads a seed value and generates an initial account balance.
 * It asks the user to choose an ATM transaction.
 * The user can check the balance, deposit money, or withdraw money.
 * It checks the transaction choice and amounts, then displays the balance
 * or an error message.
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

// Declare the functions defined after main.
void printErrorMessage();
double deposit(double balance);
double withdrawal(double balance);

int main()
{
    // Read the seed and initialize the pseudorandom number generator.
    double seed{};
    std::cin >> seed;
    srand(seed);
    
    // Generate an initial account balance from $0 to $10,000.
    double balance{static_cast<double>(rand() % 10001)};

    // Store the user's transaction choice.
    char choice{};

    // Display the ATM menu and read the user's choice.
    std::cout << "\tATM Menu\n"
              << "\nB - Check account balance\n"
              << "D - Deposit money\n"
              << "W - Withdraw money\n"
              << "\nEnter the letter of your desired transaction: ";
    std::cin >> choice;

    // Accept balance, deposit, and withdrawal choices
    // in either uppercase or lowercase.
    if (choice == 'B' || choice == 'b' ||
        choice == 'D' || choice == 'd' ||
        choice == 'W' || choice == 'w')
    {
        // Process a deposit and update the balance.
        if (choice == 'D' || choice == 'd')
        {
            balance = deposit(balance);
        }

        // Process a withdrawal and update the balance.
        else if (choice == 'W' || choice == 'w')
        {
            balance = withdrawal(balance);
        }
        
    // Display the balance with two digits after the decimal point.
    std::cout << std::fixed << std::setprecision(2) 
            << "\nYour balance is $" << balance << ".";
    }
    
    // Display an error message if the transaction choice is invalid.
    else
    {   
        printErrorMessage();
    }
    
    // End the output with a newline.
    std::cout << std::endl;

    return 0;
}

/*
 * Displays an error message for an invalid transaction choice.
 * Parameters: none.
 * Output: a message indicating that the transaction choice is invalid.
 * Return type: void.
 */
void printErrorMessage()
{
    std::cout << "\nInvalid transaction choice.";
    return;
}

/*
 * Reads a deposit amount and adds it to the balance if it is positive.
 * Parameter: balance (double) is the current account balance.
 * Input: the deposit amount (double).
 * Output: an input prompt and an error message if the amount is invalid.
 * Returns: the updated balance (double), or the original balance
 * if the deposit amount is invalid.
 */
double deposit(double balance)
{
    // Store the user's deposit amount.
    double deposit{};
    
    // Ask the user for the deposit amount.
    std::cout << "Enter your deposit amount: ";
    std::cin >> deposit;

    // Reject deposit amounts that are zero or negative.
    if (deposit <= 0)
    {
        std::cout << "\nInvalid deposit amount.\n";
    }
    // Add a valid deposit amount to the balance.
    else
    {
        balance += deposit;
    }

    // Return the balance after processing the deposit.
    return balance;
}

/*
 * Reads a withdrawal amount and subtracts it if sufficient funds exist.
 * Parameter: balance (double) is the current account balance.
 * Input: the withdrawal amount (double).
 * Output: an input prompt and an error message if the amount is
 * nonpositive or exceeds the available balance.
 * Returns: the updated balance (double), or the original balance
 * if the withdrawal cannot be completed.
 */
double withdrawal(double balance)
{
    // Store the user's withdrawal amount.
    double withdraw{};

    // Ask the user for the withdrawal amount.
    std::cout << "Enter your withdrawal amount: ";
    std::cin >> withdraw;

    // Reject withdrawal amounts that are zero or negative.
    if (withdraw <= 0)
    {
        std::cout << "\nInvalid withdrawal amount.\n";
    }

    // Reject withdrawals that exceed the available balance.
    else if (withdraw > balance)
    {
        std::cout << "\nYou do not have sufficient funds for this withdrawal.\n";
    }

    // Subtract a valid withdrawal amount from the balance.
    else
    {
        balance -= withdraw;
    }
    
    // Return the balance after processing the withdrawal.
    return balance;
}