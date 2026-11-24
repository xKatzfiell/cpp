#include <iostream>
#include <ctime>
int main()
{

    int guess;
    int tries{};
    int nums;

    srand(time(NULL));
    int num = (rand() % 100) + 1;

    std::cout << "************** GUESS GAME **************\n";

    do
    {
        std::cout << "Enter a guess between (1-100): ";
        std::cin >> guess;

        tries += 1;

        if (guess > num)
        {
            std::cout << "Down!\n";
        }
        else if (guess < num)
        {
            std::cout << "Up!\n";
        }
        else
        {
            std::cout << "Yes correct! # tries of: " << tries << "\n";
        }

    } while (guess != num);

    std::cout << "******************************************";

    return 0;
}