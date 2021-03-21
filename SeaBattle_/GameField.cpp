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
            cout << setw(5);
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
                cout << " " << left << setw(2) << i + 1 << " ";
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

void DrawShips(int x , int y, int pos, int length, int player[][SIZE]){
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; i++)
        {
            if(i == y && j == x)
            {
                player[i][j] = 42;
            }
            if(pos == 0 && length != 0){
                y++;
                length--;
            }else if(pos == 1 && length != 0){
                x++;
                length--;
            }
        }
    }
}

void PositionPlayer(int playerA[][SIZE])
{
    int x, y, pos;
    bool end = true;
    do{
        cout << "\nВведите позицию и расположение коробля(x, y, 0 - вериткально, 1 - горизонтально): ";
        scanf("%d %*c %d %*c %d", &x, &y, &pos);
        printf("%d, %d, %d", x, y, pos);

    }while(x < 0 || x > 9 ||
           y < 0 || y > 9 ||
           pos < 0 || pos > 1);
    DrawShips(x, y, pos, 4, playerA);
}


void GameField::PosShips()
{
    PositionPlayer(fieldA);
}


