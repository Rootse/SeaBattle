#ifndef SEABATTLE_GAMEFIELD_H
#define SEABATTLE_GAMEFIELD_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Player.h"

#define EMPTY(a) printf("\x1b[%d;44m * \x1b[0m", (a))
#define SHIP "\x1b[32;44m \x1b[0m"
#define HIT "\x1b[31;44m \x1b[0m"
#define CELL(a) printf("\x1b[37;%dm * \x1b[0m", (a))
#define EndStr cout << "\n";

using namespace std;

#define SIZE 10

class GameField
{
private:

public:
    void DrawField(int PlayerA[][SIZE], int PlayerB[][SIZE]);

};

#endif // SEABATTLE_GAMEFIELD_H