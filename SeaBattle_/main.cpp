#include "GameField.h"


int main()
{
    GameField Game;

    bool end = false;
    while(!end)
    {
        Game.FillField();
        Game.DrawField();
        Game.PosShips();

        end = true;
    }

}

