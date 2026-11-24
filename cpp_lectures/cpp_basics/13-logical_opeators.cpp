#include <iostream>

int main()
{

    /* && = Check if two conditions are true.
        || = Check if at least one of two conditions are true.
        ! = Reserves the logical state of its operand.
    */

    int temp{};

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    /*
    if(temp > 0 && temp < 30){
        std::cout << "The temperature is good\n";
    }
    else{
        std::cout << "The temperatur is bad\n";
    }
    */

    if (temp <= 0 || temp >= 30)
    {
        std::cout << "The temperature is bad\n";
    }
    else
    {
        std::cout << "The temperature is good\n";
    }

    bool sunny{true};

    /*
    if(sunny){
        std::cout << "It is sunny outside";
    }
    else{
        std::cout << "It is cloudy outside";
    }
    */

    if (!sunny)
    {
        std::cout << "It is cloudy outside";
    }
    else
    {
        std::cout << "It is sunny outside";
    }

    return 0;
}