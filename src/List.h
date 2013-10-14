//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11

//This tells the compiler that we are making a data structure
// to hold items of type T, but that we are not going to specify what
// T is until later
template <class T>
class List {
  //This header file is an INTERFACE for a List. 
  //Because C++ does not support the concept of an interface, we
  // instead use a class declaration to mimic an interface. Notice
  // that we declare only the public methods of the List class,
  // but no data members, and no private methods. This is similar
  // to what we would do in a Java interface

  //Syntax note: In C++ you don't put private/protected/public on each
  // individual member function or variable. Instead, we declare a section
  // as public, and now everything that comes afterward will be public, until
  // we chage it. See LinkedList.h for another example.
 public:

  //Syntax note: C++ does not have the "abstract" keyword,
  // so to get an abstract function we have to do 2 things:
  // 1) Declare it to be virtual
  // 2) Add "=0" to the declaration to tell the compiler that
  //    the function will never be implemented

  //Return the number of items currently in the List
  virtual unsigned long size() = 0;

  //Get the value at index i, and return it.
  // If list does not contain i items, throw a string exception
  virtual T get(unsigned long i) = 0;

  //Set the value at index i to x
  // If list does not contain i items, throw a string exception
  virtual void set(unsigned long i, T x) = 0;

  //Add a new item, x, at position i. All items that were originally
  // at position i or higher get moved forward 1 to make room.
  // If list does not contain i items, throw a string exception
  virtual void add(unsigned long i, T x) = 0;

  //Remove the item at position i. All items that were originally
  // at position i+1 or higher get moved backwards 1 to fill the gap.
  // If list does not contain i items, throw a string exception
  virtual void remove(unsigned long i) = 0;
};
