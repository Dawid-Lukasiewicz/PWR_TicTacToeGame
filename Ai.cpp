#include<cstdlib>
#include "Ai.hh"



using namespace std;

Ai::Ai(char player):
    AiPlayer(player)
{}

Ai::~Ai()
{}

const char Ai::GetPlayer()
{
    return AiPlayer;
}

void Ai::MakeMove_random(shared_ptr<Board> BoardGame)
{
    int X_Value, Y_Value;
    do
    {
    X_Value=rand()%(BoardGame->GetSize());
    Y_Value=rand()%(BoardGame->GetSize());
    }while(!BoardGame->CorrectMove(AiPlayer, X_Value, Y_Value));
}

int Ai::evaluate(std::shared_ptr<Board> BoardGame, char& Opponent)
{
    //Horizontall
    if(BoardGame->HorizontalWin(AiPlayer))
        return 10;
    if(BoardGame->HorizontalWin(Opponent))
        return -10;
    // for (int i = 0; i < BoardGame->GetSize(); i++)
    // {
    //     for (int j = 0; j < BoardGame->GetSize()-2; j++)
    //     {
    //         if(BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i][j+1] && BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i][j+2])
    //         {
    //             if(BoardGame->GetBoard()[i][j] == AiPlayer)
    //                 return 10;
    //             else if(BoardGame->GetBoard()[i][j] == Opponent)
    //                 return -10;
    //         }  
    //     }
    // }
    // Verticall
    if(BoardGame->VerticalWin(AiPlayer))
        return 10;
    if(BoardGame->VerticalWin(Opponent))
        return -10;
    // for (int i = 0; i < BoardGame->GetSize()-2; i++)
    // {
    //     for (int j = 0; j < BoardGame->GetSize(); j++)
    //     {
    //         if(BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+1][j] && BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+2][j])
    //         {
    //             if(BoardGame->GetBoard()[i][j] == AiPlayer)
    //                 return 10;
    //             else if(BoardGame->GetBoard()[i][j] == Opponent)
    //                 return -10;
    //         }  
    //     }
    // }
    // Diagonal
    if(BoardGame->DiagonalWin(AiPlayer))
        return 10;
    if(BoardGame->DiagonalWin(Opponent))
        return -10;
    // for (int i = 0; i < BoardGame->GetSize()-2; i++)
    // {
    //     for (int j = 0; j < BoardGame->GetSize()-2; j++)
    //     {
    //         if(BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+1][j+1] && BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+2][j+2])
    //         {
    //             if(BoardGame->GetBoard()[i][j] == AiPlayer)
    //                 return 10;
    //             else if(BoardGame->GetBoard()[i][j] == Opponent)
    //                 return -10;
    //         }  
    //     }
    // }
    // Diagonal Inverse
    if(BoardGame->DiagonalInverseWin(AiPlayer))
        return 10;
    if(BoardGame->DiagonalInverseWin(Opponent))
        return -10;
    // for (int i = 0; i < BoardGame->GetSize()-2; i++)
    // {
    //     for (int j = BoardGame->GetSize()-1; j > 1; j--)
    //     {
    //         if(BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+1][j-1] && BoardGame->GetBoard()[i][j] == BoardGame->GetBoard()[i+2][j-2])
    //         {
    //             if(BoardGame->GetBoard()[i][j] == AiPlayer)
    //                 return 10;
    //             else if(BoardGame->GetBoard()[i][j] == Opponent)
    //                 return -10;
    //         }  
    //     }
    // }
    // If none wins return 0
    return 0;
}

int Ai::MinMax(std::shared_ptr<Board> BoardGame, int Depth, int IsWorth, bool IsMax)
{
    char OpponentPlayer = 'O';
    if(OpponentPlayer == AiPlayer)
        OpponentPlayer = 'X';
    // cout<<"IsWorth: "<<IsWorth<<endl;
    int MoveValue = evaluate(BoardGame, OpponentPlayer);

    if(MoveValue == 10 || MoveValue == -10) // If Ai wins next turn or Player wins next turn
        return MoveValue;
    // cout<<"IsWorth "<<IsWorth<<" Depth "<<Depth<<endl;
    if(BoardGame->IsTie() || IsWorth <= Depth)
    {
        // cout<<"IsWorth "<<IsWorth<<" ";
        // 
        return 0;
    }
    int Best;
    // Maximaze
    if(IsMax)
    {
        Best = -1000;
        for (int i = 0; i < BoardGame->GetSize(); i++)
        {
            for (int j = 0; j < BoardGame->GetSize(); j++)
            {
                if(BoardGame->CorrectMove(AiPlayer,i,j))    //Checking and inserting the AiPlayers into board
                {
                    IsWorth = min(IsWorth, Depth);
                    Best = max(Best, MinMax(BoardGame,++Depth,IsWorth, !IsMax)); //Taking max value of inserted move
                    BoardGame->GetBoard()[i][j] = ' ';  //Undoing the move
                    
                }
            }
        }
        return Best;
    }
    // Minimaze
    else
    {
        Best = 1000;
        for (int i = 0; i < BoardGame->GetSize(); i++)
        {
            for (int j = 0; j < BoardGame->GetSize(); j++)
            {
                if(BoardGame->CorrectMove(OpponentPlayer,i,j))  //Checking and inserting the OpponentPlayer into board
                {
                    IsWorth = max(IsWorth, Depth);
                    Best = min(Best, MinMax(BoardGame,++Depth,IsWorth, !IsMax)); //Taking min value of inserted move
                    BoardGame->GetBoard()[i][j] = ' ';  //Undoing the move
                    
                }
            }
        }
        return Best;
    }
}

void Ai::MakeBestMove(std::shared_ptr<Board> BoardGame)
{
    int BestMoveValue = -1000;
    int BestX_Move,BestY_Move;
    int IsWorth = 1000;

    for (int i = 0; i < BoardGame->GetSize(); i++)
    {
        for (int j = 0; j < BoardGame->GetSize(); j++)
        {
            if(BoardGame->CorrectMove(AiPlayer,i,j))
            {
                int CurrentMoveValue = MinMax(BoardGame, 0, IsWorth, false);
                // cout<<", CurrentMoveValue "<<CurrentMoveValue<<endl;
                BoardGame->GetBoard()[i][j] = ' ';
                if(CurrentMoveValue > BestMoveValue)
                {
                    BestMoveValue = CurrentMoveValue;
                    BestX_Move = i;
                    BestY_Move = j;
                }
            }
        }
    }
    // cout<<"X, Y: "<< BestX_Move << BestY_Move<<" "<<BestMoveValue<<endl; 
    BoardGame->CorrectMove(AiPlayer,BestX_Move,BestY_Move);
}