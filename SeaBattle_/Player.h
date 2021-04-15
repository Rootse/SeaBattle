#ifndef SEABATTLE_PLAYER_H
#define SEABATTLE_PLAYER_H

#include "GameField.h"

#define SIZE_FIELD 12

class Player{
private:
    void PutShip(int x, int y, bool pos, int len);
    bool CheckValidPos(int x, int y, bool pos, int len, bool autoFill);
    int tX, tY, temp = 1;
    int checkShip = 0;
    int mode = 0;

    int count = 0;
public:
    int playerField[SIZE_FIELD][SIZE_FIELD][2]{};
    int ships[SIZE_FIELD - 2][SIZE_FIELD - 2]{};
    void FillField();
    void PositionPlayerShips(int len, bool autoFill);
    bool Move(Player &Player, bool a = false);

    void MovePC(Player &Player, int &x, int &y);


};

#endif //SEABATTLE__PLAYER_H
