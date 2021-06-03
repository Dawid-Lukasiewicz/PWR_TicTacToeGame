#include<cstdlib>
#include "MiniMaxAi.hh"

using namespace std;

MiniMaxAi::MiniMaxAi(char player):
    Player(player)
{}

MiniMaxAi::~MiniMaxAi()
{}

const char MiniMaxAi::GetPlayer()
{
    return Player;
}

void MiniMaxAi::MakeMove_random(shared_ptr<Board> BoardGame)
{
    int X_Value, Y_Value;
    do
    {
    X_Value=rand()%(BoardGame->GetSize());
    Y_Value=rand()%(BoardGame->GetSize());
    }while(!BoardGame->CorrectMove(Player, X_Value, Y_Value));
}