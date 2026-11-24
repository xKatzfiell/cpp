#include <iostream>

int main()
{

    // integer (whole number)
    int age = 20;

    // double (number including decimal)
    double gpa = 4.0;

    // single character (char)
    char grade = 'A';

    // boolean (true or false)
    bool student = true;
    std::string ogrenciDurumu;

    if (student == true)
    {
        ogrenciDurumu = "a student";
    }
    else
    {
        ogrenciDurumu = "a not student";
    }

    // string (objects that represents a sequence of text)
    std::string school = "UTD";
    std::string name = "Can";

    std::cout << "Hello " << name << " you are " << age << " years old. Also you are " << ogrenciDurumu << " at " << school << " and your last grade is " << grade << " and GPA is " << gpa << "\n";

    return 0;
}