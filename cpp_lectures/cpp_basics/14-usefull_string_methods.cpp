#include <iostream>
#include <string>

int main()
{

    // https://cplusplus.com/reference/string/string/

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    /*
    if(name.length() > 12){
        std::cout << "Your name can not be over 12 characters!";
    }
    else{
        std::cout << "Welcome! " << name;
    }
    */

    /*
    if(name.empty()){
        std::cout << "You didn't enter your name!";
    }
    else{
        std::cout << "Welcome! " << name;
    }
    */

    // name.clear();
    // name.append("@gmail.com");
    // std::cout << "Hello " << name;

    // std::cout << name.at(0);

    // name.insert(0, "@");
    // std::cout << name;

    // std::cout << name.find(" ");

    name.erase(0, 3);
    std::cout << name;

    return 0;
}