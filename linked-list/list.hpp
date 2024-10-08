#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class Node
{
public:
   T value;
   Node<T> *prev;
   Node<T> *next;
   Node(T value) : value(value), prev(nullptr), next(nullptr) {};
};

template <typename T>
class List
{
private:
   Node<T> *head;
   Node<T> *tail;
   int size;
   Node<T> *nodeAt(int idx)
   {
      if (idx > this->size - 1 || idx < 0)
      {
         throw std::out_of_range("Invalid index");
      }

      Node<T> *val = this->head;

      for (int i = 0; i < idx; ++i)
      {
         val = val->next;
      }

      return val;
   }

public:
   List() : head(nullptr), tail(nullptr), size(0) {};
   T at(int idx)
   {
      if (idx > this->size - 1 || idx < 0)
      {
         throw std::out_of_range("Invalid index");
      }

      Node<T> *val = this->head;

      for (int i = 0; i < idx; ++i)
      {
         val = val->next;
      }

      return val->value;
   }
   T last() const
   {
      if (this->size == 0)
      {
         throw std::out_of_range("Invalid index");
      }

      return this->tail->value;
   }
   T first() const
   {
      if (this->size == 0)
      {
         throw std::out_of_range("Invalid index");
      }

      return this->head->value;
   }
   void prepend(Node<T> *value)
   {
      if (this->head == nullptr)
      {
         this->head = value;
         this->tail = value;
      }
      else
      {
         Node<T> *prevHead = this->head;
         this->head = value;
         this->head->next = prevHead;
         prevHead->prev = this->head;
      }

      ++this->size;
   }
   void prepend(T value)
   {
      this->prepend(new Node<T>(value));
   }
   void append(Node<T> *value)
   {
      if (this->tail == nullptr)
      {
         this->tail = value;
         this->head = value;
      }
      else
      {
         /*
                  3 -> 5 -> 6[tail]   (9)
            (1)   3 -> 5 -> 6  (9)
            (2)   3 -> 5 ->
         */
         Node<T> *prevTail = this->tail;
         this->tail = value;
         this->tail->prev = prevTail;
         this->tail->prev->next = this->tail;
      }

      ++this->size;
   }
   void append(T value)
   {
      this->append(new Node<T>(value));
   }
   void remove(int idx)
   {
      if (idx > this->size - 1 || idx < 0)
      {
         throw std::out_of_range("Invalid index");
      }

      Node<T> *currentNode = this->nodeAt(idx);
      Node<T> *nextNode = currentNode->next;
      Node<T> *prevNode = currentNode->prev;

      if (prevNode == nullptr)
      {
         this->head = nextNode;
         nextNode->prev = nullptr;
      }
      else
      {
         prevNode->next = nextNode;
      }

      if (nextNode == nullptr)
      {
         this->tail = prevNode;
         prevNode->next = nullptr;
      }
      else
      {
         nextNode->prev = prevNode;
      }

      delete currentNode;
      --this->size;
   }
   void print()
   {
      Node<T> *v = this->head;

      while (v != nullptr)
      {
         std::cout << v->value << " " << std::endl;
         v = v->next;
      }
   }
   int length() const
   {
      return this->size;
   }
};

#endif