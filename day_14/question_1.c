// Write a program to Linear search 

#include <stdio.h>

int main() {
    int arr[100], n, i, search, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++) {
        if(arr[i] == search) {
            printf("Element found at index %d (Position %d).\n", i, i + 1);
            found = 1; 
            break; 
        }
    }

    if(found == 0) {
        printf("Number not found in the array.\n");
    }

    return 0;
} 