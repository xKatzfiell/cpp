#include <iostream>

int main()
{

    // integer (whole number)

    int x;  // declaration
    x = 20; // assignment

    int y = 10; // mixed

    int sum = x + y;
    int multiple = x * y;
    int divide = x / y;

    std::cout << x << std::endl;
    std::cout << y << "\n";
    std::cout << sum << "\n";
    std::cout << multiple << "\n";
    std::cout << divide << "\n";

    // double (number including decimal)

    double gpa = 4.0;
    double point = 3.67;

    std::cout << gpa * point << "\n";

    // single character

    char grade = 'A';

    std::cout << grade << "\n";

    // boolean (true or false)

    bool student = true;
    bool power = false;

    std::cout << student << "\n";
    std::cout << power << "\n";

    // string (objects that represents a squence of text)

    std::string name = "Can";

    std::cout << name << "\n";

    return 0;
}