/*
 * This program reads a random number seed and the number of die rolls.
 * It uses the seed to initialize the random number generator.
 * Then, it generates values from 1 through 6 and counts each result.
 * If the number of rolls is greater than zero, it displays each face's
 * frequency and percentage of the total rolls.
 * The results are right aligned, and the percentages are displayed
 * with one digit after the decimal point.
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

// Function declaration.
void dispFreqAndPercentages(unsigned int faceOfRoll[7], unsigned int numberOfRoll);

int main()
{
    // Define the variables,
    unsigned int numberOfRoll{};    // Stores the number of rolls requested.
    unsigned int faceOfRoll[7]{};   // Stores the counts for faces 1-6.
    double seed{};                  // Stores the random number seed.

    // Read the seed used to generate the random numbers.
    std::cin >> seed;

    // Initialize the random number generator with the given seed.
    srand(seed);

    // Ask for the number of times to roll the die.
    std::cout << "Please enter the number of times to roll the die: ";
    std::cin >> numberOfRoll;

    std::cout << std::endl;

    // Roll the die and display results only when the roll count is positive.
    if (numberOfRoll > 0)
    {
        // Generate one result for each requested roll.
        for (unsigned int i{0}; i < numberOfRoll; i++)
        {
            int number = rand() % 6 + 1; // Stores the current die face, 1-6.

            // Increase the counter for the face that was rolled.
            faceOfRoll[number]++;
        }

        // Display the frequency and percentage for each face.
        dispFreqAndPercentages(faceOfRoll, numberOfRoll);
    }
    
    return 0;
}

/*
 * Displays the frequency and percentage for each die face.
 * Parameters: faceOfRoll is an unsigned int array containing the counts
 *             for faces 1-6. The element at index 0 is not used.
 *             numberOfRoll is an unsigned int containing the total rolls.
 *             The number of rolls must be greater than zero.
 * Output: each face number, its frequency, and its percentage of the rolls.
 *         The percentages are displayed with one decimal place.
 * Returns: void.
 */
void dispFreqAndPercentages(unsigned int faceOfRoll[7], unsigned int numberOfRoll)
{
    // Visit the six face counters, skipping the unused element at index 0.
    for (int i{1}; i <= 6; i++)
    {
        // Divide this face's count by the total rolls and multiply by 100.
        double percentage = (faceOfRoll[i] * 100.0) / numberOfRoll;

        // Display the labeled results, right aligning the numeric values.
        std::cout << "Face #" << i << ":" 
                  << " Frequency:" << std::setw(6) << std::right << faceOfRoll[i]
                  << " Percentage: " << std::setw(5) << std::fixed << std::setprecision(1) << std::right << percentage
                  << std::endl;
    }

}