#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#define boolean char
#define boolean_true 1
#define boolean_false 0

#define SUDOKU_SET_CHECKER_SIZE 10

typedef struct strSudokuSetChecker{
    char* set;
} SudokuSetChecker;

inline void SudokuSetChecker_reset(SudokuSetChecker* iSudokuSetChecker);
inline void SudokuSetChecker_set(SudokuSetChecker* iSudokuSetChecker, const int iPosition, const char iValue);
inline int SudokuSetChecker_get(SudokuSetChecker* iSudokuSetChecker, const int iPosition);
inline bool SudokuSetChecker_check(SudokuSetChecker* iSudokuSetChecker);



inline void SudokuSetChecker_reset(SudokuSetChecker* iSudokuSetChecker){
    memset(iSudokuSetChecker, 0, sizeof(struct strSudokuSetChecker));
}

inline void SudokuSetChecker_set(SudokuSetChecker* iSudokuSetChecker, const int iPosition, const char iValue){
    iSudokuSetChecker->set[iPosition] = iValue;
}

inline int SudokuSetChecker_get(SudokuSetChecker* iSudokuSetChecker, const int iPosition) {
    return iSudokuSetChecker->set[iPosition];
}


inline bool SudokuSetChecker_check(SudokuSetChecker* iSudokuSetChecker) {
    for (int i =0 ; i<SUDOKU_SET_CHECKER_SIZE ; i++){
        if (iSudokuSetChecker->set[i] != '1'){
            return 0;
        }
    }
    return boolean_true;
}

#endif // BUFFER_H_INCLUDED
