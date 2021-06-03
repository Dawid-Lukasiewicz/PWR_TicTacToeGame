#include "Game.hh"

using namespace std;

Game::Game():
    Board::Board()
{}

Game::Game(int NewSize):
    Board::Board(NewSize)
{}

Game::~Game()
{}

const char& Game::GetTurn()
{
    return Turn;
}

void Game::SetTurn(char NextTurn)
{
    Turn=NextTurn;
}

void Game::DisplayBoard()
{
    Board::DisplayBoard();
}

char Game::NextPlayer(char CurrentPlayer)
{
    if(CurrentPlayer == 'X')
        return 'O';
    else
        return 'X';
}

char Game::NextTurn(char CurrentPlayer)
{
    int tmpX, tmpY;
    bool flag = true;
    do
    {
        cout<<"Ruch gracza: "<<CurrentPlayer<<endl;
        cin>>tmpX>>tmpY;
        if(BoardGame[tmpX][tmpY] == ' ')
        {
            BoardGame[tmpX][tmpY] = CurrentPlayer;
            flag = false;
        }
        else
        {
            DisplayBoard();
            cout<<"Spot occupied"<<endl;
        }
    } while (flag);

    return NextPlayer(CurrentPlayer);
}

bool Game::AchieveWin(char CurrentPlayer)
{
    
}