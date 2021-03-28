

#include "Game.h"

void Battle(GameField G)
{
    bool end = false;
    while(!end)
    {
        cout << "\nВыбирите ячейку: ";

    }
}

void GameStart()
{
    GameField Game;

    bool end = false;
    while(!end)
    {
        Game.FillField();
        Game.DrawField();

        for(int i = 4; i >= 1; i--)
        {
            for(int j = i; j != 5; j++)
            {
                Game.PositionPlayerShips(Game.fieldA, i, true);
                Game.PositionPlayerShips(Game.fieldB, i, true);
                Game.DrawField();
            }
        }
        end = true;
    }
}
