#include "GameField.h"

#define EMPTY "\x1b[32;44m \x1b[0m"
#define SHIP "\x1b[32;44m \x1b[0m"
#define HIT "\x1b[31;44m \x1b[0m"
#define CELL(a) printf("\x1b[37;%dm • \x1b[0m", (a))
#define EndStr cout << "\n";


void GameField::FillField()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            fieldA[i][j] = 44;
            fieldB[i][j] = 44;
            fieldBDraw[i][j] = 44;
        }
    }
};

void GameField::DrawField()
{
//    system("clear");
    system("cls");
    for (int i = 0; i < SIZE * 2; i++)
    {
        char sym = (char)(i + 65);
        if(i != 0 && i % SIZE == 0)
        {
            cout << setw(4);
        }
        if(i >= SIZE)
        {
            sym = (char)(i - SIZE + 65);
        }
        cout << " " << sym << " ";
    }
    EndStr;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE * 2; j++)
        {
            if(j != 0 && j % SIZE == 0)
            {
                cout << " " << i << " ";
            }
            (j >= SIZE) ? CELL(fieldB[i][j-SIZE]) : CELL(fieldA[i][j]);
        }
        EndStr;
    }
    EndStr;
}

void PutShip(int x , int y, bool pos, int len, int player[][SIZE])
{
    for(int i = 0; i < len; i++)
    {
        player[y][x] = 42;
        (pos) ? x++ : y++;
    }
}

bool CheckValidPos(int x, int y, bool pos, int len, int playerShips[][SIZE], bool autoFill)
{
    bool isOverlay = true;
    bool isField = false;

    int xLen = x + 1;
    int yLen = y + 1;
    (pos) ? xLen += len : yLen += len;
    (pos) ? isField = xLen <= 10 : isField = yLen <= 10;
    for(int i = y - 1; i < yLen; i++)
    {
        for(int j = x - 1; j < xLen; j++)
        {
            if(playerShips[i][j] == 42)
            {
                isOverlay = true;
            }
        }
    }
    if(!isField || !isOverlay)
    {
        return false;
    }else if(!autoFill)
    {
        cout << "\nНеверное значение, попробуйте снова.";
    }
    return true;
}

void GameField::PositionPlayerShips(int player[][SIZE], int len, bool autoFill)
{
    int x = 0;
    int y = 0;
    bool pos;

    bool valid = false;
    while(!valid)
    {
        if(!autoFill)
        {
            char xSym = 'A';
            string dot;
            (len == 1) ? dot = " точки " : dot = " точек ";
            cout << "\nВведите позицию коробля из " << len << dot << "(A,1,(0 - вериткально, 1 - горизонтально)): ";
            cin >> xSym;
            cin.ignore(1);
            cin >> y;
            cin.ignore(1);
            cin >> pos;

            xSym = toupper(xSym);
            x = (int)(xSym-65);

        }else{
            x = rand()%10;
            y = rand()%10;
            pos = rand()%2;
        }

        if(x > 9 || x < 0 || y > 9 || y < 0){
            valid = false;
            continue;
        }
        valid = CheckValidPos(x, y, pos, len, player, autoFill);
    }
    PutShip(x, y, pos, len, player);
}



