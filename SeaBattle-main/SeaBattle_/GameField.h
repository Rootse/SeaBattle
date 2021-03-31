#ifndef SEABATTLE_GAMEFIELD_H
#define SEABATTLE_GAMEFIELD_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Player.h"

#define SHIP "\x1b[32;44m \x1b[0m"
#define HIT "\x1b[31;44m \x1b[0m"
#define CELL(a, b) printf("\x1b[1;%d;%dm o \x1b[0m", (a), (b))
#define EndStr cout << "\n";
#define SIZE_FIELD 10

using namespace std;



class GameField
{
private:

public:
    void DrawField(int PlayerA[][SIZE_FIELD][2], int PlayerB[][SIZE_FIELD][2]);

};

#endif // SEABATTLE_GAMEFIELD_H