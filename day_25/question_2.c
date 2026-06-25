//     Write a program to Find common characters in strings

#include <stdio.h>
void findCommonCharacters(char *str1, char *str2) {
    int count[256] = {0}; 
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
    }

    printf("Common characters: ");
    for (i = 0; str2[i] != '\0'; i++) {
        if (count[(unsigned char)str2[i]] > 0) {
            printf("%c ", str2[i]);
            count[(unsigned char)str2[i]] = 0; 
        }
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    findCommonCharacters(str1, str2);

    return 0;
}