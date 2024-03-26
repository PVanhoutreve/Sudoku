#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED


#define boolean char
#define boolean_true 1
#define boolean_false 0

#define SUDOKU_SET_CHECKER_SIZE 10

typedef struct strSudokuSetChecker{
    char set[SUDOKU_SET_CHECKER_SIZE];
} SudokuSetChecker;

inline void SudokuSetChecker_reset(SudokuSetChecker* iSudokuSetChecker) {
    memset(iSudokuSetChecker, 0, sizeof(struct strSudokuSetChecker));
}

inline void SudokuSetChecker_init(SudokuSetChecker* iSudokuSetChecker) {
    SudokuSetChecker_reset(iSudokuSetChecker);
}

inline void SudokuSetChecker_set(SudokuSetChecker* iSudokuSetChecker, const int iPosition, const char iValue){
    iSudokuSetChecker->set[iPosition] = iValue;
}

inline void SudokuSetChecker_increment(SudokuSetChecker* iSudokuSetChecker, const int iPosition) {
    iSudokuSetChecker->set[iPosition] += 1;
}

inline int SudokuSetChecker_get(SudokuSetChecker* iSudokuSetChecker, const int iPosition) {
    return iSudokuSetChecker->set[iPosition];
}


inline boolean SudokuSetChecker_check(SudokuSetChecker* iSudokuSetChecker) {
    for (int i = 1; i < SUDOKU_SET_CHECKER_SIZE; i += 1) {
        if (SudokuSetChecker_get(iSudokuSetChecker, i) != 1) {
            return boolean_false;
        }
    }
    return boolean_true;
}


/*
inline void setBufferColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne){
    int i=0;
    for (i=0; i<sudoku.ligne; i++){
        tabTemp.tabTemp[i] = sudoku.tab[colonne-1 + i*sudoku.colonne] + '0';
    }
}

inline void setBufferCarre (struct Sudoku sudoku, struct TabTemp tabTemp, int Carre){
    int i,j = 0 ;
    int racine = sqrt(sudoku.ligne);
    for (i=0; i < racine ; i++){
        for (j=0 ; j < racine ; j ++){
            tabTemp.tabTemp[i*racine+ j] = sudoku.tab[ (Carre/3) * sudoku.colonne * racine + i*sudoku.colonne + j] + '0';
        }
    }
}
*/
#endif // BUFFER_H_INCLUDED
