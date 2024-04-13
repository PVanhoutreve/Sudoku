#ifndef SUDOKUSOLVE_H_INCLUDED
#define SUDOKUSOLVE_H_INCLUDED
#include "sudoku.h"

void Sudoku_Solve(Sudoku* sudoku,SudokuSetChecker* sudokuSetChecker);
void Sudoku_PlusOneInTabIndexZero(Sudoku* sudoku, int Index);

void Sudoku_PlusOneInTabIndexZero(Sudoku* sudoku, int Index){
    sudoku->tab[Index]+= 1;
    if (sudoku->tab[Index] == 10){
        sudoku->tab[Index] = 1;
        Sudoku_PlusOneInTabIndexZero(sudoku, Index + 1);
    }
}

void Sudoku_Solve(Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    int k;
    do{
        Sudoku_PlusOneInTabIndexZero (sudoku, sudoku->tabIndexZero[0]) ;
        k = Sudoku_Check(sudoku,sudokuSetChecker);
    }while (k != 1);
}

#endif // SUDOKUSOLVE_H_INCLUDED
