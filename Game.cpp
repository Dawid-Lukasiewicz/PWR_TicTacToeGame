#include "Game.hh"

using namespace std;

Game::Game(std::shared_ptr<Board>board):
    BoardGame(board)
{}

Game::Game(std::shared_ptr<Board>board, std::shared_ptr<Ai> ai):
    BoardGame(board), AiGame(ai)
{}

Game::Game(std::shared_ptr<Board>board, std::shared_ptr<Ai> ai1, std::shared_ptr<Ai> ai2):
    BoardGame(board), AiGame(ai1), AiGame2(ai2)
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
    BoardGame->DisplayBoard();
}

void Game::DisplayBoardClear()
{
    BoardGame->DisplayBoardClear();
}

char Game::MakeRandomMove()
{
    if(AiGame->GetPlayer() == Turn)
    {
        AiGame->MakeMove_random(BoardGame);
        return AiGame2->GetPlayer();
    }
    else
    {
        AiGame2->MakeMove_random(BoardGame);
        return AiGame->GetPlayer();
    }
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
    int X_Value, Y_Value;
    do
    {
        cout<<"Player: "<<CurrentPlayer<<endl;
        do
        {
            cin>>X_Value>>Y_Value;
            if(X_Value > BoardGame->GetSize()-1 || Y_Value > BoardGame->GetSize()-1)
                cout<<"Exceeded board index"<<endl;
        }while(X_Value > BoardGame->GetSize()-1 || Y_Value > BoardGame->GetSize()-1);
    } while (!BoardGame->CorrectMovePlayer(CurrentPlayer, X_Value, Y_Value));
    return NextPlayer(CurrentPlayer);
}

char Game::NextTurnAi(char CurrentPlayer)
{
    if(AiGame->GetPlayer()==CurrentPlayer)
    {
        cout<<"Player: "<<CurrentPlayer<<endl;
        AiGame->MakeBestMove(BoardGame);
    }
    else
    {
        int X_Value, Y_Value;
        do
        {
            cout<<"Player: "<<CurrentPlayer<<endl;
            do
            {
                cin>>X_Value>>Y_Value;
                if(X_Value > BoardGame->GetSize()-1 || Y_Value > BoardGame->GetSize()-1)
                    cout<<"Exceeded board index"<<endl;
            }while(X_Value > BoardGame->GetSize()-1 || Y_Value > BoardGame->GetSize()-1);
        }while(!BoardGame->CorrectMovePlayer(CurrentPlayer, X_Value, Y_Value));
    }
    return NextPlayer(CurrentPlayer);
}

char Game::NextTurnAivsAi(char CurrentPlayer)
{
    if(AiGame->GetPlayer()==CurrentPlayer)
    {
        AiGame->MakeBestMove(BoardGame);
    }
    else
    {
        AiGame2->MakeBestMove(BoardGame);   
    }
    return NextPlayer(CurrentPlayer);
}