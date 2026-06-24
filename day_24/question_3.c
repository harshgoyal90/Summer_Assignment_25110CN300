//   Write a program to Find longest word

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    char longestWord[100];
    int maxLen = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    int i = 0, currentLen = 0;
    int startIdx = 0;
    
    while (sentence[i] != '\0') {
        if (isalnum(sentence[i])) {
            if (currentLen == 0) {
                startIdx = i; 
            }
            currentLen++;
        } else {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                strncpy(longestWord, &sentence[startIdx], maxLen);
                longestWord[maxLen] = '\0'; 
            }
            currentLen = 0; 
        }
        i++;
    }

    if (maxLen > 0) {
        printf("The longest word is: \"%s\"\n", longestWord);
        printf("Length: %d\n", maxLen);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}