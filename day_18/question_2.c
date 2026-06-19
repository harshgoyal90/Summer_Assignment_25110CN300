// Write a program to Selection sort 

#include <stdio.h>

int main() {
    int arr[100], n, i, j, position, swap;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        position = i;

        for (j = i + 1; j < n; j++){
            if (arr[position] > arr[j]) {
                position = j;
            }
        }

        if (position != i) {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }

    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}