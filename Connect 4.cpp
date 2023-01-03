#include <iostream>
#include <stdlib.h>
using namespace std;

int punc = 0;

void Draw(char array[][20], int row, int col){
    system("cls");
    int counter = 49;
    // Numbering the first column form one to row;
    for(int i=0; i<row-1; i++){
        array[i][0] = counter;
        counter++;
    }
    // Numbering the last row from one to col;
    counter = 49;
    for(int i=1; i<col; i++){
        array[row-1][i] = counter;
        counter++;
    }
    // Display the array on the screen;
     for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << array[i][j] << "    "  ;
        }
        cout << endl;
        cout << endl;
    }
}

void player_one(char array[][20], int row, int col, int blank[]){
    int player_one;
    cout << "Player 1 (X), please select Column = ";
    while(true){
        cin >> player_one;
        if(player_one >= 1 && player_one <= col-1 && blank[player_one-1] >= 0)
            break;
        else
            cout << "The column number " << player_one << " is FULL, Choose another one.";
    }
    int current = blank[player_one-1];
    array[current][player_one] = 'X';
    blank[player_one-1] -= 1;
    punc += 1;
    }
void player_two(char array[][20], int row, int col, int blank[]){
    int player_two;
    cout << "Player 2 (O), please select Column = ";
    while(true){
        cin >> player_two;
        if(player_two >= 1 && player_two <= col-1 && blank[player_two-1] >= 0)
            break;
        else
            cout << "The column number " << player_two << " is FULL, Choose another one.";
    }
    int current = blank[player_two-1];
    array[current][player_two] = 'O';
    blank[player_two-1] -= 1;
    punc += 1;
}
char whowins(char array[][20], int row, int col){
    int Xc, Oc;

    // Processing the rows to determine the winner
    for(int i=row-2; i>=0; i--){
        Xc = 0;     Oc = 0;
        for(int j=1; j<col; j++){
            if(array[i][j] == 'X'){
                Xc += 1;
                Oc = 0;
            }
            else if(array[i][j] == 'O'){
                Oc += 1;
                Xc = 0;
            }
            else{
                Xc = 0;
                Oc = 0;
            }
        }
        if(Xc == 4)
            return 'X';
        else if(Oc == 4)
            return 'O';
    }
    // Processing the columns to determine the winner
    for(int i=1; i<col; i++){
        Xc = 0;     Oc = 0;
        for(int j=row-2; j>=0; j--){
            if(array[j][i] == 'X'){
                Xc += 1;
                Oc = 0;
            }
            else if(array[j][i] == 'O'){
                Oc += 1;
                Xc = 0;
            }
            else{
                Xc = 0;
                Oc = 0;
            }
        }
        if(Xc == 4)
            return 'X';
        else if(Oc == 4)
            return 'O';
    }
    // Processing the main diagonals to determine the winner
    int diagcol, diagrow;
    for(int i=1; i<col-1; i++){
        Xc=0;   Oc=0;
        if(i > col/2){
            diagcol = 2;
            diagrow = row-2-i;
        }
        else{
            diagcol = i;
            diagrow = row-2;
        }
        while(diagrow>=0){
            if(array[diagrow][diagcol] == 'X'){
                Xc += 1;
                Oc = 0;
            }
            else if(array[diagrow][diagcol] == 'O'){
                Oc += 1;
                Xc = 0;
            }
            else{
                Xc = 0;
                Oc = 0;
            }
            diagrow--;
            diagcol++;
          }

        if(Xc == 4)
            return 'X';
        else if(Oc == 4)
            return 'O';
    }
    // Processing the secondary diagonals to determine the winner
    for(int i=0; i<row-1; i++){
        Xc=0;   Oc=0;
        if(i > col-1/2){
            diagcol = 2;
            diagrow = 0;
        }
        else{
            diagcol = 1;
            diagrow = i;
        }
        while(diagrow<row-1){
            if(array[diagrow][diagcol] == 'X'){
                Xc += 1;
                Oc = 0;
            }
            else if(array[diagrow][diagcol] == 'O'){
                Oc += 1;
                Xc = 0;
            }
            else{
                Xc = 0;
                Oc = 0;
            }
            diagrow++;
            diagcol++;
          }
        if(Xc == 4)
            return 'X';
        else if(Oc == 4)
            return 'O';
    }

    return 'd';
}

int main() {
    cout << "Enter the Rows and Columns of the board (4 <= Rows && Columns <= 9), please = " << endl;
    int row, col;

    // Making sure of correct input
     while(true){
        cin >> row >> col;
        if(row >= 4 && row <= 9 && col >= 4 && col <= 9)
            break;
        else
            cout << "Wrong input, Try again with correct numbers" << endl;
    }

    // array to calculate the number of free rows
    int blank[col];
    for(int i=0; i<col; i++)
        blank[i] = row-1;

    // Main Array to store the inputs
    char array[20][20] = {'    '};
    row += 1;
    col += 1;
    Draw(array, row, col);

    // Loop to let the user inputs the numbers until winning
    while(punc < (row-1)*(col-1)){
        player_one(array, row, col, blank);
        Draw(array, row, col);
        if(whowins(array, row, col) != 'd'){
            cout << "The winner is player (" << whowins(array, row, col) << ") Congrats!" << endl;
            return 0;
        }
        player_two(array, row, col, blank);
        Draw(array, row, col);
        if(whowins(array, row, col) != 'd'){
            cout << "The winner is player (" << whowins(array, row, col) << ") Congrats!" << endl;
            return 0;
         }
    }

    cout << "It's a DRAW Situation" << endl;
    return 0;
}
