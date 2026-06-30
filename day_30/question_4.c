//    Write a program to Develop complete mini project using arrays, strings and functions

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Function Declarations
void displayMenu();
void addStudent(int ids[], char names[][NAME_LENGTH], int *count);
void displayStudents(int ids[], char names[][NAME_LENGTH], int count);
void searchStudent(int ids[], char names[][NAME_LENGTH], int count);

int main() {
    // Arrays to store student data
    int studentIDs[MAX_STUDENTS];
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    int studentCount = 0; // Tracks current number of students
    
    int choice;

    printf("=== Welcome to the Student Management System ===\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clears the newline character left in the buffer by scanf

        switch (choice) {
            case 1:
                addStudent(studentIDs, studentNames, &studentCount);
                break;
            case 2:
                displayStudents(studentIDs, studentNames, studentCount);
                break;
            case 3:
                searchStudent(studentIDs, studentNames, studentCount);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

// Function to print the main menu
void displayMenu() {
    printf("\n-----------------------------\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Name\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

// Function to add a student
void addStudent(int ids[], char names[][NAME_LENGTH], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: System database is full!\n");
        return;
    }

    printf("\nEnter Student ID (integer): ");
    scanf("%d", &ids[*count]);
    getchar(); // Clear newline buffer

    printf("Enter Student Name: ");
    // fgets reads strings safely, including spaces
    fgets(names[*count], NAME_LENGTH, stdin);
    
    // Remove the trailing newline character added by fgets
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("\nSuccess: Student added successfully!\n");
    (*count)++; // Increment the total student count
}

// Function to display all recorded students
void displayStudents(int ids[], char names[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n=== Student Records ===\n");
    printf("%-10s %-30s\n", "ID", "Name");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s\n", ids[i], names[i]);
    }
}

// Function to search for a student by their name
void searchStudent(int ids[], char names[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    int found = 0;

    printf("\nEnter the exact student name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline

    printf("\nSearching...\n");
    for (int i = 0; i < count; i++) {
        // strcmp returns 0 if strings match perfectly
        if (strcmp(names[i], searchName) == 0) {
            printf("Match Found! ID: %d | Name: %s\n", ids[i], names[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with the name \"%s\".\n", searchName);
    }
}