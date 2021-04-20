

#include "Game.h"

void Battle(GameField G)
{
    bool end = false;
    while(!end)
    {
        cout << "\nВыбирите ячейку: ";
        end = true;

    }
}

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
        while(Game.count < 100)
        {
            bool isHit = false;
            do
            {
                isHit = PlayerA.Move(PlayerB);
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);
                Game.count++;
            }while(isHit);
            do
            {
                isHit = PlayerB.Move(PlayerA, true);
//                for(int i = 0; i < 10; i++)
//                {
//                    for(int j = 0; j < 10; j++)
//                    {
//                        cout << PlayerA.ships[i][j] << " | ";
//                    }
//                    cout << "\n";
//                }
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField, scoreA, scoreB);
                Game.count++;
            }while(isHit);
            unsigned short temp = -1;
            if(Game.count > 20)
            {
                temp = CheckWin(PlayerA, PlayerB);
            }
            if(temp == 1)
            {
                scoreA++;
                break;
            }else if(temp == 2){
                scoreB++;
                break;
            }
        }
        end = true;
    }
}
