#include <iostream>
#include <cmath>


int main(){

    double a;
    double b;
    double c;

    std::cout << "What is the first side of the triangle?: ";
    std::cin >> a;

    std::cout << "What is the second side of the triangle?: ";
    std::cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));

    std::cout << "Hypothenuse is " << c;
    return 0;
}