// Write a program to Find common elements

#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 5, 8, 10};
    int arr2[] = {2, 4, 8, 11, 15};
 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Common elements are: ");

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break; 
            }
        }
    }

    return 0;
}