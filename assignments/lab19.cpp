/*
 * This program reads a random number seed from the user.
 * It uses the seed to initialize the random number generator.
 * Then, it fills a ten by eight integer array column by column
 * with random numbers from 1 through 10.
 * For each element, it adds the values of the neighbors above,
 * below, to the left, and to the right when those neighbors exist.
 * It displays each element's row and column indices and neighbor sum.
 */

#include <iostream>
#include <cstdlib>

using namespace std;    // I do not prefer to use namespace.
                        // However, without it, the test code gives an error.

// Declare the functions defined after main.
void createMatrix(int matrix[][8], const int rows, const int cols);
int findSumOfNeighbors(const int matrix[][8], const int i, const int j,
                       const int rows, const int cols);

int main()
{
    // Define the variables.
    int rows{10}, cols{8};  // Store the number of rows and columns.
    int i{}, j{};           // Store the current row and column indices.
    int matrix[10][8]{};    // Stores the generated random numbers.
    int seed{};             // Stores the random number seed.

    // Read the seed used to generate the random numbers.
    std::cin >> seed;

    // Initialize the random number generator with the given seed.
    srand(seed);

    // Fill the entire array before calculating any neighbor sums.
    createMatrix(matrix, rows, cols);

    // Visit each element in row order to calculate and display its result.
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            // Get the sum of the existing neighbors of this element.
            int sum = findSumOfNeighbors(matrix, i, j, rows, cols);

            // Display the element's indices and the sum of its neighbors.
            std::cout << "The sum of the neighbors of array"
                      << "[" << i << "]"
                      << "[" << j << "]" << " is " << sum << "."
                      << std::endl;
        }
    }

    return 0;
}

/*
 * Fills the array column by column with random integers from 1 through 10.
 * Parameters: matrix is a two-dimensional int array with eight columns
 *             that receives the generated random numbers.
 *             rows is a const int containing the number of rows.
 *             cols is a const int containing the number of columns.
 * Output: none. The generated numbers are stored in matrix.
 * Returns: void.
 */
void createMatrix(int matrix[][8], const int rows, const int cols)
{
    // Select one column at a time.
    for (int j = 0; j < cols; j++)
    {
        // Fill every row in this column before moving to the next column.
        for (int i = 0; i < rows; i++)
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

/*
 * Adds the existing upper, lower, left, and right neighbors of one element.
 * Parameters: matrix is a two-dimensional const int array with eight
 *             columns containing the values to examine.
 *             i is a const int containing the selected row index.
 *             j is a const int containing the selected column index.
 *             rows is a const int containing the number of rows.
 *             cols is a const int containing the number of columns.
 *             The selected indices must be within the array bounds.
 * Output: none. The array is not modified.
 * Returns: an int containing the sum of the existing neighbors.
 */
int findSumOfNeighbors(const int matrix[][8], const int i, const int j,
                       const int rows, const int cols)
{
    int sum{};  // Stores the sum of the existing neighboring values.

    // Add the upper neighbor if the element is not in the first row.
    if (i > 0)
    {
        sum += matrix[i - 1][j];
    }

    // Add the lower neighbor if the element is not in the last row.
    if (i < rows - 1)
    {
        sum += matrix[i + 1][j];
    }

    // Add the left neighbor if the element is not in the first column.
    if (j > 0)
    {
        sum += matrix[i][j - 1];
    }

    // Add the right neighbor if the element is not in the last column.
    if (j < cols - 1)
    {
        sum += matrix[i][j + 1];
    }

    return sum;
}
