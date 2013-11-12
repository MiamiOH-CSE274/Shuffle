//You will need this so you can make a string to throw in
// remove
#include <string>
#include <iostream>


//Syntax note: C++ is not very good at figuring out which methods belong
//to which classes. That is why we have to use the scope operator to
//tell the compiler that this LinkedList() method belongs to the
//LinkedList<T> class.


/*

I IMPLEMENTED THIS LAB BY USING DOUBLE LINKEDLIST AFTER READING Open Data Structures (in C++)

Edition 0.1F FF.

Pat Morin

*/


template <class T>
LinkedList<T>::LinkedList()
{

  dummyNode = new Node();

  dummyNode->next = dummyNode;

  dummyNode->prev = dummyNode;

  numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList()
{
	for(int i=0;i<(int)numItems;i++)

	{
	  remove(0);
	}

	delete dummyNode;
}


template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i)

{

   if((int)i>(int)(size()))
   {

	 throw std :: string("Error! Invalid index!");
   }


   if((int)i < 0)
   {

	 throw std :: string("Error! Invalid index!");
   }



   if(i == (unsigned long)-1)

   {
	  return dummyNode;
   }


  Node* head;

  if( (int)i < (int)(numItems/2) )
  {

   head = dummyNode->next;

   for(int k = 0;k< (int)i;k++)
   {

	  head = head->next;
   }
  }

  else
  {
     head = dummyNode;

	 for(int k = (int)numItems;k>(int)i;k--)
	 {

		head = head->prev;
	 }
  }

  return head;

}


template <class T>
T LinkedList<T>::get(unsigned long i)
{

   if((int)i >= (int)(size()))
   {

	 throw std :: string("Error! Invalid index!");
   }

   if((int)i < 0)
   {

	 throw std :: string("Error! Invalid index!");
   }

  Node * getter = find(i);

  return (getter -> data);
}



//Set the value at index i to x
// If list does not contain i items, through a string exception

template <class T>
void LinkedList<T>::set(unsigned long i, T x)
{
   if((int)i >= (int)(size()))
   {

	 throw std :: string("Error! Invalid index!");
   }

   if((int)i < 0)
   {

	 throw std :: string("Error! Invalid index!");
   }

   Node * setter  = find(i);
   setter -> data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x)
{

   if( ((int)i) > ((int)size()))
   {
     throw std :: string("Error! Invalid index!");
   }

   if((int)i < 0)
   {

	 throw std :: string("Error! Invalid index!");
   }


   Node* current = find(i);

   Node* newOne = new Node();

   newOne->data = x;

   newOne->prev = current->prev;

   newOne->next = current;

   newOne->next->prev = newOne;

   newOne->prev->next = newOne;

   numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i)
{
   if((int)i<0)
   {

	 throw std :: string("Error! Invalid index!");
   }

   if((int)size() == 0)
   {
     throw std :: string("Error! Invalid index!");
   }

   if( ((int)size() != 0) && ((int)i >= (int)size())  )
   {
     throw std :: string("Error! Invalid index!");
   }

   Node* remover = find(i);

   remover->prev->next = remover->next;

   remover->next->prev = remover->prev;

   delete remover;

   numItems--;

}



template <class T>
void LinkedList<T>::takeAll(LinkedList<T>& src)
{

    find(size())->next = src.find(0);

    src.find(0)->prev = find(size()-1);

    numItems = numItems + src.size();

}

template <class T>
unsigned long LinkedList<T>::size()
{

  return numItems;
}
