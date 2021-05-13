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

void GameStart()
{
    GameField Game;
    Player PlayerA;
    Player PlayerB;

    bool end = false;
    while(!end)
    {
        unsigned short scoreA = 0;
        unsigned short scoreB = 0;
        PlayerA.FillField();
        PlayerB.FillField();
        GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);

        for(int i = 4; i >= 1; i--)
        {
            for(int j = i; j != 5; j++)
            {
                PlayerA.PositionPlayerShips(i, true);
                PlayerB.PositionPlayerShips(i, true);
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);
            }
        }
        bool isHit = false;
        unsigned short shipA = 0;
        unsigned short shipB = 0;
        while(true)
        {
            do
            {
                isHit = PlayerA.Move(PlayerB);
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);
                if (isHit)
                {
                    shipA++;
                }
            } while (isHit);
            do {
                isHit = PlayerB.Move(PlayerA, true);
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);
                if (isHit)
                {
                    shipB++;
                }
            } while (isHit);
            if (shipA == 10)
            {
                scoreA++;
                break;
            } else if (shipB == 10)
            {
                scoreB++;
                break;
            }
        }
        end = true;
    }
}

int main()
{
    srand(time(nullptr));
//    SetConsoleOutputCP(CP_UTF8);
    GameStart();
}