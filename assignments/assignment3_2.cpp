/*
 * This program gets a seed value from the ZyBooks and generates two pseudorandom numbers.
 * It asks to the user a substraction question using two numbers.
 * Then, it checks the user's answer and prints the answer.
 * Finally, it displays the correct calculation.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Define the variables.
    unsigned int seed{}; // Stores the value of seed.
    std::cin >> seed;    // Takes the value of seed from ZyBooks.
    int answer{};        // Stores the value of answer.
    int userAnswer{};    // Stores the value of user's answer.

    // Use the seed to initialize the pseudorandom number generator.
    srand(seed);

    // Generate pseudorandom numbers.
    int numberOne{rand() % 10}; // Stores the value of number one.
    int numberTwo{rand() % 10}; // Stores the value of number two.

    // If numberOne is greater than numberTwo,
    // subtract numberTwo from numberOne.
    if (numberOne > numberTwo)
    {
        // Take the answer from the user.
        std::cout << "What is " << numberOne << " - " << numberTwo << "? " << std::endl;
        std::cin >> userAnswer;

        // Calculate the answer.
        answer = numberOne - numberTwo;

        // Check whether the user's answer is correct.
        if (answer == userAnswer)
        {
            // If answer is correct, then print the message.
            std::cout << "Your answer is correct!" << std::endl;
        }
        else
        {
            // Otherwise, print the incorrect message.
            std::cout << "Your answer is incorrect!" << std::endl;
        }

        // Print the calculation formula.
        std::cout << std::endl
                  << numberOne << " - " << numberTwo << " = " << answer << std::endl;
    }

    // If numberTwo is greater than numberOne,
    // subtract numberOne from numberTwo.
    else
    {

        // Take the answer from the user.
        std::cout << "What is " << numberTwo << " - " << numberOne << "? " << std::endl;
        std::cin >> userAnswer;

        // Calculate the answer.
        answer = numberTwo - numberOne;

        // Check whether the user's answer is correct.
        if (answer == userAnswer)
        {
            // If answer is correct, then print the correct message.
            std::cout << "Your answer is correct!" << std::endl;
        }
        else
        {
            // Otherwise, print the incorrect message.
            std::cout << "Your answer is incorrect!" << std::endl;
        }

        // Print the whole calculation proccess.
        std::cout << std::endl
                  << numberTwo << " - " << numberOne << " = " << answer << std::endl;
    }

    return 0;
}