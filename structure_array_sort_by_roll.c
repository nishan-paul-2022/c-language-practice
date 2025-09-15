/*
 * Purpose: Demonstrates sorting an array of structures by an integer member (roll number) using bubble sort, fully function-based.
 * Topic: Arrays of Structures, Sorting, Integer Comparison
 */

#include <stdio.h>
#include <string.h>

// Define a structure to hold student information
typedef struct {
    char name[100]; // Student's name
    int roll;       // Student's roll number
    double cgpa;    // Student's CGPA
} StudentInfo;

// Function to input student data
void input_students(StudentInfo students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d Name: ", i + 1);
        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            fprintf(stderr, "Error reading name for student %d.\n", i + 1);
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        // Remove newline
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Student %d Roll and CGPA: ", i + 1);
        if (scanf("%d %lf", &students[i].roll, &students[i].cgpa) != 2) {
            fprintf(stderr, "Error reading roll/CGPA for student %d.\n", i + 1);
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        while (getchar() != '\n'); // Consume leftover newline
    }
}

// Function to sort students by roll number
void sort_students_by_roll(StudentInfo students[], int num_students) {
    StudentInfo temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].roll > students[j + 1].roll) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to print students
void print_students(const StudentInfo students[], int num_students) {
    printf("\n--- Sorted Student Data (by Roll Number) ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll: %d, CGPA: %.2lf\n", students[i].name, students[i].roll, students[i].cgpa);
    }
    printf("\n");
}

int main(void) {
    int num_students;
    printf("Enter the number of students: ");
    if (scanf("%d", &num_students) != 1 || num_students <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return 0;
    }
    while (getchar() != '\n'); // Consume leftover newline

    StudentInfo students[num_students];

    input_students(students, num_students);
    sort_students_by_roll(students, num_students);
    print_students(students, num_students);

    return 0;
}
