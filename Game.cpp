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
    //Horizonally
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size-2; j++)
        {
            if(BoardGame[i][j]==BoardGame[i][j+1] && BoardGame[i][j]==BoardGame[i][j+2] && BoardGame[i][j]==CurrentPlayer)
            {
                cout<<"The "<<CurrentPlayer<<" Won"<<endl;
                return true;
            }
        }
    }

    //Vertically
    for (int i = 0; i < Size-2; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(BoardGame[i][j]==BoardGame[i+1][j] && BoardGame[i][j]==BoardGame[i+2][j] && BoardGame[i][j]==CurrentPlayer)
            {
                cout<<"The "<<CurrentPlayer<<" Won"<<endl;
                return true;
            }
        }
    }

    //Diagonally
    for (int i = 0; i < Size-2; i++)
    {
        for (int j = 0; j < Size-2; j++)
        {
            if(BoardGame[i][j]==BoardGame[i+1][j+1] && BoardGame[i][j]==BoardGame[i+2][j+2] && BoardGame[i][j]==CurrentPlayer)
            {
                cout<<"The "<<CurrentPlayer<<" Won"<<endl;
                return true;
            }
        }
    }
    return false;
}