#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include <vector>

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
class LinkedList
{
private:
   /**
    * A pointer to the first element in the LinkedList
    */
   Node<T> *head;
   /**
    * A pointer to the last element in the LinkedList
    */
   Node<T> *tail;
   /**
    * The size of the linked LinkedList
    */
   int size;
   /**
    * Retrieve a pointer to the node at a particular index
    *
    * @param idx The index of the node to find
    * @throws std::out_of_range - If the index is invalid
    */
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
   /**
    * Create an empty linked list
    */
   LinkedList() : head(nullptr), tail(nullptr), size(0) {};

   /**
    * Create a linked list with an array of values
    *
    * @param values The array of values
    * @param size The size of the array, which will become the size of the linked list
    */
   LinkedList(T *values, int size) : head(nullptr), tail(nullptr), size(0)
   {
      for (int i = 0; i < size; ++i)
      {
         this->append(values[i]);
      }
   }

   LinkedList(std::vector<T> &values) : head(nullptr), tail(nullptr), size(0)
   {
      for (auto value : values)
      {
         this->append(value);
      }
   }

   /**
    * Get the value of the node at an index
    *
    * @param idx The index to retrieve the value of
    * @returns The value of the node at index `idx`
    * @throws std::out_of_range - If the specified index is invalid
    */
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

   /**
    * Get the value of the last node in the linked list, also known as the tail
    *
    * @returns The value of the last node in the linked list
    * @throws std::out_of_range - If the list is empty
    */
   T last() const
   {
      if (this->size == 0)
      {
         throw std::out_of_range("Invalid index");
      }

      return this->tail->value;
   }

   /**
    * Get the value of the first node in the linked list, also known as the head
    *
    * @returns The value of the first node in the linked list
    * @throws std::out_of_range - If the list is empty
    */
   T first() const
   {
      if (this->size == 0)
      {
         throw std::out_of_range("Invalid index");
      }

      return this->head->value;
   }

   /**
    * Add a node to the beginning of the linked list
    *
    * @param value A pointer to the node to prepend
    */
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

   /**
    * Add a value to the front of the list
    *
    * @param value The value to add to the list
    */
   void prepend(T value)
   {
      this->prepend(new Node<T>(value));
   }

   /**
    * Add a node to the end of the list
    *
    * @param value A pointer to the node to append
    */
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

   /**
    * Add a value to the end of the list
    *
    * @param value The value to append
    */
   void append(T value)
   {
      this->append(new Node<T>(value));
   }

   /**
    * Remove the node at a particular index
    */
   void remove(int idx)
   {
      if (idx > this->size - 1 || idx < 0)
      {
         throw std::out_of_range("Invalid index");
      }

      Node<T> *currentNode = this->nodeAt(idx);
      Node<T> *nextNode = currentNode->next;
      Node<T> *prevNode = currentNode->prev;

      if (prevNode == nullptr && nextNode != nullptr)
      {
         this->head = nextNode;
         this->head->prev = nullptr;
      }
      else if (prevNode != nullptr)
      {
         prevNode->next = nextNode;
      }

      if (nextNode == nullptr && prevNode != nullptr)
      {
         this->tail = prevNode;
         prevNode->next = nullptr;
      }
      else if (nextNode != nullptr)
      {
         nextNode->prev = prevNode;
      }

      if (nextNode == nullptr && prevNode == nullptr)
      {
         this->head = nullptr;
         this->tail = nullptr;
      }

      delete currentNode;
      --this->size;
   }

   void clear()
   {
      while (this->head != nullptr)
      {
         this->remove(0);
      }
   }

   /**
    * Print the list out. This will print each item
    * in the list on a newline.
    */
   void print() const
   {
      Node<T> *v = this->head;

      while (v != nullptr)
      {
         std::cout << "  " << v->value << " ";
         if (v != this->tail)
         {
            std::cout << std::endl;
         }
         v = v->next;
      }
   }

   /**
    * Get the length of the linked list
    *
    * @returns The length of the list
    */
   int length() const
   {
      return this->size;
   }

   /**
    * Return whether or not the linked list is empty
    *
    * @returns Whether the list is empty
    */
   bool isEmpty() const
   {
      return this->size == 0;
   }
};

#endif