// Write a program to Rotate array right

#include <stdio.h>

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of places to rotate right: ");
    scanf("%d", &k);

    k = k % n; 

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Array after right rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}