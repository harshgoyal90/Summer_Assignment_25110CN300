//    Write a program to Create menu-driven string operations system

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Display String\n");
        printf("2. Find Length\n");
        printf("3. Convert to Uppercase\n");
        printf("4. Convert to Lowercase\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("String: %s\n", str);
                break;
            case 2:
                printf("Length of string: %lu\n", strlen(str));
                break;
            case 3:
                for (int i = 0; str[i] != '\0'; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z') {
                        str[i] = str[i] - 'a' + 'A';
                    }
                }
                printf("String in uppercase: %s\n", str);
                break;
            case 4:
                for (int i = 0; str[i] != '\0'; i++) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] = str[i] - 'A' + 'a';
                    }
                }
                printf("String in lowercase: %s\n", str);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}