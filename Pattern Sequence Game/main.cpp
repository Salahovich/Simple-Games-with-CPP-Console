/*
============================================
Project: Light Sequence Game
Owner: Eng. Mohamed Salah Abdallah
Duration: 2.30~3.00 Hours
============================================
*/
#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Board
{
public:
    Board()
    {
        level = 1;
        lightVector.resize(16);
        userVector.resize(16);
    };
    ~Board()
    {
        userVector.clear();
        lightVector.clear();
    };
    void DisplayLights()
    {
        bool enter;
        system("cls");
        cout << "=======================================================================================================" << endl;
        cout << "=========================================PATTERN SEQEUNCE GAME=========================================" << endl;
        cout << "=======================================================================================================" << endl;
        for(int i=0; i<=4; i++)
        {
            for(int j=0; j<=4; j++)
            {
                enter=false;
                if(i==0 && j!=0)
                    cout << "  " << j;
                else if(j==0 && i!=0)
                    cout << i <<" ";
                if(displaylight){
                    for(int k=0; k<level&&i!=0&&j!=0; k++)
                    {
                        if(lightVector[k].first == i && lightVector[k].second == j)
                        {
                            cout << "*";
                            enter = true;
                            break;
                        }
                    }
                    if(!enter&&i!=0&&j!=0)
                        cout << " ";
                }
                if(i!=0&&j!=0)
                    cout << "  ";
            }
            cout<<endl<< "------------"<<endl;
        }
        cout << "Level = " << level << ",   Enter 0 to exit the game"<<endl;
        if(displaylight)
            Sleep(1200);
        displaylight = false;
    }


    void generateLight()
    {
        displaylight=true;
        srand(time(NULL));
        for(int i=0; i<level; i++)
        {
            lightVector[i].first = (rand() % 4) + 1;
            lightVector[i].second = (rand() % 4) + 1;
        }
        for(int i=0; i<level; i++)
        {
            for(int j=0; j<level-1&&i!=j; j++)
            {
                if(lightVector[i].first == lightVector[j].first && lightVector[i].second ==lightVector[j].second)
                {
                    lightVector[j].first = (rand() % 4) + 1;
                    lightVector[j].second = (rand() % 4) + 1;
                }
            }
        }
    }
    void increaseLevels()
    {
        level++;
    }
    void takeInput()
    {
        for(int i=0; i<level; i++)
        {
            cout << "Enter the coordinates of the " << i+1 << "th pattern: ";
            cin >> userVector[i].first;
            if(userVector[i].first == 0)
                exit(0);
            cin >> userVector[i].second;
        }
    }
    int getLevel()
    {
        return level;
    }
    bool check()
    {
        bool correct;
        for(int i=0; i<level; i++)
        {
            correct = false;
            for(int j=0; j<level; j++)
            {
                if(lightVector[i].first == userVector[j].first && lightVector[i].second == userVector[j].second)
                {
                    correct = true;
                }
            }
            if(!correct)
                return false;
        }
        return true;
    }
    void setBoolean(bool s){
        displaylight= s;
    }
private:
    bool displaylight = false;
    vector<pair<int, int>>userVector;
    vector<pair<int, int>>lightVector;
    int level;
};

int main()
{
    Board mainBoard;
    while(mainBoard.getLevel()<=16)
    {
        mainBoard.generateLight();
        mainBoard.DisplayLights();
        mainBoard.DisplayLights();
        mainBoard.takeInput();
        if(mainBoard.check())
            mainBoard.increaseLevels();
        else
        {
            mainBoard.setBoolean(true);
            mainBoard.DisplayLights();
            cout << "Wrong Pattern, you LOSE!!" << endl;
            return 0;
        }
    }
    cout << "Congrats, you Completed the game!!" << endl;
    return 0;
}
