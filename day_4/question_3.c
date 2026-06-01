#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0;

    printf("Enter a three digit: ");
    scanf("%d", &num);

    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
    
        result += remainder * remainder * remainder;
        
        originalNum /= 10;
    }

    if (result == num)
        printf("The %d is Armstrong number.\n", num);
    else
        printf("The %d is not an Armstrong number.\n", num);

    return 0;
}
