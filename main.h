#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
struct Sudoku{
    int ligne ;
    int colonne ;
    int *tab;
};
struct PlaceZero{
    struct PlaceZero *precedent;
    int place ;
    struct PlaceZero *suivant ;
};
struct PileZero {
    struct PlaceZero *actuel ;
};
int racineCarre (int nombre);
void read (struct Sudoku sudoku , int ligne , int colonne);
void set (struct Sudoku sudoku, int valeur , int ligne , int colonne);
void initSudokuLigne (struct Sudoku sudoku , int ligne);
void initSudokuColonne (struct Sudoku sudoku , int colonne);
void affiche (struct Sudoku sudoku);
int VerificationLigne (struct Sudoku sudoku, int ligne);
int VerificationAllLigne (struct Sudoku sudoku);
int VerificationColonne (struct Sudoku sudoku, int colonne);
void EmpilerPileZero (struct PileZero *pile, int nouvellePlace);
void ajouter (struct Sudoku sudoku ,struct PileZero *pile);
void retour (struct PileZero *pile);
void Solve (struct Sudoku sudoku);
#endif // MAIN_H_INCLUDED
