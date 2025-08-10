#ifndef Player_h
#define Player_h
#include "Deck.h"

class Player : public Deck{
public:
    void printCards();
    int cardValue();
    int playerPlay();
    void nextCard(int i);
    
};

#endif
