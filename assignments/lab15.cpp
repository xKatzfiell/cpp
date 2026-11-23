/*
 * This program asks the user for an output file name.
 * If the file cannot be opened, it displays an error message.
 * Otherwise, it reads words or phrases until the user enters "123".
 * It converts each character to its integer code and writes
 * the codes to the file, with one line for each entered text.
 */

#include <iostream>
#include <string>
#include <fstream>

int main()
{
    // Define the variables.
    std::string fileName{};    // Stores the output file name.
    std::ofstream outputFile;  // Writes data to the output file.
    std::string text{};        // Stores the word or phrase.

    // Get the output file name from the user.
    std::cout << "Enter the name of the output file.\n";
    std::getline(std::cin, fileName);

    // Open the file for writing.
    outputFile.open(fileName);

    // Display an error message if the file cannot be opened.
    if (!outputFile)
    {
        std::cout << "\nError, unable to open the output file.\n";
    }
    else
    {
        // Ask the user for the first word or phrase.
        std::cout << "Enter a word or phrase [enter 123 to end input].\n";

        // Read whole lines until input fails or the user enters "123".
        while (std::getline(std::cin, text) && text != "123")
        {
            // Check each character in the entered text.
            for (unsigned int i = 0; i < text.length(); i++)
            {
                // Write the character's integer code followed by a space.
                outputFile << static_cast<int>(text[i]) << ' ';
            }

            // Start a new line in the file after each word or phrase.
            outputFile << '\n';

            // Ask the user for another word or phrase.
            std::cout
                << "Enter another word or phrase [enter 123 to end input].\n";
        }

        // Close the output file after processing the entered text.
        outputFile.close();
    }

    return 0;
}