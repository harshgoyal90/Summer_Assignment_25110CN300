//    Write a program to Create marksheet generation system

#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks[5]; // Array to store marks of 5 subjects
    float totalMarks;
    float percentage;
};
int main() {
    struct Student student;
    int i;

    printf("Enter student name: ");
    scanf("%s", student.name);

    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);

    student.totalMarks = 0;

    // Input marks for 5 subjects
    for(i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &student.marks[i]);
        student.totalMarks += student.marks[i];
    }

    // Calculate percentage
    student.percentage = (student.totalMarks / 500) * 100;

    // Display the marksheet
    printf("\nMarksheet:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Total Marks: %.2f\n", student.totalMarks);
    printf("Percentage: %.2f%%\n", student.percentage);

    return 0;
}