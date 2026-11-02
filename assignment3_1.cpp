/*
 * This program gets a seed value from the user.
 * It generates pseudorandom numbers based on the user's seed and prints them.
 * Then, it generates pseudorandom numbers based on the current time and prints them.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Defines the variable.
    unsigned int seed{}; // Stores the value of seed.

    // Get input from the user.
    std::cout << "Enter a seed for the random number generator: ";
    std::cin >> seed;

    // Seed the random number generator using the stored value.
    srand(seed);

    // Call rand() to generate and print 5 pseudorandom numbers.
    std::cout << "First 5 numbers (seed = user input): "
              << rand() << ", "
              << rand() << ", "
              << rand() << ", "
              << rand() << ", "
              << rand();

    // Seed the random number generator using the current time.
    srand(time(0));

    // Skip to the next line.
    std::cout << std::endl;

    // Call rand() to generate and print 5 new pseudorandom numbers.
    std::cout << "First 5 numbers (seed = current time): "
              << rand() << ", "
              << rand() << ", "
              << rand() << ", "
              << rand() << ", "
              << rand();

    return 0;
}