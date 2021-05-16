#include "GameField.h"
#include "Player.h"
//#include <windows.h>
#include <ctime>

bool CheckShipsPlayer(Player &player)
{
    unsigned short temp = 0;
    for(int i = 0; i < 10; i++)
    {
        if(player.ships[i][8] == player.ships[i][9]){
            temp++;
        }
    }
    if(temp == 10)
    {
        return true;
    }else{
        return false;
    }
}

int CheckWin(Player &PlayerA, Player &PlayerB)
{
    if(CheckShipsPlayer(PlayerA))
    {
        return 1;
    }else if(CheckShipsPlayer(PlayerB)){
        return 2;
    }
    return 0;
}

void PutShips(Player &A, Player &B, GameField G, bool aut = true)
{
    for(int i = 4; i >= 1; i--)
    {
        for(int j = i; j != 5; j++)
        {
            A.PositionPlayerShips(i, aut);
            B.PositionPlayerShips(i, aut);
            G.DrawField(A.playerField, B.playerField);
        }
    }
}

void Moves(Player &pA, Player &pB, GameField &G)
{
    bool isHit = false;
    unsigned short shipA = 0;
    unsigned short shipB = 0;
    while(true)
    {
        do
        {
            isHit = pA.Move(pB);
            G.DrawField(pA.playerField, pB.playerField);
            if (isHit)
            {
                shipA++;
            }
        } while (isHit);
        do {
            isHit = pB.Move(pA, true);
            G.DrawField(pA.playerField, pB.playerField);
            if (isHit)
            {
                shipB++;
            }
        } while (isHit);
        if (shipA == 20)
        {
            ++G.scoreA;
            break;
        } else if (shipB == 20)
        {
            ++G.scoreB;
            break;
        }
    }
}

void GameStart()
{
    GameField Game;

    bool end = false;
    int i = 0;
    while(i<10)
    {
        Player PlayerA;
        Player PlayerB;
        PlayerA.FillField();
        PlayerB.FillField();
        Game.DrawField(PlayerA.playerField, PlayerB.playerField);

        PutShips(PlayerA, PlayerB, Game);

        Moves(PlayerA, PlayerB, Game);

        i++;
        end = true;
    }
}

int main()
{
    srand(time(nullptr));
//    SetConsoleOutputCP(CP_UTF8);
    GameStart();
}