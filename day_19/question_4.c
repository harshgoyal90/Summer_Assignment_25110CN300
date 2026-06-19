// Write a program to Find diagonal sum

#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[10][10];
    int sum = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows != cols) {
        printf("Error: Diagonal sum is only possible for a square matrix (Rows and Columns must be equal).\n");
        return 1; 
    }

    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        sum = sum + matrix[i][i]; 
    }

    printf("\nThe sum of the diagonal elements is: %d\n", sum);

    return 0;
}