//    Write a program to Compress a string


#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char compressed[200]; 
    int i, j = 0;
    int count;

    printf("Enter a string to compress: ");
    scanf("%s", str);

    int length = strlen(str);

    for (i = 0; i < length; i++) {

        count = 1;
        while (i < length - 1 && str[i] == str[i + 1]) {
            count++;
            i++; 
        }

        compressed[j++] = str[i];

        j += sprintf(&compressed[j], "%d", count);
    }
    
    compressed[j] = '\0';

    printf("\nOriginal String: %s\n", str);
    printf("Compressed String: %s\n", compressed);

    if (strlen(compressed) >= length) {
        printf("Note: Compression didn't reduce the size.\n");
    }

    return 0;
}