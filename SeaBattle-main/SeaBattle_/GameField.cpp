#include "GameField.h"


void GameField::DrawField(int PlayerA[][SIZE], int PlayerB[][SIZE]) {
//    system("clear");
    system("cls");
    for (int i = 0; i < SIZE * 2; i++) {
        char sym = (char) (i + 65);
        if (i != 0 && i % SIZE == 0) {
            cout << setw(4);
        }
        if (i >= SIZE) {
            sym = (char) (i - SIZE + 65);
        }
        cout << " " << sym << " ";
    }
    EndStr;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE * 2; j++) {
            if (j != 0 && j % SIZE == 0) {
                cout << " " << i << " ";
            }
            if(PlayerA[i][j - SIZE] == 31 && j >= SIZE) {
                EMPTY(PlayerB[i][j - SIZE]);
            } else {
                (j >= SIZE) ? CELL(PlayerB[i][j - SIZE]) : CELL(PlayerA[i][j]);
            }

        }
        EndStr;
    }
    EndStr;
}