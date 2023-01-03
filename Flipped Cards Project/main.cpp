#include <iostream>
#include <Card.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int Score = 0;
Card* cards = new Card[12];

/*  ============================ Display the cards on the screen  ============================ */
void Display(){
    system("cls");
    cout << "=============================Flip Cards Game=============================";
    for(int i=0; i<12; i++){
        if(i%4==0)
            cout << endl;
        if(cards[i].getStatus() == Still)
            cout << cards[i].showID() << "     ";
        else if(cards[i].getStatus() == Flipped)
            cout << cards[i].showSymbol() << "     ";
    }
    cout << "Your Score = " << Score << endl;
}
/* ============================================*/

int main()
{
    int attemptOne, attemptTwo;
    while(Score<6){

        /*  ============================ Enter the first card index from the user ============================  */
        Display();
        cout << "Enter the first card, please: ";
        cin >> attemptOne;
        if(attemptOne < 1 || attemptOne > 12){
            cout << "Wrong Card" << endl;
            continue;
        }
        else
            cards[attemptOne-1].setStatus(Flipped);
        /* ============================================*/

        /* ============================  Enter the first card index from the user  ============================ */
        Display();
        cout << "Enter the second card, please: ";
        cin >> attemptTwo;
        if(attemptTwo < 1 || attemptTwo > 12 || attemptTwo == attemptOne){
            cout << "Wrong Card" << endl;
            cards[attemptOne-1].setStatus(Still);
            continue;
        }
        else
            cards[attemptTwo-1].setStatus(Flipped);
        /* ============================================*/

        /* Check if the cards equals or not */
        Display();
        if(cards[attemptOne-1]!=cards[attemptTwo-1]){
            cards[attemptOne-1].setStatus(Still);
            cards[attemptTwo-1].setStatus(Still);
        }
        else
            Score++;
        /* ============================================*/

    }
    cout << "======================Congratualtions, you've won the game!!======================" << endl;

    /* ============================ Delete the pointer and out it to NUll ===============================*/
    delete[] cards;
    cards = 0;

    return 0;
}
