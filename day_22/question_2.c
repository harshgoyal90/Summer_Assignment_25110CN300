//  Write a program to Count words in a sentence  

#include <stdio.h>

int countWords(char *str) {
    int count = 0;
    int inWord = 0; 

    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            inWord = 0;
        } 
        else if (inWord == 0) {
            inWord = 1;
            count++;
        }
        str++; 
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int words = countWords(sentence);
    printf("Total number of words: %d\n", words);

    return 0;
}