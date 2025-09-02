#include "EnglishDictionary.h"
#include <iostream>

int main(){
    
    EnglishDictionary dict("My Dictionary");
    Entry<std::string, std::string> word1("dog", "A loyal animal.");
    dict.add(Entry<std::string, std::string>("apple", "A fruit that grows on trees."));
    dict.add(Entry<std::string, std::string>("apple", "A tech company."));
    dict.add(Entry<std::string, std::string>("apple", "red fruit"));
    dict.add(Entry<std::string, std::string>("banana", "A yellow fruit."));
    dict.add(Entry<std::string, std::string>("banana", "A green fruit"));
    dict.add(Entry<std::string, std::string>("banana", "grow in Africa"));
    dict.add(Entry<std::string, std::string>("banana", "healthy"));
    dict.add(Entry<std::string, std::string>("cat", "A small domesticated carnivorous mammal."));
    dict.add(Entry<std::string, std::string>("dog", "A domesticated carnivorous mammal."));
    dict.add(word1);
    
    std::cout<<"Printing forward: "<<std::endl;
    dict.printDictionary(true);
    std::cout<<std::endl;
    
    std::cout<<"Printing backwards: "<<std::endl;
    dict.printDictionary(false);
    
    std::cout<<std::endl;
    std::cout<<"Printng the word 'dog' with two defintions: "<<std::endl;
    dict.printDictionary("dog");
    
    std::cout<<std::endl;
    std::cout<<"Removing the first word 'apple':  "<<std::endl;
    dict.deleteFirst("apple");
    dict.printDictionary(true);
    
    std::cout<<std::endl;
    dict.find("banana");
    std::cout<<std::endl;
    dict.printDictionary("banana");
     
    std::cout<<std::endl;
    std::cout<<"Removing the first word 'banana':  "<<std::endl;
    dict.deleteFirst("banana");
    dict.printDictionary(true);
    
    std::cout<<std::endl;
    std::cout<<"Removing the all the words 'dog':  "<<std::endl;
    dict.deleteWord("dog");
    dict.printDictionary(true);
    
     std::cout<<std::endl;
    std::cout<<"Printing forward: "<<std::endl;
    dict.printDictionary(true);
    std::cout<<std::endl;
    
    std::cout<<"Printing backwards: "<<std::endl;
    dict.printDictionary(false);
    
    return 0;

}
