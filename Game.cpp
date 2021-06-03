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
    if(CurrentPlayer == Players[1])
        return Players[0];
    else
        return Players[1];
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
    // Tie
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(BoardGame[i][j]==' ')
                goto NotFilled;
        }
    }
    cout<<"Tie!"<<endl;
    return true;
    NotFilled:
    
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

    //Diagonally Right
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
    //Diagonally Inverse
    for (int i = 0; i < Size-2; i++)
    {
        for (int j = Size-1; j > 1; j--)
        {
            // cout<<"Checing player "<<CurrentPlayer<<endl<<BoardGame[i][j]<<" "<<BoardGame[i+1][j-1]<<" "<<BoardGame[i+2][j-2]<<endl;
            if(BoardGame[i][j]==BoardGame[i+1][j-1] && BoardGame[i][j]==BoardGame[i+2][j-2] && BoardGame[i][j]==CurrentPlayer)
            {
                cout<<"The "<<CurrentPlayer<<" Won"<<endl;
                return true;
            }
        }
    }
    return false;
}