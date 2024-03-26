#include "sudoku.h"

void setCaseSudoku(struct Sudoku sudoku, int valeur, int ligne, int colonne) {
    sudoku.tab[sudoku.colonne * (ligne - 1) + colonne - 1] = valeur;
}

void AjouteUnCaseSudoku(struct Sudoku sudoku, int index) {
    if (sudoku.tab[sudoku.tabIndexZero[index]] == 9) {
        sudoku.tab[sudoku.tabIndexZero[index]] = 1;
        AjouteUnCaseSudoku(sudoku, index + 1);
    }
    else {
        sudoku.tab[sudoku.tabIndexZero[index]] = sudoku.tab[sudoku.tabIndexZero[index]] + 1;
    }
}


void Sudoku_print(Sudoku sudoku) {
    int i, j = 0;
    for (i = 0; i < SUDOKU_SIZE; i++) {
        if (i && (i % SUDOKU_LINE_SIZE) == 0) {
            printf("\n");
        }
        printf("%d ", Sudoku_get(&sudoku, i / SUDOKU_LINE_SIZE, i % SUDOKU_LINE_SIZE));
    }
}

/*

void initSudokuLigne(struct Sudoku sudoku, struct TabTemp tabTemp, int ligne) {
    int i = 0;
    printf("Donner la %d-eme ligne du sudoku  ", ligne);
    scanf("%s", tabTemp.tabTemp);
    tabTemp[sudoku.colonne] = '\0';
    for (i = 0; i < sudoku.colonne; i++) {
        sudoku.tab[(ligne - 1) * sudoku.colonne + i] = tabTemp.tabTemp[i] - '0';
    }
}

void initSudokuColonne(struct Sudoku sudoku, struct TabTemp tabTemp, int colonne) {
    int i = 0;
    printf("Donner la %d-eme colonne du sudoku", colonne + 1);
    scanf("%s", tabTemp.tabTemp);
    tabTemp[sudoku.ligne] = '\0';
    for (i = 0; i < sudoku.ligne; i++) {
        sudoku.tab[colonne - 1 + i * sudoku.colonne] = tabTemp.tabTemp[i] - '0';
    }
}
*/