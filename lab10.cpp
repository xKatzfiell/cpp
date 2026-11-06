/*
 * This code gets the radius of a sphere from the user.
 * If the radius is greater than zero, it calculates the volume
 * and surface area and displays them with three decimal places.
 * Otherwise, it displays an error message.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

// Function prototypes.
double findVolume(double radius);
double findSurfaceArea(double radius);
void printCalculatedValues(double radius, double volume, double surfaceArea);

// Calculate pi using the inverse cosine of -1.
double const PI{acos(-1)};

int main()
{
    // Define the variable.
    double radius{}; // Radius of the sphere entered by the user.

    // Display the heading.
    std::cout << "\t\tSphere Calculator\n";

    // Ask the user for the radius and read the input.
    std::cout << "\nPlease enter the radius of a sphere: ";
    std::cin >> radius;

    // Display an error if the radius is zero or negative.
    if (radius <= 0)
    {
        std::cout << "\nError, the radius must be greater than 0!\n";
    }
    else
    {
        // Calculate the volume and surface area using the functions.
        // Store the returned values in the variables.
        double volume = findVolume(radius);
        double surfaceArea = findSurfaceArea(radius);

        // Display the radius and calculated values.
        printCalculatedValues(radius, volume, surfaceArea);
    }

    return 0;
}

// Receives the sphere's radius as a double.
// Calculates the volume.
// Returns the volume as a double.
double findVolume(double radius)
{
    double volume = (4.0 / 3) * PI * (radius * radius * radius);
    return volume;
}

// Receives the sphere's radius as a double.
// Calculates the surface area.
// Returns the surface area as a double.
double findSurfaceArea(double radius)
{
    double surfaceArea = 4.0 * PI * (radius * radius);
    return surfaceArea;
}

// Receives the radius, volume, and surface area as double values.
// Displays them with three decimal places and appropriate units.
// Returns no value.
void printCalculatedValues(double radius, double volume, double surfaceArea)
{
    // Display the radius with three decimal places.
    std::cout << std::fixed << std::setprecision(3) << "\nA sphere with a radius of " << radius << " has:\n";

    // Display the volume in cubic units.
    std::cout << std::fixed << std::setprecision(3) << "\tVolume = " << volume << " cubic units.\n";

    // Display the surface area in square units.
    std::cout << std::fixed << std::setprecision(3) << "\tSurface area = " << surfaceArea << " square units.\n";

    return;
}