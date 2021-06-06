#include "Board.hh"

using namespace std;

Board::Board()
{
    BoardGame = new char*[Size];
    for (int i = 0; i < Size; i++)
    {
        BoardGame[i] = new char[Size];
        for (int j = 0; j < Size; j++)
        {
            BoardGame[i][j] = ' ';
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < Size; i++)
    {
        delete[] BoardGame[i];
    }
    delete[] BoardGame;
}

Board::Board(int NewSize, int NewToWin):
    Size(NewSize), ToWin(NewToWin)
{
    BoardGame = new char*[Size];
    for (int i = 0; i < Size; i++)
    {
        BoardGame[i] = new char[Size];
        for (int j = 0; j < Size; j++)
        {
            BoardGame[i][j] = ' ';
        }
    }
}

Board::Board(char **ABoard, int size)
{
    Size = size;
    BoardGame = new char*[Size];
    for (int i = 0; i < Size; i++)
    {
        BoardGame[i] = new char[Size];
        for (int j = 0; j < Size; j++)
        {
            BoardGame[i][j] = ABoard[i][j];
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

void Board::DisplayBoardClear()
{
    system("cls");
    DisplayBoard();
}

bool Board::CorrectMovePlayer(char& CurrentPlayer, int X_Value, int Y_Value)
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

bool Board::CorrectMove(char& CurrentPlayer, int X_Value, int Y_Value)
{
    if(BoardGame[X_Value][Y_Value] == ' ')
        {
            BoardGame[X_Value][Y_Value] = CurrentPlayer;
            return true;
        }
        else
        {
            return false;
        }
}

bool Board::IsTie()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(BoardGame[i][j]==' ')
                return false;
        }
    }
    return true;
}

bool Board::HorizontalWin(char& CurrentPlayer)
{
    char TmpA;

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size-ToWin+1; j++)
        {
            if(BoardGame[i][j] == CurrentPlayer)
            {
                int Points = 0;
                TmpA = BoardGame[i][j];
                for (int k = j; k < ToWin; k++)
                {
                    
                    if(TmpA == BoardGame[i][k])
                        Points++;
                    if(Points >= ToWin)
                        return true;
                }
            }
        }
    }
    return false;
}

bool Board::VerticalWin(char& CurrentPlayer)
{
    char TmpA;
    for (int i = 0; i < Size-ToWin+1; i++)
    {
        for (int j = 0; j < Size ; j++)
        {
            if(BoardGame[i][j] == CurrentPlayer)
            {
                int Points = 0;
                TmpA = BoardGame[i][j];
                for (int k = i; k < ToWin; k++)
                {
                    
                    if(TmpA == BoardGame[k][j])
                        Points++;
                    if(Points >= ToWin)
                        return true;
                }
            }
        }
    }
    return false;
}

bool Board::DiagonalWin(char& CurrentPlayer)
{
    char TmpA;
    for (int i = 0; i < Size-ToWin+1; i++)
    {
        for (int j = 0; j < Size-ToWin+1; j++)
        {
            if(BoardGame[i][j] == CurrentPlayer)
            {
                int Points = 0;
                TmpA = BoardGame[i][j];
                for (int k = 0; k < ToWin; k++)
                {      
                    if(TmpA == BoardGame[k+i][k+j])
                        Points++;
                    if(Points >= ToWin)
                        return true;
                }
            }
        }
    }
    return false;
}

bool Board::DiagonalInverseWin(char& CurrentPlayer)
{
    char TmpA;
    for (int i = 0; i < Size-ToWin+1; i++)
    {
        for (int j = Size-1; j > 0 + ToWin-2; j--)
        {
            if(BoardGame[i][j] == CurrentPlayer)
            {
                int n = i;
                int Points = 0;
                TmpA = BoardGame[i][j];
                for (int k = j; k > -1; k--)
                {   
                    if(TmpA == BoardGame[n++][k])
                        Points++;
                    else
                        break;
                    if(Points >= ToWin)
                        return true;
                }
            }
        }
    }
    return false;
}

bool Board::AchieveWin(char& CurrentPlayer)
{
    //Horizonally
    if(HorizontalWin(CurrentPlayer))
    {
        cout<<"The "<<CurrentPlayer<<" Won"<<endl;
        return true;
    }
    //Vertically
    if(VerticalWin(CurrentPlayer))
    {
        cout<<"The "<<CurrentPlayer<<" Won"<<endl;
        return true;
    }
    //Diagonally
    if(DiagonalWin(CurrentPlayer))
    {
        cout<<"The "<<CurrentPlayer<<" Won"<<endl;
        return true;
    }
    //Diagonally Inverse
    if(DiagonalInverseWin(CurrentPlayer))
    {
        cout<<"The "<<CurrentPlayer<<" Won"<<endl;
        return true;
    }
    // Tie
    if(IsTie())
    {
        cout<<"Tie!"<<endl;
        return true;
    }
    return false;
}