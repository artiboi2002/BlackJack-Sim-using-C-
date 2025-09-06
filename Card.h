#ifndef CARD_H
#define CARD_H


#include <iostream>
using namespace std;

class Card {
    private:
    int value;
    string name;
    string symbol;

    public:
    Card() : value(0), name(""), symbol("") {}
    Card (int v, string n, string s){
    	value = v;
    	name = n;
    	symbol = s;
	}
    void setName(string);
    void setValue(int);
    void setSymbol(string);
    string getName();
    int getValue();
    string getSymbol();

};
#endif