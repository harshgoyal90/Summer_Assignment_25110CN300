//   Write a program to Create mini employee management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char department[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void menu();

int main() {
    int choice;
    
    while(1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        
        switch(choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Display the main menu
void menu() {
    printf("\n=================================");
    printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
    printf("\n=================================");
    printf("\n1. Add Employee");
    printf("\n2. Display All Employees");
    printf("\n3. Search Employee by ID");
    printf("\n4. Delete Employee");
    printf("\n5. Exit");
    printf("\n=================================\n");
}

// 1. Add a new employee to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear newline character from buffer
    
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline
    
    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;
    
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    
    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    
    printf("\nEmployee added successfully!\n");
}

// 2. Read and display all records
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo employee records found. Try adding some first!\n");
        return;
    }
    
    Employee emp;
    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-----------------------------------------------------------------\n");
    
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-20s $%-9.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }
    printf("-----------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    
    int searchId, found = 0;
    Employee emp;
    
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);
    
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if(emp.id == searchId) {
            found = 1;
            printf("\nEmployee Found!");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDepartment: %s", emp.department);
            printf("\nSalary: $%.2f\n", emp.salary);
            break;
        }
    }
    
    if(!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Delete an employee record
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }
    
    // Create a temporary file to copy over everything except the deleted record
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }
    
    int deleteId, found = 0;
    Employee emp;
    
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);
    
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if(emp.id == deleteId) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }
    
    fclose(fp);
    fclose(tempFp);
    
    if(found) {
        remove(FILE_NAME);         // Delete old file
        rename("temp.dat", FILE_NAME); // Rename temp file to original name
        printf("\nEmployee record deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temp file
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}