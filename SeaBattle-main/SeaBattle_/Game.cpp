//
// Created by yan on 3/22/21.
//

#include "Game.h"
#include "GameField.h"



void GameStart()
{
    GameField Game;

    bool end = false;
    while(!end)
    {
        Game.FillField();
        Game.DrawField();

        for(int i = 1; i <= 4; i++)
        {
            for(int j = 4; j >= i; j--)
            {
                Game.PositionPlayerShips(i);
                Game.DrawField();
            }
        }

        end = true;
    }
}
