#include "IteratorG.h"


// Returns a reference to the value of the current node 
template <typename K, typename V>
const V& IteratorG<K,V>:: operator*(){
    return v->elm.getV();
}

// Compares the current iterator with another for equality.
template <typename K, typename V>
bool IteratorG<K,V>:: operator==(const IteratorG& p) const{
    return v == p.v;
}
 
 // Compares the current iterator with another for inequality.   
template <typename K, typename V>
bool IteratorG<K,V>:: operator!=(const IteratorG& p) const{
    return v != p.v;
} 

// Moves the iterator to the next position in the list.    
template <typename K, typename V>
IteratorG<K,V>& IteratorG<K,V>:: operator++(){
    v = v->next;
    return *this;
}
  
// Moves the iterator to the prev position in the list  
template <typename K, typename V>
IteratorG<K,V>& IteratorG<K,V>:: operator--(){
    v = v->prev;
    return *this;
}

// Constructor to initialize the iterator with a pointer to a node.
template <typename K, typename V>
IteratorG<K,V>:: IteratorG(DNodeG<K,V>* u){
        v = u;
}

 //returns a reference to the entry of the current node.   
template <typename K, typename V>
const Entry<K,V>& IteratorG<K,V>:: entry(){
    return v->elm;
}

template class IteratorG<std::string, std::string>;

