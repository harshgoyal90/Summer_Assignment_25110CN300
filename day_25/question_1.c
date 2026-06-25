//  Write a program to Merge two sorted arrays

#include <stdio.h>

int main() {
    int n1, n2, n3;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d sorted elements for the first array:\n", n1);
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d sorted elements for the second array:\n", n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    n3 = n1 + n2;
    int arr3[n3];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    printf("\nThe merged sorted array is:\n");
    for(int m = 0; m < n3; m++) {
        printf("%d ", arr3[m]);
    }
    printf("\n");

    return 0;
}