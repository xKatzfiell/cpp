/*
 * This code simulates rolling two dice using pseudorandom numbers
 * and display a message based on the sum of the dice numbers.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Define the seed and take input.
    int seed{};       // Stores the value of seed.
    std::cin >> seed; // Take the seed from ZyBook.

    // Use the seed to initialize the pseudorandom number generator.
    srand(seed);

    // Define the variables and call the rand() function to generate pseudorandom numbers from 1 to 6.
    int dice1{(rand() % 6) + 1}; // Stores the value of dice1.
    int dice2{(rand() % 6) + 1}; // Stores the value of dice2.

    // Print generated numbers.
    std::cout << "Die 1: " << dice1 << std::endl;
    std::cout << "Die 2: " << dice2 << std::endl;

    // If the sum of dice1 and dice2 is 7 or 11,
    // print "Player loses." message.
    if ((dice1 + dice2) == 7 || (dice1 + dice2) == 11)
    {
        std::cout << "\nPlayer loses." << std::endl;
    }
    // If the sum of dice1 and dice2 is 2 or 3,
    // print "Player wins." message.
    else if ((dice1 + dice2) == 2 || (dice1 + dice2) == 3)
    {
        std::cout << "\nPlayer wins." << std::endl;
    }
    // If the sum of dice1 and dice2 is 12,
    // print "Start over." message.
    else if (dice1 + dice2 == 12)
    {
        std::cout << "\nStart over." << std::endl;
    }
    // Otherwise, print "Keep rolling." message.
    else
    {
        std::cout << "\nKeep rolling." << std::endl;
    }

    return 0;
}