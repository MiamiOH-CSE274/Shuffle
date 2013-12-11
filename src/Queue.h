//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/06/26

//This tells the compiler that we are making a data structure
// to hold items of type T, but that we are not going to specify what
// T is until later
template <class T>
class Queue {
  //This header file is an INTERFACE for a queue. 
  //Because C++ does not support the concept of an interface, we
  // instead use a class declaration to mimic an interface. Notice
  // that we declare only the public methods of the Queue class,
  // but no data members, and no private methods. This is similar
  // to what we would do in a Java interface

  //Syntax note: In C++ you don't put private/protected/public on each
  // individual member function or variable. Instead, we declare a section
  // as public, and now everything that comes afterward will be public, until
  // we chage it. See ArrayQueue.h for another example.
 public:

  //Add the input item to the back of the queue
  //If it is impossible to do so (perhaps your are out of memory)
  // then throw a string exception.
  //Syntax note: C++ does not have the "abstract" keyword,
  // so to get an abstract function we have to do 2 things:
  // 1) Declare it to be virtual
  // 2) Add "=0" to the declaration to tell the compiler that
  //    the function will never be implemented
  virtual void add(T toAdd) = 0;
  //Remove the first item from the queue, and return it
  //If the queue is empty, throw a string exception
  virtual T remove() = 0;

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems() = 0;
};
