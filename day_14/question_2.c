//  Write a program to Frequency of an element 

#include <stdio.h>

int main() {
    int n, element, num = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to find frequency: ");
    scanf("%d", &element);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            num++;
        }
    }
    
    printf("Frequency of %d in the array is: %d\n", element, num);
    
    return 0;
}