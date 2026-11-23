/*
 * This program asks the user for an input file name.
 * It reads numbers from the file and checks their values.
 * Numbers from 18 through 60 are valid.
 * It writes invalid numbers to badvalues.txt with three decimal places.
 * Then, it displays the total, valid, and invalid value counts.
 * It displays the average of the valid numbers with one decimal place,
 * or a message if there are no valid numbers.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    // Define the variables.
    std::string fileName{};       // Stores the input file name.
    std::ifstream fileInput{};    // Reads numbers from the input file.
    std::ofstream fileOutput{};   // Writes invalid numbers to a file.
    double validValues{};        // Stores the sum of valid numbers.
    double averageValidValues{}; // Stores the average of valid numbers.
    int countValidValues{};      // Stores the number of valid values.
    double badValues{};          // Stores the sum of invalid numbers.
    int countBadValues{};        // Stores the number of invalid values.
    double value{};              // Stores the current number read.

    // Get the input file name from the user.
    std::cout << "Enter the input file name.\n";
    std::getline(std::cin, fileName);

    // Open the input file and the file for invalid numbers.
    fileInput.open(fileName);
    fileOutput.open("badvalues.txt");

    // Display an error message if the input file cannot be opened.
    if (!fileInput)
    {
        std::cout << "Error, the file \"" << fileName
                  << "\" could not be opened.\n";
    }
    else
    {
        // Read and check each number until no more numbers can be read.
        while (fileInput >> value)
        {
            // Numbers below 18 or above 60 are invalid.
            if (value < 18 || value > 60)
            {
                // Add the invalid number to its sum and increase its count.
                badValues += value;
                countBadValues++;

                // Write the invalid number with three decimal places.
                fileOutput << std::fixed << std::setprecision(3)
                           << value << std::endl;
            }
            else
            {
                // Add the valid number to its sum and increase its count.
                validValues += value;
                countValidValues++;
            }
        }

        // Display the total, valid, and invalid value counts.
        std::cout << "\nTotal number of values read: "
                  << (countBadValues + countValidValues) << std::endl
                  << "Valid values read: "
                  << countValidValues << std::endl
                  << "Invalid values read: "
                  << countBadValues << std::endl;

        // Display a message if no valid numbers were read.
        if (countValidValues == 0)
        {
            std::cout << "The file did not contain any valid values.\n";
        }
        else
        {
            // Calculate the average of the valid numbers.
            averageValidValues = validValues / countValidValues;

            // Display the average of the valid numbers with one decimal place.
            std::cout << std::fixed << std::setprecision(1)
                      << "The average of the valid numbers read is "
                      << averageValidValues << ".\n";
        }
    }

    // Close the input and output files.
    fileInput.close();
    fileOutput.close();

    return 0;
}