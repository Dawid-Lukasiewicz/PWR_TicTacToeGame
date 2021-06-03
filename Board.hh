#ifndef BOARD
#define BOARD

#include<iostream>

class Board
{
protected:
    int Size = 3;
    int **BoardMatrix;
    char **BoardGame;
public:
    Board();
    ~Board();
    Board(int NewSize);

    void DisplayBoard();
};

#endif