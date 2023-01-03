/*
Project: Snake
Owner: Eng. Mohamed Salah
Duration: 3.00~3.30 hours;
*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;

enum Direction {Top, Down, Left, Right};

int rows = 20;
int columns = 40;

class Board
{
private:
    pair<int,int> fruit;
    int score;

public:
    Board()
    {
        score = 0;
        fruit.first=0;
        fruit.second=0;
    };
    virtual ~Board() {};

    virtual void Display() = 0;
    void generateFruit()
    {
        srand(time(NULL));
        fruit.first = (rand() % (rows-2)) + 1;
        fruit.second = (rand() % (columns-2)) + 1;
    }
    void increaseScore()
    {
        score+=1;
    }
    int getScore()
    {
        return score;
    }
    pair<int,int> getFruit()
    {
        return fruit;
    }
};

class Snake : public Board
{
private:
    pair<int,int>Head;
    vector<pair<int, int>>Tail;
    Direction dir;
public:
    Snake()
    {
        Head.first = rows/2;
        Head.second = columns/2;
        generateFruit();
        Tail.resize(rows*columns);
        Tail[0]=Head;
    };
    void Input()
    {
        if(_kbhit()){
            char userInput = _getch();
            if(userInput=='w' || userInput=='W')
                dir = Top;
            else if(userInput == 's' || userInput=='S')
                dir = Down;
            else if(userInput == 'a' || userInput=='A')
                dir = Left;
            else if(userInput == 'd' || userInput=='D')
                dir = Right;
        }
    }
    void Move()
    {

        if(dir==Top)
            Head.first--;
        else if(dir==Down)
            Head.first++;
        else if(dir==Right)
            Head.second++;
        else if(dir==Left)
            Head.second--;

        for(int i=getScore(); i>0; i--)
            Tail[i] = Tail[i-1];    // Swapping the tail elements from back
        Tail[0]=Head;   // Put the head at the first element of the array
        if(getFruit().first == Head.first && getFruit().second == Head.second)
        {
            increaseScore();
            generateFruit();
        }
    }
    bool Lose()
    {
        if(Head.first == 0 || Head.first == rows-1 || Head.second == 0 || Head.second==columns-1)
            return true;
        for(int i=1; i<getScore(); i++)
        {
            if(Head.first == Tail[i].first && Head.second == Tail[i].second)
                return true;
        }
        return false;
    }
    bool Win()
    {
        if(getScore() == (rows-2*columns-2)-1)
            return true;
        return false;
    }
    void Display()
    {
        system("cls");
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                if(i==0 || i == rows-1)
                    cout << "*";
                else if(j==0 || j== columns-1)
                    cout << "*";
                else if(i==getFruit().first && j == getFruit().second)
                    cout << "o";
                else if(i==Head.first && j ==Head.second)
                    cout << "O";
                else if(getScore()>0)
                {
                    bool tai =false;
                    for(int k=1; k<=getScore(); k++)
                    {
                        if(Tail[k].first==i && Tail[k].second==j)
                        {
                            cout << "o";
                            tai=true;
                            break;
                        }
                    }
                    if(!tai)
                        cout << " ";
                }
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "Score= " << getScore() << endl;
    }

    ~Snake() {};
};

int main()
{
    Snake* myBoard = new Snake;
    while(true)
    {
        myBoard->Display();
        myBoard->Input();
        myBoard->Move();
        if(myBoard->Lose())
            break;
        if(myBoard->Win())
        {
            cout<<"You have completed the game!!, Congratulations"<<endl;
            return 0;
        }
    }
    cout << "Oops, you have Lost" << endl;
    delete myBoard;
    myBoard=0;

    return 0;
}
