#include "GameField.h"


void GameField::DrawField(int PlayerA[][SIZE_FIELD][2], int PlayerB[][SIZE_FIELD][2]) {
    system("clear");
//    system("cls");
    cout << setw(36) << "Счет - " << scoreA << " | " << scoreB << "\n";
    for (int i = 0; i < SIZE_FIELD * 2; i++) {
        char sym = (char) (i + 64);
        if ( i == 0) {
            cout << setw(4);
        }else if(i % SIZE_FIELD == 0){
            cout << setw(11);
        }
        if (i > SIZE_FIELD) {
            sym = (char) (i - SIZE_FIELD + 64);
        }
        if((i > 0 && i < 11) || (i - SIZE_FIELD > 0 && i - SIZE_FIELD < 11)){
            cout << " " << sym << " ";
        }

    }
    EndStr;
    for (int i = 0; i < SIZE_FIELD; i++) {
        for (int j = 0; j < SIZE_FIELD * 2; j++) {
            if(j != 0 && j % SIZE_FIELD == 0){
                (i == 0 || i == 11) ? cout << setw(4) << " ": cout << setw(3) << i << " ";
            }
            if(j >= SIZE_FIELD && PlayerB[i][j - SIZE_FIELD][1] != BG_BLUE && PlayerB[i][j - SIZE_FIELD][1] != BG_GREEN)
            {
                CELL(PlayerB[i][j - SIZE_FIELD][0], PlayerB[i][j - SIZE_FIELD][1]);
            }else if(j < SIZE_FIELD){
                CELL(PlayerA[i][j][0], PlayerA[i][j][1]);
            }else{
                CELL(T_WHITE, BG_BLUE);
            }
        }
        EndStr;
    }
    EndStr;
}