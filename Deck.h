#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"
using namespace std;

class Deck{
    private:
    Card deck[416];
    string names[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int values[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
    string symbols[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    public:
    friend class Player;
    friend class Dealer;
    Deck();
    void shuffleCards();
    void print();
    

};
#endif
