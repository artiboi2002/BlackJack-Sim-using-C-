#include "EnglishDictionary.h"
#include "IteratorG.h"
#include <iostream>
EnglishDictionary:: EnglishDictionary(string n){
    name = n;
}
EnglishDictionary::  ~EnglishDictionary(){} 

// number of words
int EnglishDictionary:: words() const{
    return dictionary.size();
}

// number of unique words
int EnglishDictionary:: uniqueWords() const{
    return dictionary.uniqueKeys();
}

// check if the dictionary its empty
bool EnglishDictionary:: empty() const{
    return dictionary.empty();
}

// add a new word with definiton
void EnglishDictionary:: add(Entry<std::string, std::string> e){
    dictionary.put(e.getK(), e.getV());
} 

// delete the first 
void EnglishDictionary:: deleteFirst(string word){
        IteratorG<std::string, std::string> it = dictionary.find(word);
        dictionary.erase(it);
}

// delete all the words
void EnglishDictionary:: deleteWord(string word){
       Range<std::string, std::string> range = dictionary.findAll(word);
       dictionary.erase(range);
 }
 
// print the whole dictionary recursively 
void EnglishDictionary::printDictionary(bool forward)   
{
     if (forward) {
        printRecursive(dictionary.begin(), true, words()); // Start from the beginning
    } else {
        printRecursive(IteratorG<std::string, std::string>(dictionary.end().v->prev), false, words()); // Start from the last node
    }
}

// print all the words with the same name
void EnglishDictionary::printDictionary(const std::string& word) {
    Range<std::string, std::string> range = dictionary.findAll(word);
    dictionary.print(range);
}

// find the word
Entry<string, string> EnglishDictionary:: find(string word){
   IteratorG<std::string, std::string> it = dictionary.find(word);
   cout<<"Word you looking for is: "<<it.v->elm.getK();
    return it.entry();
}


// Additional function to make the printDictionary(bool) recursively
void EnglishDictionary::printRecursive(IteratorG<std::string, std::string> it, bool forward, int n) {
    if (n <= 0 || it == dictionary.end()) {
        return;
    }
    std::cout << it.entry().getK() << ": " << it.entry().getV() << std::endl;
    if (forward) {
        ++it; // Move forward
    } else {
        --it; // Move backward
    }
    printRecursive(it, forward, n - 1); // Recursive call
}





