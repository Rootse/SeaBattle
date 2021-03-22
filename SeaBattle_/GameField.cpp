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
        }
    }
};

void GameField::DrawField()
{
    system("clear");
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
            if(j > SIZE)
            {
                CELL(fieldB[i - SIZE][j - SIZE]);
            }else{
                CELL(fieldA[i][j]);
            }
        }
        EndStr;
    }
    EndStr;
}

void PutShip(int x , int y, int pos, int len, int player[][SIZE]){
    bool end = false;
    for(int i = 0; i < SIZE && !end; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i == y && j == x)
            {
                player[i][j] = 42;
            }
            if(pos == 0 && len != 0){
                y++;
                len--;
            }else if(pos == 1 && len != 0){
                x++;
                len--;
            }
            (len == 0) ? end = true : false;
        }
    }
}

void GameField::PositionPlayerShips(int len)
{
    int x = 0;
    int y = 0;
    int pos = 0;
    char xSym = 'A';

    string dot;
    (len == 1) ? dot = " точки " : dot = " точек ";

    bool isDiapazone;
    bool isField;
    do{
        cout << "\nВведите позицию коробля из " << len << dot << "(A,1,(0 - вериткально, 1 - горизонтально)): ";
        cin >> xSym;
        cin.ignore(1);
        cin >> y;
        cin.ignore(1);
        cin >> pos;
        cin.ignore(32767, '\n');

        x = (int)(xSym-65);
//        printf("%d, %d, %d", x, y, pos);
        isDiapazone = x >= 0 || x <= 9 || y >= 0 || y <= 9 || pos >= 0 || pos <= 1;
        if(pos == 0)
        {
            isField = y + len < 9;
        }else{
            isField = x + len < 9;
        }
    }while(!isDiapazone && !isField);
    PutShip(x, y, pos, len, fieldA);
}



