#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "SudokuSetChecker.h"

#define SUDOKU_SIZE 81
#define SUDOKU_LINE_SIZE 9
#define SUDOKU_CHECK_POSSIBILITIES 9

typedef struct strSudoku{
    int tab[SUDOKU_SIZE];
    int *tabIndexZero;
    int tabIndexZeroSize;
} Sudoku;


inline boolean Sudoku_Solver(Sudoku* iSudoku, const int indexTab) {

    if (indexTab >= iSudoku->tabIndexZeroSize) {
        return Sudoku_check(iSudoku);
    }

    boolean stopLoop = boolean_false;
    for (int i = 0; !stopLoop && i < SUDOKU_CHECK_POSSIBILITIES; i += 1) {
        iSudoku->tab[iSudoku->tabIndexZero[indexTab]] = i;
        stopLoop = Sudoku_Solver(iSudoku, indexTab + 1);
    }
    return stopLoop;
}

inline void Sudoku_Solver(Sudoku* iSudoku) {
    if (iSudoku->tabIndexZeroSize) {
        Sudoku_Solver(iSudoku, 0);
    }
    else {
        printf("Sudoku already solved");
    }
    return;
}



inline void Sudoku_reset(Sudoku* iSudoku) { memset(iSudoku, 0, sizeof(struct strSudoku)); }
inline void Sudoku_init (Sudoku* iSudoku) { Sudoku_reset(iSudoku); }


inline int  Sudoku_index(const int iLine, const int iColumn) { return iLine * SUDOKU_LINE_SIZE + iColumn; }


inline void Sudoku_set(Sudoku* iSudoku, const int iLine, const int iColumn, const char iValue) { iSudoku->tab[Sudoku_index(iLine, iColumn)] = iValue; }
inline int  Sudoku_get(Sudoku* iSudoku, const int iLine, const int iColumn                   ) { return iSudoku->tab[Sudoku_index(iLine, iColumn)]; }


inline boolean Sudoku_check(Sudoku* iSudoku) {
    for (int i = 0; i < SUDOKU_CHECK_POSSIBILITIES; i += 1) {
        boolean aTmp = Sudoku_checkLine(iSudoku, i);
        aTmp &= Sudoku_checkColumn(iSudoku, i);
        aTmp &= Sudoku_checkSquare(iSudoku, i);
        if (!aTmp) {
            return boolean_false;
        }
    }
    return boolean_true;
}

inline boolean Sudoku_checkLine(Sudoku* iSudoku, const int iLine) {
    SudokuSetChecker aSudokuSetChecker;
    SudokuSetChecker_init(&aSudokuSetChecker);

    for (int i = 0; i < SUDOKU_LINE_SIZE; i += 1) {
        const int aCaseValue = Sudoku_get(iSudoku, iLine, i);
        SudokuSetChecker_increment(&aSudokuSetChecker, aCaseValue);
    }

    return SudokuSetChecker_check(&aSudokuSetChecker);
}

inline boolean Sudoku_checkColumn(Sudoku* iSudoku, const int iColumn) {
    SudokuSetChecker aSudokuSetChecker;
    SudokuSetChecker_init(&aSudokuSetChecker);

    for (int i = 0; i < SUDOKU_LINE_SIZE; i += 1) {
        const int aCaseValue = Sudoku_get(iSudoku, i, iColumn);
        SudokuSetChecker_increment(&aSudokuSetChecker, aCaseValue);
    }

    return SudokuSetChecker_check(&aSudokuSetChecker);

}

inline boolean Sudoku_checkSquare(Sudoku* iSudoku, const int iIndex) {
    SudokuSetChecker aSudokuSetChecker;
    SudokuSetChecker_init(&aSudokuSetChecker);

    const int aIndexSquareLine   = iIndex / 3;
    const int aIndexSquareColumn = iIndex % 3;

    for (int i = 0; i < 3; i += 1) {
        const int aCaseValue = Sudoku_get(iSudoku, aIndexSquareLine * 3 * SUDOKU_LINE_SIZE, aIndexSquareColumn * 3 + i);
        SudokuSetChecker_increment(&aSudokuSetChecker, aCaseValue);
    }
    for (int i = 0; i < 3; i += 1) {
        const int aCaseValue = Sudoku_get(iSudoku, (aIndexSquareLine * 3 + 1) * SUDOKU_LINE_SIZE, aIndexSquareColumn * 3 + i);
        SudokuSetChecker_increment(&aSudokuSetChecker, aCaseValue);
    }
    for (int i = 0; i < 3; i += 1) {
        const int aCaseValue = Sudoku_get(iSudoku, (aIndexSquareLine * 3 + 2) * SUDOKU_LINE_SIZE, aIndexSquareColumn * 3 + i);
        SudokuSetChecker_increment(&aSudokuSetChecker, aCaseValue);
    }

    return SudokuSetChecker_check(&aSudokuSetChecker);
}


void Sudoku_print(Sudoku sudoku);

void read (struct Sudoku sudoku , int ligne , int colonne);
void set (struct Sudoku sudoku, int valeur , int ligne , int colonne);
void initSudokuLigne (struct Sudoku sudoku, struct TabTemp tabTemp, int ligne);
void initSudokuColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne);
void AjouteUnCaseSudoku (struct Sudoku sudoku, int index);



#endif // SUDOKU_H_INCLUDED
