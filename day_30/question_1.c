//   Write a program to Create student record system using arrays and strings  

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Defining the structure to hold a single student's data
struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float gpa;
};

// Function prototypes
void addStudent(struct Student records[], int *count);
void displayStudents(struct Student records[], int count);
void searchStudent(struct Student records[], int count);

int main() {
    struct Student records[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Safety check for integer input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(records, &studentCount);
                break;
            case 2:
                displayStudents(records, studentCount);
                break;
            case 3:
                searchStudent(records, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add a new student record
void addStudent(struct Student records[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Clear the trailing newline character left in the buffer by scanf
    getchar(); 
    
    printf("Enter Student Name: ");
    // fgets is safer than scanf for strings because it allows spaces in names
    fgets(newStudent.name, NAME_LENGTH, stdin);
    // Remove the newline character that fgets automatically appends
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    // Store the new student into the array and increment the total count
    records[*count] = newStudent;
    (*count)++;
    
    printf("Record added successfully!\n");
}

// Function to display all records
void displayStudents(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-5.2f\n", records[i].rollNumber, records[i].name, records[i].gpa);
    }
}

// Function to search for a specific student
void searchStudent(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", records[i].rollNumber);
            printf("Name:        %s\n", records[i].name);
            printf("GPA:         %.2f\n", records[i].gpa);
            return; // Exit function early since we found the student
        }
    }
    
    printf("Student with Roll Number %d not found.\n", targetRoll);
}


