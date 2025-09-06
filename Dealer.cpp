#include "Dealer.h"

// print dealers card
void Dealer:: printCard(bool hide){
    if(hide == true){ //hide the second card
        cout<<"Dealer card: "<<deck[0].getName() << " of "<<deck[0].getSymbol()<<endl;
        cout<<"Dealer card: Hidden Card"<<endl;
    }
    else{
        for(int i = 0; i < 2; i ++){ //print both cards
            cout<<"Dealer card: "<<deck[i].getName() << " of "<<deck[i].getSymbol()<<endl;
        }
    }
}
void Dealer:: nextCard(int i){
    cout<<"Dealer card: "<<deck[i].getName() << " of "<<deck[i].getSymbol()<<endl;
}

int Dealer::cardValue() {
    int value = 0;
    int aces = 0;
    for (int i = 0; i < 2; i++) {
        int cardVal = deck[i].getValue();
        if (cardVal == 11) {
            aces++; //count number of aces
        }
        value += cardVal;
    }
    while (value > 21 && aces > 0) { //go in loop if value is greater 21 and if aces are >0
        value -= 10;  //change the ace to 1 instead of 11 when value is > 21
        aces--; //decrement ace
    }
    return value;  //return value
}

int Dealer::dealerPlay(int count){
    int aces = 0;
    bool open = false;
    for (int i = 0; i < 2; i++) {
            if (deck[i].getValue() == 11) {
                aces++;  //count aces again
            }
        }
    printCard(open);
    int value = cardValue();
    if(value < 17){
        while(value < 17){
            nextCard(count);
            int newCardValue = deck[count].getValue();
            if (newCardValue == 11) {  //check if the next cards are aces
                    aces++;   //increment it
            }
            value += newCardValue;
            while (value > 21 && aces > 0) { //decrease that value but 10 if its greater than >21
                    value -= 10;
                    aces--;
            }
            count++;
        }
    }
    if(value >= 17 && value <= 20){
          cout<<"Dealer stands with the value: "<<value<<endl;  //If value is 17 >= x <= 20
    }
    if(value == 21){
        cout<<"BlackJack!! Dealer WINS"<<endl; //if its 21 automatically a blackjack
    }
    if(value > 21){
        cout<<"Dealer busted with the value: "<<value<<endl; //greater than 21 bust
    }
    return value;
}
