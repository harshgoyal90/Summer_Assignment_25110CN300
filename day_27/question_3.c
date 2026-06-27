//    Write a program to Create salary management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char designation[30];
    float baseSalary;
    float hra;
    float da;
    float pf;
    float netSalary;
};

// Function prototypes
void addEmployee();
void displayAll();
void searchEmployee();

const char* FILE_NAME = "salary_records.dat";

int main() {
    int choice;

    while(1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nThank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new employee record and save it to a file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Employee emp;

    printf("\n--- Enter Employee Details ---");
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    
    // Clear input buffer before reading strings
    getchar(); 
    
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline character

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Base Salary: $");
    scanf("%f", &emp.baseSalary);

    // Automatic Salary Calculations
    emp.hra = emp.baseSalary * 0.10f; // 10% HRA
    emp.da = emp.baseSalary * 0.05f;  // 5% DA
    emp.pf = emp.baseSalary * 0.12f;  // 12% PF Deduction
    emp.netSalary = (emp.baseSalary + emp.hra + emp.da) - emp.pf;

    // Write the structure block to the file
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// Function to read and display all records from the file
void displayAll() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo records found! Add some records first.\n");
        return;
    }

    struct Employee emp;
    printf("\n=================================================================================\n");
    printf("%-5s %-15s %-12s %-10s %-8s %-8s %-8s %-10s\n", 
           "ID", "Name", "Design.", "Base Sal", "HRA", "DA", "PF", "Net Sal");
    printf("=================================================================================\n");

    // Read until end of file
    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-5d %-15s %-12s $%-9.2f $%-7.2f $%-7.2f $%-7.2f $%-9.2f\n",
               emp.id, emp.name, emp.designation, emp.baseSalary, emp.hra, emp.da, emp.pf, emp.netSalary);
    }
    printf("=================================================================================\n");
    fclose(fp);
}

// Function to search for a specific employee by their ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId;
    int found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if(emp.id == searchId) {
            found = 1;
            printf("\n--- Employee Found ---");
            printf("\nID:          %d", emp.id);
            printf("\nName:        %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nBase Salary: $%.2f", emp.baseSalary);
            printf("\nHRA (10%%):   $%.2f", emp.hra);
            printf("\nDA (5%%):     $%.2f", emp.da);
            printf("\nPF (12%%):    $%.2f", emp.pf);
            printf("\n-----------------------");
            printf("\nNet Salary:  $%.2f\n", emp.netSalary);
            break;
        }
    }

    if(!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}