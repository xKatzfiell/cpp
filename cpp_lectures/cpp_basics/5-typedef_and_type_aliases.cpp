#include <iostream>

typedef std::string text_t;
// using text_t = std::string;

int main()
{

    /* typedef = Reserved keyword used to create an additional name (alias) for another "data type".
                New identifier for an existing type helps with readability and reduces typos.
                Use when there is a clear benefit replaced with 'using' (work better w/ templates)
    */

    text_t name = "Can";
    std::string lastname = "Yilmaz";

    std::cout << name << " " << lastname;

    return 0;
}