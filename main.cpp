#include <ctime>
#include "windows.h" 
#include "Board.hh"
#include "Game.hh"
#include "Ai.hh"

#define SLEEP 1000

using namespace std;

void Gamemode(int Size, int ToWin)
{   
    shared_ptr<Board> BoardToPlay = make_shared<Board>(Size, ToWin);
    Game *tmp = new Game(BoardToPlay);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    do
    {
        tmp->DisplayBoardClear();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    }while(!BoardToPlay->AchieveWin(CurrentPlayer));
    tmp->DisplayBoard();
}

void GamemodeAi(int Size, int ToWin)
{
    shared_ptr<Ai> ai = make_shared<Ai>('X');
    shared_ptr<Board> BoardToPlay = make_shared<Board>(Size, ToWin);
    Game *tmp = new Game(BoardToPlay,ai);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->NextTurn(tmp->GetTurn()));
    do
    {
        tmp->DisplayBoardClear();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurnAi(tmp->GetTurn()));
    }while(!BoardToPlay->AchieveWin(CurrentPlayer));
    tmp->DisplayBoard();
}

void GamemodeAivsAi(int Size, int ToWin)
{
    shared_ptr<Ai> ai = make_shared<Ai>('O');
    shared_ptr<Ai> ai2 = make_shared<Ai>('X');
    shared_ptr<Board> BoardToPlay = make_shared<Board>(Size, ToWin);
    Game *tmp = new Game(BoardToPlay,ai,ai2);
    char CurrentPlayer;

    tmp->DisplayBoard();
    tmp->SetTurn(tmp->MakeRandomMove());
    do
    {
        Sleep(SLEEP);
        tmp->DisplayBoardClear();
        CurrentPlayer = tmp->GetTurn();
        tmp->SetTurn(tmp->NextTurnAivsAi(tmp->GetTurn()));
    }while(!BoardToPlay->AchieveWin(CurrentPlayer));
    tmp->DisplayBoard();
}


int main()
{
    srand(time(NULL));
    char Button;
    int Size;
    int ToWin;
    do
    {
        
        cout<<"Choose gamemode"<<endl<<"1. Player vs Player"<<endl;
        cout<<"2. Player vs AI"<<endl<<"3. AI vs AI"<<endl<<"q. leave"<<endl;
        cin>>Button;
        switch (Button)
        {
        case '1':
            do
            {
                cout<<"Insert board size and win condition ";
                cin>>Size>>ToWin;
                cout<<endl;
                if(Size < 0 && ToWin <= Size)
                    cout<<"Incorrect size value or win condition"<<endl;
            }while(Size < 0 && ToWin <= Size);  
            Gamemode(Size, ToWin);
            break;

        case '2':
            do
            {
                cout<<"Insert board size and win condition ";
                cin>>Size>>ToWin;
                cout<<endl;
                if(Size < 0 && ToWin <= Size)
                    cout<<"Incorrect size value or win condition"<<endl;
            }while(Size < 0 && ToWin <= Size);  
            GamemodeAi(Size, ToWin);
            break;

        case '3':
            do
            {
                cout<<"Insert board size and win condition ";
                cin>>Size>>ToWin;
                cout<<endl;
                if(Size < 0 && ToWin <= Size)
                    cout<<"Incorrect size value or win condition"<<endl;
            }while(Size < 0 && ToWin <= Size);  
            GamemodeAivsAi(Size, ToWin);
            break;
        
        default:
            break;

        case 'q':
            break;
        }
    } while(Button != 'q');

    return 0;
}