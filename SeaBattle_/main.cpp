#include "Game.h"
#include <windows.h>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);
    GameStart();
}

