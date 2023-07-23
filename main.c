//
//  main.c
//  Sudoku
//
//  Created by Thomas Guibert on 11/12/2021.
//
// 
#include <stdio.h>
/*
 5 0 5 0 0 3 8 0 0
 2 0 0 0 0 0 0 6 0
 0 1 0 0 0 0 0 0 2
 0 0 0 4 0 0 0 0 0
 8 0 0 0 0 0 1 9 0
 0 0 0 9 0 0 0 0 8
 0 0 4 0 0 8 0 0 3
 0 0 0 7 0 6 0 5 0
 7 0 0 0 0 0 0 0 0

 
 
 */

int solveSudoku(int,int);
void scanSudoku(void);
void printSudoku(void);
int sameColum(int,int,int);
int sameSquare(int,int,int);
int sameRow(int,int,int);


int sudoku[9][9]={0};
// le programme principale qui appelle les sous fonctions
int main(){
    int x = 0;
    int y = 0;
    scanSudoku();
    printSudoku();
    solveSudoku(x,y);
    printSudoku();
    return 0;
    
}
// permet à l'utilisateur de remplir les emplacements prédefinis
void scanSudoku(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf(" Saisir le chiffre de la ligne %d",i+1);
            printf(" et de la colonne %d", j+1);
            printf(" : \n");
            scanf("%d",&sudoku[i][j]);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    printf(" %d", sudoku[i][j]);
                    
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}

// permet d'afficher la grille de sudoku
void printSudoku() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf(" %d", sudoku[i][j]);
            
        }
        printf("\n");
    }
    printf("\n\n");
}
// permet de résoudre le sudoku
int solveSudoku(int  x, int y){
    int num = 1;
    int tx = 0;
    int ty = 0;
    // verifie si la case est deja remplie
    // si oui il passe a la case d'apres
    if(sudoku[x][y] != 0){
        if( x== 8 && y == 8){
            return 1;
        }
        if ( x < 8){
            x++;
        } else {
            x = 0;
            y++;
        }
        
        if(solveSudoku(x, y)){
            return 1;
        } else{
            return 0;
        }
        
    }
    // si la case est vide ( est remplie par un 0)
    // il va essayer un chiffre qui est ni dans la meme ligne / colonne / oui grille de 3*3
    if(sudoku[x][y] == 0){
        while ( num < 10){
            if( !sameSquare(x, y , num) && !sameColum(x, y , num) && !sameRow(x, y , num)){
                sudoku[x][y] = num;
                if ( x == 8 && y ==8){
                    return 1;
                }
                if ( x < 8){
                    tx= x+1;
                } else {
                    tx = 0;
                    ty=y+1;
                }
                
                if(solveSudoku(tx,ty)){
                    return 1;
                }
                
            }
            num++;
        }
        if(x== 0 && y == 0){
            printf("\n\n Pas de solution pour la grille :\n\n");
        }
        sudoku[x][y] = 0;
        return 0;
    }
    return 0;
}
// sous fonction qui verifie si le chiffre que l'on veut tester est dans la meme colonne
int sameColum(int x , int y , int num){
    for(int i = 0; i<8; i++){
        if(sudoku[x][i] == num){
            return 1;
            
        }
    }
    return 0;
}
// sous fonction qui verifie si le chiffre que l'on veut tester est dans la meme ligne
int sameRow(int x , int y , int num){
    for(int i = 0; i<9; i++){
        if(sudoku[i][y] == num){
            return 1;
            
        }
    }
    return 0;
}
// sous fonction qui verifie si le chiffre que l'on veut tester est dans la meme grille de 3*3
int sameSquare(int x , int y , int num){
    if(x < 3){
        x = 0;
    } else if (x < 6){
        x= 3;
    } else {
        x = 6;
    }
    
    if(y < 3){
        y = 0;
    } else if (y < 6){
        y = 3;
    } else {
        y = 6;
    }
    
    for(int i = x; i< x+3; i++){
        for(int j = y; j < y+3; j++){
            if (sudoku[i][j] == num){
                return 1;
                        
            }
        }
        
    }
    return 0;
}
