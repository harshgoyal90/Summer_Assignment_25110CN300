#include <stdio.h>

int main() {
    int n,i;
    int t1 = 0, t2 = 1;
    int nextTerm = 0;

    printf("Enter the number of (n) Fibonacci term: ");
    scanf("%d", &n);

    if (n <= 0)
     {
        printf("Please enter a number greater than 0.\n");
     } 
    else if (n == 1) \
    {
        printf("The 1st Fibonacci number is: %d\n", t1);
    } 
    else if (n == 2) 
    {
        printf("The 2nd Fibonacci number is: %d\n", t2);
    } 
    else 
    {
        for ( i = 3; i <= n; i++)
         {
            nextTerm = t1 + t2;
            t1 = t2;       
            t2 = nextTerm;
         }
        printf("The %dth Fibonacci number is: %d\n", n, nextTerm);
    }
    return 0;
}