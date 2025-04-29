#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <conio.h>
using namespace std;

//struct defs
struct Pos {
    int row;
    int col;
};

//func defs
void displayRoom(char room[9][9], int size);
void genRoom(char room[9][9], int size);
void plotPlayer(char room[9][9], Pos& startPos, int size);
void movePlayer(char room[9][9], Pos& pos, char move, int size);

//main func
int main()
{
    Pos pos;
    char move;
    char room[9][9];
    
    genRoom(room, 9);
    plotPlayer(room, pos, 9);
    displayRoom(room, 9);
    cout << "Row: " << pos.row << " Col: " << pos.col << endl;

    while (true) {
        if (_kbhit()) {
            move = _getch();
            if (move == 27) break;
            movePlayer(room, pos, move, 9);
            system("cls");
            displayRoom(room, 9);
            cout << "Row: " << pos.row << " Col: " << pos.col << endl;
        }
    }


    return 0; 
}


//other func
//gen
void displayRoom(char room[9][9], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << left << setw(2) << room[i][j];
        }
        cout << endl;
    }
}

void genRoom(char room[9][9], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            room[i][j] = '_';
        }
    }
}
//move
void plotPlayer(char room[9][9], Pos& startPos, int size) {
    srand(time(0));
    startPos;
    startPos.row = rand() % size, startPos.col = rand() % size;
    room[startPos.row][startPos.col] = 'T';
}

void movePlayer(char room[9][9], Pos& pos, char move, int size) {
    switch (move) {
    case 'w':
        if ((pos.row - 1) >= 0 && (pos.row - 1) <= 8) {
            room[pos.row][pos.col] = '_';
            pos.row -= 1;
            room[pos.row][pos.col] = 'T';
        }
        break;
    case 'a':
        if ((pos.col - 1) >= 0 && (pos.col - 1) <= 8) {
            room[pos.row][pos.col] = '_';
            pos.col -= 1;
            room[pos.row][pos.col] = 'T';
        }
        break;
    case 's':
        if ((pos.row + 1) >= 0 && (pos.row + 1) <= 8) {
            room[pos.row][pos.col] = '_';
            pos.row += 1;
            room[pos.row][pos.col] = 'T';
        }
        break;
    case 'd':
        if ((pos.col + 1) >= 0 && (pos.col + 1) <= 8) {
            room[pos.row][pos.col] = '_';
            pos.col += 1;
            room[pos.row][pos.col] = 'T';
        }
        break;
    default:
        cout << "wrong key use wasd for movement";
        break;
    }
}