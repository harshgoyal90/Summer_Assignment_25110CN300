// Write a program to Move zeroes to end

#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int writePointer = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[writePointer] = arr[i];
            writePointer++;
        }
    }

    while (writePointer < n) {
        arr[writePointer] = 0;
        writePointer++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 0, 3, 0, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    moveZeroesToEnd(arr, n);

    printf("Array after moving zeroes: ");
    printArray(arr, n);

    return 0;
}