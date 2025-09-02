 #include "NodeDictionaryG.h"
#include "IteratorG.h"

// Constructor taht also creates dummy nodes
template <typename K, typename V>
NodeDictionaryG<K,V>:: NodeDictionaryG(): uKeys(0), n(0){
    header = new DNodeG<K,V>;
    trailer = new DNodeG<K,V>;
    header->next = trailer;
    trailer->prev = header;
}
 
// Destructor to free the memory of all nodes
template <typename K, typename V>
NodeDictionaryG<K,V>::  ~NodeDictionaryG(){
    while(!empty()){
        erase(IteratorG<K,V>(header->next));
    }
    delete header;
    delete trailer;
} 

// Returns the current size of the nodes
template <typename K, typename V>
int NodeDictionaryG<K,V>:: size() const{
    return n;
}

// Returns the number of unique keys
template <typename K, typename V>
int  NodeDictionaryG<K,V>::uniqueKeys() const{
    return uKeys;
}  

// checks if its empty    
template <typename K, typename V>
bool  NodeDictionaryG<K,V>::empty() const{
    return n == 0;
} 

// Returns an iterator that points to the nodes after the header   
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>:: begin() const{
    return IteratorG<K,V>(header->next);
}
 
// Returns an Iterator that points to the trailer  
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>:: end() const{
    return IteratorG<K,V>(trailer);
}

// Finds the first entry with the given key.
template <typename K, typename V>    
IteratorG<K,V>  NodeDictionaryG<K,V>::find(const K& k) const{
    for(IteratorG<K,V> p(begin()); p != end(); ++p){
        if(p.v->elm.getK() == k){
            return p;
        }
    }
    return end();
}

// // Inserts a key-value pair.  
template <typename K, typename V>
IteratorG<K,V>  NodeDictionaryG<K,V>::put(const K& k, const V& v){
    Range<K,V> r = findAll(k);
    IteratorG<K,V> p;
    if(r.getB()==r.getE())
    {
        p = end();
        uKeys++;
    }
    else
    p = r.getE();
    DNodeG<K,V>* temp1 = p.v; // p’s node
    DNodeG<K,V>* temp2 = temp1->prev; // p’s predecessor
    DNodeG<K,V>* new_node = new DNodeG<K,V>; // new node to insert
    new_node->elm.setK(k);
    new_node->elm.setV(v);
    new_node->next = temp1 ; 
    temp1 ->prev = new_node; 
    new_node->prev = temp2; 
    temp2->next = new_node; 
    n++;
    return p;
}


// Erase entry at a given key 
template <typename K, typename V>
void NodeDictionaryG<K,V>:: erase(const K& k){
    
    for(IteratorG<K,V> p(begin()); p != end(); ++p){
        if(p.v->elm.getK() == k){
            erase(p);
        }
    }
    
}

// Erase key at a given iterator 
template <typename K, typename V>
void NodeDictionaryG<K,V>::erase(const IteratorG<K,V>& p)  // Removes the entry at the given iterator.
{     
    
      DNodeG<K,V>* oldNode = p.v;
      if(oldNode->elm.getK() != oldNode->next->elm.getK() && oldNode->elm.getK() != oldNode->prev->elm.getK()){
        uKeys--;
      }
      DNodeG<K,V>* temp1 = oldNode->next;
      DNodeG<K,V>* temp2 = oldNode->prev;
      temp1->prev = temp2;
      temp2->next = temp1;
      delete oldNode;
      n--;
}

// Erase all same keys 
template <typename K, typename V>
void NodeDictionaryG<K,V>:: erase(Range<K,V>& r){
    for(IteratorG<K,V> p = r.getB(); p!= r.getE(); ++p){
        erase(p);
    }
} 

// Find all keys that are the same	
template <typename K, typename V>
Range<K,V> NodeDictionaryG<K,V>::findAll(const K& k){
    IteratorG<K,V> b = find(k);
    IteratorG<K,V> e = b;
    while(e != end() && e.v->elm.getK() == b.v->elm.getK()){
        ++e;
    }
    return Range<K,V>(b,e);
}


// Print all the entries
template <typename K, typename V>
void NodeDictionaryG<K,V>:: print(){
     for(IteratorG<K,V> p(begin()); p != end(); ++p){
       std::cout<<p.v->elm<<"<----->";
       std::cout<<std::endl;
    }
}

// Print only the entries with the same key	
template <typename K, typename V>
void  NodeDictionaryG<K,V>::print(Range<K,V>& r){
    for(IteratorG<K,V> p = r.getB(); p != r.getE(); ++p){
        std::cout<<*p<<std::endl;
}
}

template class NodeDictionaryG<std::string, std::string>;