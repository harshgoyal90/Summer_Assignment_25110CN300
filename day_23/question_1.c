//  Write a program to Find first non-repeating character

#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void findFirstNonRepeating(char *str) {
    int count[NO_OF_CHARS] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            return;
        }
    }

    printf("All characters are repeating or the string is empty.\n");
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    findFirstNonRepeating(str);

    return 0;
}