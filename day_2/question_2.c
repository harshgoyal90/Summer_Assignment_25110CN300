#include <stdio.h>

int main() {
    int num, remainder;
    int reversedNumber = 0;

   
    printf("Enter an Number: ");
    scanf("%d", &num);

    for (; num != 0; num = num / 10) {
        remainder = num % 10;                     
        reversedNumber = reversedNumber * 10 + remainder; 
    }

    // Printing the final answer
    printf("Reversed number: %d\n", reversedNumber);

    return 0;
} 