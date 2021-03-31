#include "GameField.h"


void GameField::DrawField(int PlayerA[][SIZE_FIELD][2], int PlayerB[][SIZE_FIELD][2]) {
//    system("clear");
    system("cls");
    for (int i = 0; i < SIZE_FIELD * 2; i++) {
        char sym = (char) (i + 65);
        if (i != 0 && i % SIZE_FIELD == 0) {
            cout << setw(4);
        }
        if (i >= SIZE_FIELD) {
            sym = (char) (i - SIZE_FIELD + 65);
        }
        cout << " " << sym << " ";
    }
    EndStr;
    for (int i = 0; i < SIZE_FIELD; i++) {
        for (int j = 0; j < SIZE_FIELD * 2; j++) {
            if (j != 0 && j % SIZE_FIELD == 0) {
                cout << " " << i << " ";
            }
            if(j >= SIZE_FIELD && PlayerB[i][j - SIZE_FIELD][1] != 44 && PlayerB[i][j - SIZE_FIELD][1] != 42)
            {
                CELL(PlayerB[i][j - SIZE_FIELD][0], PlayerB[i][j - SIZE_FIELD][1]);
            }else if(j >= SIZE_FIELD)
            {
                CELL(37, 44);
            }else{
                CELL(PlayerA[i][j][0], PlayerA[i][j][1]);
            }
        }
        EndStr;
    }
    EndStr;
}