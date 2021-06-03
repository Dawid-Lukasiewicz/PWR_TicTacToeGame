#include "Board.hh"
#include "Game.hh"

using namespace std;

int main()
{
    Game *tmp = new Game(5);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    do
    {

        tmp->DisplayBoard();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
        tmp->AchieveWin(CurrentPlayer);
    }while(1);
    
    return 0;

}