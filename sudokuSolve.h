#ifndef SUDOKUSOLVE_H_INCLUDED
#define SUDOKUSOLVE_H_INCLUDED
#include "buffer.h"
#include "sudoku.h"

int VerificationLigne (struct Sudoku sudoku, struct TabTemp tabTemp , int ligne);
int VerificationAllLigne (struct Sudoku sudoku,struct TabTemp tabTemp );
int VerificationColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne);
int VerificationAllColonne (struct Sudoku sudoku,struct TabTemp tabTemp);
int VerificationCarre (struct Sudoku sudoku,struct TabTemp tabTemp, int numero);
int VerificationAllCarre (struct Sudoku sudoku, struct TabTemp tabTemp);
void Solve (struct Sudoku sudoku, struct TabTemp tabTemp );
void SetTabIndiceZero (struct Sudoku sudoku);

int VerificationLigne (struct Sudoku sudoku, struct TabTemp tabTemp , int ligne){
    int i = 0;
    for (i=0; i < sudoku.colonne ; i ++){
        tabTemp.tabTemp[sudoku.tab[(ligne-1)*sudoku.colonne + i]] = '1';
    }
    tabTemp.tabTemp[sudoku.ligne] = '\0';
    if ( strcmp(tabTemp.tabTemp, '111111111') == 0 ){
        return 1 ;
    }
    else{
    return 0;
    }
}

int VerificationAllLigne (struct Sudoku sudoku,struct TabTemp tabTemp ){
    int a = 1 ; int i = 0 ;
    for (i=1; i < sudoku.ligne + 1 ; i++ ){
        a *= VerificationLigne (sudoku, tabTemp ,i);
    }
    return a ;
}

int VerificationColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne){
    int i =0;
    for (i=0; i < sudoku.ligne ; i ++){
        tabTemp.tabTemp[sudoku.tab[colonne-1 + i*sudoku.ligne]] = '1';
    }
    tabTemp.tabTemp[sudoku.ligne]='\0';
    if ( strcmp (tabTemp.tabTemp, "111111111")==0){
        return 1 ;
    }
    else{
    return 0;
    }
}

int VerificationAllColonne (struct Sudoku sudoku, struct TabTemp tabTemp){
    int a = 1 ; int i = 0 ;
    for (i=1; i < sudoku.colonne + 1 ; i++ ){
        a *= VerificationColonne (sudoku, tabTemp, i);
    }
    return a ;
}

int VerificationCarre (struct Sudoku sudoku,struct TabTemp tabTemp, int numero){
    int i = 0 ;
    int indiceDepart = ((numero-1)/(sudoku.ligne/3))*(sudoku.colonne*3) + (numero%(sudoku.ligne/3))*(sudoku.ligne/3);
    for (i = 0 ; i < sudoku.ligne ; i++){
        tabTemp.tabTemp[sudoku.tab[indiceDepart + i + (i/(sudoku.ligne/3))*sudoku.ligne]] = '1' ;
    }
    tabTemp.tabTemp[sudoku.ligne]='\0';
    if ( strcmp (tabTemp.tabTemp, "111111111")==0){
        return 1 ;
    }
    else{
    return 0;
    }
}

int VerificationAllCarre (struct Sudoku sudoku, struct TabTemp tabTemp){
    int i=0 ; int j=1;
    for (i=0;i<sudoku.ligne/3;i++){
        j *= VerificationCarre(sudoku, tabTemp, i);
    }
        return j;
}

void SetTabIndiceZero (struct Sudoku sudoku){
    int i,j = 0 ; int k = 0 ;
    for (i=0;i<sudoku.ligne;i++){
        for(j=0;j<sudoku.colonne;j++){
            if (sudoku.tab[i*sudoku.colonne + j] == 0){
                sudoku.tabIndexZero[k] = i*sudoku.colonne + j ;
                k++ ;
            }
        }
    }
    sudoku.tabIndexZero[k] = -1 ;
}

void Solve (struct Sudoku sudoku, struct TabTemp tabTemp){
    int k = 1;
    do{
    k=1;
        AjouteUnCaseSudoku (sudoku, sudoku.tabIndexZero[0]) ;
        k = VerificationAllCarre (sudoku, tabTemp)* VerificationAllLigne(sudoku,tabTemp) * VerificationAllColonne(sudoku,tabTemp);
    }while (k != 1);
}

#endif // SUDOKUSOLVE_H_INCLUDED
