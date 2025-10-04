#include<stdio.h>
#define SIZE 3
int isLowerTriangular(int mat[SIZE][SIZE], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i < j && mat[i][j] != 0){
                return 0; // Not a lower triangular matrix
            }

        }
    }
    return 1; // Is a lower triangular matrix

}
int isDiagonalmatrix(int mat[SIZE][SIZE], int n){
     int i,j;
     for(i = 0; i < n ; i++){
        for(j = 0; j < n; j++){
            if(i != j && mat[i][j] != 0){
                return 0; // Not a diagonal matrix
            }

        }
     }
     return 1;// Is a diagonal matrix
}
 
int main(){

    int mat[SIZE][SIZE];
    int i, j;
    printf("Enter elements for a %dx%d matrix:\n", SIZE, SIZE);
    for(i =0; i< SIZE; i++){
        for(j = 0 ; j < SIZE; j++){
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);

        }
    }
    printf("\nThe input matrix is:\n");
    for(i =0; i< SIZE; i++){
        for(j = 0 ; j < SIZE; j++){
            printf("%d ", mat[i][j]);

        }
        printf("\n");
    }
    if(isLowerTriangular(mat, SIZE)){
        printf("The matrix is a lower triangular matrix.\n");
    } else {
        printf("The matrix is not a lower triangular matrix.\n");
    }

    if(isDiagonalmatrix(mat, SIZE)){
        printf("The matrix is a diagonal matrix.\n");
    } else {
        printf("The matrix is not a diagonal matrix.\n");
    }
    
    return 0;
}