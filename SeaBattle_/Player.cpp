#include "Player.h"

#define SIZE_XY 2

void Player::FillField()
{
    for(int i = 0; i < SIZE_FIELD; i++)
    {
        for(int j = 0; j < SIZE_FIELD; j++)
        {
            playerField[i][j][0] = 37;
            playerField[i][j][1] = 44;
            ships[i][j] = -1;
        }
    }
}

void Player::PutShip(int x, int y, bool pos, int len)
{
    for(int i = 0; i < len; i++)
    {
        playerField[y][x][0] = 37;
        playerField[y][x][1] = 42;
        ships[count][i * 2] = x;
        ships[count][i * 2 + 1] = y;
        (pos) ? x++ : y++;
    }
    ships[count][9] = len;
    ships[count][8] = 0;
    count++;
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

bool CheckValidMove(int playerField[][SIZE_FIELD][2], int x, int y)
{
    if(playerField[y][x][1] == 44 || playerField[y][x][1] == 42 && x <= 9 && x >= 0 && y <= 9 && y >= 0)
    {
        return true;
    }else{
        return false;
    }
}

void ReplaceColorShip(Player &Player, int nShip)
{
    for(int i = 0; i < 8; i += 2)
    {
        Player.playerField[Player.ships[nShip][i+1]][Player.ships[nShip][i]][1] = 41;
    }
}

void IsDeadShip(Player &Player, int x, int y)
{
    int text, bg;
    for(int i = 0; i < SIZE_FIELD; i++)
    {
        for(int j = 0; j < 8; j += 2)
        {
            if(Player.ships[i][j] == x && Player.ships[i][j+1] == y)
            {
                Player.ships[i][8]++;
                text = 33;      //Text YELLOW
                if(Player.ships[i][8] == Player.ships[i][9])
                {
                    ReplaceColorShip(Player, i);
                    bg = 41;    //BG RED
                }else{
                    bg = 47;    //BG RED
                }
            }
        }
    }
    Player.playerField[y][x][0] = text;
    Player.playerField[y][x][1] = bg;
}

void Player::Move(Player &Player, bool a)
{
    int pos[SIZE_XY];
    if(!a)
    {
        bool valid = false;
        while(!valid){
            cout << "\nВведите координаты для выстрела(A-J | 0-9): ";
            GetPosition(pos);
            valid = CheckValidMove(Player.playerField, pos[0], pos[1]);
        }
        IsDeadShip(Player, pos[0], pos[1]);
    }else{
        GetPosition(pos, true);
        CheckValidMove(Player.playerField, pos[0], pos[1]);
        playerField[pos[1]][pos[0]][1] = 40;
    }
}