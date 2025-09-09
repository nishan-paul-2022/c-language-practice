// Purpose: Demonstrates sorting an array of structures by an integer member (roll number) using bubble sort, with improved clarity and input handling.
// Topic: Arrays of Structures, Sorting, Integer Comparison

#include <stdio.h>
#include <string.h> // For strcpy

// Define a structure to hold student information
struct StudentInfo {
    char name[100]; // Student's name
    int roll;       // Student's roll number
    double cgpa;    // Student's CGPA
};

// Function to input student data into an array of structures
void inputStudentData(struct StudentInfo students[], int numStudents) {
    int i;
    printf("\nEnter student details (Name, Roll, CGPA) for each student:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        // Safely read student name using fgets
        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            fprintf(stderr, "Error reading name for student %d.\n", i + 1);
            // Clear buffer and continue or return error
            while (getchar() != '\n');
            continue;
        }
        // Remove trailing newline character from name
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        // Read roll number and CGPA, with input validation
        if (scanf("%d %lf", &students[i].roll, &students[i].cgpa) != 2) {
            fprintf(stderr, "Error reading roll number or CGPA for student %d.\n", i + 1);
            // Clear the input buffer in case of scanf failure
            while (getchar() != '\n');
            // Skip to the next iteration if input fails
            continue;
        }
        // Consume the newline character after reading CGPA to prepare for the next iteration
        while (getchar() != '\n');
    }
}

// Function to output the array of student information
void outputStudentArray(struct StudentInfo students[], int numStudents) {
    int i;
    printf("\n--- Sorted Student Data (by Roll Number) ---\n");
    for (i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll: %d, CGPA: %.2lf\n", students[i].name, students[i].roll, students[i].cgpa);
    }
    printf("\n");
}

// Function to sort an array of StudentInfo structures by roll number using bubble sort
void sortStudentsByRoll(struct StudentInfo students[], int numStudents) {
    int i, j;
    struct StudentInfo tempStudent; // Temporary variable for swapping

    // Bubble sort algorithm
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            // Compare roll numbers
            if (students[j].roll > students[j + 1].roll) {
                // Swap the entire structures
                tempStudent = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tempStudent;
            }
        }
    }
}

int main() {
    int numStudents; // Number of students

    // Prompt user for the number of students
    printf("Enter the number of students: ");
    // Read the number of students and validate input
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
        fprintf(stderr, "Invalid input for number of students. Please enter a positive integer.\n");
        return 0;
    }

    // Consume the newline character left by scanf after reading numStudents
    while (getchar() != '\n');

    // Declare an array of structures (Variable Length Array - C99 feature)
    struct StudentInfo students[numStudents];

    // Input student data
    inputStudentData(students, numStudents);

    // Sort the array of students by roll number
    sortStudentsByRoll(students, numStudents);

    // Output the sorted array
    outputStudentArray(students, numStudents);

    return 0;
}
