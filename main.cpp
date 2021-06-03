#include "Board.hh"
#include "Game.hh"

using namespace std;

int main()
{
    Game *tmp = new Game(3);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    do
    {

        tmp->DisplayBoard();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
        if(tmp->AchieveWin(CurrentPlayer))
            return 0;
    }while(1);
    
    return 0;

}