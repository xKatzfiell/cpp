#include <iostream>

int main()
{

    /*
        This code get initials from the user as a char.
        Then, converts the chars to integers and add one to each integer.
        Finally, it displays the new char to the user.
    */

    // Define the variables.

    char firstInitial;
    char lastInitial;
    int firstInitialValue;
    int lastInitialValue;

    // Get the inputs from the user.

    std::cout << "Enter your first initial: ";
    std::cin >> firstInitial;

    std::cout << "Enter your last initial: ";
    std::cin >> lastInitial;

    // Convert the chars to their integer.

    firstInitialValue = static_cast<int>(firstInitial);

    lastInitialValue = static_cast<int>(lastInitial);

    // Display the original chars and their integers. Then, display the new char with one added to its integer.

    std::cout << "\n"
              << firstInitial << " has code " << firstInitialValue << std::endl;
    std::cout << firstInitialValue << " plus one is " << firstInitialValue + 1 << " which is the character " << static_cast<char>(firstInitial + 1) << "\n";

    std::cout << "\n"
              << lastInitial << " has code " << lastInitialValue << std::endl;
    std::cout << lastInitialValue << " plus one is " << lastInitialValue + 1 << " which is the character " << static_cast<char>(lastInitial + 1) << "\n";

    return 0;
}