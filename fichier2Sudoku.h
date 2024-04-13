#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include "buffer.h"

#define SUDOKU_SIZE 81
#define SUDOKU_LINE_SIZE 9
#define SUDOKU_CHECK_POSSIBILITIES 9
#define boolean_true 1
#define boolean_false 0

typedef struct strSudoku{
    int *tab;
    int *tabIndexZero;
    int tabIndexZeroSize;
} Sudoku;

void Sudoku_Affiche(Sudoku* sudoku);
int Sudoku_Check(Sudoku* iSudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, const int iLigne);
int Sudoku_CheckColumn(Sudoku* sudoku,SudokuSetChecker* sudokuSetChecker, const int iColumn);
int Sudoku_CheckSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, int position);
int Sudoku_CheckAllLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckAllColumn (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckAllSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);
void SetTabIndiceZero (Sudoku *sudoku);

inline void Sudoku_reset(Sudoku* iSudoku) { memset(iSudoku, 0, sizeof(struct strSudoku)); }
inline void Sudoku_init (Sudoku* iSudoku) { Sudoku_reset(iSudoku); }

inline int  Sudoku_index(const int iLine, const int iColumn) { return iLine * SUDOKU_LINE_SIZE + iColumn; }

inline void Sudoku_set(Sudoku* iSudoku, const int iLine, const int iColumn, const char iValue) { iSudoku->tab[Sudoku_index(iLine, iColumn)] = iValue; }
inline int  Sudoku_get(Sudoku* iSudoku, const int iLine, const int iColumn                   ) { return iSudoku->tab[Sudoku_index(iLine, iColumn)]; }

void Sudoku_Affiche(Sudoku* sudoku){
    for (int i =0; i < SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE ; i++ ){
        for (int j =0; j < SUDOKU_LINE_SIZE*SUDOKU_LINE_SIZE ; j++ ){
            printf("%d ",sudoku->tab[i*SUDOKU_LINE_SIZE + j]);
        }
        printf("\n");
    }
}


int Sudoku_Check(Sudoku* iSudoku, SudokuSetChecker* sudokuSetChecker) {
    for(int i = 1; i<SUDOKU_LINE_SIZE; i++){
        bool aTmp = Sudoku_CheckAllLigne(iSudoku,sudokuSetChecker);
        aTmp &= Sudoku_CheckAllColumn(iSudoku,sudokuSetChecker);
        aTmp &= Sudoku_CheckAllSquare(iSudoku,sudokuSetChecker);
        return aTmp ;
}

int Sudoku_CheckLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, const int iLigne){
    SudokuSetChecker_reset(sudokuSetChecker);
    for (int i=0; i < SUDOKU_LINE_SIZE ; i ++){
        sudokuSetChecker->set[sudoku->tab[(iLigne-1)*SUDOKU_LINE_SIZE + i]] = '1';
    }
    sudokuSetChecker->set[SUDOKU_LINE_SIZE] = '\0';

    return SudokuSetChecker_check(sudokuSetChecker);

}

int Sudoku_CheckAllLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=1; i < SUDOKU_LINE_SIZE + 1 ; i++ ){
        if (Sudoku_CheckLigne(sudoku,sudokuSetChecker,i) != 1){
            return 0;
        }
    }
    return 1 ;
}

int Sudoku_CheckColumn(Sudoku* sudoku,SudokuSetChecker* sudokuSetChecker, const int iColumn) {
    SudokuSetChecker_reset(sudokuSetChecker);
    for (int i=0; i < SUDOKU_LINE_SIZE ; i ++){
        sudokuSetChecker->set[sudoku->tab[iColumn-1 + i*SUDOKU_LINE_SIZE]] = '1';
    }
    sudokuSetChecker->set[SUDOKU_LINE_SIZE]='\0';

    return SudokuSetChecker_check(sudokuSetChecker);

}

int Sudoku_CheckAllColumn (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=1; i < SUDOKU_LINE_SIZE + 1 ; i++ ){
        if (Sudoku_CheckColumn(sudoku,sudokuSetChecker,i) != 1){
            return 0;
        }
    }
    return 1 ;
}

int Sudoku_CheckSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, int position){
    SudokuSetChecker_reset(sudokuSetChecker);
    int indiceDepart = ((position-1)/(SUDOKU_LINE_SIZE/3))*(SUDOKU_LINE_SIZE*3) + (position%(SUDOKU_LINE_SIZE/3))*(SUDOKU_LINE_SIZE/3);
    for (int i = 0 ; i < SUDOKU_LINE_SIZE; i++){
        sudokuSetChecker->set[sudoku->tab[indiceDepart + i + (i/(SUDOKU_LINE_SIZE/3))*SUDOKU_LINE_SIZE]] = '1' ;
    }
    sudokuSetChecker->set[SUDOKU_LINE_SIZE]='\0';

    return SudokuSetChecker_check(sudokuSetChecker);

}

int Sudoku_CheckAllSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=0;i<SUDOKU_LINE_SIZE/3;i++){
        if (Sudoku_CheckSquare(sudoku , sudokuSetChecker ,i*3 + i/3 * SUDOKU_LINE_SIZE * sqrt(SUDOKU_LINE_SIZE)) != 1){
            return 0;
        }
    }
    return 1;
}

void SetTabIndiceZero (Sudoku *sudoku){
    int k = 0 ;
    for (int i=0;i<SUDOKU_LINE_SIZE;i++){
        for(int j=0;j<SUDOKU_LINE_SIZE;j++){
            if (sudoku->tab[i*SUDOKU_LINE_SIZE + j] == 0){
                sudoku->tabIndexZero[k] = i*SUDOKU_LINE_SIZE + j ;
                k++ ;
            }
        }
    }
    sudoku->tabIndexZeroSize = k ;
}
/* inline bool Sudoku_Solver(Sudoku* iSudoku, const int indexTab) {

    if (indexTab >= iSudoku->tabIndexZeroSize) {
        return Sudoku_check(iSudoku);
    }

    bool stopLoop = boolean_false;
    for (int i = 0; !stopLoop && i < SUDOKU_CHECK_POSSIBILITIES; i += 1) {
        iSudoku->tab[iSudoku->tabIndexZero[indexTab]] = i;
        stopLoop = Sudoku_Solver(iSudoku, indexTab + 1);
    }
    return stopLoop;
}*/

/* inline void Sudoku_Solver(Sudoku* iSudoku) {
    if (iSudoku->tabIndexZeroSize) {
        Sudoku_Solver(iSudoku, 0);
    }
    else {
        printf("Sudoku already solved");
    }
    return;
}*/
#endif // SUDOKU_H_INCLUDED
