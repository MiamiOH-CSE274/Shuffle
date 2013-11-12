//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/06/26
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue <T> {
 public:
  //See Queue.h for documentation of these methods

  //This class MUST use the "circular" array concept,
  // so if I do add, remove, add, remove, add, remove ...
  // even if I do it 10000000 times, your array should not grow.
  // The array should never grow unless numItems == backingArraySize
  void add(T toAdd);
  T remove();
  unsigned long getNumItems();

  //Initialize all private member variables.
  // You initial backing array should be length 10. Allocate it
  // using "new"
  ArrayQueue();
  //Delete any dynamically allocated memory. If you are deleting
  // an array, be sure to use "delete[]" instead of "delete"
  virtual ~ArrayQueue();

 private:
  //If the backing array is too small, you may call this function.
  // It should create a new backing array twice as big as the old one,
  // and copy over the old data into the new array. It should finish
  // off by calling delete[] on the old backing array
  void grow();

  //Pointer to the array that we are using to store the queue
  T* backingArray;
  
  //The index in T where the front of the queue is.
  unsigned long front;
  //Number of items in the queue
  unsigned long numItems;

  //Number of spaces in the array pointed to by backingArray
  unsigned long backingArraySize;
};

/***
 *
 * Normally when we write C++, we put declarations in the .h file,
 * and code in a matching .cpp file. Unfortunately, when working with
 * templates, this doesn't work very well. If you tried to compile
 * ArrayQueue.ipp, it wouldn't know what type "T" is, and so couldn't
 * succeed. So when we use template classes, we have to include the
 * source code for the whole class.
 *
 **/
#include "ArrayQueue.ipp"
