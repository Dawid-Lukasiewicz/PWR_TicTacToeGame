#ifndef BOARD
#define BOARD
#include<memory>
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

    const int& GetSize();
    char** GetBoard();

    void DisplayBoard();
    bool CorrectMove(char& CurrentPlayer, int X_Value, int Y_Value);
    bool AchieveWin(char CurrentPlayer);
};

#endif