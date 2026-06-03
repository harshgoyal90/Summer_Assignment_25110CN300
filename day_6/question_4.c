#include <stdio.h>

int main() {
    int x;
    int n;
    int result = 1; 
    int i;

    printf("Enter the base (x): ");
    scanf("%d", &x);

    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        result = result * x;
    }

    printf("%d raised to the power of %d is: %d\n", x, n, result);

    return 0;
}