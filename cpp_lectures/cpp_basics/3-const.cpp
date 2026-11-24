#include <iostream>

int main()
{

    /* The const keyword specifies that a variable's value is constant
        tells the compiler to prevent anything from modifying it.
        (read-only)
    */

    const int LIGHT_SPEED = 299979245;
    // int LIGHT_SPEED = 1;
    const double PI = 3.14;
    // double PI = 3;
    const char FIRST_LETTER_OF_NAME = 'C';
    // char FIRST_LETTER_OF_NAME = 'A';
    const bool STUDENT = true;
    // bool STUDENT = false;
    const std::string HEIGHT = "6feet";
    // std::string HEIGHT = "1feet";

    std::cout << LIGHT_SPEED << " " << PI << " " << FIRST_LETTER_OF_NAME << " " << STUDENT << " " << HEIGHT << "\n";
    return 0;
}