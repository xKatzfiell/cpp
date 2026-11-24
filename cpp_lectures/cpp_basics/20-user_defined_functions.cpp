#include <iostream>

void happyBirthday(std::string name, int age);

int main()
{

    /* function = A block of reusable code.
     */

    std::string name = "Katz";
    int age{20};

    happyBirthday(name, age);

    return 0;
}

void happyBirthday(std::string name, int age)
{
    std::cout << "Happy birthday to " << name << "\n";
    std::cout << "Happy birthday to " << name << "\n";
    std::cout << "Happy birthday dear " << name << "\n";
    std::cout << "Happy birthday to " << name << "\n";
    std::cout << "You are " << age << " years old!\n";
}