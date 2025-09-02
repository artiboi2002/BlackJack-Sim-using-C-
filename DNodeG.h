#ifndef DNODEG_H_
#define DNODEG_H_
#include <iostream>
#include "Entry.h"
class EnglishDictionary;

template <typename K, typename V>
class IteratorG;

template <typename K, typename V>
class NodeDictionaryG;

template <typename K, typename V>
class Entry;

template <typename K, typename V>
class DNodeG{
    private:
    Entry<K,V> elm;
    DNodeG<K,V>* next;
    DNodeG<K,V>* prev;
    
    public:
    DNodeG(const Entry<K, V>& e = Entry<K,V>(), DNodeG<K, V>* n = nullptr, DNodeG<K, V>* p = nullptr): elm(e), next(n), prev(p){
        ++activeNodes;
    }
    ~DNodeG(){
        --activeNodes;
    }
    static int activeNodes;
    friend class IteratorG<K,V>;
    friend class NodeDictionaryG<K,V>;
    friend class EnglishDictionary;
};

template <typename K, typename V>
int DNodeG<K,V>::activeNodes = 0;

#endif
