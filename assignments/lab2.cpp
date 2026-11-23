/*
 *   This code converts the hours, minutes and seconds to duration in seconds.
 *   Then it sum all values and print it.
 */

#include <iostream>

int main()
{

    // Define the values type.
    int hours{};   // Stores the value of the hours as a zero, but it will be replaced by user's input.
    int minutes{}; // Stores the value of the minutes as a zero, but it will be replaced by user's input.
    int seconds{}; // Stores the value of the seconds as a zero, but it will be replaced by user's input.

    // Give information about the program.
    std::cout << "Enter the time to complete the task in hours, minutes, and seconds.\n";

    // Get values from user. And convert to it in seconds.
    std::cout << "Enter the hours: ";
    std::cin >> hours;
    hours = hours * 60 * 60;

    // Get values from user. And convert to it in seconds.
    std::cout << "Enter the minutes: ";
    std::cin >> minutes;
    minutes = minutes * 60;

    // Get values from user. And convert to it in seconds.
    std::cout << "Enter the seconds: ";
    std::cin >> seconds;

    // Sum  all the values and print the total duration in seconds as a result.
    std::cout << "\nThe duration in seconds is " << hours + minutes + seconds << "." << std::endl;

    return 0;
}