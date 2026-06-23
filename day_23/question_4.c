//   Write a program to Find maximum occurring character

#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

char getMaxOccurringChar(char* str) {

    int count[ASCII_SIZE] = {0};

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }

    int max = -1; 
    char result;   

    for (int i = 0; i < len; i++) {
        if (max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    return result;
}

int main() {
    char str[] = "sample string is good";
    
    printf("Original String: %s\n", str);
    
    char maxChar = getMaxOccurringChar(str);
    printf("Maximum occurring character is: '%c'\n", maxChar);
    
    return 0;
}