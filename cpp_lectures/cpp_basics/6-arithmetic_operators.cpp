#include <iostream>

int main()
{

   /* arithmetic operators = Return the result of a specific arithmetic operation.
                             ( +, -,  *, /, % )
   */

   int students = 20;
   /* students = students + 1;
      students+=1;
      students++;
   */

   /* students = students - 1;
      students-=1;
      students--;
   */

   /* students = students * 2;
      students *=2;
   */

   /* students = students / 2;
      students /=2;
   */

   int remainder = students % 3;

   std::cout << remainder << std::endl;
   std::cout << students;

   return 0;
}