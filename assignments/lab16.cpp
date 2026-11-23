/*
 * This program asks the user for a sales data file name.
 * It reads the store numbers and sales amounts from the file.
 * Then, it displays each store's sales and a bar chart.
 * Each dollar sign represents $1,000 in sales.
 * It displays an error message if the file cannot be opened
 * or no sales records can be read.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    // Define the variables.
    unsigned int storeNumber{}; // Stores the store number.
    double storeSales{};        // Stores the store's sales amount.
    std::string dataName{};     // Stores the input file name.
    std::ifstream inputFile{};  // Reads data from the input file.
    int dataCount{};            // Stores the number of records read.
    char dollarSign{'$'};      // Stores the character used for the bars.

    // Get the sales data file name from the user.
    std::cout << "Enter the name of the file that contains the sales data.\n";
    std::getline(std::cin, dataName);

    // Open the file for reading.
    inputFile.open(dataName);

    // Read and display the sales data if the file opens.
    if (inputFile)
    {
        // Print the chart heading and explain the dollar signs.
        std::cout
            << "\n\n\tSALES BARCHART - Each $ represents $1,000 in sales.\n\n";

        // Read a store number and sales amount for each record.
        while (inputFile >> storeNumber && inputFile >> storeSales)
        {
            // Display the store number, sales amount, and sales bar.
            // Divide sales by 1,000 to find the number of dollar signs.
            std::cout << "Store Number:"
                      << std::setw(5) << std::right << storeNumber
                      << std::fixed << std::setprecision(2)
                      << "\tSales:"
                      << std::setw(10) << std::right << storeSales
                      << "\t"
                      << std::string((storeSales / 1000), dollarSign)
                      << std::endl;

            // Increase the number of records read.
            dataCount++;
        }

        // Display an error message if no sales records were read.
        if (dataCount == 0)
        {
            std::cout << "Unable to read sales record from the file.";
        }

        // Close the input file.
        inputFile.close();
    }
    else
    {
        // Display an error message if the file cannot be opened.
        std::cout << "Error, unable to open the input file.\n";
    }

    return 0;
}