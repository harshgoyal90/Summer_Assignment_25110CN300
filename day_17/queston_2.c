//  Write a program to Union of arrays 

#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int n1 = 5, n2 = 5;

    printf("Union of the two arrays: ");

    for (int i = 0; i < n1; i++) {
        printf("%d ", a[i]);
    }

    for (int i = 0; i < n2; i++) {
        int found = 0;
        for (int j = 0; j < n1; j++) {
            if (b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", b[i]);
        }
    }

    return 0;
}