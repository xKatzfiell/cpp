#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loadMorseArray(std::string[], std::ifstream&);
void genMorse(std::string&, const std::string, const std::string[]);

int main()
{
    std::string morseCodes[26];
    std::ifstream morseFile{"morseLetters.txt"};
    std::string line{};
    std::string converted{};
    std::string inputName{};
    std::string outputName{};

    if (!morseFile)
    {
        std::cout << "Error, unable to open file morseLetters.txt.\n";
    }
    else if (!loadMorseArray(morseCodes, morseFile))
    {
        std::cout << "Error, unable to load Morse codes.\n";
    }
    else
    {
        std::cout << "Please enter the input file name: ";
        std::getline(std::cin, inputName);

        std::ifstream inputFile(inputName);

        if (!inputFile)
        {
            std::cout << "Error, unable to open file " << inputName << ".\n";
        }
        else
        {
            std::cout << "Please enter the output file name: ";
            std::getline(std::cin, outputName);

            std::ofstream outputFile(outputName);

            if (!outputFile)
            {
                std::cout << "Error, unable to open file " << outputName << ".\n";
            }
            else
            {
                int lineCount{0};

                while (std::getline(inputFile, line))
                {
                    genMorse(converted, line, morseCodes);
                    outputFile << converted << '\n';
                    lineCount++;
                }

                if (lineCount > 0)
                {
                    std::cout << "Translation complete. " << lineCount << " lines translated.\n";
                }
            }
        }
    }

    return 0;
}

bool loadMorseArray(std::string morseCodes[], std::ifstream& morseFile)
{
    char letter{};
    int count{0};
    bool isLoaded{false};

    while (count < 26 && (morseFile >> letter >> morseCodes[count]))
    {
        count++;
        
        if (count == 26)
        {
            isLoaded = true;
        }
    }

    return isLoaded;
}

void genMorse(std::string& output, const std::string input, const std::string morseCodes[])
{
    output.clear();

    for (int i = 0; i < static_cast<int>(input.length()); i++)
    {
        char ch = input[i];

        if (ch == ' ' || ch == '.')
        {
            output += ch;
        }
        else
        {
            int index = ch % 'A';

            output += morseCodes[index];
            output += ' ';
        }
    }
}