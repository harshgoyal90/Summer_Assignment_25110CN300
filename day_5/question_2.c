#include <stdio.h>

int main() {
    int num, originalNum, remainder, sum = 0;
    int i, f;

    printf("Enter an integer: ");
    scanf("%d", &num);
    
    originalNum = num;

    
    while (num > 0) {
        remainder = num % 10; 

        f = 1;
        for (i = 1; i <= remainder; i++) {
            f = f * i;
        }
        sum = sum + f; 
        num = num / 10;   
    }

    if (sum == originalNum) {
        printf("%d is a Strong Number.\n", originalNum);
    } else {
        printf("%d is NOT a Strong Number.\n", originalNum);
    }

    return 0;
}