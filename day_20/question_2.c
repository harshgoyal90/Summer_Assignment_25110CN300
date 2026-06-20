//   Write a program to Check symmetric matrix

#include <stdio.h>

int main() {
    int rows, cols, i, j, isSymmetric = 1;
    int matrix[10][10];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("The matrix must be a square matrix (rows = columns) to be symmetric.\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; 
                break;           
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }

    printf("\nThe given matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric == 1) {
        printf("\nResult: The matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nResult: The matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}