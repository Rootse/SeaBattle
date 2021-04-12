#include "Player.h"

void Player::FillField()
{
    for (int i = 0; i < SIZE_FIELD; i++)
    {
        for (int j = 0; j < SIZE_FIELD; j++)
        {
            playerField[i][j][0] = 37;
            playerField[i][j][1] = 44;
            ships[i][j] = -1;
        }
    }
}

void Player::PutShip(int x, int y, bool pos, int len)
{
    for (int i = 0; i < len; i++)
    {
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
    if (xLen <= 10 && yLen <= 10)
    {
        isField = true;
    }
    else {
        return false;
    }
    for (int i = y - 1; i <= yLen; i++)
    {
        for (int j = x - 1; j <= xLen; j++)
        {
            if (playerField[i][j][1] == 42)
            {
                isOverlay = false;
            }
        }
    }
    if (!isField || !isOverlay)
    {
        return false;
    }
    else if (!autoFill)
    {
        cout << "\nНеверное значение, попробуйте снова.";
    }
    return true;
}

void GetPosition(int &x, int &y, bool a = false)
{
    if(a) {
        x = rand() % 10;
        y = rand() % 10;
    }else
    {
        while(true)
        {
            cout << "\nВведите координаты для выстрела(A-J | 0-9): ";
            char xSym = 'A';
            cin >> xSym;

            cin.ignore(1);
            cin >> y;
            cin.ignore(32767, '\n');
            xSym = toupper(xSym);
            x = (int)(xSym - 65);
            if(x >= 0 && x <= 9 && y >= 0 && y <= 9)
            {
                break;
            }
        }
    }
}

void Player::PositionPlayerShips(int len, bool autoFill)
{
    int x, y;
    bool pos;
    bool valid = false;
    while (!valid)
    {
        if (!autoFill)
        {
            string dot;
            (len == 1) ? dot = " точки " : dot = " точек ";
            cout << "\nВведите позицию коробля из " << len << dot << "(A-J | 0-9 | 0 - вериткально, 1 - горизонтально): ";
            GetPosition(x, y);
            cin >> pos;
            cin.ignore(32767, '\n');
        }
        else {
            GetPosition(x, y, true);
            pos = rand() % 2;
        }

        if (x > 9 || x < 0 || y > 9 || y < 0) {
            valid = false;
            continue;
        }
        valid = CheckValidPos(x, y, pos, len, autoFill);
    }
    PutShip(x, y, pos, len);
}

void ReplaceColorShip(Player& Player, int nShip)
{
    for (int i = 0; i < 8 && Player.ships[nShip][i] != -1; i += 2)
    {
        int x = Player.ships[nShip][i];
        int y = Player.ships[nShip][i+1];
        //        Player.playerField[y+1][x][1] = 46;
        //        Player.playerField[y-1][x][1] = 46;
        //        Player.playerField[y][x+1][1] = 46;
        //        Player.playerField[y+1][x-1][1] = 46;
        Player.playerField[y][x][1] = 41;
        Player.playerField[y][x][0] = 33;
    }
}

int FindShip(Player &Player, int x, int y)
{
    for (int i = 0; i < SIZE_FIELD; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            if(Player.ships[i][j] == x && Player.ships[i][j + 1] == y)
            {
                return i;
            }
        }
    }
    return -1;
}

void IsDeadShip(Player& Player, int x, int y)
{
    int text = 37, bg = 0;
    bool end = false;
    int i = FindShip(Player, x ,y);
    if(i != -1)
    {
        for (int j = 0; j < 8 && !end; j += 2)
        {
            if (Player.ships[i][j] == x && Player.ships[i][j + 1] == y)
            {
                Player.ships[i][8] += 1;
                text = 33;      //Text YELLOW
                if (Player.ships[i][8] == Player.ships[i][9])
                {
                    ReplaceColorShip(Player, i);
                    end = true;
                }else{
                    bg = 47;
                }
                break;
            }
        }
    }
    if(!end)
    {
        Player.playerField[y][x][0] = text;
        Player.playerField[y][x][1] = bg;
    }
}

void Player::MovePC(Player &Player, int &x, int &y)
{
    int hor = 0;
    int vert = 0;
    if(Player::mode == 0)
    {
        while(true)
        {
            y = rand() % 10;
            int t = 3 - (y % 4);
            x = t + 1 + 4 * (rand() % 2);
            tX = x;
            tY = y;
            if(Player.playerField[y][x][1] == 42 || Player.playerField[y][x][1] == 44)
            {
                break;
            }
        }
    }else{
        while(true)
        {
            (checkShip == 0) ? hor = -temp : (checkShip == 1) ? hor = temp :(checkShip == 2) ? vert = -temp : vert = temp;
            x = tX + hor;
            y = tY + vert;
            if(Player.playerField[y][x][1] != 42)
            {
                checkShip++;
                if(Player.playerField[y][x][1] != 44)
                {
                    continue;
                }
            }else if(Player.playerField[y][x][1] == 42)
            {
                tX = x;
                tY = y;
                int i = FindShip(Player, x, y);
                temp = Player.ships[i][8];
            }
            break;
        }
    }
}

void Player::Move(Player& Player, bool a)
{
    int x, y;
    if (!a)
    {
        while (true) {
            GetPosition(x, y);
            if (Player.playerField[y][x][1] == 42 || Player.playerField[y][x][1] == 44) {
                break;
            }
        }
        IsDeadShip(Player, x, y);
    }
    else {
        MovePC(Player, x, y);
        IsDeadShip(Player, x, y);
        if(Player.playerField[y][x][0] == 33 && Player.playerField[y][x][1] != 41)
        {
            mode = 1;
        }else if(Player.playerField[tY][tX][1] == 41)
        {
            checkShip = 0;
            mode = 0;
        }
    }
}