#include <iostream>
#include <ctime>

int main()
{

    /* pseudo-random = Not truly random (but close)
     */

    srand(time(NULL));

    int randNum = (rand() % 6) + 1;

    std::cout << randNum;

    return 0;
}