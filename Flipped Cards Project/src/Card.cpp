#include "Card.h"
#include <time.h>
#include <stdlib.h>

int Card::counter=0;
vector<char> Card::cardSymbols = {'$', '#', '@', '&', '*', '%', '$', '#', '@', '&', '*', '%'};
Card::Card()
{
    srand(time(NULL));
    int index = (rand() % 12);
    counter++;
    id = counter;
    if(index >= cardSymbols.size())
        index =(rand() % cardSymbols.size());
    symbol = cardSymbols[index];
    auto it = cardSymbols.begin();
    cardSymbols.erase(it+index);
    status = Still;
}
int Card::showID(){
    return id;
}
char Card::showSymbol(){
    return symbol;
}
bool Card::operator!=(Card &other){
    if(symbol != other.symbol)
        return true;
    return false;
}
STAT Card::getStatus(){
    return status;
}
STAT Card::setStatus(STAT s){
    status = s;
}
Card::~Card()
{
    //dtor
}
