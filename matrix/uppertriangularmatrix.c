#include <stdio.h>

// Define the size of the matrix
#define SIZE 3

int isUpperTriangular(int matrix[SIZE][SIZE], int size) {
    int i, j;
    // Check elements below the main diagonal
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i > j && matrix[i][j] != 0) {
                // If any element below the diagonal is non-zero, return 0 (false)
                return 0;
            }
        }
    }
    // If all elements below the diagonal are zero, return 1 (true)
    return 1;
}

int main() {
    int matrix[SIZE][SIZE];
    int i, j;

    // Input elements for the matrix
    printf("Enter elements for a %dx%d matrix:\n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("\nThe input matrix is:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Check if the matrix is upper triangular
    if (isUpperTriangular(matrix, SIZE)) {
        printf("The matrix is an upper triangular matrix.\n");
    } else {
        printf("The matrix is not an upper triangular matrix.\n");
    }

    return 0;
}