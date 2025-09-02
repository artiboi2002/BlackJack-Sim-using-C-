#ifndef ENGLISHDICTIONARY_H_
#define ENGLISHDICTIONARY_H_

#include "NodeDictionaryG.h"
#include <iostream>
using namespace std;

class EnglishDictionary{
    private:
    string name; 
    NodeDictionaryG<std::string, std::string> dictionary; 
    
    public:
    EnglishDictionary(string);
    ~EnglishDictionary();  
    int words() const;  
    int uniqueWords() const;  
    bool empty() const; 
    void add(Entry<string, string>);  
    void deleteFirst(string); 
    void deleteWord(string);  
    void printDictionary(bool); 
    void printDictionary(const string&); 
    Entry<string, string> find(string); 
    void printRecursive(IteratorG<std::string, std::string>, bool, int);
};

#endif