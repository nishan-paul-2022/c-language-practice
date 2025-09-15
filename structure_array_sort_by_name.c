/*
 * Purpose: Demonstrates sorting an array of structures by a string member (name) using bubble sort, with improved clarity and input handling.
 * Topic: Arrays of Structures, Sorting, String Comparison
 */

#include <stdio.h>
#include <string.h>

// Define a structure to hold student information
typedef struct {
    char name[100]; // Student's name
    int roll;       // Student's roll number
    double cgpa;    // Student's CGPA
} StudentInfo;

// Function to sort an array of StudentInfo structures by name using bubble sort
void sort_students_by_name(StudentInfo students[], int num_students) {
    StudentInfo temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to print an array of StudentInfo structures
void print_students(const StudentInfo students[], int num_students) {
    printf("\n--- Sorted Student Data ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll: %d, CGPA: %.2lf\n", students[i].name, students[i].roll, students[i].cgpa);
    }
    printf("\n");
}

// Function to input student data
void input_students(StudentInfo students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: ", i + 1);
        if (scanf(" %99[^\n] %d %lf", students[i].name, &students[i].roll, &students[i].cgpa) != 3) {
            fprintf(stderr, "Invalid input for student %d. Skipping.\n", i + 1);
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        while (getchar() != '\n'); // Consume leftover newline
    }
}

int main(void) {
    int num_students;
    printf("Enter the number of students: ");
    if (scanf("%d", &num_students) != 1 || num_students <= 0) {
        fprintf(stderr, "Invalid input for number of students.\n");
        return 0;
    }
    while (getchar() != '\n'); // Consume leftover newline

    StudentInfo students[num_students];

    printf("Enter student details (Name Roll CGPA):\n");
    input_students(students, num_students);

    sort_students_by_name(students, num_students);
    print_students(students, num_students);

    return 0;
}
