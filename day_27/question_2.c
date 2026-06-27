//     Write a program to Create employee management system

#include <stdio.h>
struct Employee {
    char name[50];
    int id;
    float salary;
};
int main() {
    struct Employee employee;
    
    printf("Enter employee name: ");
    scanf("%s", employee.name);
    
    printf("Enter employee ID: ");
    scanf("%d", &employee.id);
    
    printf("Enter salary: ");
    scanf("%f", &employee.salary);
    
    printf("\nEmployee Record:\n");
    printf("Name: %s\n", employee.name);
    printf("ID: %d\n", employee.id);
    printf("Salary: %.2f\n", employee.salary);
    
    return 0;
}