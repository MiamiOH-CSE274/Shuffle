//You will need this so you can make a string to throw in
// remove
#include <string>


//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.

template <class T>
LinkedList<T>::LinkedList(){
	dummyNode = new Node();
	
	dummyNode -> next = dummyNode;
	dummyNode -> prev = dummyNode;
	
	numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (numItems > 0){
		remove(0);
	}

	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	Node* p;
	
	if (i > size() || i < 0)
		throw (std::string) "Invalid i (find)";

	if (i == numItems)
		return dummyNode;

	if (i < (numItems/2)) {
		p = dummyNode -> next;
		for (int j = 0; (j < (int)i); j++)
			p = p -> next;
	}
	else {
		p = dummyNode;
		for (int j = numItems; j > (int)i; j--)
			p = p -> prev;
	}

	return (p);
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	if (i >= size() || i < 0)
		throw (std::string) "List does not contain i items";
		
	Node* s = find(i);	

	s->data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	Node* u = find(i);

	Node* temp = new Node();

	if (i > size() || i < 0)
		throw (std::string) "List does not contain i items(add)";

	temp -> data = x;
	temp -> next = u;
	temp -> prev = u -> prev;
	temp -> prev -> next = temp;
	temp -> next -> prev = temp;
	
	numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (numItems == 0)
		throw (std::string) "List is already empty! (remove)";
	
	if (i >= size() || i < 0)
		throw (std::string) "Invalid i!";
	
	Node* w = find(i);
	
	w -> prev -> next = w -> next;
	w -> next -> prev = w -> prev;
	
	delete w;
	numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	if (i >= size() || i < 0)
		throw (std::string) "List does not contain i items";

	Node* f = find(i);

	return (f -> data);
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
	// Find splice
	Node* begin = find(i);
	Node* end = find(i+len-1);
	
	// remove from List
	begin -> prev -> next = end -> next;
	end -> next -> prev = begin -> prev;

	// Update List size
	numItems = numItems - len;

	// Find place to add in target List
	Node* insert = target.find(t);
	
	// Add splice to target List
	insert -> prev -> next = begin;
	begin -> prev = insert -> prev;
	insert -> prev = end;
	end -> next = insert;	

	// Update target size
	target.numItems = target.size() + len;

}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}