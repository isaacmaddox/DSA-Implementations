#include "list.hpp"
#include <iostream>

int main()
{
   List<int> list;

   list.append(3);
   list.append(4);
   list.append(5);
   list.prepend(2);
   list.prepend(1);
   list.prepend(-200);

   list.print();

   std::cout << std::endl
             << "Item at index 2: " << list.at(2) << std::endl
             << std::endl;

   list.remove(2);

   list.print();

   std::cout << std::endl
             << std::endl
             << "List size is " << list.length() << std::endl;

   return EXIT_SUCCESS;
}