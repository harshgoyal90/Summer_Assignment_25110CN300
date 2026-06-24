//  Write a program to Check string rotation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isRotation(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return 0;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    strcpy(temp, s1);
    strcat(temp, s1);

    int result = (strstr(temp, s2) != NULL);

    free(temp);

    return result;
}

int main() {
    char str1[] = "AAbbCCDD";
    char str2[] = "ACDAbbCD";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (isRotation(str1, str2)) {
        printf("Result: Strings are rotations of each other.\n");
    } else {
        printf("Result: Strings are NOT rotations of each other.\n");
    }

    return 0;
}