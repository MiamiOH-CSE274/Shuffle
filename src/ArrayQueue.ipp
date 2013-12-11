//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(unsigned int size){ //make sure variable names match!
	backingArraySize = size;
	backingArray = new T [backingArraySize];
    front = 0;
    numItems = 0;
}//end constructor

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}//end destructor

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if(numItems==backingArraySize)
        grow();
    
    backingArray[(front+numItems)%backingArraySize] = toAdd; //formula from class
    numItems += 1;
}//end add

template <class T>
T ArrayQueue<T>::remove(){
	if(numItems==0)
		throw (std::string)"No elements remain to be removed.";

	T removed = backingArray[front];
	front = (front+1) % backingArraySize;
	numItems -= 1;
	return removed;
}//end remove

template <class T>
T ArrayQueue<T>::removeTail(){
	if(numItems==0)
		throw (std::string)"No elements remain to be removed.";

	T removed = backingArray[(front+numItems-1)%backingArraySize];
	numItems -= 1;
	return removed;
}//end remove

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}//end getNumItems

template <class T>
void ArrayQueue<T>::grow(){
	T* replacement = new T[backingArraySize*2];
	if (replacement==NULL)
	  throw std::string("You have run out of memory, sorry.");

	for (unsigned long i=0; i<numItems; i++)
	  replacement[i] = backingArray[(i+front)%backingArraySize];

	front = 0;
	delete[] backingArray;
	backingArray = replacement;
	backingArraySize *= 2;
}//end grow
