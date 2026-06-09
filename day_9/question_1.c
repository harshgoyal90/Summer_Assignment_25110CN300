#include <stdio.h>

int main() {
    int rows;
    int i,j;

    printf("Enter the number of lines: ");
    scanf("%d", &rows);

    for (i = rows; i >= 1; i--) {
        
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n");
    }

    return 0;
}