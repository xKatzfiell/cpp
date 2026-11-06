/* This code calculates how long sound takes to travel through a selected medium.
 * First, the user selects a medium and enters a distance in feet.
 * Then, the code checks the inputs and calculates the travel time by dividing the distance
 * by the speed of sound. Finally, it displays an error message or the travel time in seconds.
 */

#include <iostream>
#include <iomanip>

int main()
{

    // Define the variables.
    const double WOOD{12631.230};  // Stores the speed of sound in wood, feet per second.
    const double STEEL{10614.815}; // Stores the speed of sound in steel, feet per second.
    const double WATER{4714.572};  // Stores the speed of sound in water, feet per second.
    const double AIR{1125.334};    // Stores the speed of sound in air, feet per second.
    unsigned int medium{};         // Stores the value of medium.
    double distance{};             // Stores the value of distance, in feet.
    double time{};                 // Stores the value of time, in seconds.

    // Display the menu and get the user's medium choice.
    std::cout << "\tTime for Sound to Travel through a Medium given Distance\n"
              << "\n1 - Wood\n"
                 "2 - Steel\n"
                 "3 - Water\n"
                 "4 - Air\n"
              << "\nEnter the number of the medium: ";
    std::cin >> medium;

    // Check if the choice does not match any of the options.
    // If it does not match, print an error message.
    if (medium < 1 || medium > 4)
    {
        std::cout << "\nError, invalid medium!\n"
                  << "Please run the program again.";
    }

    else
    {
        // Get distance from the user.
        std::cout << "Enter the distance to travel (in feet): ";
        std::cin >> distance;

        // Check if the distance is less than or equal to zero.
        // If it is, display an error message.
        if (distance <= 0)
        {
            std::cout << "\nInput error! The distance must be greater than zero.";
        }

        // Calculate the travel time based on selected medium.
        // Then, print the result.
        else
        {
            switch (medium)
            {
            case 1:
                time = distance / WOOD;
                std::cout << std::fixed << std::setprecision(4) << "\nIn wood it will take " << time << " seconds to travel "
                          << std::setprecision(1) << distance << " feet.";
                break;

            case 2:
                time = distance / STEEL;
                std::cout << std::fixed << std::setprecision(4) << "\nIn steel it will take " << time << " seconds to travel "
                          << std::setprecision(1) << distance << " feet.";
                break;

            case 3:
                time = distance / WATER;
                std::cout << std::fixed << std::setprecision(4) << "\nIn water it will take " << time << " seconds to travel "
                          << std::setprecision(1) << distance << " feet.";
                break;

            case 4:
                time = distance / AIR;
                std::cout << std::fixed << std::setprecision(4) << "\nIn air it will take " << time << " seconds to travel "
                          << std::setprecision(1) << distance << " feet.";
                break;
            }
        }
    }

    return 0;
}