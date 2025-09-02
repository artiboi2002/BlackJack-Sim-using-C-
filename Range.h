#ifndef RANGE_H
#define RANGE_H
#include "IteratorG.h"
template <typename K, typename V>
class Range { 
private:
IteratorG<K,V> _begin; 
IteratorG<K,V> _end; 

public:

// Constructor 
Range(const IteratorG<K,V>& b, const IteratorG<K,V>& e): _begin(b), _end(e) { }

// Get the begginging of iterator
IteratorG<K,V>& getB()  { return _begin; } 

// Get the end of the iterator
IteratorG<K,V>& getE()  { return _end; } 
};

#endif 