#include <stdio.h>

int main() {
    int decimalNumber, i = 0;
    int binaryNum[32]; 

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    while (decimalNumber > 0) {
        binaryNum[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;   
        i++;                          
    }

    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
    return 0;
}