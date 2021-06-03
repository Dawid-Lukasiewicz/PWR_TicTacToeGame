#include "Board.hh"

using namespace std;

Board::Board()
{
    BoardMatrix = new int*[Size];
    BoardGame = new char*[Size];
    for (int i = 0; i < Size; i++)
    {
        BoardMatrix[i] = new int[Size];
        BoardGame[i] = new char[Size];
    }

    int k = 1;
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            BoardMatrix[i][j] = k++;
            BoardGame[i][j] = ' ';
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < Size; i++)
    {
        delete[] BoardMatrix[i];
    }
    delete[] BoardMatrix;
}

Board::Board(int NewSize):
    Size(NewSize)
{
    BoardMatrix = new int*[Size];
    BoardGame = new char*[Size];
    for (int i = 0; i < Size; i++)
    {
        BoardMatrix[i] = new int[Size];
        BoardGame[i] = new char[Size];
    }

    int k = 1;
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            BoardMatrix[i][j] = k++;
            BoardGame[i][j] = ' ';
        }
    }
}

const int& Board::GetSize()
{
    return Size;
}

char** Board::GetBoard()
{
    return BoardGame;
}


void Board::DisplayBoard()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(j<Size-1)
                cout<<BoardGame[i][j]<<" "<<"| ";
            else
                cout<<BoardGame[i][j];
        }
        cout<<endl;
    }
}

bool Board::CorrectMove(char& CurrentPlayer, int X_Value, int Y_Value)
{
    if(BoardGame[X_Value][Y_Value] == ' ')
        {
            BoardGame[X_Value][Y_Value] = CurrentPlayer;
            return true;
        }
        else
        {
            cout<<"Spot occupied"<<endl;
            return false;
        }
}

bool Board::AchieveWin(char CurrentPlayer)
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