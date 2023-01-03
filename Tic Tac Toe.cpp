#include <iostream>
#include <stdlib.h>
using namespace std;

void navigate(char map[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(j!=2)
                cout << "  " << map[i][j] << "  |";
            else
                cout << "  " << map[i][j];

        }
        if(i!=2){
            cout << endl;
            cout << "----------------" << endl;
        }
        else
            cout << endl;
    }
}
int playeroneInput(){
    int player_1;
    while(true){
        cout << "Input number, player 1 (X) : ";
        cin >> player_1;
        if (player_1 <= 9 && player_1 >= 1)
            return player_1;
    }
}
int playertwoInput(){
    int player_2;
    while(true){
        cout << "Input number, player 2 (O) : ";
        cin >> player_2;
        if (player_2 <= 9 && player_2 >= 1)
            return player_2;
    }
}
void processingplayer1(char array[3][3], int number){
    if(number<=3)
        array[0][number-1] = 'X';
    else if(number<=6)
        array[1][(number-3)-1] = 'X';
    else
        array[2][(number-6)-1] = 'X';
}
void processingplayer2(char array[3][3], int number){
    if(number<=3)
        array[0][number-1] = 'O';
    else if(number<=6)
        array[1][(number-3)-1] = 'O';
    else
        array[2][(number-6)-1] = 'O';
}
void Whowins(char map[3][3]){
    int Xc=0, Oc=0;
    // Horizontal Checking
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(map[i][j] == 'X')
                Xc += 1;
            else if(map[i][j] == 'O')
                Oc += 1;
        }
        if(Xc == 3){
            cout << "Player 1 (X) WINS" << endl;
            exit(1);
        }
        else if(Oc == 3){
            cout << "Player 2 (O) WINS" << endl;
            exit(1);
        }
        Xc = 0;     Oc = 0;
    }
    // Vertical Checking
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(map[j][i] == 'X')
                    Xc += 1;
                else if(map[j][i] == 'O')
                    Oc += 1;
            }
            if(Xc == 3){
                cout << "Player 1 (X) WINS" << endl;
                exit(1);
            }
            else if(Oc == 3){
                cout << "Player 2 (O) WINS" << endl;
                exit(1);
            }
            Xc = 0;     Oc = 0;
        }
    // Diagonal Checking
        if(map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X'){
            cout << "Player 1 (X) WINS" << endl;
            exit(1);
        }
        if(map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O'){
            cout << "Player 2 (O) WINS" << endl;
            exit(1);
        }
         if(map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X'){
            cout << "Player 1 (X) WINS" << endl;
            exit(1);
        }
        if(map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O'){
            cout << "Player 2 (O) WINS" << endl;
            exit(1);
        }
}

int main(){

    char map[3][3] = {'1','2','3','4','5','6','7','8','9'};
    int player_1, player_2, flag=0;
    navigate(map);

    for(int i=0; i<=4; i++){
        player_1 = playeroneInput();
        system("cls");
        processingplayer1(map, player_1);
        navigate(map);
        Whowins(map);
        if (i==4){
            flag = 1;
            break;
        }
        player_2 = playertwoInput();
        system("cls");
        processingplayer2(map, player_2);
        navigate(map);
        Whowins(map);
    }
    if(flag==1)
        cout << "It's a DRAW situation" << endl;

    return 0;
}
