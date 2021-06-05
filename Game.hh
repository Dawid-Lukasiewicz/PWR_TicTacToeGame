#ifndef GAME
#define GAME

#include <memory>
#include "Board.hh"
#include "Ai.hh"

class Game
{
private:
    char Players[2] = {'O','X'};
    char Turn = 'O';
    std::shared_ptr<Ai> AiGame = nullptr;
    std::shared_ptr<Ai> AiGame2 = nullptr;
    std::shared_ptr<Board> BoardGame = nullptr;
public:
    Game();
    ~Game();
    Game(std::shared_ptr<Board>board);
    Game(std::shared_ptr<Board>board, std::shared_ptr<Ai> ai);
    Game(std::shared_ptr<Board>board, std::shared_ptr<Ai> ai1, std::shared_ptr<Ai> ai2);

    const char& GetTurn();
    void SetTurn(char NextTurn);

    void DisplayBoard();
    void DisplayBoardClear();
    char MakeRandomMove();
    char NextTurn(char CurrentPlayer);
    char NextTurnAi(char CurrentPlayer);
    char NextTurnAivsAi(char CurrentPlayer);
    char NextPlayer(char CurrentPlayer);
};

#endif