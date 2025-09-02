#ifndef NODEDICTIONARYG_H_
#define NODEDICTIONARYG_H_
#include "MapG.h"
#include "DNodeG.h"
#include "Entry.h"
#include "Range.h"

template <typename K, typename V>
class IteratorG;

template <typename K, typename V>
class NodeDictionaryG: public MapG<IteratorG<K,V>, K, V>{
  private:
    int uKeys; 
    int n;  
    DNodeG<K,V>* header;  
    DNodeG<K,V>* trailer;
      
    public:
    NodeDictionaryG();  
    ~NodeDictionaryG();  
    int size() const; 
    int uniqueKeys() const;  
    bool empty() const;  
    IteratorG<K,V> begin() const; 
    IteratorG<K,V> end() const; 
    IteratorG<K,V> find(const K& k) const;  
   //If there are entry with key == k the new entry will be inserted after the last entry with key = k.
    IteratorG<K,V> put(const K& k, const V& v);
	void erase(const K& k); 
	void erase(const IteratorG<K,V>& p); 
	void erase(Range<K,V>& r); 
	Range<K,V> findAll(const K& k); 
	void print(); 
	void print(Range<K,V>& r);  
    
    
};

#endif