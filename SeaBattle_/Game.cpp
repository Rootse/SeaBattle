

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

void GameStart()
{
    GameField Game;
    Player PlayerA;
    Player PlayerB;

    bool end = false;
    while(!end)
    {
        PlayerA.FillField();
        PlayerB.FillField();
        GameField::DrawField(PlayerA.playerField, PlayerB.playerField);

        for(int i = 4; i >= 1; i--)
        {
            for(int j = i; j != 5; j++)
            {
                PlayerA.PositionPlayerShips(i, true);
                PlayerB.PositionPlayerShips(i, true);
                GameField::DrawField(PlayerA.playerField, PlayerB.playerField);
            }
        }
        int count = 0;
        while(count < 100)
        {
            PlayerA.Move(PlayerB);
            PlayerB.Move(PlayerA, true);
            GameField::DrawField(PlayerA.playerField, PlayerB.playerField);
            count++;
        }
        end = true;
    }
}
