#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "main.h"


int main(){
    struct Sudoku sudoku ; int i = 0; sudoku.ligne = 9 ; sudoku.colonne = 9 ; sudoku.tab = malloc(sudoku.ligne*sudoku.colonne*sizeof(int)) ;
    if (sudoku.tab == 0){
        exit(0);
    }
    for (i=1;i<=sudoku.ligne;i++){
        initSudokuLigne(sudoku,i);
    }
    affiche(sudoku);

    Solve (sudoku);

    affiche (sudoku);
}



void read (struct Sudoku sudoku , int ligne , int colonne){
    printf ("%d" ,sudoku.tab[sudoku.colonne*(ligne-1) + colonne]);
}

void set (struct Sudoku sudoku, int valeur , int ligne , int colonne){
    sudoku.tab[9*(ligne-1) + colonne-1] = valeur ;
}

void initSudokuLigne (struct Sudoku sudoku , int ligne){
    char ligneTemp[10];int i = 0;
    printf ("Donner la %d-eme ligne du sudoku  ", ligne);
    scanf ("%s",ligneTemp);
    for (i=0;i<sudoku.colonne ;i++){
        sudoku.tab[(ligne-1)*sudoku.colonne + i] = ligneTemp[i]-48; // mais pourquoi pour passer du caractère 1 aux nombre 1 il faut mettre un -48 ???
    }
}

void initSudokuColonne (struct Sudoku sudoku , int colonne){
    char ligneTemp[sudoku.ligne + 1];int i = 0;
    printf ("Donner la %d -eme colonne du sudoku", colonne + 1);
    scanf ("%s",ligneTemp);
    for (i=0;i<sudoku.ligne ;i++){
        sudoku.tab[colonne-1 + i*9]= ligneTemp[i] - 48;
    }
}

void affiche (struct Sudoku sudoku){
    int i,j = 0;
    for (i = 0 ; i < sudoku.ligne;i++){
        for (j = 0 ; j < sudoku.colonne ; j ++){
            printf ("%d ", sudoku.tab[i*sudoku.colonne + j]);
            if(j == (sudoku.colonne-1)){
                printf("\n");
            }
        }
    }

}

int VerificationLigne (struct Sudoku sudoku, int ligne){
    char tabTemp[10]; int i = 0;
    for (i=0; i < sudoku.colonne ; i ++){
        tabTemp[sudoku.tab[(ligne-1)*sudoku.colonne + i]] = 1 ;
    }
    if ( strcmp(tabTemp, "111111111") == 0 ){
        return 1 ;
    }
    else{return 0;}
}

int VerificationAllLigne (struct Sudoku sudoku){
    int a = 1 ; int i = 0 ;
    for (i=1; i < sudoku.ligne + 1 ; i++ ){
        a *= VerificationLigne (sudoku, i);
    }
    return a ;
}

int VerificationColonne (struct Sudoku sudoku, int colonne){
    char tabTemp[sudoku.colonne + 1]; int i =0;
    for (i=0; i < sudoku.ligne ; i ++){
        tabTemp[sudoku.tab[colonne-1 + i*sudoku.ligne]] = 1;
    }
    if ( strcmp (tabTemp, "111111111")==0){
        return 1 ;
    }
    else{return 0;}
}

int VerificationAllColonne (struct Sudoku sudoku){
    int a = 1 ; int i = 0 ;
    for (i=1; i < sudoku.colonne + 1 ; i++ ){
        a *= VerificationColonne (sudoku, i);
    }
    return a ;
}

int VerificationCarre (struct Sudoku sudoku, int numero){
    char tabTemp[10] ; int i = 0 ; int indiceDepart = ((numero-1)/(sudoku.ligne/3))*(sudoku.colonne*3) + (numero%(sudoku.ligne/3))*(sudoku.ligne/3);
    for (i = 0 ; i < sudoku.ligne ; i++){
        tabTemp[sudoku.tab[indiceDepart + i + (i/(sudoku.ligne/3))*sudoku.ligne]] = 1 ;
    }
    if ( strcmp (tabTemp, "111111111")==0){
        return 1 ;
    }
    else{return 0;}
}

int VerificationAllCarre (struct Sudoku sudoku){
    int i=0 ; int j=1;
    for (i=0;i<sudoku.ligne/3;i++){
        j *= VerificationCarre(sudoku,i);
    }
        return j;
}

void EmpilerPileZero (struct PileZero *pile, int nouvellePlace){
    struct PlaceZero *nouveau = malloc(sizeof(struct PlaceZero));
    nouveau->precedent = pile->actuel;
    nouveau->place = nouvellePlace ;
    nouveau->suivant = NULL ;
    pile->actuel = nouveau;
}

void ajouter (struct Sudoku sudoku ,struct PileZero *pile){
    sudoku.tab[pile->actuel->place] ++ ;
    if (sudoku.tab[pile->actuel->place] == (sudoku.ligne + 1)){
        sudoku.tab[pile->actuel->place] = 1;
        pile->actuel = pile->actuel->precedent ;
        ajouter (sudoku, pile);
    }
    return ;
}

void retour (struct PileZero *pile){
    if (pile->actuel->suivant != NULL){
        pile->actuel = pile->actuel->suivant;
        retour (pile);
    }
    return ;
}

void Solve (struct Sudoku sudoku){
    int i = 0, j=0 ;
    struct PileZero *pile ; pile = NULL ; pile->actuel = NULL ;
    for (i=0 ; i<sudoku.ligne ; i++){
        for (j=0;j<sudoku.colonne;j++){
            if (sudoku.tab[i*sudoku.colonne+j] == 0){
                EmpilerPileZero (pile,i*sudoku.colonne+j);
            }
        }
    }// on créer la liste des zeros

    int k = 1;
    do{
        k=1;
        ajouter (sudoku,pile);
        retour (pile);
        k = VerificationAllCarre (sudoku)* VerificationAllLigne(sudoku) * VerificationAllColonne(sudoku);
    }while (k != 1);
}

