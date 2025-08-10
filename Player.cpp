#include "Player.h"
#include <cctype>

//printing first 2 cards
void Player:: printCards(){
    for(int i = 2; i < 4; i ++){
        cout<<"Player card "<< i - 1<<": "<<deck[i].getName() << " of "<<deck[i].getSymbol()<<endl;
    }
}

// printing next card
void Player:: nextCard(int i){
    cout<<"Player card "<< i - 1<<": "<<deck[i].getName() << " of "<<deck[i].getSymbol()<<endl;
}


// returning the value of the first 2 cards
int Player::cardValue() {
    int value = 0;
    int aces = 0;
    for (int i = 2; i < 4; i++) {
        int cardVal = deck[i].getValue();
        if (cardVal == 11) {  //check how many aces are in the two cards
            aces++;  //increment it
        }
        value += cardVal;  //value  = with the addition of two cards
    }
    while (value > 21 && aces > 0) { //loop through while value is > 21 and numbers of aces are > 21
        value -= 10; //subtract the value by 10 to make the ace as 1
        aces--; //decrement ace
    }
    return value;
}

// Hit or Stand and the current value of the card
int Player:: playerPlay(){
    int value = cardValue();
    int count = 4;
    int aces = 0;
    char input = '\0';
    printCards();
    cout<<"Card Value is: "<<cardValue()<<endl;
    
    if(value == 21){
        cout<<"BlackJack You Win!!!! "<<endl; //if from two first cards its 21 immidiate blackjack
        return 0;
    }
    
    for (int i = 2; i < 4; i++) {
        int cardVal = deck[i].getValue();
        if (cardVal == 11) { //count the number of aces
            aces++;
        }
    }
    while(input != 's' && input != 'S'){  //loop through until user stands
        if(value > 21){
            cout<<"Busted you lose! "<<endl<<endl;
            break;
        }
        cout<<"Hit or Stand? (Press H to hit | Press S to stand) ";
        cin>>input;
        if (input == 'H' || input == 'h') { //if user asks to Hit
            nextCard(count); //hit the next random card
            int newCardValue = deck[count].getValue();
            if (newCardValue == 11) { //if that next card is ace
                aces++;  //add that ace to 1
            }
            value += newCardValue;  //get the current value
            while (value > 21 && aces > 0) {  // loop through if value > 21 and ace > 0
                value -= 10;   //if ace makes it over 21 then subtract that ace with 10 to change it into 1
                aces--;
            }
            cout << "Player current value is: " << value << endl;  // Show updated total
            count++;  //increment count for the next card
        }
        else if (input == 's' || input == 'S') {
            break;          //if user stands break the loop
            }
        if (value == 21){
            cout<<"BlackJack You Win!!!! "<<endl;
            break;  //if the user hits 21 its blackjack
        }
    }
            if (value <= 21) {
                cout << "You stand with a total value of: " << value << endl << endl;
            }//if user decides to stay just give the standing value
    
    return count;  //return card count because the dealer will get the next card.
}






