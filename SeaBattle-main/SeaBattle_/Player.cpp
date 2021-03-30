#include "Player.h"

#define SIZE_XY 2

void Player::FillField()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            playerField[i][j][0] = 37;
            playerField[i][j][1] = 44;
            fieldDraw[i][j][0] = 37; // withe
            fieldDraw[i][j][1] = 44; // blue
        }
    }
}

void Player::PutShip(int x, int y, bool pos, int len)
{
    for(int i = 0; i < len; i++)
    {
        playerField[y][x][1] = 42;
        playerField[y][x][0] = 30;
        (pos) ? x++ : y++;
    }
}

bool Player::CheckValidPos(int x, int y, bool pos, int len, bool autoFill)
{
    bool isOverlay = true;
    bool isField;

    int xLen = x + 1;
    int yLen = y + 1;
    (pos) ? xLen += len : yLen += len;
    if(xLen <= 10 && yLen <= 10)
    {
        isField = true;
    }else{
        return false;
    }
    for(int i = y - 1; i <= yLen; i++)
    {
        for(int j = x - 1; j <= xLen; j++)
        {
            if(playerField[i][j][1] == 42)
            {
                isOverlay = false;
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

bool CheckValidMove(Player &Player, int x, int y)
{
    if(Player.playerField[y][x][1] == 42 && (Player.playerField[y][x-1][1] == 42 ||
                                          Player.playerField[y][x+1][1] == 42 ||
                                          Player.playerField[y][y-1][1] == 42 ||
                                          Player.playerField[y][y+1][1] == 42))
    {
        Player.fieldDraw[y][x][0] = 31;
    }
}

void GetPosition(int pos[], bool a = false)
{
    if(!a)
    {
        char xSym = 'A';
        cin >> xSym;
        cin.ignore(1);
        cin >> pos[1];
        cin.ignore(32767, '\n');

        xSym = toupper(xSym);
        pos[0] = (int) (xSym - 65);
    }else{
        pos[0] = rand()%10;
        pos[1] = rand()%10;
    }
}

void Player::PositionPlayerShips(int len, bool autoFill)
{
    int xy[SIZE_XY];
    bool pos;
    bool valid = false;
    while(!valid)
    {
        if(!autoFill)
        {
            string dot;
            (len == 1) ? dot = " точки " : dot = " точек ";
            cout << "\nВведите позицию коробля из " << len << dot << "(A-J | 0-9 | 0 - вериткально, 1 - горизонтально): ";
            GetPosition(xy);
            cin >> pos;
            cin.ignore(32767, '\n');
        }else{
            GetPosition(xy, true);
            pos = rand()%2;
        }

        if(xy[0] > 9 || xy[0] < 0 || xy[1] > 9 || xy[1] < 0){
            valid = false;
            continue;
        }
        valid = CheckValidPos(xy[0], xy[1], pos, len, autoFill);
    }
    PutShip(xy[0], xy[1], pos, len);
}

void Player::Move(Player &Player, bool a)
{
    int pos[SIZE_XY];
    if(!a)
    {
        cout << "\nВведите координаты для выстрела(A-J | 0-9): ";
        GetPosition(pos);
        CheckValidMove(Player, pos[0], pos[1]);
        Player.fieldDraw[pos[1]][pos[0]][1] = 40;
    }else{
        GetPosition(pos, true);
        CheckValidMove(Player, pos[0], pos[1]);
        playerField[pos[1]][pos[0]][1] = 40;
    }
}