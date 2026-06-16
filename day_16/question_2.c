// Write a program to Find maximum frequency elemen

#include <stdio.h>

int findMaxFrequencyElement(int arr[], int size, int *maxFreq) {
    int maxElement = arr[0];
    *maxFreq = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;
 
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > *maxFreq) {
            *maxFreq = count;
            maxElement = arr[i];
        }
    }

    return maxElement;
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 3, 2, 5, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int frequency = 0;

    int maxElement = findMaxFrequencyElement(arr, size, &frequency);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nMaximum frequency element: %d", maxElement);
    printf("\nIt appears %d times.\n", frequency);

    return 0;
}