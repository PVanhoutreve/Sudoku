#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#define SUDOKU_SIZE 81
#define SUDOKU_LINE_SIZE 9
#define SUDOKU_CHECK_POSSIBILITIES 9
#define boolean_true 1
#define boolean_false 0

typedef struct strSudoku{
    int *tab;
} Sudoku;

void Sudoku_Affiche(Sudoku* sudoku);
int Sudoku_Check(Sudoku* iSudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, const int iLigne);
int Sudoku_CheckColumn(Sudoku* sudoku,SudokuSetChecker* sudokuSetChecker, const int iColumn);
int Sudoku_CheckSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, int position);
int Sudoku_CheckAllLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckAllColumn (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);
int Sudoku_CheckAllSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker);


void Sudoku_Affiche(Sudoku* sudoku){
    for (int i =0; i < SUDOKU_SIZE ; i++ ){
        for (int j =0; j < SUDOKU_SIZE ; j++ ){
            printf("%d ",sudoku->tab[i*SUDOKU_LINE_SIZE + j]);
        }
        printf("\n");
    }
}


bool Sudoku_Check(Sudoku* iSudoku, SudokuSetChecker* sudokuSetChecker) {
    for(int i = 1; i<SUDOKU_LINE_SIZE; i++){
        bool aTmp = Sudoku_CheckAllLigne(iSudoku,sudokuSetChecker);
        if (aTmp == 0){ return 0;}
        aTmp &= Sudoku_CheckAllColumn(iSudoku,sudokuSetChecker);
        if (aTmp == 0){ return 0;}
        aTmp &= Sudoku_CheckAllSquare(iSudoku,sudokuSetChecker);
        if (aTmp == 0){ return 0;}
        return 1 ;
}

bool Sudoku_CheckLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, int iLigne){
    SudokuSetChecker={0} ; // réinitialise un tableau allouer avec malloc à 0 ?

    for (int i=0; i < SUDOKU_LINE_SIZE ; i ++){
        sudokuSetChecker[sudoku->tab[(iLigne-1)*SUDOKU_LINE_SIZE + i]]= 1;
    }

    for(i=0;i<SuDOKU_LINE_SIZE ; i ++){
        if (sudokuSetChecker[i]==0){
            return 0;
        }
    }

    return 1;

}

bool Sudoku_CheckAllLigne (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=1; i < SUDOKU_LINE_SIZE + 1 ; i++ ){
        if (Sudoku_CheckLigne(sudoku,sudokuSetChecker,i) == 0){
            return 0;
        }
    }
    return 1 ;
}

bool Sudoku_CheckColumn(Sudoku* sudoku,SudokuSetChecker* sudokuSetChecker, const int iColumn) {
     SudokuSetChecker={0} ; // réinitialise un tableau allouer avec malloc à 0 ?

    for (int i=0; i < SUDOKU_LINE_SIZE ; i ++){
        sudokuSetChecker[sudoku->tab[iColumn-1 + i*SUDOKU_LINE_SIZE]] = 1 ;
    }
    for(i=0;i<SuDOKU_LINE_SIZE ; i ++){
        if (sudokuSetChecker[i]==0){
            return 0;
        }
    }
    return 1;
}

bool Sudoku_CheckAllColumn (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=1; i < SUDOKU_LINE_SIZE + 1 ; i++ ){
        if (Sudoku_CheckColumn(sudoku,sudokuSetChecker,i) == 0){
            return 0;
        }
    }
    return 1 ;
}

bool Sudoku_CheckSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker, int position){
    SudokuSetChecker={0} ; // réinitialise un tableau allouer avec malloc à 0 ?

    int indiceDepart = ((position-1)%3 *(SUDOKU_LINE_SIZE/3) + ((position-1)/3) *(SUDOKU_LINE_SIZE*3);

    for (int i = 0 ; i < SUDOKU_LINE_SIZE; i++){
        sudokuSetChecker[sudoku->tab[indiceDepart + i%3 + (i/3)*SUDOKU_LINE_SIZE]] = 1 ;
    }

    for(i=0;i<SuDOKU_LINE_SIZE ; i ++){
        if (sudokuSetChecker[i]==0){
            return 0;
        }
    }
    return 1;

}

bool Sudoku_CheckAllSquare (Sudoku* sudoku, SudokuSetChecker* sudokuSetChecker){
    for (int i=0;i<SUDOKU_LINE_SIZE;i++){
        if (Sudoku_CheckSquare(sudoku , sudokuSetChecker ,i+1)) == 0){
            return 0;
        }
    }
    return 1;
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
