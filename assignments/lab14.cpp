/*
 * This program asks the user to enter a line of text.
 * It asks again if the entered text is empty.
 * Then, it counts the commas and space characters in the text
 * and displays their total.
 */

#include <iostream>
#include <string>

// Declare the functions defined after main.
std::string getString(std::string prompt);
bool isCommaOrSpace(char character);

int main()
{
    // Define the variables.
    unsigned int commaAndSpace{};   // Stores the total number of commas and spaces.
    std::string text{};             // Stores the text as a string.

    // Get a non-empty line of text from the user.
    text = getString("Please enter a line of text.");

    // Check each character in the entered text.
    for (unsigned int i{0}; i < text.size(); i++)
    {
        // Increase the count if the character is a comma or a space.
        if (isCommaOrSpace(text[i]))
        {
            commaAndSpace++;
        }
    }

    // Print the total number of commas and space characters.
    std::cout << "\nThe entered text contains " << commaAndSpace
              << " commas and space characters." << std::endl;

    return 0;
}

/*
 * Reads a line of text and asks again if it is empty.
 * Parameter: prompt (std::string) is the message shown to the user.
 * Input: a line of text (std::string).
 * Output: the prompt and an error message for each empty entry.
 * Returns: the non-empty text entered by the user (std::string).
 */
std::string getString(std::string prompt)
{
    std::string text; // Stores the line entered by the user.

    // Display the prompt and read the whole line, including spaces.
    std::cout << prompt << std::endl;
    std::getline(std::cin, text);

    // Keep asking until the user enters a non-empty line.
    while (text.empty())
    {
        // Display an error message and read a new line.
        std::cout << "\nError, empty string received." << std::endl;
        std::cout << prompt << std::endl;
        std::getline(std::cin, text);
    }

    // Return the non-empty text.
    return text;
}

/*
 * Checks whether the given character is a comma or a space.
 * Parameter: character (char) is the character to check.
 * Returns: true (bool) if the character is a comma or a space;
 * otherwise, false.
 */
bool isCommaOrSpace(char character)
{
    bool CommaOrSpace{false}; // Stores whether the character is a comma or a space.

    // Set the result to true if the character is a comma or a space.
    if (character == ',' || character == ' ')
    {
        CommaOrSpace = true;
    }

    return CommaOrSpace;
}