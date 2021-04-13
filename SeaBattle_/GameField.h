#ifndef SEABATTLE_GAMEFIELD_H
#define SEABATTLE_GAMEFIELD_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Player.h"

#define CELL(a, b) printf("\x1b[1;%d;%dm * \x1b[0m", (a), (b))
#define EndStr cout << "\n";
#define SIZE_FIELD 12

using namespace std;

class GameField
{
private:

public:
    static void DrawField(int PlayerA[][SIZE_FIELD][2], int PlayerB[][SIZE_FIELD][2]);
};

#endif // SEABATTLE_GAMEFIELD_H