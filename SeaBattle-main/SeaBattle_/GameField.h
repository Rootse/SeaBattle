#ifndef SEABATTLE_GAMEFIELD_H
#define SEABATTLE_GAMEFIELD_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define SIZE 10

class GameField
{
private:


public:
    int fieldA[SIZE][SIZE];
    int fieldB[SIZE][SIZE];
    void FillField();
    void DrawField();
    void PositionPlayerShips(int player[][SIZE], int len, bool fill);

protected:
};

#endif // SEABATTLE_GAMEFIELD_H