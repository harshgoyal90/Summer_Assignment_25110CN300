//  Write a program to Sort names alphabetically

#include <stdio.h>
#include <string.h>
void sortNames(char names[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char names[n][100];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    sortNames(names, n);

    printf("\nNames sorted alphabetically:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}