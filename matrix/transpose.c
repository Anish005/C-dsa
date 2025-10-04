#include<stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int transpose[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            transpose[i][j] = matrix[j][i];
        }
        
    }
    printf("Transpose of the matrix:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", transpose[i][j]);
        } 
        printf("\n");
    }
}