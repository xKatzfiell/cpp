/*
 * This program asks the user to enter a Fahrenheit temperature of 120 or lower.
 * It converts the entered temperature and the following temperatures
 * to Celsius, increasing the Fahrenheit value by 4 each time.
 * Then, it displays the temperatures up to 120 Fahrenheit in a table
 * with one digit after the decimal point.
 */

#include <iostream>
#include <iomanip>

int main()
{

    // Define the variables.
    double fahrenheit{}; // Stores the Fahrenheit temperature.
    double celsius{};    // Stores the calculated Celsius temperature.

    // Get the starting Fahrenheit temperature from the user.
    std::cout << "Enter a Fahrenheit temperature of 120 or lower: ";
    std::cin >> fahrenheit;
    
    // Skip to the next line.
    std::cout << std::endl;


        // Display the table only if the entered temperature is 120 or lower.
        if (fahrenheit <= 120){
        // Print the headings of the table.
        std::cout << "|" << std::setw(10) << std::right
                  << "Fahrenheit" << "|"
                  << std::setw(8) << std::right
                 << "Celsius" << "|" << std::endl;

        // Repeat the conversion while the Fahrenheit temperature is 120 or lower.
        do{
        {           
            // Print the Fahrenheit temperature with one decimal place.
            std::cout << std::fixed << std::setprecision(1) 
                      << "|" << std::setw(10) << std::right
                      << fahrenheit << "|";
            
            // Convert the current Fahrenheit temperature to Celsius.
            celsius = (5.0 / 9) * (fahrenheit - 32.0);

            // Increase the Fahrenheit temperature by 4 for the next row.
            fahrenheit += 4;

            // Print the Celsius temperature in the same row.
            std::cout << std::setw(8) << std::right
                      << celsius << "|" << std::endl;
        }
        } while (fahrenheit <= 120);
    }

    return 0;
}