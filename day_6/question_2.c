#include <stdio.h>

int main() {
    int binary, decimal = 0, weight = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary > 0) {
        remainder = binary % 10;         
        decimal = decimal + remainder * weight; 
        weight = weight * 2;        
        binary = binary / 10;       
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}