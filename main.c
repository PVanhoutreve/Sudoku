#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main(){
    int i=0 ,j=0 ,k =0;
    int sudoku[81]={4,9,1,6,7,5,2,3,8,
                    2,7,3,9,8,1,4,5,6,
                    8,5,0,4,3,2,9,1,7,
                    7,1,2,0,5,6,3,4,9,
                    5,6,4,7,0,3,1,8,2,
                    9,3,8,1,2,0,6,7,5,
                    1,4,5,2,6,7,0,9,3,
                    6,8,7,3,4,9,5,0,1,
                    3,2,9,5,1,8,7,6,4};
    affiche (sudoku) ;

    printf ("voici la solution :\n");

    for (i=0; i<81 ; i ++){
        if (sudoku[i] == 0){
            j++ ;
        }
    }
    int **tab = NULL ;
    tab = malloc(sizeof (int *) * j);
    for (i=0; i<81 ; i ++){
        if ( sudoku[i] == 0){
            *(tab + k) = &(sudoku[i]) ;
            k ++ ;
        }
    }
    Solvetableau (sudoku, tab , j);

    affiche (sudoku);
    return 0;
}

void affiche (int tableau[81]){
    int i,j;
    for (i = 0 ; i< 9 ; i ++){
       for (j=0 ; j < 9 ; j++){
            if ( j == 8 ){
                printf(" %d \n", tableau[i*9+j] );
            }
            else{
                printf(" %d ", tableau[i*9+j] );
            }

       }

    }
}

int TestLigne (int *Case, int tableau[81]){
    int j,i = 0, NbATrouver = 1 , comptage = 0 ;
        for (i=0; i< 9 ; i++){
            for (j= (Case-tableau)  - (Case - tableau)%9  ; j < (Case-tableau)  - (Case - tableau)%9 + 9 ; j++){
                if (tableau[j] == NbATrouver){
                comptage ++ ; NbATrouver ++ ;
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else{
            return 0 ;
        }
}

int TestColonne (int *Case, int tableau[81]){
    int j,i = 0, NbATrouver = 1 , comptage = 0 ;
        for (i=0; i< 9 ; i++){
            for (j= (Case-tableau)%9 ; j < 81 ; j = j + 9){
                if (tableau[j] == NbATrouver){
                    comptage ++ ; NbATrouver ++ ;
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
}

int TestCarre (int *place , int tableau[81]){
    int i,j,k = 0; int NbATrouver = 1 , comptage = 0;
    if ( (((place-tableau) % 9) < 3) && (((place-tableau) - (place-tableau)%9) < 19 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=0 ; j<3 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    } // 1er carré
    if ( (((place-tableau) % 9) >= 3) && (((place-tableau) % 9) < 6 ) && (((place-tableau) - (place-tableau)%9) < 19 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=3 ; j<6 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    } // 2eme carre
    if ( (((place-tableau) % 9) >= 6) && ((place-tableau) - (place-tableau)%9 < 19 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=6 ; j<9 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }//3eme carre
    if ( (((place-tableau) % 9) < 3) && (((place-tableau) - (place-tableau)%9) >= 19 ) && (((place-tableau) - (place-tableau)%9) < 46 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=27 ; j<30 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 4eme carre
    if ( (((place-tableau) % 9) >= 3) && (((place-tableau) % 9) < 6 ) && (((place-tableau) - (place-tableau)%9) >= 19 ) && (((place-tableau) - (place-tableau)%9) < 46 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=30 ; j<33 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 5eme carre
    if ( (((place-tableau) % 9) >= 6) && (((place-tableau) - (place-tableau)%9) >= 19 ) && (((place-tableau) - (place-tableau)%9) < 46 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=33 ; j<36 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 6eme
    if ( (((place-tableau) % 9) < 3) && (((place-tableau) - (place-tableau)%9) >= 46 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=54 ; j<57 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 7eme carre
    if ( (((place-tableau) % 9) >= 3) && (((place-tableau) % 9) < 6)  && (((place-tableau) - (place-tableau)%9) >= 46 )){
        for (k=0 ; k < 9 ; k++ ){
            for (j=57 ; j<60 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 8eme
    else{
        for (k=0 ; k < 9 ; k++ ){
            for (j=60 ; j<63 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }// 9eme
}

void Solvetableau (int tableau[81], int **tab, int j){
    int i = 0 ,l=0 ; int k=0 ; int n =0 ;
    do{
        if( (TestLigne(*(tab + k) , tableau))*(TestColonne(*(tab + k) , tableau))*( TestCare(*(tab + k) , tableau))==1 ){
            k ++ ;
        }
        else if ( (TestLigne(*(tab + k) , tableau))*(TestColonne(*(tab + k) , tableau))*(TestCare(*(tab + k) , tableau))!=1 && **(tab + k) != 9){
            **(tab+k) = **(tab + k) + 1;
        }
        else if ( (TestLigne( *(tab + k) , tableau))*(TestColonne(*(tab + k) , tableau))*(TestCare(*(tab + k) , tableau))!=1 && **(tab + k) == 9 ){
           if ( **(tab+k) == 9 && **(tab + k + 1) != 9 ){
                **(tab + k + 1) = **(tab + k + 1) + 1 ;
                **(tab + k )= 1;
           }
           else if (**(tab+k) == 9 && **(tab + k + 1) == 9){
                for (i=0 ; i < j - 2 ; i ++){
                    if ( (**(tab + i) == 9) && (**(tab + i + 1) == 9) && (**(tab + i + 2) != 9 ) ){
                        **(tab + i + 2) = **(tab + i + 2) +1 ;
                        for (l = 0 ; l < i+2 ; l ++){
                            **(tab + l)=1 ;
                        }
                        k = 0;
                    }
                }
           }
        }
        else {}
        n=1;
        for (i = 0; i<j;i++){
            n *= TestLigne (*(tab+i),tableau);
            n *= TestColonne (*(tab +i),tableau);
            n *= TestCare(*(tab+i),tableau);
        }
    }while ( n != 1 );
}

int TestCare (int *Place, int tableau[81]){
    int i,j,k = 0; int NbATrouver = 1 , comptage = 0;
        for (k=0 ; k < 9 ; k++ ){
            for (j= (*Place - *Place%3)-(((*Place - *Place%3)%27-((*Place - *Place%3)%27)%9)%8)*9 ; j < (*Place - *Place%3)-(((*Place - *Place%3)%27-((*Place - *Place%3)%27)%9)%8)*9 +3 ; j ++){
                for (i=0; i < 3 ; i++){
                    if (tableau[j + i * 9] == NbATrouver){
                        comptage ++ ; NbATrouver ++;
                    }
                }
            }
        }
        if (comptage == 9){
            return 1 ;
        }
        else {
            return 0 ;
        }
}

