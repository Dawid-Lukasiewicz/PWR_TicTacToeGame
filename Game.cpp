#include "Game.hh"

using namespace std;

Game::Game(std::shared_ptr<Board>board):
    BoardGame(board)
{}

Game::Game(std::shared_ptr<Board>board, std::shared_ptr<MiniMaxAi> ai):
    BoardGame(board), Ai(ai)
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

char Game::NextPlayer(char CurrentPlayer)
{
    if(CurrentPlayer == Players[1])
        return Players[0];
    else
        return Players[1];
}

char Game::NextTurn(char CurrentPlayer)
{
    if(Ai->GetPlayer()==CurrentPlayer)
    {
        cout<<"Player: "<<CurrentPlayer<<endl;
        Ai->MakeMove_random(BoardGame);
    }
    else
    {
        int X_Value, Y_Value;
        do
        {
            cout<<"Player: "<<CurrentPlayer<<endl;
            cin>>X_Value>>Y_Value;
        } while (!BoardGame->CorrectMove(CurrentPlayer, X_Value, Y_Value));
    }
    return NextPlayer(CurrentPlayer);
}

char Game::MakeMove(char CurrentPlayer)
{
    return NextPlayer(CurrentPlayer);
}