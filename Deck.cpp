#include "Deck.h"
#include <iostream>
#include "Card.h"
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

//Create eight decks
Deck::	Deck() {
	int count = 0;
	for(int i = 0; i < 8; i ++) {
		for (int j = 0; j < 13; j ++) {
			for (int k = 0; k < 4; k ++) {
				deck[count] = Card(values[j], names[j], symbols[k]);
				count++;
			}
		}
	}
    shuffleCards(); //shuffle cards whenver created
}

//shuffle cards
void Deck:: shuffleCards(){
    default_random_engine rng(static_cast<unsigned int>(time(0)));
    shuffle(&deck[0], &deck[416], rng);
}




















































