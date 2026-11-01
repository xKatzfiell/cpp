/*
 *   This code converts the given seconds to hours, minutes and seconds.
 *   Then prints the converted hours, minutes and second.
 */

#include <iostream>

int main()
{

    // Define the values.
    const int SEC_PER_MIN = 60;    // Stores the value of seconds per minutes as a constant.
    const int SEC_PER_HOUR = 3600; // Stores the value of seconds per hour as a constant.
    int seconds{};                 // Stores the value of total seconds as a zero, but it will be replaced by user's input.

    // Give the information about program.
    std::cout << "This program converts a time entered in seconds to hours, minutes, and seconds.\n";

    // Get value from the user.
    std::cout << "Please enter a time in seconds: ";
    std::cin >> seconds;

    // Make calculations such as hours, minutes and seconds. Then print it.
    std::cout << std::endl
              << seconds << " seconds is:\n";
    std::cout << "\t" << seconds / SEC_PER_HOUR << " hours\n";
    std::cout << "\t" << (seconds % SEC_PER_HOUR) / SEC_PER_MIN << " minutes\n";
    std::cout << "\t" << ((seconds % SEC_PER_HOUR) % SEC_PER_MIN) << " seconds\n";

    return 0;
}