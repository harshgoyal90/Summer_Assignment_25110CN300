//  Write a program to Find pair with given sum

#include <stdio.h>

int main() {

    int arr[] = {1, 4, 45, 6, 10, 8};
    int target_sum = 16;

    int n = sizeof(arr) / sizeof(arr[0]);
    int found = 0; 

    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget Sum: %d\n\n", target_sum);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target_sum) {
                printf("Pair found: %d and %d (at indices %d and %d)\n", arr[i], arr[j], i, j);
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("No pair found with the given sum.\n");
    }

    return 0;
}