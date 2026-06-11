// Write a program to Write function to find maximum

#include <stdio.h>

// Function declaration/definition
int findmax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a, b, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    max = findmax(a, b);

    printf("The maximum number is: %d\n", max);

    return 0;
}