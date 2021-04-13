#include "GameField.h"


void GameField::DrawField(int PlayerA[][SIZE_FIELD][2], int PlayerB[][SIZE_FIELD][2]) {
//    system("clear");
    system("cls");
    for (int i = 1; i < (SIZE_FIELD - 1) * 2; i++) {
        char sym = (char) (i + 64);
        if (i % (SIZE_FIELD - 1) == 0) {
            cout << setw(5);
        }
        if (i >= SIZE_FIELD - 1) {
            sym = (char) (i - (SIZE_FIELD - 2) + 64);
        }
        cout << " " << sym << " ";
    }
    EndStr;
    for (int i = 1; i < SIZE_FIELD - 1; i++) {
        for (int j = 1; j < (SIZE_FIELD - 1) * 2; j++) {
            if (j % (SIZE_FIELD - 1) == 0) {
                cout << setw(3) << i << " ";
            }
            if(j > SIZE_FIELD && PlayerB[i][j - (SIZE_FIELD - 1)][1] != 44 && PlayerB[i][j - (SIZE_FIELD - 1)][1] != 42)
            {
                CELL(PlayerB[i][j - (SIZE_FIELD - 1)][0], PlayerB[i][j - (SIZE_FIELD - 1)][1]);
            }else if(j < SIZE_FIELD - 1){
                CELL(PlayerA[i][j][0], PlayerA[i][j][1]);
            }else{
                CELL(37, 44);
            }
        }
        EndStr;
    }
    EndStr;
}