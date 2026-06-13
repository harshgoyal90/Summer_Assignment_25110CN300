// Write a program to Find sum and average of array   

#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    
    average = sum / n;

    printf("\nSum of array elements: %.2f", sum);
    printf("\nAverage of array elements: %.2f", average);

    return 0;
}