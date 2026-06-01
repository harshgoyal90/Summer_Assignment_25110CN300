#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp, remainder, digits, sum;

    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    printf("\nArmstrong numbers between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        temp = i;
        digits = 0;
        sum = 0;

        while (temp > 0) {
            temp = temp / 10;
            digits++;
        }

        temp = i; 

        while (temp > 0) {
            remainder = temp % 10;
            sum = sum + round(pow(remainder, digits)); 
            temp = temp / 10;
        }

        if (sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}