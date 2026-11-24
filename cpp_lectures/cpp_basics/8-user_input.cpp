#include <iostream>
#include <string>

int main()
{

    /* cout << (insertion operator)
        cin >> (extraction operator)
    */

    std::string name;
    int age;

    std::cout << "What is your full name?: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "How old are you?: ";
    std::cin >> age;

    std::cout << "Hello " << name << "." << " You are " << age << " years old.";

    return 0;
}