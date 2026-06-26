#ifndef SUDOKUSOLVE_H_INCLUDED
#define SUDOKUSOLVE_H_INCLUDED
#include "sudoku.h"
#define SUDOKU_LINE_SIZE 9

void Sudoku_Solve(Sudoku* sudoku_Solver , SudokuSetChecker* sudokuSetChecker);
void Sudoku_addOne(Sudoku* sudoku_solver, int* Index);
void SetTabIndiceZero (Sudoku *sudoku_Solver);

 typedef struct strSudoku_solver{
    int *tab;
    int *tabIndexZero;
    int tabIndexZeroSize;
    } Sudoku_Solver;


void Sudoku_Solver_AddOne(Sudoku* sudoku_Solver,int Index){
    sudoku_Solver->tab[tabIndexZero[Index]] += 1;
    if (sudoku_Solver->tabIndexZero[tabIndexZeroSize-1] == 10 && sudoku_Solver->tab[0]==10){
        Printf ("le sudoku n'est pas faisable");
        exit ;
    }
    if (sudoku_Solver->tab[Index] == 10){
        sudoku_Solver->tab[Index] = 1;
        Sudoku_Solver_AddOne(sudoku_Solver, Index + 1);
    }
}

void Sudoku_Solver_Solve(Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    int k;

    struct Sudoku_Solver sudoku_solver ;

    for (int i=0;i<SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE;i++){
        sudoku_Solver->tab[i] = sudoku[i];
    }

    void SetTabIndiceZero (Sudoku *sudoku_Solver){
    int k = 0 ;
        for (int i=0;i<SUDOKU_LINE_SIZE;i++){ // set nombre de zéro
            for(int j=0;j<SUDOKU_LINE_SIZE;j++){
                if (sudoku->tab[i*SUDOKU_LINE_SIZE + j] == 0){
                    k++ ;
                }
            }
        }
        Sudoku_Solver->tabIndexZeroSize = k ;
        Sudoku_Solver->tabIndexZero = (int *)malloc(k * sizeof(int));

        k=0;

        for (int i=0;i<SUDOKU_LINE_SIZE;i++){ // set les indives des zéros
            for(int j=0;j<SUDOKU_LINE_SIZE;j++){
                if (sudoku->tab[i*SUDOKU_LINE_SIZE + j] == 0){
                    Sudoku_Solver->tabIndexZero[k] = i*SUDOKU_LINE_SIZE +j ;
                }
            }
        }
    }

    do{
        k = 1;
        Sudoku__Solver_AddOne (sudoku, sudoku->tabIndexZero[0]) ;
        k = Sudoku_Check(sudoku,sudokuSetChecker);
    }while (k != 1);
}

#endif // SUDOKUSOLVE_H_INCLUDED
