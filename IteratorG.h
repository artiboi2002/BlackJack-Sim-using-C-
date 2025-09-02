#ifndef ITERATORG_H_
#define ITERATORG_H_
#include "DNodeG.h"
#include "NodeDictionaryG.h"
#include "Entry.h"
template <typename K, typename V>
class IteratorG{
    private:
    DNodeG<K,V>* v;
    
    public:
    const V& operator*();
    bool operator==(const IteratorG& p) const;
    bool operator!=(const IteratorG& p) const; 
    IteratorG& operator++();
    IteratorG& operator--();
    IteratorG(DNodeG<K,V>* u);
    const Entry<K,V>& entry();
    IteratorG(){};
    friend class NodeDictionaryG<K,V>;
    friend class EnglishDictionary;
};

#endif