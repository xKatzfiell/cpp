#include <iostream>

int main()
{

    char op;
    double num1{};
    double num2{};
    double result{};

    std::cout << "*********** Calculator ***********" << std::endl;

    std::cout << "Choose an operator ( + - * /): ";
    std::cin >> op;

    std::cout << "Choose first number: ";
    std::cin >> num1;

    std::cout << "Choose second number: ";
    std::cin >> num2;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        std::cout << "Result: " << result << std::endl;
        break;

    case '-':
        result = num1 - num2;
        std::cout << "Result: " << result << std::endl;
        break;

    case '*':
        result = num1 * num2;
        std::cout << "Result: " << result << std::endl;
        break;

    case '/':
        result = num1 / num2;
        std::cout << "Result: " << result << std::endl;
        break;

    default:
        std::cout << "Choose a valid operator!" << std::endl;
    }

    std::cout << "**********************************" << std::endl;

    return 0;
}