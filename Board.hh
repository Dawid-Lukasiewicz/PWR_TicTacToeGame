#ifndef BOARD
#define BOARD
#include<memory>
#include<iostream>

class Board
{
protected:
    int Size = 3;
    int ToWin = 3;
    char **BoardGame;
public:
    Board();
    ~Board();
    Board(int NewSize, int NewToWin);
    Board(char **ABoard, int size);

    const int& GetSize();
    char** GetBoard();

    void DisplayBoard();
    void DisplayBoardClear();
    bool CorrectMovePlayer(char& CurrentPlayer, int X_Value, int Y_Value);
    bool CorrectMove(char& CurrentPlayer, int X_Value, int Y_Value);
    bool IsTie();
    bool HorizontalWin(char& CurrentPlayer);
    bool VerticalWin(char& CurrentPlayer);
    bool DiagonalWin(char& CurrentPlayer);
    bool DiagonalInverseWin(char& CurrentPlayer);
    bool AchieveWin(char& CurrentPlayer);
};

#endif