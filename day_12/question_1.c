// Write a program to Write function for palindrome 

#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;  
        }
        left++;
        right--;
    }
    return 1;  
}

int main() {
    char ch[100];
    
    printf("Enter a word: ");
    scanf("%s", ch);
    
    if (isPalindrome(ch)) {
        printf("%s is a palindrome\n", ch);
    } else {
        printf("%s is not a palindrome\n", ch);
    }
    
    return 0;
}