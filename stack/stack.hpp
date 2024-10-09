#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
   std::vector<T> values;

public:
   Stack() : values(std::vector<T>()) {};

   void push(T value)
   {
      values.push_back(value);
   }

   T peek()
   {
      return values.back();
   }

   T pop()
   {
      T value = values.back();
      values.pop_back();
      return value;
   }

   void clear()
   {
      values.clear();
   }

   bool isEmpty() const
   {
      return values.empty();
   }

   void print() const
   {
      for (auto val : values)
      {
         std::cout << val << std::endl;
      }
   }
};

#endif