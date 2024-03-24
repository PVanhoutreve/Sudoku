#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
#include "buffer.h"
struct Sudoku{
    int ligne ;
    int colonne ;
    int *tab;
    int *tabIndexZero;
};

void read (struct Sudoku sudoku , int ligne , int colonne);
void set (struct Sudoku sudoku, int valeur , int ligne , int colonne);
void initSudokuLigne (struct Sudoku sudoku, struct TabTemp tabTemp, int ligne);
void initSudokuColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne);
void affiche (struct Sudoku sudoku);
void setCaseSudoku (struct Sudoku sudoku, int valeur , int ligne , int colonne);
void AjouteUnCaseSudoku (struct Sudoku sudoku, int index);

void setCaseSudoku (struct Sudoku sudoku, int valeur , int ligne , int colonne){
    sudoku.tab[sudoku.colonne*(ligne-1) + colonne-1] = valeur ;
}

void AjouteUnCaseSudoku (struct Sudoku sudoku, int index){
    if (sudoku.tab[sudoku.tabIndexZero[index]] ==9){
        sudoku.tab[sudoku.tabIndexZero[index]] = 1;
        AjouteUnCaseSudoku(sudoku, index + 1);
    }
    else {
        sudoku.tab[sudoku.tabIndexZero[index]] = sudoku.tab[sudoku.tabIndexZero[index]] + 1 ;
    }
}

void read (struct Sudoku sudoku , int ligne , int colonne){
    printf ("%d" ,sudoku.tab[sudoku.colonne*(ligne-1) + colonne]);
}

void affiche (struct Sudoku sudoku){
    int i,j = 0;
    for (i = 0 ; i < sudoku.ligne;i++){
        for (j = 0 ; j < sudoku.colonne ; j ++){
            read(sudoku , i , j);
            if(j == (sudoku.colonne-1)){
                printf("\n");
            }
        }
    }
}

void initSudokuLigne (struct Sudoku sudoku, struct TabTemp tabTemp, int ligne){
    int i = 0;
    printf ("Donner la %d-eme ligne du sudoku  ", ligne);
    scanf ("%s",tabTemp.tabTemp);
    tabTemp[sudoku.colonne] = '\0' ;
    for (i=0;i<sudoku.colonne ;i++){
        sudoku.tab[(ligne-1)*sudoku.colonne + i] = tabTemp.tabTemp[i]-'0';
    }
}

void initSudokuColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne){
    int i = 0;
    printf ("Donner la %d-eme colonne du sudoku", colonne + 1);
    scanf ("%s",tabTemp.tabTemp);
    tabTemp[sudoku.ligne] = '\0' ;
    for (i=0;i < sudoku.ligne ;i++){
        sudoku.tab[colonne-1 + i*sudoku.colonne]= tabTemp.tabTemp[i] - '0';
    }
}
#endif // SUDOKU_H_INCLUDED
