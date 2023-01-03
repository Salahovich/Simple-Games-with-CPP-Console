#ifndef CARD_H
#define CARD_H
#include <vector>
using namespace std;
enum STAT {Flipped, Still};

class Card
{
    public:
        static vector<char> cardSymbols;
        static int counter;
        Card();
        int showID();
        char showSymbol();
        bool operator!=(Card &other);
        STAT getStatus();
        STAT setStatus(STAT s);
        virtual ~Card();

    private:
        int id;
        char symbol;
        STAT status;

};

#endif // CARD_H
