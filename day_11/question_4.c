// Write a program to Write function to find factorial

#include <stdio.h>

int factorial(int n)
{
    int result = 1;
    int i;

    if (n < 0)
    {
        printf("Factorial not possible for negative number\n");
        return -1;
    }

    for (i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

int main()
{
    int num, fact;

    printf("Enter a number: ");
    scanf("%d", &num);

    fact = factorial(num);

    if (fact != -1)
    {
        printf("Factorial of %d = %d\n", num, fact);
    }

    return 0;
}
