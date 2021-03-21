#ifndef SEABATTLE_GAMEFIELD_H
#define SEABATTLE_GAMEFIELD_H

#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE 10

class GameField
{
private:
    int fieldA[SIZE][SIZE];
    int fieldB[SIZE][SIZE];


public:
    void FillField();
    void DrawField();
    void PosShips();

protected:
};

#endif // SEABATTLE_GAMEFIELD_H