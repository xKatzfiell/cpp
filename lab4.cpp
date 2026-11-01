
/*  This code finds the first character of two given words.
 *   Then, it combines the given words (first plus second, and second plus first in that order)
 *   and finds middle characters of these combined words.
 */

#include <iostream>
#include <string> // needs for string function

int main()
{

  // Define the variables.
  std::string firstWord{};  // Stores the first word as a string.
  std::string secondWord{}; // Stores the second word as a string
  int lenghtWords{};        // It will store the lenght of two words later.

  // Take inputs from the user, and use getline to include white spaces.
  std::cout << "Please enter a word or phrase.\n";
  std::getline(std::cin, firstWord);

  std::cout << "Enter a second word or phrase.\n";
  std::getline(std::cin, secondWord);

  // Find the lengths of the two given words and divide them by two to find middle characters.
  lenghtWords = ((firstWord + secondWord).size()) / 2;

  // Find and print first characters of given words by using .at function.
  std::cout << "\nThe first character of \"" << firstWord << "\" is: " << firstWord.at(0) << "\n";
  std::cout << "The first character of \"" << secondWord << "\" is: " << secondWord.at(0) << "\n";

  // Combine the first and second words in that order, then print it.
  std::cout << "\nThe second string concatenated after the last character of the first string is:\n";
  std::cout << "\t" << firstWord + secondWord << std::endl;

  // Print the middle characters of the combined word.
  std::cout << "\tThe middle character of this string is: " << (firstWord + secondWord).at(lenghtWords);

  // Combine the second and first words in that order, then print it.
  std::cout << "\nThe first string concatenated after the last character of second string is:\n";
  std::cout << "\t" << secondWord + firstWord << std::endl;

  // Print the middle characters of the combined word.
  std::cout << "\tThe middle character of this string is: " << (secondWord + firstWord).at(lenghtWords);

  return 0;
}