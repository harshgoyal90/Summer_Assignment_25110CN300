// Write a program to Write function to find sum of two numbers

#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int n1, n2, result;

    printf("Enter first number : ");
    scanf("%d", &n1);

    printf("Enter second number : ");
    scanf("%d", &n2);

    result = sum(n1, n2);

    printf("Sum of %d and %d = %d\n", n1, n2, result);

    return 0;
}