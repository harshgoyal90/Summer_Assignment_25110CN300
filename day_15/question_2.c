// Write a program to Rotate array left 

#include <stdio.h>

int main() {
    int n, rotations = 2, r, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter %d elements: ", n);
    for( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    for( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(r = 0; r < rotations; r++) {
        int firstelement = arr[0]; 
     
        for( i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        arr[n - 1] = firstelement;
    }
    printf("Array after %d left rotations: \n", rotations);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}