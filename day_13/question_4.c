// Write a program to Count even and odd elements

#include<stdio.h>
int main () {
    int n, i;
    printf(" Enter the elements of array :");
    scanf("%d", &n);
     
    int A[n];
    for (i = 0; i < n; i++){
    printf("Enter Number of elements : ", i + 1);
    scanf("%d", &A[i]);
    }
    int even = 0, odd = 0;
    for (i = 0; i < n; i++)
    if (A[i] % 2 == 0){

        even++;
         
    }
    else {

        odd++;
        
    }
    printf("Count of even number %d\n", even);
    printf("Count of odd number %d", odd);
   
    return 0;
}