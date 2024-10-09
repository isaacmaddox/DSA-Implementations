#include "list.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
void printList(LinkedList<T> &list, int lineWidth = 20)
{
   std::cout << std::endl
             << std::setw(lineWidth) << std::setfill('-') << "" << std::endl;

   if (!list.isEmpty())
      list.print();
   else
      std::cout << "  List is empty";

   std::cout
       << std::endl
       << std::setw(lineWidth) << std::setfill('-') << std::left << "" << std::endl;
}

int main()
{
   using std::cout, std::endl;
   LinkedList<int> list;

   cout << "Empty List Constructor" << endl;

   list.append(5);
   list.append(7);
   list.prepend(6);

   list.remove(1);

   printList(list);

   list.clear();

   printList(list);

   cout << endl
        << "Array List Constructor" << endl;

   std::string arr[2] = {"Hello", "World "};
   LinkedList<std::string> list2(arr, 2);

   printList(list2);

   list2.remove(1);

   printList(list2);

   cout << endl
        << "Vector List Constructor" << endl;

   std::vector<char> vec({'a', 'b', 'c', 'd'});

   LinkedList<char> list3(vec);

   printList(list3);

   list3.prepend('i');

   printList(list3);

   list3.clear();

   printList(list3);

   return EXIT_SUCCESS;
}