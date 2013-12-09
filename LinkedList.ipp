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
  while(numItems > 0){
  remove(0);
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i > numItems || i < 0){
  throw (std::string)"The item does not exists, please enter another index";
  }
  if(i == numItems){
  return dummyNode;
  }

  //below it is indexing to find index i.
  Node* cur = dummyNode ->next;
  int count = 0;
  while(count != i){
	cur = cur -> next;
	count++;
  }
  return cur;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
 find(i)->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  Node* cur = find(i);
  Node* temp = new Node();
  
  //Below is making the new node.
  temp -> data = x;
  temp -> next = cur;
  temp -> prev = cur ->prev;
  
  //Below is adjusting old nodes to point in the correct direction
  temp -> prev -> next = temp;
  temp -> next -> prev = temp;

  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  if(numItems == 0){
  throw (std::string)"The list is empty cannot remove";
  }
  if(i > numItems){
  throw (std::string)"The item does not exists, please enter another index";
  }
  Node* cur = find(i);
  
  cur -> prev -> next = cur -> next;
  cur -> next -> prev = cur -> prev;
  delete cur;
  numItems--; 
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  return find(i)->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  // I'm making a node that I'm using Nick Contini's logic for splice.
		  Node* beginning = find(i);
          Node* end = find(i+len-1);
          end->next->prev=beginning->prev;
          beginning->prev->next=end->next;
          numItems=numItems-len;

          Node* insertHere=target.dummyNode;
          if(target.numItems>0){
                insertHere = target.find(t);
                }
          if(t<0){
                throw (std::string)"Not a valid index!";
          }
                
          end->next=insertHere;
          beginning->prev=insertHere->prev;
          insertHere->prev->next=beginning;
          insertHere->prev=end;
          target.numItems=target.numItems+len;

	//End of material from Nick.
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}