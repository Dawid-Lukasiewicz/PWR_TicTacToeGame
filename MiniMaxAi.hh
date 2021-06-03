#ifndef AI
#define AI

#include "Board.hh"

class MiniMaxAi
{
private:
    char Player;
public:
    MiniMaxAi() = delete;
    MiniMaxAi(char player);
    ~MiniMaxAi();

    const char GetPlayer();
    void MakeMove_random(std::shared_ptr<Board> BoardGame);
};


#endif