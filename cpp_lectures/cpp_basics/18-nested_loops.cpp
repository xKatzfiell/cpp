#include <iostream>

int main(){

    /* loop(){
            loop(){

            }
        }
    */

    int columns;
    std::cout << "How many columns?: ";
    std::cin >> columns;

    int rows;
    std::cout << "How many rows?: ";
    std::cin >> rows;

    char symbol;
    std::cout << "Enter a symbol to use: ";
    std::cin >> symbol;


    for(int i{1}; i <= columns; i += 1){
       for(int j{1}; j <= rows; j++){
        std::cout << symbol << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}