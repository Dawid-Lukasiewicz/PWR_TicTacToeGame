#ifndef GAME
#define GAME

#include <memory>
#include "Board.hh"
#include "MiniMaxAi.hh"

class Game
{
private:
    char Players[2] = {'O','X'};
    char Turn = 'O';
    std::shared_ptr<MiniMaxAi> Ai = nullptr;
    std::shared_ptr<Board> BoardGame = nullptr;
public:
    Game();
    ~Game();
    Game(std::shared_ptr<Board>board);
    Game(std::shared_ptr<Board>board, std::shared_ptr<MiniMaxAi> ai);

    const char& GetTurn();
    void SetTurn(char NextTurn);

    void DisplayBoard();
    char NextTurn(char CurrentPlayer);
    char MakeMove(char CurrentPlayer);
    char NextPlayer(char CurrentPlayer);
    // bool AchieveWin(char CurrentPlayer);
};

#endif