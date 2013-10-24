//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List <T> {
 private:
  struct Node{
    T data;
    Node* next;
    Node* prev;
  };

 public:
  //See List.h for documentation of these methods
  //Return the number of items currently in the List
  virtual unsigned long size();

  //Get the value at index i, and return it.
  // If list does not contain i items, throw a string exception
  virtual T get(unsigned long i);

  //Set the value at index i to x
  // If list does not contain i items, throw a string exception
  virtual void set(unsigned long i, T x);

  //Add a new item, x, at position i. All items that were originally
  // at position i or higher get moved forward 1 to make room.
  // If list does not contain i items, throw a string exception
  virtual void add(unsigned long i, T x);

  //Remove the item at position i. All items that were originally
  // at position i+1 or higher get moved backwards 1 to fill the gap.
  // If list does not contain i items, throw a string exception
  virtual void remove(unsigned long i);

  //Optional, but may be useful in the Shuffle project
  //Remove len items, starting with index i, and insert into target list
  // at position t. 
  virtual void splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t);

  //Initialize all private member variables.
  // Be sure to create the dummy node using "new"
  LinkedList();
  //Delete any dynamically allocated memory. You will need to loop
  // through all your nodes, deleting them one at a time
  virtual ~LinkedList();

 private:
  //Pointer to the dummy node.
  Node* dummyNode;

  //Return a pointer to item i.
  //Special cases: If i == (numItems), return a pointer to the dummyNode
  //If i is an invalid number, throw a string exception
  Node* find(unsigned long i);
  
  //Number of items in the list
  unsigned long numItems;
};

#include "LinkedList.ipp"
