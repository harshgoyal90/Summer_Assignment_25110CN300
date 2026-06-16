// Write a program to Find missing number in array

#include <stdio.h>

int main() {
    int n, i;
    int arraySum = 0, totalSum = 0;

    printf("Enter the value of n (total count including missing): ");
    scanf("%d", &n);

    int arr[n - 1];
    printf("Enter %d elements: ", n - 1);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        arraySum += arr[i]; 
    }

    totalSum = (n * (n + 1)) / 2;

    printf("The missing number is: %d\n", totalSum - arraySum);

    return 0;
}