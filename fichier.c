#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "sudokuSolver.h"
#define SUDOKU_LINE_SIZE 9

int main(){
    Sudoku* sudoku = NULL;
    sudoku->tab = malloc(SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE*sizeof(int)) ;
    sudoku->tabIndexZero = malloc(SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE*sizeof(int)) ;
    sudoku->tabIndexZeroSize = 0;

    SudokuSetChecker* sudokuSetChecker = NULL;
    sudokuSetChecker->set = malloc (SUDOKU_LINE_SIZE*sizeof(char));

    int tab[SUDOKU_LINE_SIZE * SUDOKU_LINE_SIZE] =  {4,9,1,6,7,5,2,3,8,
                                                     2,0,3,9,8,1,4,5,6,
                                                     8,5,0,4,3,2,9,1,7,
                                                     7,1,2,8,5,0,3,4,9,
                                                     5,6,4,7,0,3,1,8,2,
                                                     9,3,8,1,2,4,6,7,0,
                                                     1,4,5,2,6,7,8,9,3,
                                                     6,8,7,3,4,9,5,2,1,
                                                     3,2,9,5,1,8,7,6,4};
    for (int i=0;i<SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE;i++){
        sudoku->tab[i]=tab[i];
    }
    SetTabIndiceZero (sudoku);

    Sudoku_Affiche(sudoku);

    Sudoku_Solve(sudoku , sudokuSetChecker );

    Sudoku_Affiche(sudoku);
}
