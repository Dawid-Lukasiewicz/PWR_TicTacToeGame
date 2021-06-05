#ifndef AI
#define AI

#include "Board.hh"

class Ai
{
private:
    char AiPlayer;
public:
    Ai() = delete;
    Ai(char player);
    ~Ai();

    const char GetPlayer();
    void MakeMove_random(std::shared_ptr<Board> BoardGame);

    int evaluate(std::shared_ptr<Board> BoardGame, char& Opponent);
    int MinMax(std::shared_ptr<Board> BoardGame, int Depth, int IsWorth, bool IsMax);
    void MakeBestMove(std::shared_ptr<Board> BoardGame);
};


#endif