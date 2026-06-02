#include <stdio.h>

int main() {
    int num;
    int largestfactor = 0;
    int i;

    printf("Enter a number: ");
    scanf("%d", &num);

    int originalnumber = num;

    while (num % 2 == 0) {
        largestfactor = 2;
        num = num / 2;
    }

    for (i = 3; i * i <= num; i = i + 2) {
        while (num % i == 0) {
            largestfactor = i;
            num = num / i;
        }
    }

    if (num > 2) {
        largestfactor = num;
    }

    printf("The largest prime factor of %d is: %d\n", originalnumber, largestfactor);

    return 0;
}

