#include <ctime>
#include "Board.hh"
#include "Game.hh"
#include "MiniMaxAi.hh"

using namespace std;

int main()
{
    srand(time(NULL));
    shared_ptr<MiniMaxAi> Ai = make_shared<MiniMaxAi>('X');
    shared_ptr<Board> BoardToPlay = make_shared<Board>(2);
    Game *tmp = new Game(BoardToPlay,Ai);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    do
    {
        tmp->DisplayBoard();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    }while(!BoardToPlay->AchieveWin(CurrentPlayer));
    tmp->DisplayBoard();

    return 0;
}