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

// constructor
ArrayQueue<T>::ArrayQueue(){
	
	front = 0;
	numItems =0;
	backingArraySize = START_SIZE;

	// new operator allowcate memory for array of type T (T will be decide at run time)
	backingArray = new T[backingArraySize];
	
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {

	//the use of [] when destroying an array allocated with new
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){

	// if numItems == backingArraySize, grow the array
		
		if(numItems == backingArraySize)
				grow();
		
		backingArray[(front+numItems)%backingArraySize] = toAdd;
		numItems++;
		
		
}



template <class T>
T ArrayQueue<T>::remove(){
	// throw is not a method, it is a special keyword. 
	// if you want to throw a string, you have to cast back to string
	if(numItems==0){
	throw (std::string)"Sorry, the array is empty";
	}
	T removedItem = backingArray[front];
	front = (front+ 1)%backingArraySize;
	numItems--;
	return removedItem;

}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* newBackingArray = new T[backingArraySize*2];
	if(newBackingArray == NULL)
		throw (std::string) "Unable to add input item. Your computer may out of memory ";
	for(unsigned int i =0; i<backingArraySize; i++){
		newBackingArray[front+i] = backingArray[(front + i) % backingArraySize];
	}
	backingArraySize = backingArraySize*2;
	delete[] backingArray;
	backingArray = newBackingArray;
	
}