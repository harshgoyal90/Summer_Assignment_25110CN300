//   Write a program to Remove duplicate characters

#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int seen[256] = {0}; 
    int targetIndex = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i]; 

        if (seen[ch] == 0) {
            seen[ch] = 1;          
            str[targetIndex] = str[i]; 
            targetIndex++;
        }
    }

    str[targetIndex] = '\0';
}

int main() {
    char str[] = "programming is a wonderful thing to learn";
    
    printf("Original String: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}