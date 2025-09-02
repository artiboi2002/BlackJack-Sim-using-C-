#ifndef ENTRY_H_
#define ENTRY_H_
#include <iostream>

template <typename K, typename V>
class Entry{
    private:
    K _key; 
    V _value;  
    public:
     Entry(const K& = K(), const V& = V()); 
     ~Entry(); 
     
     // Getters
     const K& getK() const;  
     const V& getV() const; 
     
     //Setters
     void setK(K);
     void setV(V); 
     friend std::ostream& operator<<(std::ostream& os, Entry& p){
		os<<std::endl<<"{"<<p._key<<" ; "<<p._value<<"}";
		return os;
	}
};

#endif