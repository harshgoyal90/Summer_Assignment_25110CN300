// Write a program to Write function for Armstrong

#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum = num;
    int remainder, result = 0;
    int n = 0;

    int temp = num;
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        result += round(pow(remainder, n)); 
        temp /= 10;
    }

    if (result == originalNum) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}