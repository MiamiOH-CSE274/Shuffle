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
ArrayQueue<T>::ArrayQueue()
{

        //Initizlize the size of array as 10.
        backingArraySize = START_SIZE;
    
	//Allocate the memory.
	backingArray = new T[backingArraySize];

	//The front index of element in array.
	front = 0;

	//Record the number of elements in the array.
	numItems = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() 
{
    
	//Free the memory.
	delete [] backingArray;

	//Set backingArray to be NULL.
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd)
{

//To check if backingArray is full.

  if(numItems + 1 > backingArraySize)

     {
     
     if(backingArray == NULL)
     {
        
        throw std::string("Error! Something bad happens in array");
     
     }
     
     
	   grow();
     
     }

  backingArray[ ( front + numItems ) % backingArraySize ] = toAdd;

  //After adding one element in the array, increase the number of element as one.
	 numItems++;
}

template <class T>
T ArrayQueue<T>::remove()
{
   
   //Create a object which will hold a element that needs to be removed.
   T rm;

  //Throw a exception if no element in the array.
  if(numItems == 0)
      {
	  throw std::string("Error! There is no element is the queue.");
      }


  //According to the FIFO policy, store the front element in the array.
  rm = backingArray[front];


  
  //After delete a element, increase the index of front element as one.
  front = ( (front+1) % (backingArraySize) );



  //Decrease the number of element in the array.
  numItems--;

  //Return rm.
  return rm;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){

	return numItems;

}

template <class T>
void ArrayQueue<T>::grow()
{
 
   
    //To increase the front index of array.
    int count = 0;

    T *newArray = new T[2 * backingArraySize];

	while(count<numItems){

                //Exactly copy the elements from old array to new array.
		newArray[ ( front+count % backingArraySize )] = backingArray[ ( front+count ) % backingArraySize ];

		count++;
	}

	backingArraySize = 2 * backingArraySize;



    //Deallocate the original array.
    delete [] backingArray;

    //Ensure the original array will not be a dangling pointer.
    backingArray = NULL;

    backingArray = newArray;



}
