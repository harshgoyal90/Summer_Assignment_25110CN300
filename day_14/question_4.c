//  Write a program to Find duplicates in array

#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 4, 10, 2, 8};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int found_duplicate = 0; 

    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Duplicate elements found in the array:\n");
    
    for(int i = 0; i < size; i++) {
        
        for(int j = i + 1; j < size; j++) {
            
            if(arr[i] == arr[j]) {
                printf("%d\n", arr[i]);
                found_duplicate = 1;
                break; 
            }
        }
    }

    if(found_duplicate == 0) {
        printf("No duplicate elements found.\n");
    }

    return 0;
}