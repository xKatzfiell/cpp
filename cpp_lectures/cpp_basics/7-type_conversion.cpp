#include <iostream>

int main()
{

    /* type conversion = Conversion a value of one data type to another.
                        Implict = Automatic.
                        Explicit = Precede value with new data type.
    */

    // double x = 3.14;
    double x = (int)3.14;

    std::cout << x << std::endl;

    int corrects = 8;
    int questions = 10;
    double score = corrects / (double)questions * 100;

    std::cout << score << "%";

    return 0;
}