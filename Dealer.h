#include "Deck.h"
#include "Player.h"
#ifndef Dealer_h
#define Dealer_h
class Dealer : public Player{
public:
    void printCard(bool);
    void nextCard(int i);
    int cardValue();
    int dealerPlay(int);
};

#endif
