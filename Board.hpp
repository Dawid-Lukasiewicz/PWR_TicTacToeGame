#include<iostream>

using namespace std;

class Board
{
private:
    int Size = 3;
    int **BoardMatrix;
    char **BoardGame;
public:
    Board();
    ~Board();
    Board(int NewSize);

    void DisplayBoard();
};

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

void Board::DisplayBoard()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(j<Size-1)
                cout<<BoardGame[i][j]<<"  "<<'|';
            else
                cout<<BoardGame[i][j]<<"  ";
        }
        cout<<endl;
    }
}