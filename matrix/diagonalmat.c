#include <stdio.h>
#define SIZE 3

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
//specic function to check identity matrix
int isIdentitymatrix(int mat[SIZE][SIZE], int n){
     int i,j;
     for(i = 0; i < n ; i++){
        for(j = 0; j < n; j++){
            if(i == j && mat[i][j] != 1){
                return 0; // Not an identity matrix
            }
            if(i != j && mat[i][j] != 0){
                return 0; // Not an identity matrix
            }

        }
     }
     return 1;// Is an identity matrix
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

    if(isDiagonalmatrix(mat, SIZE)){
        printf("The matrix is a diagonal matrix.\n");
    } else {
        printf("The matrix is not a diagonal matrix.\n");
    }

    return 0;
}