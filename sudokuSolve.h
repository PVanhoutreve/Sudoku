#ifndef SUDOKU_SOLVER_H_INCLUDED
#define SUDOKU_SOLVER_H_INCLUDED
#include "sudoku.h"
#include <stdlib.h>
#define SUDOKU_LINE_SIZE 9

typedef struct strSudoku_solver {
    int* tab;
    int* tabIndexZero;
    int tabIndexZeroSize;
} Sudoku_Solver;

void Sudoku_Solver_AddOne(Sudoku_Solver* sudoku_solver, int Index);
void SetTabIndiceZero(Sudoku_Solver* sudoku_solver);
void Sudoku_Solver_Solve(Sudoku* sudoku, int* sudokuSetChecker);



void SetTabIndiceZero(Sudoku_Solver* sudoku_solver) {
    int k = 0;
    for (int i = 0;i < SUDOKU_LINE_SIZE;i++) { // set nombre de zéro
        for (int j = 0;j < SUDOKU_LINE_SIZE;j++) {
            if (sudoku_solver->tab[i * SUDOKU_LINE_SIZE + j] == 0) {
                k++;
            }
        }
    }
    sudoku_solver->tabIndexZeroSize = k;
    sudoku_solver->tabIndexZero = malloc(k * sizeof(int));

    k = 0;

    for (int i = 0;i < SUDOKU_LINE_SIZE;i++) { // set les indives des zéros
        for (int j = 0;j < SUDOKU_LINE_SIZE;j++) {
            if (sudoku_solver->tab[i * SUDOKU_LINE_SIZE + j] == 0) {
                sudoku_solver->tabIndexZero[k] = i * SUDOKU_LINE_SIZE + j;
                sudoku_solver->tab[sudoku_solver->tabIndexZero[k]] = 1;// on met tous les zéros à un avec la bonne place
                k++;
            }
        }
    }
}

void Sudoku_Solver_AddOne(Sudoku_Solver* sudoku_solver, int Index) {
    sudoku_solver->tab[sudoku_solver->tabIndexZero[Index]] += 1;

    if (sudoku_solver->tab[sudoku_solver->tabIndexZero[Index]] == 10) {
        sudoku_solver->tab[sudoku_solver->tabIndexZero[Index]] = 1;
        Sudoku_Solver_AddOne(sudoku_solver, Index + 1);
    }
}

void Sudoku_Solver_Solve(Sudoku* sudoku, int* sudokuSetChecker) {
    int k;

    Sudoku_Solver* sudoku_solver = malloc(sizeof(Sudoku_Solver));
    sudoku_solver->tab = malloc(SUDOKU_LINE_SIZE * SUDOKU_LINE_SIZE * sizeof(int));
    sudoku_solver->tabIndexZero = NULL;
    sudoku_solver->tabIndexZeroSize = 0;

    for (int i = 0; i < SUDOKU_LINE_SIZE * SUDOKU_LINE_SIZE;i++) {
        sudoku_solver->tab[i] = sudoku->tab[i];
    }


    SetTabIndiceZero(sudoku_solver);

    int compteur = 0;
    int essai_max = (sudoku_solver->tabIndexZeroSize) ^ 9; //nombre d'essai max à faire pour faire toutes les possibilités

    k = Sudoku_Check(sudoku, sudokuSetChecker); // on check si avec que des 1 ça marche

    while (k != 1 || compteur < essai_max) {

        Sudoku_Solver_AddOne(sudoku_solver, 0);
        compteur++;

        k = Sudoku_Check(sudoku, sudokuSetChecker);
    }

    if (k == 1) {
        Sudoku_Affiche(sudoku_solver->tab);
    }
    else { printf("il n'est pas possible de résoudre ce sudoku"); }
}

#endif // SUDOKUSOLVE_H_INCLUDED
