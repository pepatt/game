#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <conio.h>
using namespace std;

//global
char playerChar = 'T';
char currTile = '_';

//struct defs
struct Pos {
    int row;
    int col;
};

struct Stats {
    int stren = 1;
    int craft = 1;
};

//func defs
void displayRoom(char room[9][9], int size);
void displayStats(Stats stats);
void genRoom(char room[9][9], int size);
void plotPlayer(char room[9][9], Pos& startPos, int size);
void movePlayer(char room[9][9], Pos& pos, char move, int size);
void stepHandler(char room[9][9], Pos& pos, char axis, int incr);

//main func
int main()
{
    Pos pos;
    Stats stats;
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
    room[startPos.row][startPos.col] = playerChar;
}

void movePlayer(char room[9][9], Pos& pos, char move, int size) {
    switch (move) {
    case 'w':
        stepHandler(room, pos, 'r', -1);
        break;
    case 'a':
        stepHandler(room, pos, 'c', -1);
        break;
    case 's':
        stepHandler(room, pos, 'r', 1);
        break;
    case 'd':
        stepHandler(room, pos, 'c', 1);
        break;
    default:
        cout << "wrong key use wasd for movement";
        break;
    }
}

void displayStats(Stats stats) {
    cout << "Strength: " << stats.stren << " Craft: " << stats.craft << endl;
}

void stepHandler(char room[9][9], Pos& pos, char axis, int incr) {
    switch (axis) {
    case 'r':
        if ((pos.row + incr) >= 0 && (pos.row + incr) <= 8) {
            room[pos.row][pos.col] = currTile;
            currTile = room[pos.row + incr][pos.col];
            pos.row += incr;
            room[pos.row][pos.col] = playerChar;
        }
        break;
    case 'c':
        if ((pos.col + incr) >= 0 && (pos.col + incr) <= 8) {
            room[pos.row][pos.col] = currTile;
            currTile = room[pos.row][pos.col + incr];
            pos.col += incr;
            room[pos.row][pos.col] = playerChar;
        }
        break;
    default:
        cout << "error in step handling" << endl;
    }
}