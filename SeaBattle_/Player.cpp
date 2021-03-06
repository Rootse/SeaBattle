#include "Player.h"

void Player::FillField()
{
    for (int i = 0; i < SIZE_FIELD; i++)
    {
        for (int j = 0; j < SIZE_FIELD; j++)
        {
            if (i < 10 && j < 10)
            {
                ships[i][j] = -1;
            }
            if (i != 0 && i != 11 && j != 0 && j != 11)
            {
                playerField[i][j][0] = T_WHITE;
                playerField[i][j][1] = BG_BLUE;
            }
            else {
                playerField[i][j][0] = T_WHITE;
                playerField[i][j][1] = 40;
            }
        }
    }
}

void Player::PutShip(int x, int y, bool pos, int len)
{
    for (int i = 0; i < len; i++)
    {
        playerField[y][x][1] = BG_GREEN;
        ships[ship][i * 2] = x;
        ships[ship][i * 2 + 1] = y;
        (pos) ? x++ : y++;
    }
    ships[ship][8] = 0;
    ships[ship][9] = len;
    ship++;
}

bool Player::CheckValidPos(int x, int y, bool pos, int len, bool autoFill)
{
    bool isOverlay = true;
    bool isField;

    int xLen = x + 1;
    int yLen = y + 1;
    (pos) ? xLen += len : yLen += len;
    if (xLen <= 11 && yLen <= 11)
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
            if (playerField[i][j][1] == BG_GREEN)
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

void GetPosition(int& x, int& y, bool a = false)
{
    if (a) {
        x = 1 + rand() % 11;
        y = 1 + rand() % 11;
    }
    else
    {
        while (true)
        {
            cout << "\nВведите координаты для выстрела(A-J | 1-10): ";
            char xSym = 'A';
            cin >> xSym;

            cin.ignore(1);
            cin >> y;
            cin.ignore(32767, '\n');
            xSym = toupper(xSym);
            x = (int)(xSym - 64);
            if (x >= 1 && x <= 10 && y >= 1 && y <= 10)
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
            cout << "\nВведите позицию коробля из " << len << dot << "(A-J | 1-10 | 0 - вериткально, 1 - горизонтально): ";
            GetPosition(x, y);
            cin >> pos;
            cin.ignore(32767, '\n');
        }
        else {
            GetPosition(x, y, true);
            pos = rand() % 2;
        }

        if (x < 1 || x > 11 || y < 1 || y > 11) {
            valid = false;
            continue;
        }
        valid = CheckValidPos(x, y, pos, len, autoFill);
    }
    PutShip(x, y, pos, len);
}

void ReplaceColorShip(Player& Player, int nShip)
{
    int len = Player.ships[nShip][9] * 2 - 1;
    for (int tY = Player.ships[nShip][1] - 1; tY >= Player.ships[nShip][1] - 1 && tY <= Player.ships[nShip][len] + 1; tY++)
    {
        for (int tX = Player.ships[nShip][0] - 1; tX >= Player.ships[nShip][0] - 1 && tX <= Player.ships[nShip][len - 1] + 1; tX++)
        {
            if(tX != 0 && tX != 11 && tY != 0 && tY != 11)
            {
                Player.playerField[tY][tX][1] = BG_CYAN;
            }
        }
    }
    for (int i = 0; i <= len; i += 2)
    {
        int x = Player.ships[nShip][i];
        int y = Player.ships[nShip][i + 1];

        Player.playerField[y][x][1] = 41;
        Player.playerField[y][x][0] = 33;
    }
}

int FindShip(Player &Player, int x, int y)
{
    for (int i = 0; i < SIZE_SHIPS; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            if (Player.ships[i][j] == x && Player.ships[i][j + 1] == y)
            {
                return i;
            }
        }
    }
    return -1;
}

void IsDeadShip(Player &Player, int x, int y)
{
    int text = T_WHITE, bg = BG_BLACK;
    bool end = false;
    int i = FindShip(Player, x, y);
    if (i != -1)
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
                }
                else {
                    bg = 47;
                }
                break;
            }
        }
    }
    if (!end)
    {
        Player.playerField[y][x][0] = text;
        Player.playerField[y][x][1] = bg;
    }
}

void GetPos(Player &P, int &x, int &y, int &tX, int &tY)
{
    while (true) {
        y = 1 + rand() % 10;
        int indent, t;
        if (P.ships[0][8] == P.ships[0][9] && P.ships[1][8] == P.ships[1][9] && P.ships[2][8] == P.ships[2][9])
        {
            x = 1 + rand() % 10;
        }
        else if (P.ships[0][8] == P.ships[0][9]) {
            int r = 1 + rand() % 3;
            (r == 1) ? indent = 4 : indent = 2;
            t = indent - (y % 5);
            x = t + 1 + 3 * (rand() % 3);
        }
        else {
            indent = 4;
            t = indent - (y % 5);
            x = t + 1 + 3 * (rand() % 3);
        }
        if (P.playerField[y][x][1] == BG_GREEN || P.playerField[y][x][1] == BG_BLUE) {
            tX = x;
            tY = y;
            break;
        }
    }
}

void Player::MovePC(Player& Player, int& x, int& y)
{
    if (Player::mode == 0)
    {
        GetPos(Player, x, y, tX, tY);
    }
    else {
        while (true)
        {
            int hor = 0;
            int vert = 0;
            (checkShip == 0) ? hor = -temp : (checkShip == 1) ? hor = temp : (checkShip == 2) ? vert = -temp : vert = temp;
            x = tX + hor;
            y = tY + vert;
            if (Player.playerField[y][x][1] != BG_GREEN)
            {
                checkShip++;
                bool xy = x >= 1 && x <= 10 && y >= 1 && y <= 10;
                if (Player.playerField[y][x][1] != BG_BLUE)
                {
                    continue;
                }
                if (Player.playerField[tY][tX][0] == T_YELLOW)
                {
                    int i = FindShip(Player, tX, tY);
                    temp = Player.ships[i][8];
                }
                break;
            }else{
                tX = x;
                tY = y;
                temp = 1;
            }
            break;
        }
    }
}

bool Player::Move(Player &Player, bool a)
{
    int x, y;
    if (!a)
    {
        while (true) {
            GetPosition(x, y);
            if (Player.playerField[y][x][1] == BG_GREEN || Player.playerField[y][x][1] == BG_BLUE) {
                break;
            }
        }
        IsDeadShip(Player, x, y);
    }
    else {
        MovePC(Player, x, y);
        IsDeadShip(Player, x, y);
        if (Player.playerField[y][x][0] == T_YELLOW && Player.playerField[y][x][1] != BG_RED)
        {
            mode = 1;
        }
        else if (tX >= 1 && tX <= 10 && tY >= 1 && tY <= 10 && Player.playerField[tY][tX][1] == BG_RED)
        {
            checkShip = 0;
            mode = 0;
        }
    }
    if(Player.playerField[y][x][1] == BG_WHITE || Player.playerField[y][x][1] == BG_RED){
        return true;
    }
    return false;
}