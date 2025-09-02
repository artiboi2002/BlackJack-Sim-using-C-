 #include "Entry.h"


// Constructor
template <typename K, typename V>
Entry<K,V>::Entry(const K& k, const V& v): _key(k), _value(v){} 
 
// Destructor
template <typename K, typename V>
Entry<K,V>:: ~Entry(){}
  
// Get key
template <typename K, typename V>
const K& Entry<K,V>:: getK() const{
    return _key;
} 

// Get Value
template <typename K, typename V>
const V& Entry<K,V>:: getV() const{
    return _value;
} 

// Set Key     
template <typename K, typename V>
void Entry<K,V>:: setK(K k){
    _key = k;
}
  
// Set Value   
template <typename K, typename V>
void Entry<K,V>:: setV(V v){
    _value = v;
}

template class Entry<std::string, std::string>;