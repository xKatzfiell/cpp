/*
 *  This code gets value of angle from the user. It converts to the radian type.
 *  Calculates the values of cosinus, sinus and tangent.
 *  Print the lines of the table in order.
 *  Then, in the third line, it prints calculated values of the trigonometric functions.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    // Define the variables.
    const double PI{acos(-1)}; // Stores the value of PI.
    const int WIDTH{10};       // Stores the value of setw function's width.
    const int PREC{4};         // Stores the value of setprecision function's.
    double angle{};            // Stores  the value of angle as a zero, but it will be replaced.

    // Get inputer from the user.
    std::cout << "Enter an angle in degrees (between 0 and 90): ";
    std::cin >> angle;

    // Calculate the values of trigonometric functions by using given angle.
    double angleInRadians{angle * PI / 180}; // It converts the degree to radian.
    double cosine{cos(angleInRadians)};      // Calculates the value of cosinus.
    double sine{sin(angleInRadians)};        // Calculates the value of sinus.
    double tangent{tan(angleInRadians)};     // Calculates the value of tangent.

    // Skip to the next line.
    std::cout << std::endl;

    // Print the first line of the table.
    std::cout << std::setw(WIDTH) << "Angle" << "|" << std::setw(WIDTH) << "Angle" << "|\n";

    // Print the second line of the table.
    std::cout << std::setw(WIDTH) << "Degrees" << "|" << std::setw(WIDTH) << "Radians" << "|"
              << std::setw(WIDTH) << "Cosine" << "|" << std::setw(WIDTH) << "Sine" << "|"
              << std::setw(WIDTH) << "Tangent" << "\n";

    // Print the third line with calculated values of the table.
    std::cout << std::setw(WIDTH) << angle << "|" << std::setw(WIDTH) << angleInRadians << "|"
              << std::fixed << std::setprecision(PREC) << std::setw(WIDTH) << cosine << "|"
              << std::setw(WIDTH) << sine << "|" << std::setw(WIDTH) << tangent;
    return 0;
}