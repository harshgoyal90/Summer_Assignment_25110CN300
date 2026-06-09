#include <stdio.h>

int main() {
    int size = 5; // You can change this value to make the square bigger or smaller
    
    // Outer loop for rows
    for (int i = 1; i <= size; i++) {
        
        // Inner loop for columns
        for (int j = 1; j <= size; j++) {
            
            // Print '*' if it's the first/last row or first/last column
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                // Print space for the hollow part inside
                printf(" ");
            }
        }
        
        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
}