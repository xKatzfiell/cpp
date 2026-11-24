#include <iostream>

int main()
{

    /* break = Break out of a loop.
        continue = Skip current iteration.
    */

    for (int i{1}; i <= 20; i++)
    {
        if (i == 13)
        {
            break;
            // continue;
        }
        std::cout << i << "\n";
    }

    return 0;
}