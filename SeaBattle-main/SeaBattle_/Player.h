#ifndef SEABATTLE__PLAYER_H
#define SEABATTLE__PLAYER_H

#include "GameField.h"

#define SIZE_FIELD 10

class Player{
private:
    void PutShip(int x, int y, bool pos, int len);
    bool CheckValidPos(int x, int y, bool pos, int len, bool autoFill);
    int ships[SIZE_FIELD];
    int count = 0;
public:
    int playerField[SIZE_FIELD][SIZE_FIELD][2];
//    int fieldDraw[SIZE_FIELD][SIZE_FIELD][2];
    void FillField();
    void PositionPlayerShips(int len, bool autoFill);
    void Move(Player &Player, bool a = false);

};

#endif //SEABATTLE__PLAYER_H
