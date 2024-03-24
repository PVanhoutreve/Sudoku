#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "buffer.h"
#include "sudoku.h"
#include "sudokuSolve.h"
int main(){
    struct Sudoku sudoku ;
    int i = 0;
    sudoku.ligne = 9 ;
    sudoku.colonne = 9 ;
    sudoku.tab = malloc(sudoku.ligne*sudoku.colonne*sizeof(int)) ;
    sudoku.tabIndexZero = malloc(sudoku.ligne*sudoku.colonne*sizeof(int)) ;

    struct TabTemp tabTemp;
    tabTemp.tabTemp = malloc (sudoku.ligne*sizeof(char));

    sudoku.tab = {4,9,1,6,7,5,2,3,8,
                    2,0,3,9,8,1,4,5,6,
                    8,5,0,4,3,2,9,1,7,
                    7,1,2,8,5,0,3,4,9,
                    5,6,4,7,0,3,1,8,2,
                    9,3,8,1,2,4,6,7,0,
                    1,4,5,2,6,7,8,9,3,
                    6,8,7,3,4,9,5,2,1,
                    3,2,9,5,1,8,7,6,4};


    affiche(sudoku);

    Solve (sudoku,tabTemp);

    affiche (sudoku);
}

