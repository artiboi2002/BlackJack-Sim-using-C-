#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    char again = '\0';
    bool hide= true;
    do {
        Dealer deal;
        deal.printCard(hide);
        cout<<endl;
        Player play;
        int count = play.playerPlay();
        deal.dealerPlay(count);
        cout<<"Game Over"<<endl;
        cout<<"Would you like to play again? (Y or N)";
        cin>>again;
    }
    while(again == 'Y');
}
