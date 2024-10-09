#include "stack.hpp"
#include <iostream>

int main()
{
   Stack<int> s;

   s.push(2);
   s.push(5);
   s.push(7);
   s.push(9);

   s.print();

   std::cout << std::endl;

   s.pop();
   s.pop();

   std::cout << s.peek() << std::endl;

   s.clear();

   s.print();
}