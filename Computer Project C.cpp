#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int roll_number;
    float marks;
    char grade;
};

struct Student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    /*
    This function adds a new student to the system.
    It prompts the user to enter the student's name, roll number, and marks.
    It then calculates the student's grade based on their marks.
    */
    struct Student new_student;
    
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    
    printf("Enter student roll number: ");
    scanf("%d", &new_student.roll_number);
    
    printf("Enter student marks: ");
    scanf("%f", &new_student.marks);
    
    if (new_student.marks >= 90) {
        new_student.grade = 'A';
    } else if (new_student.marks >= 80) {
        new_student.grade = 'B';
    } else if (new_student.marks >= 70) {
        new_student.grade = 'C';
    } else if (new_student.marks >= 60) {
        new_student.grade = 'D';
    } else {
        new_student.grade = 'F';
    }
    
    students[num_students] = new_student;
    num_students++;
}

void display_student(struct Student student) {
    /*
    This function displays the details of a given student.
    */
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_number);
    printf("Marks: %.2f\n", student.marks);
    printf("Grade: %c\n", student.grade);
}

void display_all_students() {
    /*
    This function displays the details of all students in the system.
    */
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i+1);
        display_student(students[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
