#ifndef GAME
#define GAME

#include "Board.hh"

class Game : public Board
{
private:
    char Players[2] = {'O','X'};
    char Turn = 'O';
    // char Player1 = 'O';
    // char Player2 = 'X';
public:
    Game();
    ~Game();
    Game(int NewSize);

    const char& GetTurn();
    void SetTurn(char NextTurn);

    void DisplayBoard();
    char NextTurn(char CurrentPlayer);
    char NextPlayer(char CurrentPlayer);
    bool AchieveWin(char CurrentPlayer);
};

#endif