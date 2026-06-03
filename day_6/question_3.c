#include <stdio.h>

int main() {
    int num, count = 0;
    int originalNum; 

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num; 

    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num = num / 2;
    }

    printf("The number of set bits (1s) in %d is: %d\n", originalNum, count);

    return 0;
}