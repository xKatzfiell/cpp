/*
 * This program gets a compass heading in degrees from the user.
 * If the heading is less than 0 or greater than 360, it prints
 * an error message and asks again.
 * Then, it calculates and prints the bearing. It prints North or South,
 * the angle with one digit after the decimal point, and East or West.
 */

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;    // I do not prefer to use namespace.
                        // However, if I do not use in this case it is giving an error.

// Function declaration.
void getBearing(double heading, std::string& face, double& angle, std::string& turn);
bool readHeading(double& heading);

int main()
{

    // Define the variables.
    double heading{};       // Stores the heading entered by the user.
    std::string face{};     // Stores North or South.
    double angle{};         // Stores the calculated angle in degrees.
    std::string turn{};     // Stores East or West.

    // Get the heading from the user and check whether it is valid.
    if(readHeading(heading))
    {
        // Calculate the bearing by using the given heading.
        getBearing(heading, face, angle, turn);
        // Print the bearing with one digit after the decimal point.
        std::cout << std::fixed << std::setprecision(1)
                  << face  << " " << angle << " degrees " << turn << std::endl;
    }

    return 0;
}

/*
 * Reads a compass heading and asks again if it is out of range.
 * Parameter: heading stores the input.
 * Input: the compass heading in degrees.
 * Output: an input prompt and an error message for an invalid heading.
 * Returns: true  when the heading is from 0 to 360 degrees.
 */
bool readHeading(double& heading)
{

    bool isValid{false};    // Stores whether the heading is valid.

    // Keep asking until the heading is within the range.
    do{
        // Ask the user for the heading and read the input.
        std::cout << "Enter a compass heading [0-360 degrees]: ";
        std::cin >> heading;

        // If the heading is less than 0 or greater than 360,
        // print an error message.
        if(heading < 0 || heading > 360)
        {
            std::cout << "\nError invalid heading entered.\n";
        }
        
        else
        {
            // Set isValid to true if the heading is in range.
            isValid = true;
        }
        
    }while(!(isValid));

    return isValid;
}

/*
 * Calculates the bearing using the given compass heading.
 * Parameters: heading is the heading from 0 to 360 degrees.
 *             face stores North or South.
 *             angle stores the calculated angle.
 *             turn stores East or West.
 * Returns: void.
 */
void getBearing(double heading, std::string& face, double& angle, std::string& turn)
{
    // If the heading is 90 or less, use it as the angle east of North.
    if (heading <= 90.0)
    {
        face = "North";
        angle = heading;
        turn = "East";
    }
    
    // If the heading is greater than 90 and less than or equal to 180,
    // subtract it from 180 to find the angle east of South.
    else if (heading <= 180.0)
    {
        face = "South";
        angle = 180.0 - heading;
        turn = "East";
    }

    // If the heading is greater than 180 and less than 270,
    // subtract 180 from it to find the angle west of South.
    else if (heading < 270.0)
    {
        face = "South";
        angle = heading - 180.0;
        turn = "West";
    } 
    
    // Otherwise, subtract the heading from 360
    // to find the angle west of North.
    else
    {
        face = "North";
        angle = 360.0 - heading;
        turn = "West";
    }
}
