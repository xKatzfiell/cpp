/*
 * This program loads the Morse codes from morseLetters.txt.
 * It asks the user for input and output file names.
 * The input text is expected to contain uppercase English letters,
 * spaces, and periods. The program converts the letters to Morse code
 * and keeps spaces, periods, and line breaks in the output file.
 * It displays an error message if a file cannot be opened or the
 * Morse codes cannot be loaded. If any lines are translated,
 * it displays the number of lines translated.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;    // I do not prefer to use namespace,
                        // However if I do not use in this case it is giving an error.

// Declare the functions defined after main.
bool loadMorseArray(std::string[], std::ifstream&);
void genMorse(std::string&, const std::string, const std::string[]);

int main()
{
    // Define the variables.
    std::string morseCodes[26];                  // Stores the Morse codes for A-Z.
    std::ifstream morseFile{"morseLetters.txt"};  // Reads the letter and code pairs.
    std::string line{};                         // Stores the current input line.
    std::string converted{};                    // Stores the translated line.
    std::string inputName{};                    // Stores the input file name.
    std::string outputName{};                   // Stores the output file name.

    // Display an error message if the Morse code file cannot be opened.
    if (!morseFile)
    {
        std::cout << "Error, unable to open file morseLetters.txt.\n";
    }
    // Load the codes and check whether all 26 pairs were read.
    else if (!loadMorseArray(morseCodes, morseFile))
    {
        std::cout << "Error, unable to load Morse codes.\n";
    }
    else
    {
        // Ask for the input file name, then open the file.
        std::cout << "Please enter the input file name: ";
        std::getline(std::cin, inputName);

        std::ifstream inputFile(inputName);

        // Display an error message if the input file cannot be opened.
        if (!inputFile)
        {
            std::cout << "Error, unable to open file " << inputName << ".\n";
        }
        else
        {
            // Ask for the output file name, then open the file.
            std::cout << "Please enter the output file name: ";
            std::getline(std::cin, outputName);

            std::ofstream outputFile(outputName);

            // Display an error message if the output file cannot be opened.
            if (!outputFile)
            {
                std::cout << "Error, unable to open file " << outputName << ".\n";
            }
            else
            {
                int lineCount{0};  // Stores the number of lines translated.

                // Read each line, translate it, and write it to the output file.
                while (std::getline(inputFile, line))
                {
                    genMorse(converted, line, morseCodes);
                    outputFile << converted << '\n';
                    lineCount++;
                }

                // Display the count if at least one line was translated.
                if (lineCount > 0)
                {
                    std::cout << "Translation complete. " << lineCount << " lines translated.\n";
                }
            }
        }
    }

    return 0;
}

/*
 * Loads 26 letter and Morse code pairs in file order.
 * Parameters: morseCodes stores the codes in A-Z order.
 *             morseFile is the open file containing
 *             the letter and code pairs in A-Z order.
 * Returns: true if all 26 pairs are read; otherwise, false.
 */
bool loadMorseArray(std::string morseCodes[], std::ifstream& morseFile)
{
    char letter{};         // Stores the letter read before each code.
    int count{0};          // Stores the number of pairs loaded.
    bool isLoaded{false};  // Tracks whether all 26 pairs were loaded.

    // Read pairs until 26 are loaded or a pair cannot be read.
    while (count < 26 && (morseFile >> letter >> morseCodes[count]))
    {
        count++;
        
        // Mark the array as loaded after reading the last pair.
        if (count == 26)
        {
            isLoaded = true;
        }
    }

    return isLoaded;
}

/*
 * Converts one input line to Morse code, keeping spaces and periods.
 * Parameters: output receives the translated line.
 *             input is the line to translate.
 *             It is expected to contain only uppercase A-Z letters,
 *             spaces, and periods.
 *             morseCodes contains the 26 codes
 *             in A-Z order.
 * Returns: void.
 */
void genMorse(std::string& output, const std::string input, const std::string morseCodes[])
{
    // Remove the previous translation before processing a new line.
    output.clear();

    // Examine each character in the input line.
    for (int i = 0; i < static_cast<int>(input.length()); i++)
    {
        char ch = input[i];  // Stores the current character.

        // Copy spaces and periods directly to the output.
        if (ch == ' ' || ch == '.')
        {
            output += ch;
        }
        else
        {
            // Map an uppercase A-Z character to its array index, 0-25.
            int index = ch % 'A';

            // Append the letter's Morse code and a separating space.
            output += morseCodes[index];
            output += ' ';
        }
    }
}
