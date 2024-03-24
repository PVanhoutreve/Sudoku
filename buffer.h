#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include "sudoku.h"
struct TabTemp{
    char *tabTemp ;
};

void setBufferLigne (struct Sudoku sudoku, struct TabTemp tabTemp, int ligne){
    int i=0;
    for (i=0; i<sudoku.colonne; i++){
        tabTemp.tabTemp[i] = sudoku.tab[ligne*sudoku.colonne + i] + '0';
    }
}

void setBufferColonne (struct Sudoku sudoku, struct TabTemp tabTemp, int colonne){
    int i=0;
    for (i=0; i<sudoku.ligne; i++){
        tabTemp.tabTemp[i] = sudoku.tab[colonne-1 + i*sudoku.colonne] + '0';
    }
}

void setBufferCarre (struct Sudoku sudoku, struct TabTemp tabTemp, int Carre){
    int i,j = 0 ;
    int racine = sqrt(sudoku.ligne);
    for (i=0; i < racine ; i++){
        for (j=0 ; j < racine ; j ++){
            tabTemp.tabTemp[i*racine+ j] = sudoku.tab[ (Carre/3) * sudoku.colonne * racine + i*sudoku.colonne + j] + '0';
        }
    }
}
#endif // BUFFER_H_INCLUDED
